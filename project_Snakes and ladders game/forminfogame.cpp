#include "forminfogame.h"
#include "ui_forminfogame.h"

FormInfoGame::FormInfoGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormInfoGame)
{
    ui->setupUi(this);
}

FormInfoGame::~FormInfoGame()
{
    delete ui;
}
