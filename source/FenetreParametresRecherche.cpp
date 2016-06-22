#include "FenetreParametresRecherche.h"
#include "ui_FenetreParametresRecherche.h"

FenetreParametresRecherche::FenetreParametresRecherche(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreParametresRecherche)
{
    this->ui->setupUi(this);
}

FenetreParametresRecherche::~FenetreParametresRecherche()
{
    delete this->ui;
}
