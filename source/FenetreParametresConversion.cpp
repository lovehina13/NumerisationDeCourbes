#include "FenetreParametresConversion.h"
#include "ui_FenetreParametresConversion.h"

FenetreParametresConversion::FenetreParametresConversion(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreParametresConversion)
{
    this->ui->setupUi(this);
}

FenetreParametresConversion::~FenetreParametresConversion()
{
    delete this->ui;
}
