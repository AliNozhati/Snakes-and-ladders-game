#include "formforget.h"
#include "ui_formforget.h"
#include <string>
#include <Structure.h>
#include <LoginAndRegister.h>
#include <qmessagebox.h>
#include <changepass.h>
using namespace std;

FormForget::FormForget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormForget)
{
    ui->setupUi(this);
}

FormForget::~FormForget()
{
    delete ui;
}

void FormForget::on_check_clicked()
{
    QMessageBox msgbox;
    string user = ui->user->text().toStdString(), name = ui->name->text().toStdString(),
           family = ui->last->text().toStdString(), phone = ui->phone->text().toStdString();
    int size_user = user.size(), size_name = name.size(), size_family = family.size(),
        size_phone = phone.size(), size_day = ui->day->currentIndex(), size_mount = ui->mount->currentIndex(),
        size_year = ui->year->currentIndex();

    if(size_user < 1)
    {
        msgbox.setText("Enter username");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else if(size_name < 1)
    {
        msgbox.setText("Enter name");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else if(size_family < 1)
    {
        msgbox.setText("Enter lastname");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else if(size_day == 0)
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
    else if(size_phone < 0)
    {
        msgbox.setText("Enter phone number");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else if(size_phone != 11)
    {
        msgbox.setText("Enter an 11-digit phone number");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        if(phone[0] != '0' || phone[1] != '9')
        {
            msgbox.setText("Enter the correct phone number");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
            return;
        }
        else
            for(int i = 0; i < 11; i++)
                if(phone[i] < 48 || phone[i] > 57)
                {
                    msgbox.setText("Enter the correct phone number");
                    msgbox.setWindowTitle("Error!");
                    msgbox.exec();
                    return;
                }
        Player p;
        p.Username = user, p.Info.Name = name, p.Info.Lastname = family, p.Info.Phonenumber = phone,
        p.Info.Birthday.Day = to_string(size_day), p.Info.Birthday.Mount = to_string(size_mount),
        p.Info.Birthday.Year = to_string(size_year+1999);
        unsigned int Check = check_forget(p, Myplayer);

        if(Check != 0)
        {
            this->close();
            IndexPlayers[4] = Check - 1;
            ChangePass *newform = new ChangePass();
            newform->show();
        }
        else
        {
            msgbox.setText("wrong");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
    }
}

