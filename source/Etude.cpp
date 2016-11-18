//==============================================================================
// Name        : Etude.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Source file of the Etude class
//==============================================================================

#include "Etude.h"
#include "Outils.h"
#include <QColor>
#include <QFile>
#include <QImage>
#include <QIODevice>
#include <QMap>
#include <QTextStream>

Etude::Etude()
{
    this->clear();
}

Etude::Etude(const Image& image, const Repere& repere, const QList<Point>& listeDePoints,
        const Parametres& parametres)
{
    this->set(image, repere, listeDePoints, parametres);
}

Etude::Etude(const Etude& etude)
{
    this->copy(etude);
}

Etude::~Etude()
{
}

const Image& Etude::getImage() const
{
    return this->image;
}

const Repere& Etude::getRepere() const
{
    return this->repere;
}

const QList<Point>& Etude::getListeDePoints() const
{
    return this->listeDePoints;
}

const Parametres& Etude::getParametres() const
{
    return this->parametres;
}

void Etude::setImage(const Image& image)
{
    this->image = image;
}

void Etude::setRepere(const Repere& repere)
{
    this->repere = repere;
}

void Etude::setListeDePoints(const QList<Point>& listeDePoints)
{
    this->listeDePoints = listeDePoints;
}

void Etude::setParametres(const Parametres& parametres)
{
    this->parametres = parametres;
}

void Etude::clear()
{
    this->set(Image(), Repere(), QList<Point>(), Parametres());
}

void Etude::set(const Image& image, const Repere& repere, const QList<Point>& listeDePoints,
        const Parametres& parametres)
{
    this->setImage(image);
    this->setRepere(repere);
    this->setListeDePoints(listeDePoints);
    this->setParametres(parametres);
}

void Etude::copy(const Etude& etude)
{
    this->setImage(etude.getImage());
    this->setRepere(etude.getRepere());
    this->setListeDePoints(etude.getListeDePoints());
    this->setParametres(etude.getParametres());
}

bool Etude::equals(const Etude& etude) const
{
    if (!this->getImage().equals(etude.getImage()))
        return false;
    if (!this->getRepere().equals(etude.getRepere()))
        return false;
    if (this->getListeDePoints() != etude.getListeDePoints())
        return false;
    if (!this->getParametres().equals(etude.getParametres()))
        return false;
    return true;
}

void Etude::fromString(const QString& fromString, const char& sep)
{
    // TODO void Etude::fromString(const QString& fromString, const char& sep)
    Q_UNUSED(fromString);
    Q_UNUSED(sep);
}

const QString Etude::toString(const char& sep) const
{
    QString toString;
    const QList<Point>& listeDePoints = this->getListeDePoints();
    const int nombreDePoints = listeDePoints.count();
    toString += "(" + this->getImage().toString(sep) + ")" + sep;
    toString += "(" + this->getRepere().toString(sep) + ")" + sep;
    toString += "[";
    for (int itPoint = 0; itPoint < nombreDePoints; itPoint++)
    {
        const Point& pointCourant = listeDePoints.at(itPoint);
        toString += "(" + pointCourant.toString(sep) + ")";
        if (itPoint < (nombreDePoints - 1))
        {
            toString += sep;
        }
    }
    toString += "]";
    toString += sep;
    toString += "(" + this->getParametres().toString(sep) + ")";
    return toString;
}

const QList<QList<Point>> Etude::getListeDeCourbes() const
{
    QList<QList<Point>> listeDeCourbes;
    QList<Point> listeDePointsCourbe;
    const QList<Point>& listeDePoints = this->getListeDePoints();
    const int nombreDePoints = listeDePoints.count();
    for (int itPoint = 0; itPoint < nombreDePoints; itPoint++)
    {
        const Point& pointCourant = listeDePoints.at(itPoint);
        const int& typePointCourant = pointCourant.getTypePoint();
        if (typePointCourant == Point::COURBE_DEBUT)
        {
            listeDePointsCourbe.clear();
            listeDePointsCourbe.append(pointCourant);
        }
        else if (typePointCourant == Point::COURBE)
        {
            listeDePointsCourbe.append(pointCourant);
        }
        else if (typePointCourant == Point::COURBE_FIN)
        {
            listeDePointsCourbe.append(pointCourant);
            listeDeCourbes.append(listeDePointsCourbe);
        }
    }
    return listeDeCourbes;
}

const QList<Point> Etude::getListeDePointsManuels() const
{
    QList<Point> listeDePointsManuels;
    const QList<Point>& listeDePoints = this->getListeDePoints();
    const int nombreDePoints = listeDePoints.count();
    for (int itPoint = 0; itPoint < nombreDePoints; itPoint++)
    {
        const Point& pointCourant = listeDePoints.at(itPoint);
        if (pointCourant.getTypePoint() == Point::MANUEL)
        {
            listeDePointsManuels.append(pointCourant);
        }
    }
    return listeDePointsManuels;
}

bool Etude::chargerEtude(const QString& cheminFichierEtude)
{
    QFile fichierEtude(cheminFichierEtude);
    if (!fichierEtude.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    const char separateur = ';';
    QTextStream fluxEntree(&fichierEtude);
    while (!fluxEntree.atEnd())
    {
        QString ligneEntree = fluxEntree.readLine();
        if (ligneEntree == "[PARAMETRES]")
        {
            ligneEntree = fluxEntree.readLine();
            Parametres parametres = this->getParametres();
            parametres.fromString(ligneEntree, separateur);
            this->setParametres(parametres);
            Image image;
            image.setImageSource(
                    QImage(parametres.getParametresFichiers().getCheminFichierImageSource()));
            this->setImage(image);
            this->restaurerImage();
            this->convertirImage();
        }
        else if (ligneEntree == "[REPERE]")
        {
            ligneEntree = fluxEntree.readLine();
            Repere repere = this->getRepere();
            repere.fromString(ligneEntree, separateur);
            this->setRepere(repere);
        }
        else if (ligneEntree == "[POINTS]")
        {
            QList<Point> listeDePoints;
            while (!fluxEntree.atEnd())
            {
                ligneEntree = fluxEntree.readLine();
                Point point;
                point.fromString(ligneEntree, separateur);
                listeDePoints.append(point);
            }
            this->setListeDePoints(listeDePoints);
        }
    }
    return true;
}

bool Etude::sauverEtude(const QString& cheminFichierEtude)
{
    Parametres parametres = this->getParametres();
    ParametresFichiers parametresFichiers = parametres.getParametresFichiers();
    parametresFichiers.setCheminFichierEtude(cheminFichierEtude);
    parametres.setParametresFichiers(parametresFichiers);
    this->setParametres(parametres);

    QFile fichierEtude(cheminFichierEtude);
    if (!fichierEtude.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    const char separateur = ';';
    QTextStream fluxSortie(&fichierEtude);
    fluxSortie << "[PARAMETRES]" << endl;
    fluxSortie << this->getParametres().toString(separateur) << endl;
    fluxSortie << "[REPERE]" << endl;
    fluxSortie << this->getRepere().toString(separateur) << endl;
    fluxSortie << "[POINTS]" << endl;
    const QList<Point>& listeDePoints = this->getListeDePoints();
    const int nombreDePoints = listeDePoints.count();
    for (int itPoint = 0; itPoint < nombreDePoints; itPoint++)
    {
        const Point& pointCourant = listeDePoints.at(itPoint);
        fluxSortie << pointCourant.toString(separateur) << endl;
    }
    return true;
}

bool Etude::exporterImageConvertie(const QString& cheminFichierImageConvertie)
{
    Parametres parametres = this->getParametres();
    ParametresFichiers parametresFichiers = parametres.getParametresFichiers();
    parametresFichiers.setCheminFichierImageConvertie(cheminFichierImageConvertie);
    parametres.setParametresFichiers(parametresFichiers);
    this->setParametres(parametres);

    QFile fichierImageConvertie(cheminFichierImageConvertie);
    if (!fichierImageConvertie.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    const QImage& imageConvertie = this->getImage().getImageConvertie();
    imageConvertie.save(cheminFichierImageConvertie);
    return true;
}

bool Etude::exporterListeDePoints(const QString& cheminFichierExport)
{
    Parametres parametres = this->getParametres();
    ParametresFichiers parametresFichiers = parametres.getParametresFichiers();
    parametresFichiers.setCheminFichierExport(cheminFichierExport);
    parametres.setParametresFichiers(parametresFichiers);
    this->setParametres(parametres);

    QFile fichierExport(cheminFichierExport);
    if (!fichierExport.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    const ParametresExport& parametresExport = parametres.getParametresExport();
    const char formatNotationNombresCaractere =
            parametresExport.getFormatNotationNombresCaractere();
    const int& nombreChiffresSignificatifs = parametresExport.getNombreChiffresSignificatifs();
    const char& caractereSeparation = parametresExport.getCaractereSeparation();
    const char& caractereSeparateurDecimal = parametresExport.getCaractereSeparateurDecimal();
    const double& seuilInterpolationNumerique = parametresExport.getSeuilInterpolationNumerique();

    QTextStream fluxSortie(&fichierExport);
    const QList<QList<Point>> listeDeCourbes = this->getListeDeCourbes();
    const QList<Point> listeDePointsManuels = this->getListeDePointsManuels();
    const int nombreDeCourbes = listeDeCourbes.count();
    const int nombreDePointsManuels = listeDePointsManuels.count();
    for (int itCourbe = 0; itCourbe < nombreDeCourbes; itCourbe++)
    {
        const QList<Point>& pointsCourbe = listeDeCourbes.at(itCourbe);
        const int nombreDePointsCourbe = pointsCourbe.count();
        if (seuilInterpolationNumerique == 0.0)
        {
            for (int itPointCourbe = 0; itPointCourbe < nombreDePointsCourbe; itPointCourbe++)
            {
                const Point& pointCourbe = pointsCourbe.at(itPointCourbe);
                fluxSortie
                        << QString::number(pointCourbe.getPointReelX(),
                                formatNotationNombresCaractere, nombreChiffresSignificatifs).replace(
                                '.', caractereSeparateurDecimal) << caractereSeparation
                        << QString::number(pointCourbe.getPointReelY(),
                                formatNotationNombresCaractere, nombreChiffresSignificatifs).replace(
                                '.', caractereSeparateurDecimal) << endl;
            }
        }
        else
        {
            const QList<Point> pointsCourbeInterpoles = interpolationNumerique(pointsCourbe,
                    seuilInterpolationNumerique);
            const int nombreDePointsCourbeInterpoles = pointsCourbeInterpoles.count();
            for (int itPointCourbeInterpole = 0;
                    itPointCourbeInterpole < nombreDePointsCourbeInterpoles;
                    itPointCourbeInterpole++)
            {
                const Point& pointCourbeInterpole = pointsCourbeInterpoles.at(
                        itPointCourbeInterpole);
                fluxSortie
                        << QString::number(pointCourbeInterpole.getPointReelX(),
                                formatNotationNombresCaractere, nombreChiffresSignificatifs).replace(
                                '.', caractereSeparateurDecimal) << caractereSeparation
                        << QString::number(pointCourbeInterpole.getPointReelY(),
                                formatNotationNombresCaractere, nombreChiffresSignificatifs).replace(
                                '.', caractereSeparateurDecimal) << endl;
            }
        }
    }
    for (int itPointManuel = 0; itPointManuel < nombreDePointsManuels; itPointManuel++)
    {
        const Point& pointManuel = listeDePointsManuels.at(itPointManuel);
        fluxSortie
                << QString::number(pointManuel.getPointReelX(), formatNotationNombresCaractere,
                        nombreChiffresSignificatifs).replace('.', caractereSeparateurDecimal)
                << caractereSeparation
                << QString::number(pointManuel.getPointReelY(), formatNotationNombresCaractere,
                        nombreChiffresSignificatifs).replace('.', caractereSeparateurDecimal)
                << endl;
    }
    // TODO Interpolation des points manuels (point le plus proche) ?
    return true;
}

void Etude::restaurerImage()
{
    Image image = this->getImage();
    image.restaurerImage();
    this->setImage(image);
}

void Etude::convertirImage()
{
    const Parametres& parametres = this->getParametres();
    const ParametresConversion& parametresConversion = parametres.getParametresConversion();
    const int& methodeConversion = parametresConversion.getMethodeConversion();

    Image image = this->getImage();
    if (methodeConversion == ParametresConversion::BRUTE)
    {
        image.restaurerImage();
    }
    else if (methodeConversion == ParametresConversion::NOIR_ET_BLANC)
    {
        image.convertirImageNoirEtBlanc(parametresConversion.getSeuilNoirEtBlanc());
    }
    else if (methodeConversion == ParametresConversion::NIVEAUX_DE_GRIS)
    {
        image.convertirImageNiveauxDeGris(parametresConversion.getNombreNiveauxDeGris());
    }
    else if (methodeConversion == ParametresConversion::TEINTES_SATUREES)
    {
        image.convertirImageTeintesSaturees(parametresConversion.getNombreNiveauxDeGris(),
                parametresConversion.getNombreTeintesSaturees(),
                parametresConversion.getSeuilSaturation());
    }
    this->setImage(image);
}

const QList<QPoint> Etude::rechercherCourbe(const QPoint& pointPixelDepart,
        const QPoint& pointPixelArrivee)
{
    this->listeDePointsDeRecherche.clear();
    this->pointPixelDepart = pointPixelDepart;
    this->pointPixelArrivee = pointPixelArrivee;
    this->listeDePointsDeRecherche.append(pointPixelDepart);
    const QRgb couleurReference = this->getImage().recupererCouleurPixel(pointPixelDepart);
    this->rechercherPointsProches(this->pointPixelDepart, couleurReference);
    this->filtrerListeDePoints(this->listeDePointsDeRecherche);
    this->traiterListeDePoints(this->listeDePointsDeRecherche);
    return this->listeDePointsDeRecherche;
}

void Etude::rechercherPointsProches(const QPoint& pointPixel, const QRgb& couleurReference)
{
    const QList<QPoint> listeDePointsProches = this->rechercherListeDePointsProches(pointPixel);
    const int nombreDePointsProches = listeDePointsProches.count();
    const int seuilToleranceNiveauxDeGris =
            this->getParametres().getParametresRecherche().getSeuilToleranceNiveauxDeGris();
    const int seuilToleranceTeintesSaturees =
            this->getParametres().getParametresRecherche().getSeuilToleranceTeintesSaturees();
    for (int itPointProche = 0; itPointProche < nombreDePointsProches; itPointProche++)
    {
        const QPoint& pointCourant = listeDePointsProches.at(itPointProche);
        if (this->listeDePointsDeRecherche.contains(pointCourant))
            continue;
        const QRgb& couleurCourante = this->getImage().recupererCouleurPixel(pointCourant);
        if (this->verifierToleranceNiveauxDeGris(couleurCourante, couleurReference,
                seuilToleranceNiveauxDeGris) != NIVEAU_DE_GRIS_COMPATIBLE)
            continue;
        if (this->verifierToleranceTeintesSaturees(couleurCourante, couleurReference,
                seuilToleranceTeintesSaturees) != TEINTE_SATUREE_COMPATIBLE)
            continue;
        this->listeDePointsDeRecherche.append(pointCourant);
        this->rechercherPointsProches(pointCourant, couleurReference);
    }
}

const QList<QPoint> Etude::rechercherListeDePointsProches(const QPoint& pointPixel) const
{
    QList<QPoint> listeDePointsProches;
    const Image& image = this->getImage();

    const int xCourant = pointPixel.x();
    const int yCourant = pointPixel.y();
    const int xPrecedent = xCourant - 1;
    const int xSuivant = xCourant + 1;
    const int yPrecedent = yCourant - 1;
    const int ySuivant = yCourant + 1;

    const QPoint pointHautGauche(xPrecedent, yPrecedent);
    const QPoint pointHaut(xCourant, yPrecedent);
    const QPoint pointHautDroite(xSuivant, yPrecedent);
    const QPoint pointGauche(xPrecedent, yCourant);
    const QPoint pointDroite(xSuivant, yCourant);
    const QPoint pointBasGauche(xPrecedent, ySuivant);
    const QPoint pointBas(xCourant, ySuivant);
    const QPoint pointBasDroite(xSuivant, ySuivant);

    if (image.verifierPresencePixel(pointHautGauche) && xPrecedent >= this->pointPixelDepart.x())
    {
        listeDePointsProches.append(pointHautGauche);
    }
    if (image.verifierPresencePixel(pointHaut))
    {
        listeDePointsProches.append(pointHaut);
    }
    if (image.verifierPresencePixel(pointHautDroite) && xSuivant <= this->pointPixelArrivee.x())
    {
        listeDePointsProches.append(pointHautDroite);
    }
    if (image.verifierPresencePixel(pointGauche) && xPrecedent >= this->pointPixelDepart.x())
    {
        listeDePointsProches.append(pointGauche);
    }
    if (image.verifierPresencePixel(pointDroite) && xSuivant <= this->pointPixelArrivee.x())
    {
        listeDePointsProches.append(pointDroite);
    }
    if (image.verifierPresencePixel(pointBasGauche) && xPrecedent >= this->pointPixelDepart.x())
    {
        listeDePointsProches.append(pointBasGauche);
    }
    if (image.verifierPresencePixel(pointBas))
    {
        listeDePointsProches.append(pointBas);
    }
    if (image.verifierPresencePixel(pointBasDroite) && xSuivant <= this->pointPixelArrivee.x())
    {
        listeDePointsProches.append(pointBasDroite);
    }

    return listeDePointsProches;
}

int Etude::verifierToleranceNiveauxDeGris(const QRgb& couleurCourante, const QRgb& couleurReference,
        const int& seuilToleranceNiveauxDeGris) const
{
    if (qGray(couleurCourante) < (qGray(couleurReference) - seuilToleranceNiveauxDeGris))
        return NIVEAU_DE_GRIS_INFERIEUR;
    else if (qGray(couleurCourante) > (qGray(couleurReference) + seuilToleranceNiveauxDeGris))
        return NIVEAU_DE_GRIS_SUPERIEUR;
    return NIVEAU_DE_GRIS_COMPATIBLE;
}

int Etude::verifierToleranceTeintesSaturees(const QRgb& couleurCourante,
        const QRgb& couleurReference, const int& seuilToleranceTeintesSaturees) const
{
    if (QColor(couleurCourante).hue()
            < ((QColor(couleurReference).hue() - seuilToleranceTeintesSaturees) % 360))
        return TEINTE_SATUREE_INFERIEURE;
    else if (QColor(couleurCourante).hue()
            > ((QColor(couleurReference).hue() + seuilToleranceTeintesSaturees) % 360))
        return TEINTE_SATUREE_SUPERIEURE;
    else if ((QColor(couleurCourante).hue() == -1 && QColor(couleurReference).hue() != -1)
            || (QColor(couleurCourante).hue() != -1 && QColor(couleurReference).hue() == -1))
        return TEINTE_SATUREE_INCOMPATIBLE;
    return TEINTE_SATUREE_COMPATIBLE;
}

void Etude::filtrerListeDePoints(const QList<QPoint>& listeDePoints)
{
    // TODO void Etude::filtrerListeDePoints(const QList<QPoint>& listeDePoints)
    Q_UNUSED(listeDePoints);

    if (!this->listeDePointsDeRecherche.contains(this->pointPixelDepart))
        return;
    if (!this->listeDePointsDeRecherche.contains(this->pointPixelArrivee))
        return;

    qSort(this->listeDePointsDeRecherche.begin(), this->listeDePointsDeRecherche.end(),
            lessThanQPoint);

    QMap<int, QList<int>> mapPointsRecherche;
    const int nombreDePointsDeRecherche = this->listeDePointsDeRecherche.count();
    for (int itPointRecherche = 0; itPointRecherche < nombreDePointsDeRecherche; itPointRecherche++)
    {
        const QPoint& pointRecherche = this->listeDePointsDeRecherche.at(itPointRecherche);
        mapPointsRecherche[pointRecherche.x()].append(pointRecherche.y());
    }

    const int xDepart = this->pointPixelDepart.x();
    const int xArrivee = this->pointPixelArrivee.x();
    for (int x = (xDepart + 1); x <= xArrivee; x++)
    {
        QList<QList<int>> listeValeursAdjacentes = listesValeursAdjacentes(mapPointsRecherche[x]);
        const int nombreValeursAdjacentes = listeValeursAdjacentes.count();
        QList<int> valeursAdjacentesRetenues = listeValeursAdjacentes.at(0);
        if (listeValeursAdjacentes.count() > 1)
        {
            double valeurMoyennePrecedente = getValeurMoyenne(mapPointsRecherche[x - 1]);
            for (int itValeurAdjacente = 0; itValeurAdjacente < nombreValeursAdjacentes;
                    itValeurAdjacente++)
            {
                QList<int> valeursAdjacentes = listeValeursAdjacentes.at(itValeurAdjacente);
                double valeurMoyenne = getValeurMoyenne(valeursAdjacentes);
                double valeurMoyenneRetenue = getValeurMoyenne(valeursAdjacentesRetenues);
                if (fabs(valeurMoyenne - valeurMoyennePrecedente)
                        < fabs(valeurMoyenneRetenue - valeurMoyennePrecedente))
                {
                    valeursAdjacentesRetenues = valeursAdjacentes;
                }
            }
        }
        mapPointsRecherche[x] = valeursAdjacentesRetenues;
    }

    this->listeDePointsDeRecherche.clear();
    if (this->getParametres().getParametresRecherche().getSelectionValeursMoyennes())
    {
        for (int x = xDepart; x <= xArrivee; x++)
        {
            int y = getValeurMoyenne(mapPointsRecherche[x]);
            this->listeDePointsDeRecherche.append(QPoint(x, y));
        }
    }
    if (this->getParametres().getParametresRecherche().getSelectionValeursMinimales())
    {
        for (int x = xDepart; x <= xArrivee; x++)
        {
            int y = getValeurMinimale(mapPointsRecherche[x]);
            this->listeDePointsDeRecherche.append(QPoint(x, y));
        }
    }
    if (this->getParametres().getParametresRecherche().getSelectionValeursMaximales())
    {
        for (int x = xDepart; x <= xArrivee; x++)
        {
            int y = getValeurMaximale(mapPointsRecherche[x]);
            this->listeDePointsDeRecherche.append(QPoint(x, y));
        }
    }
}

void Etude::traiterListeDePoints(const QList<QPoint>& listeDePoints)
{
    // TODO void Etude::traiterListeDePoints(const QList<QPoint>& listeDePoints)
    Q_UNUSED(listeDePoints);
}
