//==============================================================================
// Name        : FenetreDocumentation.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
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
    explicit FenetreDocumentation(QWidget* parent = nullptr);
    virtual ~FenetreDocumentation() override;

    // Getters

    // Setters

    // Méthodes génériques

    // Méthodes spécifiques

private:
    // Attributs de classe
    Ui::FenetreDocumentation* _ui { nullptr };
};

#endif /* FENETREDOCUMENTATION_H */
