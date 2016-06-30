//==============================================================================
// Name        : FenetreParametresAffichage.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Header file of the FenetreParametresAffichage class
//==============================================================================

#ifndef FENETREPARAMETRESAFFICHAGE_H_
#define FENETREPARAMETRESAFFICHAGE_H_

#include "ParametresAffichage.h"
#include <QDialog>

namespace Ui
{
class FenetreParametresAffichage;
}

class FenetreParametresAffichage : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreParametresAffichage(QWidget* parent = 0);
    ~FenetreParametresAffichage();

    // Getters
    // TODO Getters
    const ParametresAffichage& getParametresAffichage() const;

    // Setters
    // TODO Setters
    void setParametresAffichage(const ParametresAffichage& parametresAffichage);

    // Méthodes génériques
    // TODO Méthodes génériques

    // Méthodes spécifiques
    // TODO Méthodes spécifiques
    void actualiserElementsGraphiques();

protected:
    // TODO Méthodes spécifiques
    void initialiserElementsGraphiques();

protected slots:
    // Connecteurs spécifiques
    // TODO Connecteurs spécifiques

private:
    // Attributs de classe
    Ui::FenetreParametresAffichage* ui;
    ParametresAffichage parametresAffichage;
};

#endif /* FENETREPARAMETRESAFFICHAGE_H_ */
