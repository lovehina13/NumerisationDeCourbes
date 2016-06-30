//==============================================================================
// Name        : FenetreParametresExport.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Header file of the FenetreParametresExport class
//==============================================================================

#ifndef FENETREPARAMETRESEXPORT_H_
#define FENETREPARAMETRESEXPORT_H_

#include "ParametresExport.h"
#include <QDialog>

namespace Ui
{
class FenetreParametresExport;
}

class FenetreParametresExport : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreParametresExport(QWidget* parent = 0);
    ~FenetreParametresExport();

    // Getters
    // TODO Getters
    const ParametresExport& getParametresExport() const;

    // Setters
    // TODO Setters
    void setParametresExport(const ParametresExport& parametresExport);

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
    Ui::FenetreParametresExport* ui;
    ParametresExport parametresExport;
};

#endif /* FENETREPARAMETRESEXPORT_H_ */
