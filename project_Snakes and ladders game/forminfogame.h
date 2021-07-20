#ifndef FORMINFOGAME_H
#define FORMINFOGAME_H

#include <QWidget>

namespace Ui {
class FormInfoGame;
}

class FormInfoGame : public QWidget
{
    Q_OBJECT

public:
    explicit FormInfoGame(QWidget *parent = nullptr);
    ~FormInfoGame();

private:
    Ui::FormInfoGame *ui;
};

#endif // FORMINFOGAME_H
