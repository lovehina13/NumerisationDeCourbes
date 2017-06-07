//==============================================================================
// Name        : FenetreDocumentation.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.5 (07/06/2017)
// Description : Header file of the FenetreDocumentation class
//==============================================================================

#ifndef FENETREDOCUMENTATION_H_
#define FENETREDOCUMENTATION_H_

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
    explicit FenetreDocumentation(QWidget* parent = 0);
    ~FenetreDocumentation();

    // Getters

    // Setters

    // Méthodes génériques

    // Méthodes spécifiques

private:
    // Attributs de classe
    Ui::FenetreDocumentation* ui;
};

#endif /* FENETREDOCUMENTATION_H_ */
