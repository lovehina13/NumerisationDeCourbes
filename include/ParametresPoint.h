//==============================================================================
// Name        : ParametresPoint.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (24/06/2016)
// Description : Header file of the ParametresPoint class
//==============================================================================

#ifndef PARAMETRESPOINT_H_
#define PARAMETRESPOINT_H_

#include <QRgb>
#include <QString>

class ParametresPoint
{
public:
    // Constructeurs et destructeurs
    ParametresPoint();
    ParametresPoint(const int& stylePoint, const int& epaisseurPoint, const QRgb& couleurPoint);
    ParametresPoint(const ParametresPoint& parametresPoint);
    virtual ~ParametresPoint();

    // Getters
    const int& getStylePoint() const;
    const int& getEpaisseurPoint() const;
    const QRgb& getCouleurPoint() const;

    // Setters
    void setStylePoint(const int& stylePoint);
    void setEpaisseurPoint(const int& epaisseurPoint);
    void setCouleurPoint(const QRgb& couleurPoint);

    // Méthodes génériques
    void clear();
    void set(const int& stylePoint, const int& epaisseurPoint, const QRgb& couleurPoint);
    void copy(const ParametresPoint& parametresPoint);
    bool equals(const ParametresPoint& parametresPoint) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques
    // TODO Méthodes spécifiques

    // Enumération des styles de points
    enum stylesPoints
    {
        CARRE, CERCLE
    };

    // Définition des valeurs par défaut des paramètres d'un point
    static const int stylePointDefaut = CARRE;
    static const int epaisseurPointDefaut = 4;
    static const QRgb couleurPointDefaut = Qt::black;
    static const QRgb couleurPointAxeDefaut = Qt::red;
    static const QRgb couleurPointCourbeDefaut = Qt::blue;
    static const QRgb couleurPointManuelDefaut = Qt::green;

private:
    // Attributs de classe
    int stylePoint;
    int epaisseurPoint;
    QRgb couleurPoint;
};

#endif /* PARAMETRESPOINT_H_ */
