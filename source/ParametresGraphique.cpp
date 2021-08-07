//==============================================================================
// Name        : ParametresGraphique.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.3.0 (07/08/2021)
// Description : Source file of the ParametresGraphique class
//==============================================================================

#include "ParametresGraphique.h"
#include "Outils.h"
#include <QStringList>

ParametresGraphique::ParametresGraphique(const ParametresAxe& parametresAxeHorizontal,
        const ParametresAxe& parametresAxeVertical) :
        _parametresAxeHorizontal(parametresAxeHorizontal),
                _parametresAxeVertical(parametresAxeVertical)
{
}

const ParametresAxe& ParametresGraphique::getParametresAxeHorizontal() const
{
    return _parametresAxeHorizontal;
}

const ParametresAxe& ParametresGraphique::getParametresAxeVertical() const
{
    return _parametresAxeVertical;
}

void ParametresGraphique::setParametresAxeHorizontal(const ParametresAxe& parametresAxeHorizontal)
{
    _parametresAxeHorizontal = parametresAxeHorizontal;
}

void ParametresGraphique::setParametresAxeVertical(const ParametresAxe& parametresAxeVertical)
{
    _parametresAxeVertical = parametresAxeVertical;
}

void ParametresGraphique::clear()
{
    *this = ParametresGraphique();
}

void ParametresGraphique::set(const ParametresAxe& parametresAxeHorizontal,
        const ParametresAxe& parametresAxeVertical)
{
    setParametresAxeHorizontal(parametresAxeHorizontal);
    setParametresAxeVertical(parametresAxeVertical);
}

void ParametresGraphique::fromString(const QString& fromString, const QChar& sep)
{
    const QStringList fromStringList = listeSousElements(fromString, sep);
    ParametresAxe parametresAxeHorizontal = getParametresAxeHorizontal();
    ParametresAxe parametresAxeVertical = getParametresAxeVertical();
    parametresAxeHorizontal.fromString(fromStringList.at(0), sep);
    parametresAxeVertical.fromString(fromStringList.at(1), sep);
    setParametresAxeHorizontal(parametresAxeHorizontal);
    setParametresAxeVertical(parametresAxeVertical);
}

const QString ParametresGraphique::toString(const QChar& sep) const
{
    QString toString;
    toString += QString("(%1)").arg(getParametresAxeHorizontal().toString(sep)) + sep;
    toString += QString("(%1)").arg(getParametresAxeVertical().toString(sep));
    return toString;
}
