//==============================================================================
// Name        : ParametresTrait.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Header file of the ParametresTrait class
//==============================================================================

#ifndef PARAMETRESTRAIT_H
#define PARAMETRESTRAIT_H

#include <QChar>
#include <QMap>
#include <QRgb>
#include <QString>

class ParametresTrait
{
public:
    // Enumération des styles de traits
    enum StyleTrait
    {
        LIGNE, TIRETS, POINTILLES
    };

    // Constructeurs et destructeurs
    ParametresTrait() = default;
    ParametresTrait(const StyleTrait& styleTrait, const int& epaisseurTrait,
            const QRgb& couleurTrait);

    // Opérateurs
    bool operator==(const ParametresTrait& parametresTrait) const = default;
    bool operator!=(const ParametresTrait& parametresTrait) const = default;

    // Getters
    const StyleTrait& getStyleTrait() const;
    const int& getEpaisseurTrait() const;
    const QRgb& getCouleurTrait() const;

    // Setters
    void setStyleTrait(const StyleTrait& styleTrait);
    void setEpaisseurTrait(const int& epaisseurTrait);
    void setCouleurTrait(const QRgb& couleurTrait);

    // Méthodes génériques
    void clear();
    void set(const StyleTrait& styleTrait, const int& epaisseurTrait, const QRgb& couleurTrait);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques
    const QString getStyleTraitTexte() const;
    void setStyleTraitTexte(const QString& styleTraitTexte);

    // Définition des valeurs par défaut des paramètres d'un trait
    static const StyleTrait styleTraitDefaut { LIGNE };
    static const int epaisseurTraitDefaut { 2 };
    static const QRgb couleurTraitDefaut { 0xFF000000 };
    static const QRgb couleurTraitAxeDefaut { 0xFFFF0000 };
    static const QRgb couleurTraitCourbeDefaut { 0xFF0000FF };

private:
    // Attributs de classe
    StyleTrait _styleTrait { styleTraitDefaut };
    int _epaisseurTrait { epaisseurTraitDefaut };
    QRgb _couleurTrait { couleurTraitDefaut };

    // Définition des correspondances
    static const QMap<StyleTrait, QString> _styleTraitTexte;
};

#endif /* PARAMETRESTRAIT_H */
