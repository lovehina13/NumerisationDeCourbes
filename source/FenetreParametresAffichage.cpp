#include "FenetreParametresAffichage.h"
#include "ui_FenetreParametresAffichage.h"

FenetreParametresAffichage::FenetreParametresAffichage(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreParametresAffichage)
{
    this->ui->setupUi(this);
}

FenetreParametresAffichage::~FenetreParametresAffichage()
{
    delete this->ui;
}
