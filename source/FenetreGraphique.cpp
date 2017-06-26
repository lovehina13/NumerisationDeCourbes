//==============================================================================
// Name        : FenetreGraphique.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.5 (07/06/2017)
// Description : Source file of the FenetreGraphique class
//==============================================================================

#include "FenetreGraphique.h"
#include "ui_FenetreGraphique.h"
#include "ParametresAxe.h"
#include <QDialogButtonBox>
#include <QDoubleValidator>
#include <QPushButton>
#include <QString>
#if ENABLE_QWT
#include <QBrush>
#include <QColor>
#include <QPen>
#include <QPointF>
#include <QVector>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_marker.h>
#include <qwt_series_data.h>
#include <qwt_symbol.h>
#endif

FenetreGraphique::FenetreGraphique(QWidget* parent) :
        QDialog(parent), ui(new Ui::FenetreGraphique)
{
    this->ui->setupUi(this);

#if ENABLE_QWT
    this->ui->widgetGraphique = new QwtPlot(this);
    this->ui->gridLayoutFenetreGraphique->addWidget(this->ui->widgetGraphique, 1, 0, 1, 1);
#endif

    this->initialiserElementsGraphiques();
    this->actualiserElementsGraphiques();
}

FenetreGraphique::~FenetreGraphique()
{
    delete this->ui;
}

const QList<Courbe>& FenetreGraphique::getListeDeCourbes() const
{
    return this->listeDeCourbes;
}

const QList<Point>& FenetreGraphique::getListeDePointsManuels() const
{
    return this->listeDePointsManuels;
}

const ParametresGraphique& FenetreGraphique::getParametresGraphique() const
{
    return this->parametresGraphique;
}

const ParametresAffichage& FenetreGraphique::getParametresAffichage() const
{
    return this->parametresAffichage;
}

void FenetreGraphique::setListeDeCourbes(const QList<Courbe>& listeDeCourbes)
{
    this->listeDeCourbes = listeDeCourbes;
}

void FenetreGraphique::setListeDePointsManuels(const QList<Point>& listeDePointsManuels)
{
    this->listeDePointsManuels = listeDePointsManuels;
}

void FenetreGraphique::setParametresGraphique(const ParametresGraphique& parametresGraphique)
{
    this->parametresGraphique = parametresGraphique;
}

void FenetreGraphique::setParametresAffichage(const ParametresAffichage& parametresAffichage)
{
    this->parametresAffichage = parametresAffichage;
}

void FenetreGraphique::initialiserElementsGraphiques()
{
    const QDoubleValidator* nombreReel = new QDoubleValidator(this);
    this->ui->lineEditAxeHorizontalBorneInferieure->setValidator(nombreReel);
    this->ui->lineEditAxeHorizontalBorneSuperieure->setValidator(nombreReel);
    this->ui->lineEditAxeHorizontalPasPrincipal->setValidator(nombreReel);
    this->ui->lineEditAxeHorizontalPasSecondaire->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalBorneInferieure->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalBorneSuperieure->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalPasPrincipal->setValidator(nombreReel);
    this->ui->lineEditAxeVerticalPasSecondaire->setValidator(nombreReel);
    this->ui->buttonBox->button(QDialogButtonBox::Save)->setText("Enregistrer");
}

void FenetreGraphique::actualiserElementsGraphiques()
{
    const ParametresAxe& parametresAxeHorizontal =
            this->parametresGraphique.getParametresAxeHorizontal();
    const ParametresAxe& parametresAxeVertical =
            this->parametresGraphique.getParametresAxeVertical();

    this->ui->lineEditAxeHorizontalBorneInferieure->setText(
            QString::number(parametresAxeHorizontal.getBorneInferieure()));
    this->ui->lineEditAxeHorizontalBorneSuperieure->setText(
            QString::number(parametresAxeHorizontal.getBorneSuperieure()));
    this->ui->lineEditAxeHorizontalPasPrincipal->setText(
            QString::number(parametresAxeHorizontal.getPasPrincipal()));
    this->ui->lineEditAxeHorizontalPasSecondaire->setText(
            QString::number(parametresAxeHorizontal.getPasSecondaire()));
    this->ui->checkBoxAxeHorizontalGrillePrincipale->setChecked(
            parametresAxeHorizontal.getGrillePrincipale());
    this->ui->checkBoxAxeHorizontalGrilleSecondaire->setChecked(
            parametresAxeHorizontal.getGrilleSecondaire());
    this->ui->lineEditAxeVerticalBorneInferieure->setText(
            QString::number(parametresAxeVertical.getBorneInferieure()));
    this->ui->lineEditAxeVerticalBorneSuperieure->setText(
            QString::number(parametresAxeVertical.getBorneSuperieure()));
    this->ui->lineEditAxeVerticalPasPrincipal->setText(
            QString::number(parametresAxeVertical.getPasPrincipal()));
    this->ui->lineEditAxeVerticalPasSecondaire->setText(
            QString::number(parametresAxeVertical.getPasSecondaire()));
    this->ui->checkBoxAxeVerticalGrillePrincipale->setChecked(
            parametresAxeVertical.getGrillePrincipale());
    this->ui->checkBoxAxeVerticalGrilleSecondaire->setChecked(
            parametresAxeVertical.getGrilleSecondaire());

    this->dessinerGraphique();
}

void FenetreGraphique::effacerGraphique()
{
#if ENABLE_QWT
    QwtPlot* graphique = (QwtPlot*) this->ui->widgetGraphique;

    const QColor couleurArrierePlan = QColor(Qt::white);
    const QBrush brosseArrierePlan = QBrush(couleurArrierePlan, Qt::SolidPattern);
    graphique->detachItems();
    graphique->setCanvasBackground(brosseArrierePlan);

    graphique->replot();
#endif
}

void FenetreGraphique::dessinerGraphique()
{
    const QList<Courbe>& listeDeCourbes = this->getListeDeCourbes();
    const QList<Point>& listeDePointsManuels = this->getListeDePointsManuels();
    const int nombreDeCourbes = listeDeCourbes.count();
    const int nombreDePointsManuels = listeDePointsManuels.count();

    this->effacerGraphique();
    this->dessinerRepereGraphique();
    this->dessinerGrilleGraphique();
    for (int itCourbe = 0; itCourbe < nombreDeCourbes; itCourbe++)
    {
        const Courbe& courbe = listeDeCourbes.at(itCourbe);
        this->dessinerCourbeGraphique(courbe);
    }
    for (int itPointManuel = 0; itPointManuel < nombreDePointsManuels; itPointManuel++)
    {
        const Point& pointManuel = listeDePointsManuels.at(itPointManuel);
        this->dessinerPointManuelGraphique(pointManuel);
    }
}

void FenetreGraphique::dessinerRepereGraphique()
{
#if ENABLE_QWT
    QwtPlot* graphique = (QwtPlot*) this->ui->widgetGraphique;

    const ParametresAxe& parametresAxeHorizontal =
            this->parametresGraphique.getParametresAxeHorizontal();
    const ParametresAxe& parametresAxeVertical =
            this->parametresGraphique.getParametresAxeVertical();

    graphique->setAxisScale(QwtPlot::xBottom, parametresAxeHorizontal.getBorneInferieure(),
            parametresAxeHorizontal.getBorneSuperieure(), 0);
    graphique->setAxisScale(QwtPlot::yLeft, parametresAxeVertical.getBorneInferieure(),
            parametresAxeVertical.getBorneSuperieure(), 0);
    // TODO Affectation du pas principal
    // TODO Affectation du pas secondaire
    // TODO Paramètres d'affichage des axes

    graphique->replot();
#endif
}

void FenetreGraphique::dessinerGrilleGraphique()
{
#if ENABLE_QWT
    QwtPlot* graphique = (QwtPlot*) this->ui->widgetGraphique;

    const ParametresAxe& parametresAxeHorizontal =
            this->parametresGraphique.getParametresAxeHorizontal();
    const ParametresAxe& parametresAxeVertical =
            this->parametresGraphique.getParametresAxeVertical();

    QwtPlotGrid* grille = new QwtPlotGrid();
    const QColor couleurGrillePrincipale = QColor(Qt::black);
    const QColor couleurGrilleSecondaire = QColor(Qt::gray);
    const QBrush brosseGrillePrincipale = QBrush(couleurGrillePrincipale, Qt::SolidPattern);
    const QBrush brosseGrilleSecondaire = QBrush(couleurGrilleSecondaire, Qt::SolidPattern);
    const QPen pinceauGrillePrincipale = QPen(brosseGrillePrincipale, 1, Qt::DotLine);
    const QPen pinceauGrilleSecondaire = QPen(brosseGrilleSecondaire, 1, Qt::DotLine);
    grille->enableX(parametresAxeHorizontal.getGrillePrincipale());
    grille->enableXMin(parametresAxeHorizontal.getGrilleSecondaire());
    grille->enableY(parametresAxeVertical.getGrillePrincipale());
    grille->enableYMin(parametresAxeVertical.getGrilleSecondaire());
    grille->setMajorPen(pinceauGrillePrincipale);
    grille->setMinorPen(pinceauGrilleSecondaire);
    grille->attach(graphique);

    graphique->replot();
#endif
}

void FenetreGraphique::dessinerCourbeGraphique(const Courbe& courbe)
{
#if ENABLE_QWT
    QwtPlot* graphique = (QwtPlot*) this->ui->widgetGraphique;

    QwtPlotCurve* courbeGraphique = new QwtPlotCurve();
    QwtPointSeriesData* donneesCourbe = new QwtPointSeriesData();
    QVector<QPointF>* donneesPointsCourbe = new QVector<QPointF>();
    const int nombreDePointsCourbe = courbe.count();
    for (int itPointCourbe = 0; itPointCourbe < nombreDePointsCourbe; itPointCourbe++)
    {
        const Point& pointCourbe = courbe.at(itPointCourbe);
        donneesPointsCourbe->push_back(pointCourbe.getPointReel());
    }
    donneesCourbe->setSamples(*donneesPointsCourbe);
    courbeGraphique->setData(donneesCourbe);
    courbeGraphique->attach(graphique);
    // TODO Paramètres d'affichage des courbes

    QwtPlotMarker* premierPointGraphique = new QwtPlotMarker();
    QwtSymbol* symbolePremierPointGraphique = new QwtSymbol();
    const Point& premierPoint = courbe.at(0);
    premierPointGraphique->setSymbol(symbolePremierPointGraphique);
    premierPointGraphique->setValue(premierPoint.getPointReelX(), premierPoint.getPointReelY());
    premierPointGraphique->attach(graphique);
    // TODO Paramètres d'affichage des points

    QwtPlotMarker* dernierPointGraphique = new QwtPlotMarker();
    QwtSymbol* symboleDernierPointGraphique = new QwtSymbol();
    const Point& dernierPoint = courbe.at(nombreDePointsCourbe - 1);
    dernierPointGraphique->setSymbol(symboleDernierPointGraphique);
    dernierPointGraphique->setValue(dernierPoint.getPointReelX(), dernierPoint.getPointReelY());
    dernierPointGraphique->attach(graphique);
    // TODO Paramètres d'affichage des points

    graphique->replot();
#endif
}

void FenetreGraphique::dessinerPointManuelGraphique(const Point& pointManuel)
{
#if ENABLE_QWT
    QwtPlot* graphique = (QwtPlot*) this->ui->widgetGraphique;

    QwtPlotMarker* pointManuelGraphique = new QwtPlotMarker();
    QwtSymbol* symbolePointManuelGraphique = new QwtSymbol();
    pointManuelGraphique->setSymbol(symbolePointManuelGraphique);
    pointManuelGraphique->setValue(pointManuel.getPointReelX(), pointManuel.getPointReelY());
    pointManuelGraphique->attach(graphique);
    // TODO Paramètres d'affichage des points

    graphique->replot();
#endif
}

void FenetreGraphique::on_lineEditAxeHorizontalBorneInferieure_textChanged()
{
    ParametresAxe parametresAxeHorizontal = this->parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setBorneInferieure(
            this->ui->lineEditAxeHorizontalBorneInferieure->text().toDouble());
    this->parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    this->dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeHorizontalBorneSuperieure_textChanged()
{
    ParametresAxe parametresAxeHorizontal = this->parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setBorneSuperieure(
            this->ui->lineEditAxeHorizontalBorneSuperieure->text().toDouble());
    this->parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    this->dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeHorizontalPasPrincipal_textChanged()
{
    ParametresAxe parametresAxeHorizontal = this->parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setPasPrincipal(
            this->ui->lineEditAxeHorizontalPasPrincipal->text().toDouble());
    this->parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    this->dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeHorizontalPasSecondaire_textChanged()
{
    ParametresAxe parametresAxeHorizontal = this->parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setPasSecondaire(
            this->ui->lineEditAxeHorizontalPasSecondaire->text().toDouble());
    this->parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    this->dessinerGraphique();
}

void FenetreGraphique::on_checkBoxAxeHorizontalGrillePrincipale_stateChanged()
{
    ParametresAxe parametresAxeHorizontal = this->parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setGrillePrincipale(
            this->ui->checkBoxAxeHorizontalGrillePrincipale->isChecked());
    this->parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    this->dessinerGraphique();
}

void FenetreGraphique::on_checkBoxAxeHorizontalGrilleSecondaire_stateChanged()
{
    ParametresAxe parametresAxeHorizontal = this->parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setGrilleSecondaire(
            this->ui->checkBoxAxeHorizontalGrilleSecondaire->isChecked());
    this->parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    this->dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeVerticalBorneInferieure_textChanged()
{
    ParametresAxe parametresAxeVertical = this->parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setBorneInferieure(
            this->ui->lineEditAxeVerticalBorneInferieure->text().toDouble());
    this->parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    this->dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeVerticalBorneSuperieure_textChanged()
{
    ParametresAxe parametresAxeVertical = this->parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setBorneSuperieure(
            this->ui->lineEditAxeVerticalBorneSuperieure->text().toDouble());
    this->parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    this->dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeVerticalPasPrincipal_textChanged()
{
    ParametresAxe parametresAxeVertical = this->parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setPasPrincipal(
            this->ui->lineEditAxeVerticalPasPrincipal->text().toDouble());
    this->parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    this->dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeVerticalPasSecondaire_textChanged()
{
    ParametresAxe parametresAxeVertical = this->parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setPasSecondaire(
            this->ui->lineEditAxeVerticalPasSecondaire->text().toDouble());
    this->parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    this->dessinerGraphique();
}

void FenetreGraphique::on_checkBoxAxeVerticalGrillePrincipale_stateChanged()
{
    ParametresAxe parametresAxeVertical = this->parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setGrillePrincipale(
            this->ui->checkBoxAxeVerticalGrillePrincipale->isChecked());
    this->parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    this->dessinerGraphique();
}

void FenetreGraphique::on_checkBoxAxeVerticalGrilleSecondaire_stateChanged()
{
    ParametresAxe parametresAxeVertical = this->parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setGrilleSecondaire(
            this->ui->checkBoxAxeVerticalGrilleSecondaire->isChecked());
    this->parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    this->dessinerGraphique();
}
