#include "camera.h"
#include "ui_camera.h"
#include "map.h"

#include <qfile.h>
#include <qtextstream.h>

char ENCARAdataDir[256]="/home/tairy/Documents/v2.11/linux/ENCARA2data";

Camera::Camera(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);

    ui->m_lbPhoto->setScaledContents(true);

    //初始化成员变量
    m_timer = new QTimer(this);
    m_camera = cvCaptureFromCAM(CV_CAP_V4L);
    m_imgFrame = NULL;
    ENCARAFaceDetector = NULL;
    m_timer->start(13);

    ui->actionChangeDisplayOrder->setEnabled(true);
    ui->actionDisplayVideo->setEnabled(true);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(sltTimeOut()));
    map.show();
}

Camera::~Camera()
{
    cvReleaseCapture( &m_camera );
    delete ENCARAFaceDetector;
    delete ui;
}

float Camera::getVariance(float num){

}

void Camera::sltTimeOut()
{
   Mat frame, frameCopy;
   if( m_camera )
   {
       int i =0;
       while(1)
       {
           m_imgFrame = cvQueryFrame(m_camera);
           frame = m_imgFrame;
           if( frame.empty() )
               break;
           if( m_imgFrame->origin == IPL_ORIGIN_TL )
               frame.copyTo( frameCopy );
           else
               flip( frame, frameCopy, 0 );

           //Loading ENCARA2
           if (ENCARAFaceDetector==NULL)
           {
                ENCARAFaceDetector=new CENCARA2_2Detector(ENCARAdataDir,frame.size().width,frame.size().height);
           }
           else
           {
                    //ENCARA2 processing
                   ENCARAFaceDetector->ApplyENCARA2(m_imgFrame,2);

                   //drow the position of eye
                   ENCARAFaceDetector->PaintFacialData(m_imgFrame,CV_RGB(0,255,0));
           }
           FacialData = ENCARAFaceDetector->GetFacialData();
           faces = FacialData -> Faces;
           if(FacialData ->NumFaces >0){
               // write in a file and draw the figure!
////////////////////////////////////////////////////////////////////////////////////////
               QFile f("/home/tairy/Working/MouseTerminator/result/9.txt");
               if(!f.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append))
               {
                   cerr << "Open failed." << endl;
               }
               QTextStream txtOutput(&f);

               txtOutput<<i<<","<<1<<","<<faces[0]->e_rx-faces[0]->e_lx<<","<<faces[0]->e_ry-faces[0]->e_ly<<endl;
               cerr<<i<<","<<1<<","<<faces[0]->e_rx-faces[0]->e_lx<<","<<faces[0]->e_ry-faces[0]->e_ly<<endl;
//               txtOutput<<i<<","<<2<<","<<faces[0]->e_rx<<","<<faces[0]->e_ry<<endl;
//               txtOutput<<i<<","<<3<<","<<faces[0]->np_x<<","<<faces[0]->np_y<<endl;
//               txtOutput<<i<<","<<4<<","<<faces[0]->ml_x<<","<<faces[0]->ml_y<<endl;
               i++;
               f.close();
///////////////////////////////////////////////////////////////////////////////////
               //make mouse move
//               QPoint videoWindowPos = map.getWinPos();
//               QPoint pos;
//               int pos_x = (faces[0]->np_x % 10)>5 ? ((faces[0]->np_x/10)*10 + 10 ): ((faces[0]->np_x/10)*10);
//               int pos_y = (faces[0]->np_y % 10)>5 ? ((faces[0]->np_y/10)*10 + 10 ): ((faces[0]->np_y/10)*10);
//               pos_x += videoWindowPos.x();
//               pos_y += videoWindowPos.y();
//               pos.setX(pos_x);
//               pos.setY(pos_y);
//               QCursor::setPos(pos);
//////////////////////////////////////////////////////////////////////////////////

           }

           //将抓取到的帧转换成QImage格式
           QImage showImage((const uchar*)m_imgFrame->imageData, m_imgFrame->width, m_imgFrame->height, QImage::Format_RGB888);

           //将图片显示到QLabel上
           //ui->m_lbPhoto->resize(ui->stackedWidget->size());
           ui-> m_lbPhoto-> setPixmap(QPixmap::fromImage(showImage));
           if( cvWaitKey(50) == 27 ){
               break;
           }
       }
    }else{
        fprintf(stderr,"\n无法打开摄像头，请检查您的设备。\n");
    }
}

void Camera::on_action_triggered()
{
    exit(0);
}
