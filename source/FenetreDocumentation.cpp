//==============================================================================
// Name        : FenetreDocumentation.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (20/01/2017)
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
