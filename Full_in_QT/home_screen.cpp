#include "home_screen.h"
#include "ui_home_screen.h"

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
    time_t iTime = 0;
    time_t cTime = 0;

    time(&iTime);
    while (difftime(cTime,iTime) <= 5){
        time(&cTime);
    }

    Home_Screen HomeScreen;
    HomeScreen.setModal(true);
    HomeScreen.exec();
}
