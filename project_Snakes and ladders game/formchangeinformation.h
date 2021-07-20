#ifndef FORMCHANGEINFORMATION_H
#define FORMCHANGEINFORMATION_H

#include <QWidget>

namespace Ui {
class FormChangeInformation;
}

class FormChangeInformation : public QWidget
{
    Q_OBJECT

public:
    explicit FormChangeInformation(QWidget *parent = nullptr);
    ~FormChangeInformation();

private slots:
    void on_Login_clicked();

    void on_Back_clicked();

    void on_Forget_clicked();

private:
    Ui::FormChangeInformation *ui;
};

#endif // FORMCHANGEINFORMATION_H
