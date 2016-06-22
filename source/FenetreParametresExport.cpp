#include "FenetreParametresExport.h"
#include "ui_FenetreParametresExport.h"

FenetreParametresExport::FenetreParametresExport(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreParametresExport)
{
    this->ui->setupUi(this);
}

FenetreParametresExport::~FenetreParametresExport()
{
    delete this->ui;
}
