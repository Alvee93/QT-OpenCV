#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFileDialog>
#include<QString>
#include <iostream>
#include <string>

FaceRec fRec;
QString filename;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_load_db_clicked()
{
    QFileDialog dialog(this);                                   // Browsing files
    dialog.setNameFilter(tr("Images(*.csv *.xls *.xlsx)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString filename = QFileDialog::getOpenFileName(this,
                       tr("Open Images"), "",
                       tr("Image Files (*csv *xls *xlsx)"));
    if(!filename.isEmpty())                                 // Image showing
        {
        fRec.read_csv(filename.toLocal8Bit().constData()); // conversion from QString to c++ string
        ui->label->setText("Model trained");
    }

}

void MainWindow::on_btn_load_model_clicked()
{
    QFileDialog dialog(this);                                   // Browsing files
    dialog.setNameFilter(tr("YML(*.yml *.xml *.yaml)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString file_yml = QFileDialog::getOpenFileName(this,
                       tr("Open Images"), "",
                       tr("XML Files (*xml *yml *yaml)")); // file showing

    if(!file_yml.isEmpty()){
        fRec.load_model(file_yml.toLocal8Bit().constData());
        ui->label->setText("Model loaded");
    }
}

void MainWindow::on_btn_run_clicked()
{
    //ui->label->setNum(fRec.check_model());
    if(fRec.check_model()) {
        QFileDialog dialog(this);                                   // Browsing files
        dialog.setNameFilter(tr("Images(*.jpg *.png *.xpm)"));
        dialog.setViewMode(QFileDialog::Detail);
        filename = QFileDialog::getOpenFileName(this,
                           tr("Open Images"), "",
                           tr("Image Files (*jpg *png *bmp *pgm)")); // Image showing

        if(!filename.isEmpty()){
            QPixmap pix(filename);

            int w = ui->label_img->width ();
            int h = ui->label_img->height ();
            ui->label_img->setPixmap (pix.scaled (w,h,Qt::KeepAspectRatio));

            ui->label->setText("Loading, plz w8...");
            int i = fRec.predictLabel(filename.toLocal8Bit().constData()); //QString => string
            ui->label->setNum(i);
        }
    }

    else {
        ui->label->setText("Please load model first");
    }

}

void MainWindow::on_btn_save_model_clicked()
{
    if(fRec.check_model()){
        fRec.save_model();
        ui->label->setText("Model successfully saved");
    }
    else {
        ui->label->setText("Please load model/DB first");
    }
}
