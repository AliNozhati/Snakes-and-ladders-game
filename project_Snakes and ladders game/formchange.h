#ifndef FORMCHANGE_H
#define FORMCHANGE_H

#include <QWidget>

namespace Ui {
class FormChange;
}

class FormChange : public QWidget
{
    Q_OBJECT

public:
    explicit FormChange(QWidget *parent = nullptr);
    ~FormChange();

private slots:
    void on_change_clicked();

    void on_back_clicked();

private:
    Ui::FormChange *ui;
};

#endif // FORMCHANGE_H
