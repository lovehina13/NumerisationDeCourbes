//==============================================================================
// Name        : ParametresTrait.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (24/06/2016)
// Description : Header file of the ParametresTrait class
//==============================================================================

#ifndef PARAMETRESTRAIT_H_
#define PARAMETRESTRAIT_H_

#include <QRgb>
#include <QString>

class ParametresTrait
{
public:
    // Constructeurs et destructeurs
    ParametresTrait();
    ParametresTrait(const int& styleTrait, const int& epaisseurTrait, const QRgb& couleurTrait);
    ParametresTrait(const ParametresTrait& parametresTrait);
    virtual ~ParametresTrait();

    // Getters
    const int& getStyleTrait() const;
    const int& getEpaisseurTrait() const;
    const QRgb& getCouleurTrait() const;

    // Setters
    void setStyleTrait(const int& styleTrait);
    void setEpaisseurTrait(const int& epaisseurTrait);
    void setCouleurTrait(const QRgb& couleurTrait);

    // Méthodes génériques
    void clear();
    void set(const int& styleTrait, const int& epaisseurTrait, const QRgb& couleurTrait);
    void copy(const ParametresTrait& parametresTrait);
    bool equals(const ParametresTrait& parametresTrait) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques

    // Enumération des styles de traits
    enum stylesTraits
    {
        LIGNE, TIRETS, POINTILLES
    };

    // Définition des valeurs par défaut des paramètres d'un trait
    static const int styleTraitDefaut = LIGNE;
    static const int epaisseurTraitDefaut = 2;
    static const QRgb couleurTraitDefaut;
    static const QRgb couleurTraitAxeDefaut;
    static const QRgb couleurTraitCourbeDefaut;

private:
    // Attributs de classe
    int styleTrait;
    int epaisseurTrait;
    QRgb couleurTrait;
};

#endif /* PARAMETRESTRAIT_H_ */
