#ifndef FORMLOGIN_H
#define FORMLOGIN_H

#include <QWidget>

namespace Ui {
class FormLogin;
}

class FormLogin : public QWidget
{
    Q_OBJECT

public:
    explicit FormLogin(QWidget *parent = nullptr);
    ~FormLogin();

private slots:
    void on_LoginPlayer_clicked();

    void on_RegisterPlayer_clicked();

    void on_Back_clicked();

    void on_ForgetPlayer_clicked();

private:
    Ui::FormLogin *ui;
};

#endif // FORMLOGIN_H
