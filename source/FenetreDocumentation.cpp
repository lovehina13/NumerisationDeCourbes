//==============================================================================
// Name        : FenetreDocumentation.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.1.3 (28/05/2018)
// Description : Source file of the FenetreDocumentation class
//==============================================================================

#include "FenetreDocumentation.h"
#include "ui_FenetreDocumentation.h"

FenetreDocumentation::FenetreDocumentation(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreDocumentation)
{
    this->ui->setupUi(this);
}

FenetreDocumentation::~FenetreDocumentation()
{
    delete this->ui;
}
