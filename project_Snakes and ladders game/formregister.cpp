#include "formregister.h"
#include "ui_formregister.h"
#include <Structure.h>
#include <qmessagebox.h>
#include <LoginAndRegister.h>
#include <formlogin.h>

FormRegister::FormRegister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormRegister)
{
    ui->setupUi(this);
}

FormRegister::~FormRegister()
{
    delete ui;
}

void FormRegister::on_r_ok_clicked()
{
    QMessageBox msgbox;
    string user = ui->r_user->text().toStdString(), pass = ui->r_pass->text().toStdString(), name = ui->r_name->text().toStdString(),
            family = ui->r_family->text().toStdString(), phone = ui->r_phone->text().toStdString();
    bool flag = true;
    int size[5], day = ui->r_day->currentIndex(), mount = ui->r_mount->currentIndex(), year = ui->r_yaer->currentIndex();
    size[0] = user.length();
    size[1] = pass.length();
    size[2] = name.length();
    size[3] = family.length();
    size[4] = phone.length();

    for(int i = 0; i < 5; i++)
    {
        if(size[i] == 0)
        {
            flag = false;
            msgbox.setText("Enter form");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
            i += 5; // break
        }
    }
    if(flag)
    {
        if(day == 0)
        {
            flag = false;
            msgbox.setText("Enter day");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
        else if(mount == 0)
        {
            flag = false;
            msgbox.setText("Enter mount");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
        else if(year == 0)
        {
            flag = false;
            msgbox.setText("Enter year");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
        else if(size[4] != 11)
        {
            flag = false;
            msgbox.setText("Enter an 11-digit phone number");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
        else if(phone[0] != '0' || phone[1] != '9')
        {
            flag = false;
            msgbox.setText("Enter the correct phone number");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
        else
            for(int i = 0; flag && i < size[4]; i++)
                if(phone[i] < 48 || phone[i] > 57)
                {
                    flag = false;
                    msgbox.setText("Enter the correct phone number");
                    msgbox.setWindowTitle("Error!");
                    msgbox.exec();
                }
    }
    if(flag)
    {
        unsigned int Check = CheckRegister(Myplayer, user);
        if(Check != 0)
        {
            msgbox.setText("There is");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
        else
        {
            Player p;
            p.Username = user;
            p.Password = pass;
            p.Score = 0;
            p.Info.Birthday.Day = to_string(day);
            p.Info.Birthday.Mount= to_string(mount);
            p.Info.Birthday.Year = to_string(year + 1999);
            p.Info.Lastname = family;
            p.Info.Phonenumber = phone;
            p.Info.Name = name;

            UpdateFile(p, Myplayer);
            this->close();
        }
    }
}


void FormRegister::on_r_back_clicked()
{
    this->close();
}

