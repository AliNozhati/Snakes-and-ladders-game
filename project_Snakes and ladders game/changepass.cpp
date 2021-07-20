#include "changepass.h"
#include "ui_changepass.h"
#include <string>
#include <LoginAndRegister.h>
#include <qmessagebox.h>
using namespace std;

ChangePass::ChangePass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePass)
{
    ui->setupUi(this);
}

ChangePass::~ChangePass()
{
    delete ui;
}

void ChangePass::on_change_clicked()
{
    QMessageBox msgbox;
    string pass = ui->pass->text().toStdString();
    int size = pass.size();

    if(size == 0)
    {
        msgbox.setText("Enter password");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        change_pass(Myplayer, pass);
        this->close();
    }
}

