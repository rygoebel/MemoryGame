#ifndef CHOOSELEVELDIALOG_H
#define CHOOSELEVELDIALOG_H

#include <QDialog>

#include "ui_chooseleveldialog.h"
#include "constants.h"

class ChooseLevelDialog : public QDialog, public Ui::LevelDialog{
    Q_OBJECT

public:
    QButtonGroup * buttonsGroup;

    ChooseLevelDialog(GameLevel gameLevel, QWidget * parent = 0);
private slots:
    void on_cancelButton_clicked();
    void on_okButton_clicked();
};

#endif // CHOOSELEVELDIALOG_H
