#-------------------------------------------------
#
# Project created by QtCreator 2013-09-01T11:09:17
#
#-------------------------------------------------

QT += widgets
QT += multimedia multimediawidgets
QT += core gui
QT += webkit
QT += network
QT += webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MouseTerminator
TEMPLATE = app


SOURCES += main.cpp\
        camera.cpp

HEADERS  += camera.h

FORMS    += camera.ui

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2 \
                /home/tairy/Documents/v2.11/linux/include

LIBS += /home/tairy/Documents/v2.11/linux/lib/libencara-raw.so\
        /usr/local/lib/libopencv_calib3d.so \
        /usr/local/lib/libopencv_contrib.so \
        /usr/local/lib/libopencv_core.so \
        /usr/local/lib/libopencv_features2d.so \
        /usr/local/lib/libopencv_flann.so \
        /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_imgproc.so \
        /usr/local/lib/libopencv_legacy.so \
        /usr/local/lib/libopencv_ml.so \
        /usr/local/lib/libopencv_objdetect.so \
        /usr/local/lib/libopencv_photo.so \
        /usr/local/lib/libopencv_stitching.so \
        /usr/local/lib/libopencv_ts.so \
        /usr/local/lib/libopencv_video.so \
        /usr/local/lib/libopencv_videostab.so
