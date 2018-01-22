//==============================================================================
// Name        : FenetreDocumentation.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.1.0 (22/01/2018)
// Description : Header file of the FenetreDocumentation class
//==============================================================================

#ifndef FENETREDOCUMENTATION_H
#define FENETREDOCUMENTATION_H

#include <QDialog>
#include <QWidget>

namespace Ui
{
class FenetreDocumentation;
}

class FenetreDocumentation : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreDocumentation(QWidget* parent = NULL);
    ~FenetreDocumentation();

    // Getters

    // Setters

    // Méthodes génériques

    // Méthodes spécifiques

private:
    // Attributs de classe
    Ui::FenetreDocumentation* ui;
};

#endif /* FENETREDOCUMENTATION_H */
