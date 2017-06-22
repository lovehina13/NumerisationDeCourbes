//==============================================================================
// Name        : ParametresFichiers.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.5 (07/06/2017)
// Description : Header file of the ParametresFichiers class
//==============================================================================

#ifndef PARAMETRESFICHIERS_H_
#define PARAMETRESFICHIERS_H_

#include <QString>

class ParametresFichiers
{
public:
    // Constructeurs et destructeurs
    ParametresFichiers();
    ParametresFichiers(const QString& cheminFichierEtude, const QString& cheminFichierImageSource,
            const QString& cheminFichierImageConvertie, const QString& cheminFichierExport,
            const QString& cheminFichierParametres);
    ParametresFichiers(const ParametresFichiers& parametresFichiers);
    virtual ~ParametresFichiers();

    // Getters
    const QString& getCheminFichierEtude() const;
    const QString& getCheminFichierImageSource() const;
    const QString& getCheminFichierImageConvertie() const;
    const QString& getCheminFichierExport() const;
    const QString& getCheminFichierParametres() const;

    // Setters
    void setCheminFichierEtude(const QString& cheminFichierEtude);
    void setCheminFichierImageSource(const QString& cheminFichierImageSource);
    void setCheminFichierImageConvertie(const QString& cheminFichierImageConvertie);
    void setCheminFichierExport(const QString& cheminFichierExport);
    void setCheminFichierParametres(const QString& cheminFichierParametres);

    // Méthodes génériques
    void clear();
    void set(const QString& cheminFichierEtude, const QString& cheminFichierImageSource,
            const QString& cheminFichierImageConvertie, const QString& cheminFichierExport,
            const QString& cheminFichierParametres);
    void copy(const ParametresFichiers& parametresFichiers);
    bool equals(const ParametresFichiers& parametresFichiers) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques

private:
    // Attributs de classe
    QString cheminFichierEtude;
    QString cheminFichierImageSource;
    QString cheminFichierImageConvertie;
    QString cheminFichierExport;
    QString cheminFichierParametres;
};

#endif /* PARAMETRESFICHIERS_H_ */
