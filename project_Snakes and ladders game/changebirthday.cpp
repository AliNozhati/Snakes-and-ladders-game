#include "changebirthday.h"
#include "ui_changebirthday.h"
#include <qmessagebox.h>
#include <string>
#include <LoginAndRegister.h>

ChangeBirthday::ChangeBirthday(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeBirthday)
{
    ui->setupUi(this);
}


ChangeBirthday::~ChangeBirthday()
{
    delete ui;
}

void ChangeBirthday::on_change_clicked()
{
    QMessageBox msgbox;
    int size_day = ui->day->currentIndex(), size_mount = ui->mount->currentIndex(), size_year = ui->year->currentIndex();

    if(size_day == 0)
    {
        msgbox.setText("Enter day");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else if(size_mount == 0)
    {
        msgbox.setText("Enter mount");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else if(size_year == 0)
    {
        msgbox.setText("Enter year");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        change_birthday(Myplayer, to_string(size_day+1), to_string(size_mount+1), to_string(size_year+1999));
        this->close();
    }
}

