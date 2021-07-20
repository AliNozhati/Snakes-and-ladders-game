#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_OnePlayer_clicked();

    void on_TwoPlayers_clicked();

    void on_ThreePlayers_clicked();

    void on_FourPlayers_clicked();

    void on_end_clicked();

    void on_Information_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
