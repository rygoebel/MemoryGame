#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "chooseleveldialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QT_TRANSLATE_NOOP(QMainWindow, "Start Menu"));

    //set Background for menu
    QPixmap bkgnd(":/images/menuBackground.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    game = new Game();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    delete game;
    QApplication::quit();
}

void MainWindow::on_changeLevelButton_clicked()
{
    ChooseLevelDialog * dialog = new ChooseLevelDialog(game->getLevel(), this);
    if (dialog->exec() == QDialog::Accepted) {
        game->setLevel((GameLevel)dialog->buttonsGroup->checkedId());
    }
    delete dialog;
}

void MainWindow::on_newGameButton_clicked()
{
    hide();
    game->createNewGame();
}
