//==============================================================================
// Name        : FenetreParametresConversion.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Header file of the FenetreParametresConversion class
//==============================================================================

#ifndef FENETREPARAMETRESCONVERSION_H_
#define FENETREPARAMETRESCONVERSION_H_

#include "ParametresConversion.h"
#include <QDialog>

namespace Ui
{
class FenetreParametresConversion;
}

class FenetreParametresConversion : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreParametresConversion(QWidget* parent = 0);
    ~FenetreParametresConversion();

    // Getters
    // TODO Getters
    const ParametresConversion& getParametresConversion() const;

    // Setters
    // TODO Setters
    void setParametresConversion(const ParametresConversion& parametresConversion);

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
    Ui::FenetreParametresConversion* ui;
    ParametresConversion parametresConversion;
};

#endif /* FENETREPARAMETRESCONVERSION_H_ */
