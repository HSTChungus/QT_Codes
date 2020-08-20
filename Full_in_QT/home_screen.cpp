#include "home_screen.h"
#include "ui_home_screen.h"

// Computer Visions
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

Home_Screen::Home_Screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home_Screen)
{
    ui->setupUi(this);
}

Home_Screen::~Home_Screen()
{
    delete ui;
}

void Home_Screen::on_CamSetUP_clicked()
{


    char const* CamWindow = "Eye Tracker";

    VideoCapture cap(0);

    system("v4l2-ctl --set-ctrl vertical_flip=1"); // set video upside-down
    system("v4l2-ctl -d /dev/video0 -p 30"); // set framrate
    system("v4l2-ctl --set-fmt-video=width=640"); // set width
    system("v4l2-ctl --set-fmt-video=height=480"); // set height
    if(!cap.isOpened()){
        printf("ERROR no camera detected\n");
        cin.ignore();
    }
    else{
        printf("This part runs.\n");
    }

    resizeWindow(CamWindow, 800, 400);
    moveWindow(CamWindow, 0, 0);

    cap >> src; // rename

    time(&iTime);
    while(difftime(cTime,iTime)<=10){
        time(&cTime);
        imshow(CamWindow, src);
        waitKey(0);
    }


    Home_Screen HomeScreen;
    HomeScreen.setModal(true);
    HomeScreen.exec();
}
