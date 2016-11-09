//==============================================================================
// Name        : Outils.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (27/04/2016)
// Description : Header file of the Outils elements
//==============================================================================

#ifndef OUTILS_H_
#define OUTILS_H_

#include "Point.h"
#include <QList>
#include <QString>
#include <QStringList>

QStringList listeSousElements(const QString& chaineElements, const char& sep);
void interpolationNumerique(const double& x1, const double& y1, const double& x2, const double& y2,
        const double& x, double& y);
void interpolationNumerique(const Point& point1, const Point& point2, Point& point);
QList<Point> interpolationNumerique(const QList<Point>& listeDePoints, const double& pas);
void genererImageTest();
void testerConversionNoirEtBlanc(const int& seuilNoirEtBlanc);
void testerConversionNiveauxDeGris(const int& nombreNiveauxDeGris);
void testerConversionTeintesSaturees(const int& nombreNiveauxDeGris,
        const int& nombreTeintesSaturees, const int& seuilSaturation);

#endif /* OUTILS_H_ */
