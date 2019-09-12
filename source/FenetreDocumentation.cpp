//==============================================================================
// Name        : FenetreDocumentation.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.1.4 (12/09/2019)
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
