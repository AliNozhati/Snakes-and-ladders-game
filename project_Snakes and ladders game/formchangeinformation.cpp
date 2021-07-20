#include "formchangeinformation.h"
#include "ui_formchangeinformation.h"
#include <qmessagebox.h>
#include <LoginAndRegister.h>
#include <formchange.h>
#include <forminformation.h>
#include <formforget.h>

FormChangeInformation::FormChangeInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormChangeInformation)
{
    ui->setupUi(this);
}

FormChangeInformation::~FormChangeInformation()
{
    delete ui;
}

void FormChangeInformation::on_Login_clicked()
{
    QString Username = ui->User->text(), Password = ui->Pass->text();
    int SizeU = Username.length(), SizeP = Password.length();
    QMessageBox msgbox;

    if(SizeP < 1 || SizeU < 1)
    {
        msgbox.setText("Enter username and password");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        unsigned int Check;
        Readfile(Myplayer);
        Check = CheckLogin(Myplayer, Username.toStdString(), Password.toStdString());

        if(Check == 0)
        {
            msgbox.setText("Username or password incorrect");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
        else
        {
//            Count = 0;
            IndexPlayers[4] = Check - 1;
            this->close();
            FormChange *newform = new FormChange();
            newform->show();
        }
    }
}


void FormChangeInformation::on_Back_clicked()
{
    this->close();
    FormInformation *newform = new FormInformation();
    newform->show();
}


void FormChangeInformation::on_Forget_clicked()
{
    FormForget *newform = new FormForget();
    newform->show();
}

