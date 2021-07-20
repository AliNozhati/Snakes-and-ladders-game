#ifndef GAME_H
#define GAME_H

#include <QWidget>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void on_dice1_clicked();

    void on_dice2_clicked();

    void on_dice3_clicked();

    void on_dice4_clicked();

    void on_again_clicked();

    void on_menu_clicked();

    void on_end_clicked();

private:
    Ui::Game *ui;
};

#endif // GAME_H
