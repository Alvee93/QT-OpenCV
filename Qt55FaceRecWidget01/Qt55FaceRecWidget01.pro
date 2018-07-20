#-------------------------------------------------
#
# Project created by QtCreator 2018-07-18T23:50:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qt55FaceRecWidget01
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    facerec.cpp

HEADERS  += mainwindow.h \
    facerec.h

FORMS    += mainwindow.ui

INCLUDEPATH += "D:\\Softs\\OpenCV\\opencv24136\\opencv\\build\\include"

        LIBS += -L"D:\\Softs\\OpenCV\\opencv24136\\opencv\\build\\x64\\vc14\\lib" \
            -lopencv_core2413d \
            -lopencv_highgui2413d \
            -lopencv_imgproc2413d \
            -lopencv_features2d2413d \
            -lopencv_calib3d2413d \
            -lopencv_objdetect2413d \
            -lopencv_contrib2413d
