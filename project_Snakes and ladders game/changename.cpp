#include "changename.h"
#include "ui_changename.h"
#include <string>
#include <Structure.h>
#include <LoginAndRegister.h>
#include <qmessagebox.h>
using namespace std;

ChangeName::ChangeName(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeName)
{
    ui->setupUi(this);
}

ChangeName::~ChangeName()
{
    delete ui;
}

void ChangeName::on_change_clicked()
{
    QMessageBox msgbox;
    string name = ui->user->text().toStdString(), family = ui->Family->text().toStdString();
    int size_name = name.size(), size_family = family.size();

    if(size_name == 0 || size_family == 0)
    {
        msgbox.setText("Enter name and family");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        change_name(Myplayer, name, family);
        this->close();
    }
}

