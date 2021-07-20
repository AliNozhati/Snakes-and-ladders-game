#ifndef CHANGEPHONE_H
#define CHANGEPHONE_H

#include <QWidget>

namespace Ui {
class ChangePhone;
}

class ChangePhone : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePhone(QWidget *parent = nullptr);
    ~ChangePhone();

private slots:
    void on_change_clicked();

private:
    Ui::ChangePhone *ui;
};

#endif // CHANGEPHONE_H
