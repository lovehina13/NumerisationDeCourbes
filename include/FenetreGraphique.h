//==============================================================================
// Name        : FenetreGraphique.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.5 (07/06/2017)
// Description : Header file of the FenetreGraphique class
//==============================================================================

#ifndef FENETREGRAPHIQUE_H_
#define FENETREGRAPHIQUE_H_

#include <QDialog>
#include <QWidget>

namespace Ui
{
class FenetreGraphique;
}

class FenetreGraphique : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreGraphique(QWidget* parent = 0);
    ~FenetreGraphique();

    // Getters

    // Setters

    // Méthodes génériques

    // Méthodes spécifiques
    void actualiserElementsGraphiques();

protected:
    // Méthodes spécifiques
    void initialiserElementsGraphiques();

private:
    // Attributs de classe
    Ui::FenetreGraphique* ui;
};

#endif /* FENETREGRAPHIQUE_H_ */
