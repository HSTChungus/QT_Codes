#ifndef HOME_SCREEN_H
#define HOME_SCREEN_H

#include <QDialog>

namespace Ui {
class Home_Screen;
}

class Home_Screen : public QDialog
{
    Q_OBJECT

public:
    explicit Home_Screen(QWidget *parent = 0);
    ~Home_Screen();

private slots:
    void on_CamSetUP_clicked();

private:
    Ui::Home_Screen *ui;
};

#endif // HOME_SCREEN_H
