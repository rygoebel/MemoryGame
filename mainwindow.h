#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_exitButton_clicked();
    void on_changeLevelButton_clicked();
    void on_newGameButton_clicked();

private:
    Ui::MainWindow *ui;
    Game * game;
};

#endif // MAINWINDOW_H
