//==============================================================================
// Name        : Etude.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (30/01/2016)
// Description : Source file of the Etude class
//==============================================================================

#include "Etude.h"

Etude::Etude()
{
    this->clear();
}

Etude::Etude(const Image& image, const Repere& repere, const QList<Point>& listeDePoints,
        const Parametres& parametres)
{
    this->initialize(image, repere, listeDePoints, parametres);
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
    this->initialize(Image(), Repere(), QList<Point>(), Parametres());
}

void Etude::initialize(const Image& image, const Repere& repere, const QList<Point>& listeDePoints,
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
}

const QString Etude::toString(const char& sep) const
{
    // TODO const QString Etude::toString(const char& sep) const
    return QString();
}

void Etude::chargerEtude(const QString& cheminFichierEtude)
{
    // TODO void Etude::chargerEtude(const QString& cheminFichierEtude)
}

void Etude::sauverEtude(const QString& cheminFichierEtude)
{
    // TODO void Etude::sauverEtude(const QString& cheminFichierEtude)
}

void Etude::exporterListeDePoints(const QString& cheminFichierExport)
{
    // TODO void Etude::exporterListeDePoints(const QString& cheminFichierExport)
}

void Etude::exporterImageConvertie(const QString& cheminFichierImage)
{
    // TODO void Etude::exporterImageConvertie(const QString& cheminFichierImage)
}

void Etude::rechercherCourbe(const QPoint& pointPixelDepart, const QPoint& pointPixelArrivee)
{
    // TODO void Etude::rechercherCourbe(const QPoint& pointPixelDepart, const QPoint& pointPixelArrivee)
}

void Etude::rechercherPointsProches(const QPoint& pointPixel)
{
    // TODO void Etude::rechercherPointsProches(const QPoint& pointPixel)
}

void Etude::filterListeDePoints(const QList<QPoint>& listeDePoints)
{
    // TODO void Etude::filterListeDePoints(const QList<QPoint> listeDePoints)
}
