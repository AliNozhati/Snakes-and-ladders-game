#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <formlogin.h>
#include <LoginAndRegister.h>
#include <qmessagebox.h>
#include <forminformation.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OnePlayer_clicked()
{
    this->close();
    FormLogin *newform = new FormLogin();
    CountPlayers = 1;
    for(int i = 0; i < 4; i++)
        IndexPlayers[i] = 0;
    Readfile(Myplayer);
    newform->setWindowTitle("Player1");
    newform->show();
}


void MainWindow::on_TwoPlayers_clicked()
{
    this->close();
    FormLogin *newform = new FormLogin();
    CountPlayers = 2;
    for(int i = 0; i < 4; i++)
        IndexPlayers[i] = 0;
    Readfile(Myplayer);
    newform->setWindowTitle("Player1");
    newform->show();
}


void MainWindow::on_ThreePlayers_clicked()
{
    this->close();
    FormLogin *newform = new FormLogin();
    CountPlayers = 3;
    for(int i = 0; i < 4; i++)
        IndexPlayers[i] = 0;
    Readfile(Myplayer);
    newform->setWindowTitle("Player1");
    newform->show();
}



void MainWindow::on_FourPlayers_clicked()
{
    this->close();
    FormLogin *newform = new FormLogin();
    CountPlayers = 4;
    for(int i = 0; i < 4; i++)
        IndexPlayers[i] = 0;
    Readfile(Myplayer);
    newform->setWindowTitle("Player1");
    newform->show();
}


void MainWindow::on_end_clicked()
{
    this->close();
    QMessageBox msgbox;
    msgbox.setText("good by");
    msgbox.setWindowTitle("end");
    msgbox.exec();
}


void MainWindow::on_Information_clicked()
{
    this->close();
    FormInformation *newform = new FormInformation();
    newform->show();
}

