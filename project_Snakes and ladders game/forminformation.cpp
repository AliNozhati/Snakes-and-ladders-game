#include "forminformation.h"
#include "ui_forminformation.h"
#include <formchangeinformation.h>
#include <mainwindow.h>
#include <formscore.h>
#include <forminfogame.h>

FormInformation::FormInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormInformation)
{
    ui->setupUi(this);
}

FormInformation::~FormInformation()
{
    delete ui;
}

void FormInformation::on_ChangeInfo_clicked()
{
    this->close();
    FormChangeInformation *newform = new FormChangeInformation();
    newform->show();
}


void FormInformation::on_back_clicked()
{
    this->close();
    MainWindow *newform = new MainWindow();
    newform->show();
}


void FormInformation::on_Score_clicked()
{
    FormScore *newform = new FormScore();
    newform->show();
}


void FormInformation::on_InfoGame_clicked()
{
    FormInfoGame *newform = new FormInfoGame();
    newform->show();
}

