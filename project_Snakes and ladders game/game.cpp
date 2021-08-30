#include "game.h"
#include "ui_game.h"
#include <qmessagebox.h>
//#include <windows.h>
#include <time.h>
#include <LoginAndRegister.h>
#include <mainwindow.h>

int house[4] = {0,0,0,0};
bool flag2[4] = {1,1,1,1};

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
//ui->pushButton->setStyleSheet("background-color: black ;color:white;font-size:25px;");
    srand(time(0));
    ui->name1->setText(QString::fromStdString(Myplayer[IndexPlayers[0]].Info.Name));
    ui->name1->setStyleSheet("background-color: silver; color:blue");
    if(CountPlayers == 1)
        ui->name2->setText("Computer");
    else
        ui->name2->setText(QString::fromStdString(Myplayer[IndexPlayers[1]].Info.Name));
    ui->name2->setStyleSheet("background-color: silver; color:red");
    if(CountPlayers >= 3)
    {
        ui->name3->setText(QString::fromStdString(Myplayer[IndexPlayers[2]].Info.Name));
        ui->name3->setStyleSheet("background-color: silver; color:green");
        if(CountPlayers == 4){
            ui->name4->setText(QString::fromStdString(Myplayer[IndexPlayers[3]].Info.Name));
            ui->name4->setStyleSheet("background-color: silver; color:yellow");
        }
    }

    if(CountPlayers <= 2)
    {
        ui->label_3->hide(), ui->dice3->hide(), ui->green_2->hide(), ui->name3->hide();
        ui->label_4->hide(), ui->dice4->hide(), ui->yellow_2->hide(), ui->name4->hide();
    }
    else if(CountPlayers == 3)
    {
        ui->label_4->hide(), ui->dice4->hide(), ui->yellow_2->hide(), ui->name4->hide();
    }
    ui->dice2->setEnabled(false), ui->red->hide();
    ui->dice3->setEnabled(false), ui->blue->hide();
    ui->dice4->setEnabled(false), ui->green->hide(), ui->yellow->hide();
}

Game::~Game()
{
    delete ui;
}


void Game::on_dice1_clicked()
{
    int r;
    static bool flag = false;
    QMessageBox msgbox;
    string st;
    const QPixmap dice_one("C:/proje_maropele/image/1.jpg"), dice_two("C:/proje_maropele/image/2.jpg"),
          dice_three("C:/proje_maropele/image/3.jpg"), dice_four("C:/proje_maropele/image/4.jpg"),
          dice_five("C:/proje_maropele/image/5.jpg"), dice_six("C:/proje_maropele/image/6.jpg");

        r = rand()%6 +1;
        switch(r)
        {
            case 1: ui->RandDice->setPixmap(dice_one); break;
            case 2: ui->RandDice->setPixmap(dice_two); break;
            case 3: ui->RandDice->setPixmap(dice_three); break;
            case 4: ui->RandDice->setPixmap(dice_four); break;
            case 5: ui->RandDice->setPixmap(dice_five); break;
            case 6: ui->RandDice->setPixmap(dice_six); break;
        }

        if(r == 6)
        {
            if(house[0] == 0)
            {
                st = Myplayer[IndexPlayers[0]].Info.Name + " your dice 6, you can start";
                msgbox.setText(QString::fromStdString(st));
                msgbox.setWindowTitle("start");
                msgbox.exec();
            }
            flag = true;
            if(house[0] <= 0)
            {
                house[0]=-5;
            }
        }
        if(house[0]!=0)
        {

            house[0]+=r;
            switch(house[0])
            {
                case 2: house[0] = 38; break;
                case 4: house[0] = 14; break;
                case 9: house[0] = 31; break;
                case 33: house[0] = 85; break;
                case 51: house[0] = 11; break;
                case 52: house[0] = 88; break;
                case 56: house[0] = 15; break;
                case 62: house[0] = 57; break;
                case 80: house[0] = 99; break;
                case 92: house[0] = 53; break;
                case 98: house[0] = 8; break;
                default : break;
            }
        }

        if(house[0] > 100)
        {
            house[0] -= r;
            if(flag2[0])
            {
                flag2[0]=false;
                st = "You need  " + to_string(100-house[0]);
                msgbox.setText(QString::fromStdString(st));
                msgbox.setWindowTitle("error");
                msgbox.exec();
            }
        }

        if(house[0]!=0)
        {
            int j = 660,i = 20;
            ui->blue->show();

            j -= ((house[0]-1)/10 *71);

            if(((house[0]-1)/10)%2 == 0)
            {
                i=20;
                i+=((house[0]-1)%10)*70;
            }
            else
            {
               i=650;
               i-=((house[0]-1)%10)*70;
            }

            ui->blue->setGeometry(i, j, 71, 71);

                if (house[0] == 100)
                {
                    string win = Myplayer[IndexPlayers[0]].Info.Name + ", you win";
                    msgbox.setText(QString::fromStdString(win));
                    msgbox.setWindowTitle("end");
                    msgbox.exec();
                    Myplayer[IndexPlayers[0]].Score += 3;
                    if(CountPlayers >= 2)
                    {
                        Myplayer[IndexPlayers[1]].Score--;
                        if(CountPlayers >= 3)
                        {
                            Myplayer[IndexPlayers[2]].Score--;
                            if(CountPlayers == 4)
                                Myplayer[IndexPlayers[3]].Score--;
                        }
                    }
                    ChangeFile(Myplayer);
                    ui->dice1->setEnabled(false);
                    ui->dice2->setEnabled(false);
                    ui->dice3->setEnabled(false);
                    ui->dice4->setEnabled(false);
                    return;
                }
                else if(house[0] == house[1])
                {
                    house[1] = 0;
                    ui->red->hide();
                    if(CountPlayers != 1)
                    {
                        st = Myplayer[IndexPlayers[1]].Info.Name + ", You went to house 0";
                        msgbox.setText(QString::fromStdString(st));
                        msgbox.setWindowTitle(":/");
                        msgbox.exec();
                    }
                }
                else if(house[0] == house[2])
                {
                    house[2] = 0;
                    ui->green->hide();
                    st = Myplayer[IndexPlayers[2]].Info.Name + ", You went to house 0";
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle(":/");
                    msgbox.exec();
                }
                else if(house[0] == house[3])
                {
                    house[3] = 0;
                    ui->yellow->hide();
                    st = Myplayer[IndexPlayers[3]].Info.Name + ", You went to house 0";
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle(":/");
                    msgbox.exec();
                }
             if(flag)
             {
                 flag = false;
                 return;
             }
        }
        ui->dice1->setEnabled(false);
            if(CountPlayers == 1)
            {
//                Sleep(1000);
                Game::on_dice2_clicked();
            }
            else
            {
                ui->dice2->setEnabled(true);
            }
}


void Game::on_dice2_clicked()
{
        int r;
        static bool flag = false;
        QMessageBox msgbox;
        const QPixmap dice_one("../image/1.jpg"), dice_two("../image/2.jpg"),
              dice_three("../image/3.jpg"), dice_four("../image/4.jpg"),
              dice_five("../image/5.jpg"), dice_six("../image/6.jpg");
        string st;

            r = rand()%6 +1;
            if(CountPlayers != 1) // bazikon tasesho bebine.
                switch(r)
                {
                    case 1: ui->RandDice->setPixmap(dice_one); break;
                    case 2: ui->RandDice->setPixmap(dice_two); break;
                    case 3: ui->RandDice->setPixmap(dice_three); break;
                    case 4: ui->RandDice->setPixmap(dice_four); break;
                    case 5: ui->RandDice->setPixmap(dice_five); break;
                    case 6: ui->RandDice->setPixmap(dice_six); break;
                }
            if(r == 6)
            {
                if(house[1] == 0 && CountPlayers != 1)
                {
                    st = Myplayer[IndexPlayers[1]].Info.Name + " your dice 6, you can start";
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle("start");
                    msgbox.exec();
                }
                flag = true;
                if(house[1] <= 0)
                {
                    house[1] = -5;
                }

            }
            if(house[1] != 0)
            {
                house[1] +=r ;
                switch(house[1])
                {
                    case 2: house[1] = 38; break;
                    case 4: house[1] = 14; break;
                    case 9: house[1] = 31; break;
                    case 33: house[1] = 85; break;
                    case 51: house[1] = 11; break;
                    case 52: house[1] = 88; break;
                    case 56: house[1] = 15; break;
                    case 62: house[1] = 57; break;
                    case 80: house[1] = 99; break;
                    case 92: house[1] = 53; break;
                    case 98: house[1] = 8; break;
                    default : break;
                }
            }

            if(house[1] > 100)
            {
                house[1] -= r;
                if(CountPlayers != 1)
                {
                    if(flag2[1])
                    {
                        flag2[1] = false;
                        st = "You need " + to_string(100-house[1]);
                        msgbox.setText(QString::fromStdString(st));
                        msgbox.setWindowTitle("error");
                        msgbox.exec();
                    }
                }
            }

            if(house[1]!=0)
            {
                int j = 660,i=20;
                ui->red->show();

                j -= ((house[1]-1)/10 *71);

                if(((house[1]-1)/10)%2 == 0)
                {
                    i=20;
                    i+=((house[1]-1)%10)*70;
                }
                else
                {
                   i=650;
                   i-=((house[1]-1)%10)*70;
                }

                ui->red->setGeometry(i,j,71,71);

                if (house[1] == 100)
                {
                    string win;
                    if(CountPlayers == 1)
                    {
                        win = Myplayer[IndexPlayers[0]].Info.Name + ", you lose";
                        msgbox.setText(QString::fromStdString(win));
                        Myplayer[IndexPlayers[0]].Score--;
                        ChangeFile(Myplayer);
                    }
                    else
                    {
                        win = Myplayer[IndexPlayers[1]].Info.Name + ", you win";
                        msgbox.setText(QString::fromStdString(win));

                        Myplayer[IndexPlayers[1]].Score += 3;
                        Myplayer[IndexPlayers[0]].Score--;
                        if(CountPlayers >= 3)
                        {
                            Myplayer[IndexPlayers[2]].Score--;
                            if(CountPlayers == 4)
                            {
                                Myplayer[IndexPlayers[3]].Score--;
                            }
                        }
                        ChangeFile(Myplayer);
                    }
                    msgbox.setWindowTitle("end");
                    msgbox.exec();
                    ui->dice1->setEnabled(false);
                    ui->dice2->setEnabled(false);
                    ui->dice3->setEnabled(false);
                    ui->dice4->setEnabled(false);
                    return;
                }
                else if(house[1] == house[0])
                {
                    house[0] = 0;
                    ui->blue->hide();
                    st = Myplayer[IndexPlayers[0]].Info.Name + ", You went to house 0";
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle(":/");
                    msgbox.exec();
                }
                else if(house[1] == house[2])
                {
                    house[2] = 0;
                    ui->green->hide();
                    st = Myplayer[IndexPlayers[2]].Info.Name + ", You went to house 0";
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle(":/");
                    msgbox.exec();
                }
                else if(house[1] == house[3])
                {
                    house[3] = 0;
                    ui->yellow->hide();
                    st = Myplayer[IndexPlayers[3]].Info.Name + ", You went to house 0";
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle(":/");
                    msgbox.exec();
                }
                if(flag)
                {
                    flag = false;
                    if(CountPlayers == 1)
                       Game::on_dice2_clicked();
                    return;
                }
            }
            ui->dice2->setEnabled(false);
            if(CountPlayers > 2)
            {
                ui->dice3->setEnabled(true);
            }
            else
            {
                ui->dice1->setEnabled(true);
            }
}


void Game::on_dice3_clicked()
{
        int r;
        static bool flag = false;
        QMessageBox msgbox;
        string st;
        const QPixmap dice_one("C:/proje_maropele/image/1.jpg"), dice_two("C:/proje_maropele/image/2.jpg"),
              dice_three("C:/proje_maropele/image/3.jpg"), dice_four("C:/proje_maropele/image/4.jpg"),
              dice_five("C:/proje_maropele/image/5.jpg"), dice_six("C:/proje_maropele/image/6.jpg");

            r = rand()%6 +1;
            switch(r)
            {
                case 1: ui->RandDice->setPixmap(dice_one); break;
                case 2: ui->RandDice->setPixmap(dice_two); break;
                case 3: ui->RandDice->setPixmap(dice_three); break;
                case 4: ui->RandDice->setPixmap(dice_four); break;
                case 5: ui->RandDice->setPixmap(dice_five); break;
                case 6: ui->RandDice->setPixmap(dice_six); break;
            }
            if(r == 6)
            {
                if(house[2] == 0)
                {
                    st = Myplayer[IndexPlayers[2]].Info.Name + " your dice 6, you can start";
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle("start");
                    msgbox.exec();
                }
                flag = true;
                if(house[2] <= 0)
                {
                    house[2]=-5;
                }
            }
            if(house[2]!=0)
            {

                house[2]+=r;
                switch(house[2])
                {
                    case 2: house[2] = 38; break;
                    case 4: house[2] = 14; break;
                    case 9: house[2] = 31; break;
                    case 33: house[2] = 85; break;
                    case 51: house[2] = 11; break;
                    case 52: house[2] = 88; break;
                    case 56: house[2] = 15; break;
                    case 62: house[2] = 57; break;
                    case 80: house[2] = 99; break;
                    case 92: house[2] = 53; break;
                    case 98: house[2] = 8; break;
                    default : break;
                }
            }

            if(house[2] > 100)
            {
                house[2] -= r;
                if(flag2[2])
                {
                    flag2[2] = false;
                    st = "You need " + to_string(100-house[2]);
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle("error");
                    msgbox.exec();
                }
            }

            if(house[2]!=0)
            {
                int j = 660,i=20;
                    ui->green->show();

                j -= ((house[2]-1)/10 *71);

                if(((house[2]-1)/10)%2 == 0)
                {
                    i=20;
                    i+=((house[2]-1)%10)*70;
                }
                else
                {
                   i=650;
                   i-=((house[2]-1)%10)*70;
                }
                    ui->green->setGeometry(i,j,71,71);

                    if (house[2] == 100)
                    {
                        string win = Myplayer[IndexPlayers[2]].Info.Name + ", you win";
                        msgbox.setText(QString::fromStdString(win));
                        msgbox.setWindowTitle("end");
                        msgbox.exec();
                        Myplayer[IndexPlayers[2]].Score += 3;
                        Myplayer[IndexPlayers[0]].Score--;
                        Myplayer[IndexPlayers[1]].Score--;
                        if(CountPlayers == 4)
                        {
                            Myplayer[IndexPlayers[3]].Score--;
                        }
                        ChangeFile(Myplayer);
                        ui->dice1->setEnabled(false);
                        ui->dice2->setEnabled(false);
                        ui->dice3->setEnabled(false);
                        ui->dice4->setEnabled(false);
                        return;
                    }
                    else if(house[2] == house[0])
                    {
                        house[0] = 0;
                        ui->blue->hide();
                        string st = Myplayer[IndexPlayers[0]].Info.Name + ", You went to house 0";
                        msgbox.setText(QString::fromStdString(st));
                        msgbox.setWindowTitle(":/");
                        msgbox.exec();
                    }
                    else if(house[2] == house[1])
                    {
                        house[1] = 0;
                        ui->red->hide();
                        st = Myplayer[IndexPlayers[1]].Info.Name + ", You went to house 0";
                        msgbox.setText(QString::fromStdString(st));
                        msgbox.setWindowTitle(":/");
                        msgbox.exec();
                    }
                    else if(house[2] == house[3])
                    {
                        house[3] = 0;
                        ui->yellow->hide();
                        st = Myplayer[IndexPlayers[3]].Info.Name + ", You went to house 0";
                        msgbox.setText(QString::fromStdString(st));
                        msgbox.setWindowTitle(":/");
                        msgbox.exec();
                    }
                 if(flag)
                 {
                     flag = false;
                     return;
                 }
            }
            ui->dice3->setEnabled(false);
                if(CountPlayers > 3)
                {
                    ui->dice4->setEnabled(true);
                }
                else
                {
                    ui->dice1->setEnabled(true);
                }
}


void Game::on_dice4_clicked()
{
    int r;
    static bool flag = false;
    QMessageBox msgbox;
    string st;
    const QPixmap dice_one("C:/proje_maropele/image/1.jpg"), dice_two("C:/proje_maropele/image/2.jpg"),
          dice_three("C:/proje_maropele/image/3.jpg"), dice_four("C:/proje_maropele/image/4.jpg"),
          dice_five("C:/proje_maropele/image/5.jpg"), dice_six("C:/proje_maropele/image/6.jpg");

        r = rand()%6 +1;
        switch(r)
        {
            case 1: ui->RandDice->setPixmap(dice_one); break;
            case 2: ui->RandDice->setPixmap(dice_two); break;
            case 3: ui->RandDice->setPixmap(dice_three); break;
            case 4: ui->RandDice->setPixmap(dice_four); break;
            case 5: ui->RandDice->setPixmap(dice_five); break;
            case 6: ui->RandDice->setPixmap(dice_six); break;
        }
        if(r == 6)
        {
            if(house[3] == 0)
            {
                st = Myplayer[IndexPlayers[3]].Info.Name + " your dice 6, you can start";
                msgbox.setText(QString::fromStdString(st));
                msgbox.setWindowTitle("start");
                msgbox.exec();
            }
            flag = true;
            if(house[3] <= 0)
            {
                house[3]=-5;
            }
        }
        if(house[3]!=0)
        {

            house[3]+=r;
            switch(house[3])
            {
                case 2: house[3] = 38; break;
                case 4: house[3] = 14; break;
                case 9: house[3] = 31; break;
                case 33: house[3] = 85; break;
                case 51: house[3] = 11; break;
                case 52: house[3] = 88; break;
                case 56: house[3] = 15; break;
                case 62: house[3] = 57; break;
                case 80: house[3] = 99; break;
                case 92: house[3] = 53; break;
                case 98: house[3] = 8; break;
                default : break;
            }
        }

        if(house[3] > 100)
        {
            house[3] -= r;
            if(flag2[3])
            {
                flag2[3] = false;
                st = "You need " + to_string(100-house[3]);
                msgbox.setText(QString::fromStdString(st));
                msgbox.setWindowTitle("error");
                msgbox.exec();
            }
        }
        if(house[3]!=0)
        {
            int j = 660,i=20;
            ui->yellow->show();

            j -= ((house[3]-1)/10 *71);

            if(((house[3]-1)/10)%2 == 0)
            {
                i=20;
                i+=((house[3]-1)%10)*70;
            }
            else
            {
               i=650;
               i-=((house[3]-1)%10)*70;
            }

                ui->yellow->setGeometry(i,j,71,71);

                if (house[3] == 100)
                {
                    string win = Myplayer[IndexPlayers[3]].Info.Name + ", you win";
                    msgbox.setText(QString::fromStdString(win));
                    msgbox.setWindowTitle("tabrik");
                    msgbox.exec();
                    Myplayer[IndexPlayers[3]].Score += 3;
                    Myplayer[IndexPlayers[0]].Score--;
                    Myplayer[IndexPlayers[1]].Score--;
                    Myplayer[IndexPlayers[2]].Score--;

                    ChangeFile(Myplayer);
                    ui->dice1->setEnabled(false);
                    ui->dice2->setEnabled(false);
                    ui->dice3->setEnabled(false);
                    ui->dice4->setEnabled(false);
                    return;
                }
                else if(house[3] == house[0])
                {
                    house[0] = 0;
                    ui->blue->hide();
                    st = Myplayer[IndexPlayers[0]].Info.Name + ", You went to house 0";
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle(":/");
                    msgbox.exec();
                }
                else if(house[3] == house[1])
                {
                    house[2] = 0;
                    ui->red->hide();
                    st = Myplayer[IndexPlayers[1]].Info.Name + ", You went to house 0";
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle(":/");
                    msgbox.exec();
                }
                else if(house[3] == house[2])
                {
                    house[2] = 0;
                    ui->green->hide();
                    st = Myplayer[IndexPlayers[2]].Info.Name + ", You went to house 0";
                    msgbox.setText(QString::fromStdString(st));
                    msgbox.setWindowTitle(":/");
                    msgbox.exec();
                }
             if(flag)
             {
                 flag = false;
                 return;
             }
        }
        ui->dice4->setEnabled(false);
        ui->dice1->setEnabled(true);

}


void Game::on_again_clicked()
{
    Game *newform = new Game();
    for(int i = 0; i < 4; i++)
        house[i] = 0;
    this->close();
    newform->show();
}


void Game::on_menu_clicked()
{
    this->close();
    MainWindow *newform = new MainWindow();
    for(int i = 0; i < 4; i++)
    {
        house[i] = 0;
        IndexPlayers[i] = 0;
        flag2[i] = 1;
    }
    CountPlayers = 0, Count = 0;
    newform->show();
}


void Game::on_end_clicked()
{
    QMessageBox msgbox;
    msgbox.setText("good by");
    msgbox.setWindowTitle("exit");
    msgbox.exec();
    this->close();
}

