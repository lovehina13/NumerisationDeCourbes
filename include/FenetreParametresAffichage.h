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
#include <QWidget>

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
    const ParametresAffichage& getParametresAffichage() const;

    // Setters
    void setParametresAffichage(const ParametresAffichage& parametresAffichage);

    // Méthodes génériques

    // Méthodes spécifiques
    void actualiserElementsGraphiques();

protected:
    // Méthodes spécifiques
    void initialiserElementsGraphiques();

protected slots:
    // Connecteurs spécifiques
    void on_comboBoxFormatNotationNombres_currentIndexChanged();
    void on_spinBoxNombreDecimalesOuChiffresSignificatifs_valueChanged();
    void on_pushButtonCouleurAxes_clicked();
    void on_spinBoxEpaisseurAxes_valueChanged();
    void on_comboBoxTypeAxes_currentIndexChanged();
    void on_pushButtonCouleurCourbes_clicked();
    void on_spinBoxEpaisseurCourbes_valueChanged();
    void on_comboBoxTypeCourbes_currentIndexChanged();
    void on_pushButtonCouleurPointsAxes_clicked();
    void on_spinBoxEpaisseurPointsAxes_valueChanged();
    void on_comboBoxTypePointsAxes_currentIndexChanged();
    void on_pushButtonCouleurPointsCourbes_clicked();
    void on_spinBoxEpaisseurPointsCourbes_valueChanged();
    void on_comboBoxTypePointsCourbes_currentIndexChanged();
    void on_pushButtonCouleurPointsManuels_clicked();
    void on_spinBoxEpaisseurPointsManuels_valueChanged();
    void on_comboBoxTypePointsManuels_currentIndexChanged();

private:
    // Attributs de classe
    Ui::FenetreParametresAffichage* ui;
    ParametresAffichage parametresAffichage;
};

#endif /* FENETREPARAMETRESAFFICHAGE_H_ */
