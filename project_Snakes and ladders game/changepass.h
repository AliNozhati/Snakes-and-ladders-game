#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include <QWidget>

namespace Ui {
class ChangePass;
}

class ChangePass : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePass(QWidget *parent = nullptr);
    ~ChangePass();

private slots:
    void on_change_clicked();

private:
    Ui::ChangePass *ui;
};

#endif // CHANGEPASS_H
