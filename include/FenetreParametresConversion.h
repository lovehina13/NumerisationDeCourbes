//==============================================================================
// Name        : FenetreParametresConversion.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.1.3 (28/05/2018)
// Description : Header file of the FenetreParametresConversion class
//==============================================================================

#ifndef FENETREPARAMETRESCONVERSION_H
#define FENETREPARAMETRESCONVERSION_H

#include "ParametresConversion.h"
#include <QDialog>
#include <QWidget>

namespace Ui
{
class FenetreParametresConversion;
}

class FenetreParametresConversion : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreParametresConversion(QWidget* parent = NULL);
    ~FenetreParametresConversion();

    // Getters
    const ParametresConversion& getParametresConversion() const;

    // Setters
    void setParametresConversion(const ParametresConversion& parametresConversion);

    // Méthodes génériques

    // Méthodes spécifiques
    void actualiserElementsGraphiques();

protected:
    // Méthodes spécifiques
    void initialiserElementsGraphiques();

protected slots:
    // Connecteurs spécifiques
    void on_spinBoxSeuilNoirEtBlanc_valueChanged();
    void on_doubleSpinBoxSeuilNoirEtBlancFacteur_valueChanged();
    void on_spinBoxNombreNiveauxDeGris_valueChanged();
    void on_spinBoxNombreTeintesSaturees_valueChanged();
    void on_spinBoxSeuilSaturation_valueChanged();
    void on_doubleSpinBoxSeuilSaturationFacteur_valueChanged();

private:
    // Attributs de classe
    Ui::FenetreParametresConversion* ui;
    ParametresConversion parametresConversion;
};

#endif /* FENETREPARAMETRESCONVERSION_H */
