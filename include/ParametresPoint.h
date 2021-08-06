//==============================================================================
// Name        : ParametresPoint.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Header file of the ParametresPoint class
//==============================================================================

#ifndef PARAMETRESPOINT_H
#define PARAMETRESPOINT_H

#include <QChar>
#include <QMap>
#include <QRgb>
#include <QString>

class ParametresPoint
{
public:
    // Enumération des styles de points
    enum StylePoint
    {
        CARRE, CERCLE
    };

    // Constructeurs et destructeurs
    ParametresPoint() = default;
    ParametresPoint(const StylePoint& stylePoint, const int& epaisseurPoint,
            const QRgb& couleurPoint);

    // Opérateurs
    bool operator==(const ParametresPoint& parametresPoint) const = default;
    bool operator!=(const ParametresPoint& parametresPoint) const = default;

    // Getters
    const StylePoint& getStylePoint() const;
    const int& getEpaisseurPoint() const;
    const QRgb& getCouleurPoint() const;

    // Setters
    void setStylePoint(const StylePoint& stylePoint);
    void setEpaisseurPoint(const int& epaisseurPoint);
    void setCouleurPoint(const QRgb& couleurPoint);

    // Méthodes génériques
    void clear();
    void set(const StylePoint& stylePoint, const int& epaisseurPoint, const QRgb& couleurPoint);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques
    const QString getStylePointTexte() const;
    void setStylePointTexte(const QString& stylePointTexte);

    // Définition des valeurs par défaut des paramètres d'un point
    static const StylePoint stylePointDefaut { CARRE };
    static const int epaisseurPointDefaut { 4 };
    static const QRgb couleurPointDefaut { 0xFF000000 };
    static const QRgb couleurPointAxeDefaut { 0xFFFF0000 };
    static const QRgb couleurPointCourbeDefaut { 0xFF0000FF };
    static const QRgb couleurPointManuelDefaut { 0xFF00FF00 };

private:
    // Attributs de classe
    StylePoint _stylePoint { stylePointDefaut };
    int _epaisseurPoint { epaisseurPointDefaut };
    QRgb _couleurPoint { couleurPointDefaut };

    // Définition des correspondances
    static const QMap<StylePoint, QString> _stylePointTexte;
};

#endif /* PARAMETRESPOINT_H */
