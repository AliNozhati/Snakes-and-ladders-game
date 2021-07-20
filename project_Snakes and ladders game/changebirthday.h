#ifndef CHANGEBIRTHDAY_H
#define CHANGEBIRTHDAY_H

#include <QWidget>

namespace Ui {
class ChangeBirthday;
}

class ChangeBirthday : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeBirthday(QWidget *parent = nullptr);
    ~ChangeBirthday();

private slots:
    void on_change_clicked();

private:
    Ui::ChangeBirthday *ui;
};

#endif // CHANGEBIRTHDAY_H
