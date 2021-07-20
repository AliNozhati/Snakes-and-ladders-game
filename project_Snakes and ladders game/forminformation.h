#ifndef FORMINFORMATION_H
#define FORMINFORMATION_H

#include <QWidget>

namespace Ui {
class FormInformation;
}

class FormInformation : public QWidget
{
    Q_OBJECT

public:
    explicit FormInformation(QWidget *parent = nullptr);
    ~FormInformation();

private slots:
    void on_ChangeInfo_clicked();

    void on_back_clicked();

    void on_Score_clicked();

    void on_InfoGame_clicked();

private:
    Ui::FormInformation *ui;
};

#endif // FORMINFORMATION_H
