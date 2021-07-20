#ifndef FORMSCORE_H
#define FORMSCORE_H

#include <QWidget>

namespace Ui {
class FormScore;
}

class FormScore : public QWidget
{
    Q_OBJECT

public:
    explicit FormScore(QWidget *parent = nullptr);
    ~FormScore();

private slots:
    void on_search_name_clicked();

    void on_search_username_clicked();

    void on_search_score_clicked();

    void on_All_clicked();

private:
    Ui::FormScore *ui;
};

#endif // FORMSCORE_H
