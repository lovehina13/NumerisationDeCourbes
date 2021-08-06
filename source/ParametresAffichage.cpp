//==============================================================================
// Name        : ParametresAffichage.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the ParametresAffichage class
//==============================================================================

#include "ParametresAffichage.h"
#include "Outils.h"
#include <QStringList>

using FormatNotationNombres = ParametresAffichage::FormatNotationNombres;

const FormatNotationNombres ParametresAffichage::formatNotationNombresDefaut;
const int ParametresAffichage::nombreChiffresSignificatifsDefaut;
const ParametresTrait ParametresAffichage::parametresAxesDefaut = ParametresTrait(
        ParametresTrait::styleTraitDefaut, ParametresTrait::epaisseurTraitDefaut,
        ParametresTrait::couleurTraitAxeDefaut);
const ParametresTrait ParametresAffichage::parametresCourbesDefaut = ParametresTrait(
        ParametresTrait::styleTraitDefaut, ParametresTrait::epaisseurTraitDefaut,
        ParametresTrait::couleurTraitCourbeDefaut);
const ParametresPoint ParametresAffichage::parametresPointsAxesDefaut = ParametresPoint(
        ParametresPoint::stylePointDefaut, ParametresPoint::epaisseurPointDefaut,
        ParametresPoint::couleurPointAxeDefaut);
const ParametresPoint ParametresAffichage::parametresPointsCourbesDefaut = ParametresPoint(
        ParametresPoint::stylePointDefaut, ParametresPoint::epaisseurPointDefaut,
        ParametresPoint::couleurPointCourbeDefaut);
const ParametresPoint ParametresAffichage::parametresPointsManuelsDefaut = ParametresPoint(
        ParametresPoint::stylePointDefaut, ParametresPoint::epaisseurPointDefaut,
        ParametresPoint::couleurPointManuelDefaut);

const QMap<FormatNotationNombres, QChar> ParametresAffichage::_formatNotationNombresCaractere =
        QMap<FormatNotationNombres, QChar>( { { STANDARD, 'f' }, { SCIENTIFIQUE, 'e' } });
const QMap<FormatNotationNombres, QString> ParametresAffichage::_formatNotationNombresTexte = QMap<
        FormatNotationNombres, QString>( { { STANDARD, QString::fromUtf8("Standard") }, {
        SCIENTIFIQUE, QString::fromUtf8("Scientifique") } });

ParametresAffichage::ParametresAffichage(const FormatNotationNombres& formatNotationNombres,
        const int& nombreChiffresSignificatifs, const ParametresTrait& parametresAxes,
        const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsAxes,
        const ParametresPoint& parametresPointsCourbes,
        const ParametresPoint& parametresPointsManuels) :
        _formatNotationNombres(formatNotationNombres),
                _nombreChiffresSignificatifs(nombreChiffresSignificatifs),
                _parametresAxes(parametresAxes), _parametresCourbes(parametresCourbes),
                _parametresPointsAxes(parametresPointsAxes),
                _parametresPointsCourbes(parametresPointsCourbes),
                _parametresPointsManuels(parametresPointsManuels)
{
}

const FormatNotationNombres& ParametresAffichage::getFormatNotationNombres() const
{
    return _formatNotationNombres;
}

const int& ParametresAffichage::getNombreChiffresSignificatifs() const
{
    return _nombreChiffresSignificatifs;
}

const ParametresTrait& ParametresAffichage::getParametresAxes() const
{
    return _parametresAxes;
}

const ParametresTrait& ParametresAffichage::getParametresCourbes() const
{
    return _parametresCourbes;
}

const ParametresPoint& ParametresAffichage::getParametresPointsAxes() const
{
    return _parametresPointsAxes;
}

const ParametresPoint& ParametresAffichage::getParametresPointsCourbes() const
{
    return _parametresPointsCourbes;
}

const ParametresPoint& ParametresAffichage::getParametresPointsManuels() const
{
    return _parametresPointsManuels;
}

void ParametresAffichage::setFormatNotationNombres(
        const FormatNotationNombres& formatNotationNombres)
{
    _formatNotationNombres = formatNotationNombres;
}

void ParametresAffichage::setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs)
{
    _nombreChiffresSignificatifs = nombreChiffresSignificatifs;
}

void ParametresAffichage::setParametresAxes(const ParametresTrait& parametresAxes)
{
    _parametresAxes = parametresAxes;
}

void ParametresAffichage::setParametresCourbes(const ParametresTrait& parametresCourbes)
{
    _parametresCourbes = parametresCourbes;
}

void ParametresAffichage::setParametresPointsAxes(const ParametresPoint& parametresPointsAxes)
{
    _parametresPointsAxes = parametresPointsAxes;
}

void ParametresAffichage::setParametresPointsCourbes(const ParametresPoint& parametresPointsCourbes)
{
    _parametresPointsCourbes = parametresPointsCourbes;
}

void ParametresAffichage::setParametresPointsManuels(const ParametresPoint& parametresPointsManuels)
{
    _parametresPointsManuels = parametresPointsManuels;
}

void ParametresAffichage::clear()
{
    *this = ParametresAffichage();
}

void ParametresAffichage::set(const FormatNotationNombres& formatNotationNombres,
        const int& nombreChiffresSignificatifs, const ParametresTrait& parametresAxes,
        const ParametresTrait& parametresCourbes, const ParametresPoint& parametresPointsAxes,
        const ParametresPoint& parametresPointsCourbes,
        const ParametresPoint& parametresPointsManuels)
{
    setFormatNotationNombres(formatNotationNombres);
    setNombreChiffresSignificatifs(nombreChiffresSignificatifs);
    setParametresAxes(parametresAxes);
    setParametresCourbes(parametresCourbes);
    setParametresPointsAxes(parametresPointsAxes);
    setParametresPointsCourbes(parametresPointsCourbes);
    setParametresPointsManuels(parametresPointsManuels);
}

void ParametresAffichage::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    ParametresTrait parametresAxes = getParametresAxes();
    ParametresTrait parametresCourbes = getParametresCourbes();
    ParametresPoint parametresPointsAxes = getParametresPointsAxes();
    ParametresPoint parametresPointsCourbes = getParametresPointsCourbes();
    ParametresPoint parametresPointsManuels = getParametresPointsManuels();
    parametresAxes.fromString(fromStringList.at(2), sep);
    parametresCourbes.fromString(fromStringList.at(3), sep);
    parametresPointsAxes.fromString(fromStringList.at(4), sep);
    parametresPointsCourbes.fromString(fromStringList.at(5), sep);
    parametresPointsManuels.fromString(fromStringList.at(6), sep);
    setFormatNotationNombres(static_cast<FormatNotationNombres>(fromStringList.at(0).toInt()));
    setNombreChiffresSignificatifs(fromStringList.at(1).toInt());
    setParametresAxes(parametresAxes);
    setParametresCourbes(parametresCourbes);
    setParametresPointsAxes(parametresPointsAxes);
    setParametresPointsCourbes(parametresPointsCourbes);
    setParametresPointsManuels(parametresPointsManuels);
}

const QString ParametresAffichage::toString(const QChar& sep) const
{
    QString toString;
    toString += QString::number(getFormatNotationNombres()) + sep;
    toString += QString::number(getNombreChiffresSignificatifs()) + sep;
    toString += QString("(%1)").arg(getParametresAxes().toString(sep)) + sep;
    toString += QString("(%1)").arg(getParametresCourbes().toString(sep)) + sep;
    toString += QString("(%1)").arg(getParametresPointsAxes().toString(sep)) + sep;
    toString += QString("(%1)").arg(getParametresPointsCourbes().toString(sep)) + sep;
    toString += QString("(%1)").arg(getParametresPointsManuels().toString(sep));
    return toString;
}

const QChar ParametresAffichage::getFormatNotationNombresCaractere() const
{
    return _formatNotationNombresCaractere.value(getFormatNotationNombres());
}

const QString ParametresAffichage::getFormatNotationNombresTexte() const
{
    return _formatNotationNombresTexte.value(getFormatNotationNombres());
}

void ParametresAffichage::setFormatNotationNombresCaractere(
        const QChar& formatNotationNombresCaractere)
{
    setFormatNotationNombres(_formatNotationNombresCaractere.key(formatNotationNombresCaractere));
}

void ParametresAffichage::setFormatNotationNombresTexte(const QString& formatNotationNombresTexte)
{
    setFormatNotationNombres(_formatNotationNombresTexte.key(formatNotationNombresTexte));
}
