//==============================================================================
// Name        : Etude.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Header file of the Etude class
//==============================================================================

#ifndef ETUDE_H_
#define ETUDE_H_

#include "Image.h"
#include "Parametres.h"
#include "Point.h"
#include "Repere.h"
#include <QList>
#include <QString>

class Etude
{
public:
    // Constructeurs et destructeurs
    Etude();
    Etude(const Image& image, const Repere& repere, const QList<Point>& listeDePoints,
            const Parametres& parametres);
    Etude(const Etude& etude);
    virtual ~Etude();

    // Getters
    const Image& getImage() const;
    const Repere& getRepere() const;
    const QList<Point>& getListeDePoints() const;
    const Parametres& getParametres() const;

    // Setters
    void setImage(const Image& image);
    void setRepere(const Repere& repere);
    void setListeDePoints(const QList<Point>& listeDePoints);
    void setParametres(const Parametres& parametres);

    // Méthodes génériques
    void clear();
    void initialize(const Image& image, const Repere& repere, const QList<Point>& listeDePoints,
            const Parametres& parametres);
    void copy(const Etude& etude);
    bool equals(const Etude& etude) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques
    // TODO Méthodes spécifiques
    void chargerEtude(const QString& cheminFichierEtude);
    void sauverEtude(const QString& cheminFichierEtude);
    void exporterListeDePoints(const QString& cheminFichierExport);
    void exporterImageConvertie(const QString& cheminFichierImage);
    void rechercherCourbe(const QPoint& pointPixelDepart, const QPoint& pointPixelArrivee);

protected:
    // Méthodes spécifiques
    // TODO Méthodes spécifiques
    void rechercherPointsProches(const QPoint& pointPixel);
    void filterListeDePoints(const QList<QPoint>& listeDePoints);

private:
    // Attributs de classe
    Image image;
    Repere repere;
    QList<Point> listeDePoints;
    Parametres parametres;
};

#endif /* ETUDE_H_ */
