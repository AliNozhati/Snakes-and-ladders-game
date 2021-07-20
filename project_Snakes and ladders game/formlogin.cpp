#include "formlogin.h"
#include "ui_formlogin.h"
#include <qmessagebox.h>
#include <Structure.h>
#include <LoginAndRegister.h>
#include <formregister.h>
#include <mainwindow.h>
#include <formforget.h>
#include <game.h>

FormLogin::FormLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLogin)
{
    ui->setupUi(this);
}

FormLogin::~FormLogin()
{
    delete ui;
}

void FormLogin::on_LoginPlayer_clicked()
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
        Check = CheckLogin(Myplayer, Username.toStdString(), Password.toStdString());

        if(Check == 0)
        {
            msgbox.setText("Username or password incorrect");
            msgbox.setWindowTitle("Error!");
            msgbox.exec();
        }
        else
        {
            for(int i = 0; i < Count; i++)
            {
                if(Check-1 == IndexPlayers[i])
                {
                    msgbox.setText("You have already entered the game");
                    msgbox.setWindowTitle("Error!");
                    msgbox.exec();
                    return;
                }
            }
            IndexPlayers[Count] = Check - 1;
            Count++;

            if(Count < CountPlayers)
            {
                this->close();
                FormLogin *newf = new FormLogin();
                string show = "player" + to_string(Count+1);
                newf->setWindowTitle(QString::fromStdString(show));
                newf->show();
            }
            else
            {
                this->close();
                Game *newform = new Game();
                newform->show();
                msgbox.setText("You must bring 6 to start the game");
                msgbox.setWindowTitle("Start");
                msgbox.exec();
            }
        }
    }
}


void FormLogin::on_RegisterPlayer_clicked()
{
    FormRegister *newform = new FormRegister();
    newform->show();
}


void FormLogin::on_Back_clicked()
{
    this->close();
    for(int i = 0; i < 4; i++)
        IndexPlayers[i] = 0;
    Count = 0;
    CountPlayers = 0;
    MainWindow *newform = new MainWindow();
    newform->show();
}

void FormLogin::on_ForgetPlayer_clicked()
{
    FormForget *newform = new FormForget();
    newform->show();
}

