#ifndef CAMERA_H
#define CAMERA_H

#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QImage>

#include "cv.h"
#include "highgui.h"
#include "map.h"

#define ENCARA2INLINUX 1
// Encara2's includes: begin
#include "ENCARA2_2lib.h"
#include <FacialData.h>
// Encara2's includes: end

#include <iostream>
#include <fstream>
#include <cstdio>

#ifdef _EiC
#define WIN32
#endif

using namespace std;
using namespace cv;

namespace Ui {
class Camera;
}

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

private slots:
    void sltTimeOut();

    void on_action_triggered();

    float getVariance(float num);

private:
    Ui::Camera *ui;

    QTimer *m_timer;
    CvCapture *m_camera;        //视频获取结构 作为视频获取函数的返回值
    IplImage *m_imgFrame;
    CENCARA2_2Detector *ENCARAFaceDetector; //Detector
    //CFacialData *FacialData;
    CFacialDataperImage *FacialData; //Detection data
    CFacialData **faces;

    Map map;
};

#endif // CAMERA_H
