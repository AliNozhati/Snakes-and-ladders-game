#include "formscore.h"
#include "ui_formscore.h"
#include <string>
#include <qmessagebox.h>
#include <LoginAndRegister.h>
using namespace std;

FormScore::FormScore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormScore)
{
    ui->setupUi(this);
}

FormScore::~FormScore()
{
    delete ui;
}

void FormScore::on_search_name_clicked()
{
    QMessageBox msgbox;
    string name = ui->name->text().toStdString(), lastname = ui->lastname->text().toStdString();
    int size_name = name.size(), size_last = lastname.size();

    if(size_name == 0 || size_last == 0)
    {
        msgbox.setText("Enter name and family");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        Readfile(Myplayer);
        search_name(Myplayer, showscore, name, lastname);
        int size = showscore.size(), size_t = ui->tartib->currentIndex();
        QStringList list = {" Name ", " Lastname ", " Score "};
        ui->ShowScore->clear();
        ui->ShowScore->setRowCount(size);
        ui->ShowScore->setHorizontalHeaderLabels(list);
        ui->score->clear();
        ui->user->clear();

        if(size_t == 1)
        {
            sort (showscore, true);
        }
        else if(size_t == 2)
        {
            sort (showscore, false);
        }
        for(int i = 0; i < size; i++)
        {
            ui->ShowScore->setItem (i, 0, new QTableWidgetItem (QString::fromStdString (showscore[i].Info.Name)));
            ui->ShowScore->setItem (i, 1, new QTableWidgetItem (QString::fromStdString (showscore[i].Info.Lastname)));
            ui->ShowScore->setItem (i, 2, new QTableWidgetItem (QString::number(showscore[i].Score)));
        }

    }
}


void FormScore::on_search_username_clicked()
{
    QMessageBox msgbox;
    string user = ui->user->text().toStdString();
    int size = user.size();

    if(size == 0)
    {
        msgbox.setText("Enter Username");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        Readfile(Myplayer);
        search_user(Myplayer, showscore, user);

        int size = showscore.size(), size_t = ui->tartib->currentIndex();
        QStringList list = {" Name ", " Lastname ", " Score "};
        ui->ShowScore->clear();
        ui->ShowScore->setRowCount(size);
        ui->ShowScore->setHorizontalHeaderLabels(list);
        ui->name->clear();
        ui->lastname->clear();
        ui->score->clear();

        if(size_t == 1)
        {
            sort (showscore, true);
        }
        else if(size_t == 2)
        {
            sort (showscore, false);
        }
        for(int i = 0; i < size; i++)
        {
            ui->ShowScore->setItem (i, 0, new QTableWidgetItem (QString::fromStdString (showscore[i].Info.Name)));
            ui->ShowScore->setItem (i, 1, new QTableWidgetItem (QString::fromStdString (showscore[i].Info.Lastname)));
            ui->ShowScore->setItem (i, 2, new QTableWidgetItem (QString::number(showscore[i].Score)));
        }
    }
}


void FormScore::on_search_score_clicked()
{
    QMessageBox msgbox;
    string score = ui->score->text().toStdString();
    int size = score.size();

    if(size == 0)
    {
        msgbox.setText("Enter Score");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        Readfile(Myplayer);
        search_score(Myplayer, showscore, score);

        int size = showscore.size(), size_t = ui->tartib->currentIndex();
        ui->ShowScore->clear();
        ui->ShowScore->setRowCount(size);
        QStringList list = {" Name ", " Lastname ", " Score "};
        ui->ShowScore->setHorizontalHeaderLabels(list);
        ui->name->clear();
        ui->lastname->clear();
        ui->user->clear();

        if(size_t == 1)
        {
            sort (showscore, true);
        }
        else if(size_t == 2)
        {
            sort (showscore, false);
        }
        for(int i = 0; i < size; i++)
        {
            ui->ShowScore->setItem (i, 0, new QTableWidgetItem (QString::fromStdString (showscore[i].Info.Name)));
            ui->ShowScore->setItem (i, 1, new QTableWidgetItem (QString::fromStdString (showscore[i].Info.Lastname)));
            ui->ShowScore->setItem (i, 2, new QTableWidgetItem (QString::number(showscore[i].Score)));
        }
    }
}


void FormScore::on_All_clicked()
{
    Readfile(Myplayer);
    Myplayer.erase(Myplayer.end()-1);
    int size = Myplayer.size(), size_t = ui->tartib->currentIndex();
    ui->ShowScore->clear();
    ui->ShowScore->setRowCount(size);
    QStringList list = {" Name ", " Lastname ", " Score "};
    ui->ShowScore->setHorizontalHeaderLabels(list);
    ui->name->clear();
    ui->lastname->clear();
    ui->user->clear();
    ui->score->clear();

    if(size_t == 1)
    {
        sort (Myplayer, true);
    }
    else if(size_t == 2)
    {
        sort (Myplayer, false);
    }
    for(int i = 0; i < size; i++)
    {
        ui->ShowScore->setItem (i, 0, new QTableWidgetItem (QString::fromStdString (Myplayer[i].Info.Name)));
        ui->ShowScore->setItem (i, 1, new QTableWidgetItem (QString::fromStdString (Myplayer[i].Info.Lastname)));
        ui->ShowScore->setItem (i, 2, new QTableWidgetItem (QString::number((Myplayer[i].Score))));
    }
}

