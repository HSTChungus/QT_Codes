#include "time_select.h"
#include "home_screen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Time_Select w;

    w.show();

    return a.exec();
}
