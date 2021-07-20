#include "changephone.h"
#include "ui_changephone.h"
#include <qmessagebox.h>
#include <LoginAndRegister.h>
#include <string>
using namespace std;

ChangePhone::ChangePhone(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePhone)
{
    ui->setupUi(this);
}

ChangePhone::~ChangePhone()
{
    delete ui;
}

void ChangePhone::on_change_clicked()
{
    QMessageBox msgbox;
    string phone = ui->phone->text().toStdString();
    int size = phone.size();

    if(size == 0)
    {
        msgbox.setText("Enter Phone Number");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        if(size != 11)
        {
            msgbox.setText("Enter an 11-digit phone number");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
        else if(phone[0] != '0' || phone[1] != '9')
        {
            msgbox.setText("Enter the correct phone number");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
        else
        {
            change_phone(Myplayer, phone);
            this->close();
        }
    }
}

