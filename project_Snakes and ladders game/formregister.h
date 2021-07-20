#ifndef FORMREGISTER_H
#define FORMREGISTER_H

#include <QWidget>

namespace Ui {
class FormRegister;
}

class FormRegister : public QWidget
{
    Q_OBJECT

public:
    explicit FormRegister(QWidget *parent = nullptr);
    ~FormRegister();

private slots:
    void on_r_ok_clicked();

    void on_r_back_clicked();

private:
    Ui::FormRegister *ui;
};

#endif // FORMREGISTER_H
