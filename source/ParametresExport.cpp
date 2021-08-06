//==============================================================================
// Name        : ParametresExport.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the ParametresExport class
//==============================================================================

#include "ParametresExport.h"
#include "Outils.h"
#include <QStringList>

using FormatNotationNombres = ParametresExport::FormatNotationNombres;
using CaractereSeparation = ParametresExport::CaractereSeparation;
using CaractereSeparateurDecimal = ParametresExport::CaractereSeparateurDecimal;

const FormatNotationNombres ParametresExport::formatNotationNombresDefaut;
const int ParametresExport::nombreChiffresSignificatifsDefaut;
const CaractereSeparation ParametresExport::caractereSeparationDefaut;
const CaractereSeparateurDecimal ParametresExport::caractereSeparateurDecimalDefaut;
constexpr double ParametresExport::seuilInterpolationNumeriqueDefaut;

const QMap<FormatNotationNombres, QChar> ParametresExport::_formatNotationNombresCaractere = QMap<
        FormatNotationNombres, QChar>( { { STANDARD, 'f' }, { SCIENTIFIQUE, 'e' } });
const QMap<FormatNotationNombres, QString> ParametresExport::_formatNotationNombresTexte = QMap<
        FormatNotationNombres, QString>( { { STANDARD, QString::fromUtf8("Standard") }, {
        SCIENTIFIQUE, QString::fromUtf8("Scientifique") } });
const QMap<CaractereSeparation, QChar> ParametresExport::_caractereSeparationCaractere = QMap<
        CaractereSeparation, QChar>(
        { { ESPACE, ' ' }, { TABULATION, '\t' }, { POINT_VIRGULE, ';' } });
const QMap<CaractereSeparation, QString> ParametresExport::_caractereSeparationTexte = QMap<
        CaractereSeparation, QString>( { { ESPACE, QString::fromUtf8("Espace") }, { TABULATION,
        QString::fromUtf8("Tabulation") }, { POINT_VIRGULE, QString::fromUtf8("Point-virgule") } });
const QMap<CaractereSeparateurDecimal, QChar> ParametresExport::_caractereSeparateurDecimalCaractere =
        QMap<CaractereSeparateurDecimal, QChar>( { { POINT, '.' }, { VIRGULE, ',' } });
const QMap<CaractereSeparateurDecimal, QString> ParametresExport::_caractereSeparateurDecimalTexte =
        QMap<CaractereSeparateurDecimal, QString>( { { POINT, QString::fromUtf8("Point") }, {
                VIRGULE, QString::fromUtf8("Virgule") } });

ParametresExport::ParametresExport(const FormatNotationNombres& formatNotationNombres,
        const int& nombreChiffresSignificatifs, const CaractereSeparation& caractereSeparation,
        const CaractereSeparateurDecimal& caractereSeparateurDecimal,
        const double& seuilInterpolationNumerique) :
        _formatNotationNombres(formatNotationNombres),
                _nombreChiffresSignificatifs(nombreChiffresSignificatifs),
                _caractereSeparation(caractereSeparation),
                _caractereSeparateurDecimal(caractereSeparateurDecimal),
                _seuilInterpolationNumerique(seuilInterpolationNumerique)
{
}

const FormatNotationNombres& ParametresExport::getFormatNotationNombres() const
{
    return _formatNotationNombres;
}

const int& ParametresExport::getNombreChiffresSignificatifs() const
{
    return _nombreChiffresSignificatifs;
}

const CaractereSeparation& ParametresExport::getCaractereSeparation() const
{
    return _caractereSeparation;
}

const CaractereSeparateurDecimal& ParametresExport::getCaractereSeparateurDecimal() const
{
    return _caractereSeparateurDecimal;
}

const double& ParametresExport::getSeuilInterpolationNumerique() const
{
    return _seuilInterpolationNumerique;
}

void ParametresExport::setFormatNotationNombres(const FormatNotationNombres& formatNotationNombres)
{
    _formatNotationNombres = formatNotationNombres;
}

void ParametresExport::setNombreChiffresSignificatifs(const int& nombreChiffresSignificatifs)
{
    _nombreChiffresSignificatifs = nombreChiffresSignificatifs;
}

void ParametresExport::setCaractereSeparation(const CaractereSeparation& caractereSeparation)
{
    _caractereSeparation = caractereSeparation;
}

void ParametresExport::setCaractereSeparateurDecimal(
        const CaractereSeparateurDecimal& caractereSeparateurDecimal)
{
    _caractereSeparateurDecimal = caractereSeparateurDecimal;
}

void ParametresExport::setSeuilInterpolationNumerique(const double& seuilInterpolationNumerique)
{
    _seuilInterpolationNumerique = seuilInterpolationNumerique;
}

void ParametresExport::clear()
{
    *this = ParametresExport();
}

void ParametresExport::set(const FormatNotationNombres& formatNotationNombres,
        const int& nombreChiffresSignificatifs, const CaractereSeparation& caractereSeparation,
        const CaractereSeparateurDecimal& caractereSeparateurDecimal,
        const double& seuilInterpolationNumerique)
{
    setFormatNotationNombres(formatNotationNombres);
    setNombreChiffresSignificatifs(nombreChiffresSignificatifs);
    setCaractereSeparation(caractereSeparation);
    setCaractereSeparateurDecimal(caractereSeparateurDecimal);
    setSeuilInterpolationNumerique(seuilInterpolationNumerique);
}

void ParametresExport::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    setFormatNotationNombres(static_cast<FormatNotationNombres>(fromStringList.at(0).toInt()));
    setNombreChiffresSignificatifs(fromStringList.at(1).toInt());
    setCaractereSeparation(static_cast<CaractereSeparation>(fromStringList.at(2).toInt()));
    setCaractereSeparateurDecimal(
            static_cast<CaractereSeparateurDecimal>(fromStringList.at(3).toInt()));
    setSeuilInterpolationNumerique(fromStringList.at(4).toDouble());
}

const QString ParametresExport::toString(const QChar& sep) const
{
    QString toString;
    toString += QString::number(getFormatNotationNombres()) + sep;
    toString += QString::number(getNombreChiffresSignificatifs()) + sep;
    toString += QString::number(getCaractereSeparation()) + sep;
    toString += QString::number(getCaractereSeparateurDecimal()) + sep;
    toString += QString::number(getSeuilInterpolationNumerique());
    return toString;
}

const QChar ParametresExport::getFormatNotationNombresCaractere() const
{
    return _formatNotationNombresCaractere.value(getFormatNotationNombres());
}

const QString ParametresExport::getFormatNotationNombresTexte() const
{
    return _formatNotationNombresTexte.value(getFormatNotationNombres());
}

const QChar ParametresExport::getCaractereSeparationCaractere() const
{
    return _caractereSeparationCaractere.value(getCaractereSeparation());
}

const QString ParametresExport::getCaractereSeparationTexte() const
{
    return _caractereSeparationTexte.value(getCaractereSeparation());
}

const QChar ParametresExport::getCaractereSeparateurDecimalCaractere() const
{
    return _caractereSeparateurDecimalCaractere.value(getCaractereSeparateurDecimal());
}

const QString ParametresExport::getCaractereSeparateurDecimalTexte() const
{
    return _caractereSeparateurDecimalTexte.value(getCaractereSeparateurDecimal());
}

void ParametresExport::setFormatNotationNombresCaractere(
        const QChar& formatNotationNombresCaractere)
{
    setFormatNotationNombres(_formatNotationNombresCaractere.key(formatNotationNombresCaractere));
}

void ParametresExport::setFormatNotationNombresTexte(const QString& formatNotationNombresTexte)
{
    setFormatNotationNombres(_formatNotationNombresTexte.key(formatNotationNombresTexte));
}

void ParametresExport::setCaractereSeparationCaractere(const QChar& caractereSeparationCaractere)
{
    setCaractereSeparation(_caractereSeparationCaractere.key(caractereSeparationCaractere));
}

void ParametresExport::setCaractereSeparationTexte(const QString& caractereSeparationTexte)
{
    setCaractereSeparation(_caractereSeparationTexte.key(caractereSeparationTexte));
}

void ParametresExport::setCaractereSeparateurDecimalCaractere(
        const QChar& caractereSeparateurDecimalCaractere)
{
    setCaractereSeparateurDecimal(
            _caractereSeparateurDecimalCaractere.key(caractereSeparateurDecimalCaractere));
}

void ParametresExport::setCaractereSeparateurDecimalTexte(
        const QString& caractereSeparateurDecimalTexte)
{
    setCaractereSeparateurDecimal(
            _caractereSeparateurDecimalTexte.key(caractereSeparateurDecimalTexte));
}
