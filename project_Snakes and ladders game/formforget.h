#ifndef FORMFORGET_H
#define FORMFORGET_H

#include <QWidget>

namespace Ui {
class FormForget;
}

class FormForget : public QWidget
{
    Q_OBJECT

public:
    explicit FormForget(QWidget *parent = nullptr);
    ~FormForget();

private slots:
    void on_check_clicked();

private:
    Ui::FormForget *ui;
};

#endif // FORMFORGET_H
