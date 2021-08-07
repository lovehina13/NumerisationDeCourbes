//==============================================================================
// Name        : FenetreParametresConversion.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
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
    explicit FenetreParametresConversion(QWidget* parent = nullptr);
    virtual ~FenetreParametresConversion() override;

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
    void on_spinBoxSeuilNoirEtBlanc_valueChanged(int value);
    void on_doubleSpinBoxSeuilNoirEtBlancFacteur_valueChanged(double value);
    void on_spinBoxNombreNiveauxDeGris_valueChanged(int value);
    void on_spinBoxNombreTeintesSaturees_valueChanged(int value);
    void on_spinBoxSeuilSaturation_valueChanged(int value);
    void on_doubleSpinBoxSeuilSaturationFacteur_valueChanged(double value);

private:
    // Attributs de classe
    Ui::FenetreParametresConversion* _ui { nullptr };
    ParametresConversion _parametresConversion;
};

#endif /* FENETREPARAMETRESCONVERSION_H */
