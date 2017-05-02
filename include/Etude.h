//==============================================================================
// Name        : Etude.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.4 (02/05/2017)
// Description : Header file of the Etude class
//==============================================================================

#ifndef ETUDE_H_
#define ETUDE_H_

#include "Image.h"
#include "Parametres.h"
#include "Point.h"
#include "Repere.h"
#include <QList>
#include <QPoint>
#include <QRgb>
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
    void set(const Image& image, const Repere& repere, const QList<Point>& listeDePoints,
            const Parametres& parametres);
    void copy(const Etude& etude);
    bool equals(const Etude& etude) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques
    const QList<Courbe> getListeDeCourbes() const;
    const QList<Point> getListeDePointsManuels() const;
    bool chargerEtude(const QString& cheminFichierEtude);
    bool sauverEtude(const QString& cheminFichierEtude);
    bool exporterImageConvertie(const QString& cheminFichierImageConvertie);
    bool exporterListeDePoints(const QString& cheminFichierExport);
    void restaurerImage();
    void convertirImage();
    const QList<Courbe> rechercherCourbes(const QPoint& pointPixelDepart,
            const QPoint& pointPixelArrivee);

    // Enumération des types de tolérance de niveaux de gris
    enum typesToleranceNiveauxDeGris
    {
        NIVEAU_DE_GRIS_COMPATIBLE, NIVEAU_DE_GRIS_INFERIEUR, NIVEAU_DE_GRIS_SUPERIEUR
    };

    // Enumération des types de tolérance de teintes saturées
    enum typesToleranceTeintesSaturees
    {
        TEINTE_SATUREE_COMPATIBLE, TEINTE_SATUREE_INCOMPATIBLE, TEINTE_SATUREE_INFERIEURE,
        TEINTE_SATUREE_SUPERIEURE
    };

protected:
    // Méthodes spécifiques
    const QList<QPoint> rechercherPointsCourbes(const QPoint& pointPixelDepart,
            const QPoint& pointPixelArrivee);
    void rechercherPoints(const QPoint& pointPixel, const QRgb& couleurReference);
    const QList<QPoint> recupererPointsProches(const QPoint& pointPixel) const;
    int verifierToleranceNiveauxDeGris(const QRgb& couleurCourante, const QRgb& couleurReference,
            const int& seuilToleranceNiveauxDeGris) const;
    int verifierToleranceTeintesSaturees(const QRgb& couleurCourante, const QRgb& couleurReference,
            const int& seuilToleranceTeintesSaturees) const;
    const QList<QPoint> filtrerPointsCourbes(const QList<QPoint>& listeDePoints,
            const QPoint& pointPixelDepart, const QPoint& pointPixelArrivee);
    const QList<Courbe> construireCourbes(const QList<QPoint>& listeDePoints);

private:
    // Attributs de classe
    Image image;
    Repere repere;
    QList<Point> listeDePoints;
    Parametres parametres;

    // Attributs de classe inaccessibles
    QList<QPoint> listeDePointsDeRecherche;
    QPoint pointPixelDepart;
    QPoint pointPixelArrivee;
};

#endif /* ETUDE_H_ */
