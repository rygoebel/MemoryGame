#include "chooseleveldialog.h"

ChooseLevelDialog::ChooseLevelDialog(GameLevel gameLevel, QWidget *parent) : QDialog(parent)
{
    setupUi(this);
//    setWindowModality(Qt::ApplicationModal);
    setWindowTitle(QT_TRANSLATE_NOOP(ChooseLevelDialog, "Level Choice"));
    buttonsGroup = new QButtonGroup(this);
    buttonsGroup->addButton(easyLevelRadioButton, GameLevel::Easy);
    buttonsGroup->addButton(mediumLevelRadioButton, GameLevel::Medium);
    buttonsGroup->addButton(hardLevelRadioButton, GameLevel::Hard);
    if (gameLevel == GameLevel::Easy) {
        easyLevelRadioButton->setChecked(true);
    }
    else if (gameLevel == GameLevel::Medium) {
        mediumLevelRadioButton->setChecked(true);
    }
    else if (gameLevel == GameLevel::Hard){
        hardLevelRadioButton->setChecked(true);
    }
}

void ChooseLevelDialog::on_cancelButton_clicked()
{
    QDialog::reject();
}

void ChooseLevelDialog::on_okButton_clicked()
{
    QDialog::accept();
}
