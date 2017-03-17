//==============================================================================
// Name        : ParametresRecherche.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.3 (17/03/2017)
// Description : Header file of the ParametresRecherche class
//==============================================================================

#ifndef PARAMETRESRECHERCHE_H_
#define PARAMETRESRECHERCHE_H_

#include <QString>

class ParametresRecherche
{
public:
    // Constructeurs et destructeurs
    ParametresRecherche();
    ParametresRecherche(const int& seuilToleranceNiveauxDeGris,
            const int& seuilToleranceTeintesSaturees, const bool& selectionValeursMoyennes,
            const bool& selectionValeursMinimales, const bool& selectionValeursMaximales);
    ParametresRecherche(const ParametresRecherche& parametresRecherche);
    virtual ~ParametresRecherche();

    // Getters
    const int& getSeuilToleranceNiveauxDeGris() const;
    const int& getSeuilToleranceTeintesSaturees() const;
    const bool& getSelectionValeursMoyennes() const;
    const bool& getSelectionValeursMinimales() const;
    const bool& getSelectionValeursMaximales() const;

    // Setters
    void setSeuilToleranceNiveauxDeGris(const int& seuilToleranceNiveauxDeGris);
    void setSeuilToleranceTeintesSaturees(const int& seuilToleranceTeintesSaturees);
    void setSelectionValeursMoyennes(const bool& selectionValeursMoyennes);
    void setSelectionValeursMinimales(const bool& selectionValeursMinimales);
    void setSelectionValeursMaximales(const bool& selectionValeursMaximales);

    // Méthodes génériques
    void clear();
    void set(const int& seuilToleranceNiveauxDeGris, const int& seuilToleranceTeintesSaturees,
            const bool& selectionValeursMoyennes, const bool& selectionValeursMinimales,
            const bool& selectionValeursMaximales);
    void copy(const ParametresRecherche& parametresRecherche);
    bool equals(const ParametresRecherche& parametresRecherche) const;
    void fromString(const QString& fromString, const char& sep);
    const QString toString(const char& sep) const;

    // Méthodes spécifiques
    double getSeuilToleranceNiveauxDeGrisFacteur() const;
    double getSeuilToleranceTeintesSatureesFacteur() const;
    void setSeuilToleranceNiveauxDeGrisFacteur(const double& seuilToleranceNiveauxDeGrisFacteur);
    void setSeuilToleranceTeintesSatureesFacteur(
            const double& seuilToleranceTeintesSatureesFacteur);

    // Définition des valeurs par défaut des paramètres de recherche
    static const int seuilToleranceNiveauxDeGrisDefaut;
    static const int seuilToleranceTeintesSatureesDefaut;
    static const bool selectionValeursMoyennesDefaut;
    static const bool selectionValeursMinimalesDefaut;
    static const bool selectionValeursMaximalesDefaut;

private:
    // Attributs de classe
    int seuilToleranceNiveauxDeGris;
    int seuilToleranceTeintesSaturees;
    bool selectionValeursMoyennes;
    bool selectionValeursMinimales;
    bool selectionValeursMaximales;
};

#endif /* PARAMETRESRECHERCHE_H_ */
