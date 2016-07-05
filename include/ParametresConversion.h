//==============================================================================
// Name        : ParametresConversion.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (24/06/2016)
// Description : Header file of the ParametresConversion class
//==============================================================================

#ifndef PARAMETRESCONVERSION_H_
#define PARAMETRESCONVERSION_H_

#include <QString>

class ParametresConversion
{
public:
    // Constructeurs et destructeurs
    ParametresConversion();
    ParametresConversion(const int& methodeConversion, const int& seuilNoirEtBlanc,
            const int& nombreNiveauxDeGris, const int& nombreTeintesSaturees,
            const int& seuilSaturation);
    ParametresConversion(const ParametresConversion& parametresConversion);
    virtual ~ParametresConversion();

    // Getters
    const int& getMethodeConversion() const;
    const int& getSeuilNoirEtBlanc() const;
    const int& getNombreNiveauxDeGris() const;
    const int& getNombreTeintesSaturees() const;
    const int& getSeuilSaturation() const;

    // Setters
    void setMethodeConversion(const int& methodeConversion);
    void setSeuilNoirEtBlanc(const int& seuilNoirEtBlanc);
    void setNombreNiveauxDeGris(const int& nombreNiveauxDeGris);
    void setNombreTeintesSaturees(const int& nombreTeintesSaturees);
    void setSeuilSaturation(const int& seuilSaturation);

    // Méthodes génériques
    void clear();
    void set(const int& methodeConversion, const int& seuilNoirEtBlanc,
            const int& nombreNiveauxDeGris, const int& nombreTeintesSaturees,
            const int& seuilSaturation);
    void copy(const ParametresConversion& parametresConversion);
    bool equals(const ParametresConversion& parametresConversion) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques

    // Enumération des méthodes de conversion
    enum methodesConversion
    {
        BRUTE, NOIR_ET_BLANC, NIVEAUX_DE_GRIS, TEINTES_SATUREES
    };

    // Définition des valeurs par défaut des paramètres de conversion
    static const int methodeConversionDefaut = BRUTE;
    static const int seuilNoirEtBlancDefaut = 90;
    static const int nombreNiveauxDeGrisDefaut = 5;
    static const int nombreTeintesSatureesDefaut = 6;
    static const int seuilSaturationDefaut = 10;

private:
    // Attributs de classe
    int methodeConversion;
    int seuilNoirEtBlanc;
    int nombreNiveauxDeGris;
    int nombreTeintesSaturees;
    int seuilSaturation;
};

#endif /* PARAMETRESCONVERSION_H_ */
