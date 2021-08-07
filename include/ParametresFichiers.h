//==============================================================================
// Name        : ParametresFichiers.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Header file of the ParametresFichiers class
//==============================================================================

#ifndef PARAMETRESFICHIERS_H
#define PARAMETRESFICHIERS_H

#include <QChar>
#include <QString>

class ParametresFichiers
{
public:
    // Constructeurs et destructeurs
    ParametresFichiers() = default;
    ParametresFichiers(const QString& cheminFichierEtude, const QString& cheminFichierImageSource,
            const QString& cheminFichierImageConvertie, const QString& cheminFichierExport,
            const QString& cheminFichierParametres, const QString& cheminFichierGraphique);

    // Opérateurs
    bool operator==(const ParametresFichiers& parametresFichiers) const = default;
    bool operator!=(const ParametresFichiers& parametresFichiers) const = default;

    // Getters
    const QString& getCheminFichierEtude() const;
    const QString& getCheminFichierImageSource() const;
    const QString& getCheminFichierImageConvertie() const;
    const QString& getCheminFichierExport() const;
    const QString& getCheminFichierParametres() const;
    const QString& getCheminFichierGraphique() const;

    // Setters
    void setCheminFichierEtude(const QString& cheminFichierEtude);
    void setCheminFichierImageSource(const QString& cheminFichierImageSource);
    void setCheminFichierImageConvertie(const QString& cheminFichierImageConvertie);
    void setCheminFichierExport(const QString& cheminFichierExport);
    void setCheminFichierParametres(const QString& cheminFichierParametres);
    void setCheminFichierGraphique(const QString& cheminFichierGraphique);

    // Méthodes génériques
    void clear();
    void set(const QString& cheminFichierEtude, const QString& cheminFichierImageSource,
            const QString& cheminFichierImageConvertie, const QString& cheminFichierExport,
            const QString& cheminFichierParametres, const QString& cheminFichierGraphique);
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques

private:
    // Attributs de classe
    QString _cheminFichierEtude;
    QString _cheminFichierImageSource;
    QString _cheminFichierImageConvertie;
    QString _cheminFichierExport;
    QString _cheminFichierParametres;
    QString _cheminFichierGraphique;
};

#endif /* PARAMETRESFICHIERS_H */
