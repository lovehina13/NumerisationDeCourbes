//==============================================================================
// Name        : ParametresAffichage.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Header file of the ParametresAffichage class
//==============================================================================

#ifndef PARAMETRESAFFICHAGE_H
#define PARAMETRESAFFICHAGE_H

#include "ParametresPoint.h"
#include "ParametresTrait.h"
#include <QChar>
#include <QMap>
#include <QString>

class ParametresAffichage
{
public:
    // Enumération des formats de notation des nombres
    enum FormatNotationNombres
    {
        STANDARD, SCIENTIFIQUE
    };

    // Constructeurs et destructeurs
    ParametresAffichage() = default;
    ParametresAffichage(const FormatNotationNombres& formatNotationNombres,
            const int& nombreChiffresSignificatifs, const ParametresTrait& parametresAxes,
            const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsAxes,
            const ParametresPoint& parametresPointsCourbes,
            const ParametresPoint& parametresPointsManuels);

    // Opérateurs
    bool operator==(const ParametresAffichage& parametresAffichage) const = default;
    bool operator!=(const ParametresAffichage& parametresAffichage) const = default;

    // Getters
    const FormatNotationNombres& getFormatNotationNombres() const;
    const int& getNombreChiffresSignificatifs() const;
    const ParametresTrait& getParametresAxes() const;
    const ParametresTrait& getParametresCourbes() const;
    const ParametresPoint& getParametresPointsAxes() const;
    const ParametresPoint& getParametresPointsCourbes() const;
    const ParametresPoint& getParametresPointsManuels() const;

    // Setters
    void setFormatNotationNombres(const FormatNotationNombres& formatNotationNombres);
    void setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs);
    void setParametresAxes(const ParametresTrait& parametresAxes);
    void setParametresCourbes(const ParametresTrait& parametresCourbes);
    void setParametresPointsAxes(const ParametresPoint& parametresPointsAxes);
    void setParametresPointsCourbes(const ParametresPoint& parametresPointsCourbes);
    void setParametresPointsManuels(const ParametresPoint& parametresPointsManuels);

    // Méthodes génériques
    void clear();
    void set(const FormatNotationNombres& formatNotationNombres,
            const int& nombreChiffresSignificatifs, const ParametresTrait& parametresAxes,
            const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsAxes,
            const ParametresPoint& parametresPointsCourbes,
            const ParametresPoint& parametresPointsManuels);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques
    const QChar getFormatNotationNombresCaractere() const;
    const QString getFormatNotationNombresTexte() const;
    void setFormatNotationNombresCaractere(const QChar& formatNotationNombresCaractere);
    void setFormatNotationNombresTexte(const QString& formatNotationNombresTexte);

    // Définition des valeurs par défaut des paramètres d'affichage
    static const FormatNotationNombres formatNotationNombresDefaut { STANDARD };
    static const int nombreChiffresSignificatifsDefaut { 6 };
    static const ParametresTrait parametresAxesDefaut;
    static const ParametresTrait parametresCourbesDefaut;
    static const ParametresPoint parametresPointsAxesDefaut;
    static const ParametresPoint parametresPointsCourbesDefaut;
    static const ParametresPoint parametresPointsManuelsDefaut;

private:
    // Attributs de classe
    FormatNotationNombres _formatNotationNombres { formatNotationNombresDefaut };
    int _nombreChiffresSignificatifs { nombreChiffresSignificatifsDefaut };
    ParametresTrait _parametresAxes { parametresAxesDefaut };
    ParametresTrait _parametresCourbes { parametresCourbesDefaut };
    ParametresPoint _parametresPointsAxes { parametresPointsAxesDefaut };
    ParametresPoint _parametresPointsCourbes { parametresPointsCourbesDefaut };
    ParametresPoint _parametresPointsManuels { parametresPointsManuelsDefaut };

    // Définition des correspondances
    static const QMap<FormatNotationNombres, QChar> _formatNotationNombresCaractere;
    static const QMap<FormatNotationNombres, QString> _formatNotationNombresTexte;
};

#endif /* PARAMETRESAFFICHAGE_H */
