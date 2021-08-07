//==============================================================================
// Name        : ParametresRecherche.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Header file of the ParametresRecherche class
//==============================================================================

#ifndef PARAMETRESRECHERCHE_H
#define PARAMETRESRECHERCHE_H

#include <QChar>
#include <QString>

class ParametresRecherche
{
public:
    // Constructeurs et destructeurs
    ParametresRecherche() = default;
    ParametresRecherche(const int& seuilToleranceNiveauxDeGris,
            const int& seuilToleranceTeintesSaturees, const bool& selectionValeursMoyennes,
            const bool& selectionValeursMinimales, const bool& selectionValeursMaximales);

    // Opérateurs
    bool operator==(const ParametresRecherche& parametresRecherche) const = default;
    bool operator!=(const ParametresRecherche& parametresRecherche) const = default;

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
    void fromString(const QString& fromString, const QChar& sep);
    const QString toString(const QChar& sep) const;

    // Méthodes spécifiques
    double getSeuilToleranceNiveauxDeGrisFacteur() const;
    double getSeuilToleranceTeintesSatureesFacteur() const;
    void setSeuilToleranceNiveauxDeGrisFacteur(const double& seuilToleranceNiveauxDeGrisFacteur);
    void setSeuilToleranceTeintesSatureesFacteur(
            const double& seuilToleranceTeintesSatureesFacteur);

    // Définition des valeurs par défaut des paramètres de recherche
    static const int seuilToleranceNiveauxDeGrisDefaut { 32 };
    static const int seuilToleranceTeintesSatureesDefaut { 60 };
    static const bool selectionValeursMoyennesDefaut { true };
    static const bool selectionValeursMinimalesDefaut { false };
    static const bool selectionValeursMaximalesDefaut { false };

private:
    // Attributs de classe
    int _seuilToleranceNiveauxDeGris { seuilToleranceNiveauxDeGrisDefaut };
    int _seuilToleranceTeintesSaturees { seuilToleranceTeintesSatureesDefaut };
    bool _selectionValeursMoyennes { selectionValeursMoyennesDefaut };
    bool _selectionValeursMinimales { selectionValeursMinimalesDefaut };
    bool _selectionValeursMaximales { selectionValeursMaximalesDefaut };
};

#endif /* PARAMETRESRECHERCHE_H */
