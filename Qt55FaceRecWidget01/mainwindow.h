#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <facerec.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_load_db_clicked();

    void on_btn_load_model_clicked();

    void on_btn_run_clicked();

    void on_btn_save_model_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
