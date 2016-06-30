//==============================================================================
// Name        : FenetreParametresRecherche.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/06/2016)
// Description : Header file of the FenetreParametresRecherche class
//==============================================================================

#ifndef FENETREPARAMETRESRECHERCHE_H_
#define FENETREPARAMETRESRECHERCHE_H_

#include "ParametresRecherche.h"
#include <QDialog>

namespace Ui
{
class FenetreParametresRecherche;
}

class FenetreParametresRecherche : public QDialog
{
    Q_OBJECT

public:
    // Constructeurs et destructeurs
    explicit FenetreParametresRecherche(QWidget* parent = 0);
    ~FenetreParametresRecherche();

    // Getters
    // TODO Getters
    const ParametresRecherche& getParametresRecherche() const;

    // Setters
    // TODO Setters
    void setParametresRecherche(const ParametresRecherche& parametresRecherche);

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
    Ui::FenetreParametresRecherche* ui;
    ParametresRecherche parametresRecherche;
};

#endif /* FENETREPARAMETRESRECHERCHE_H_ */
