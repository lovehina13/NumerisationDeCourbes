//==============================================================================
// Name        : FenetreDocumentation.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Source file of the FenetreDocumentation class
//==============================================================================

#include "FenetreDocumentation.h"
#include "ui_FenetreDocumentation.h"

FenetreDocumentation::FenetreDocumentation(QWidget* parent) :
        QDialog(parent), _ui(new Ui::FenetreDocumentation)
{
    _ui->setupUi(this);
}

FenetreDocumentation::~FenetreDocumentation()
{
    delete _ui;
}
