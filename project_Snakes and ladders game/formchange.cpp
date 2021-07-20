#include "formchange.h"
#include "ui_formchange.h"
#include <qmessagebox.h>
#include <LoginAndRegister.h>
#include <changename.h>
#include <changepass.h>
#include <changebirthday.h>
#include <changephone.h>
#include <formchangeinformation.h>

FormChange::FormChange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormChange)
{
    ui->setupUi(this);
}

FormChange::~FormChange()
{
    delete ui;
}

void FormChange::on_change_clicked()
{
    QMessageBox msgbox;
    int Change = ui->select_change->currentIndex();

    if(Change == 0)
    {
        msgbox.setText("select");
        msgbox.setWindowTitle("Error!");
        msgbox.exec();
    }
    else
    {
        switch(Change)
        {
            case 1:
            {
                ChangeName *newform = new ChangeName();
                newform->show();
            }break;

            case 2:
            {
                ChangePass *newform = new ChangePass();
                newform->show();
            }break;

            case 3:
            {
                ChangeBirthday *newform = new ChangeBirthday();
                newform->show();
            }break;

            case 4:
            {
                ChangePhone *newform = new ChangePhone();
                newform->show();
            }
        }
    }
}


void FormChange::on_back_clicked()
{
    this->close();
    FormChangeInformation *newform = new FormChangeInformation();
    newform->show();
}

