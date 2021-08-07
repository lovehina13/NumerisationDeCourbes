//==============================================================================
// Name        : FenetreGraphique.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the FenetreGraphique class
//==============================================================================

#include "FenetreGraphique.h"
#include "ui_FenetreGraphique.h"
#include "ParametresAxe.h"
#include <QDialogButtonBox>
#include <QDoubleValidator>
#include <QFile>
#include <QFileDialog>
#include <QIODevice>
#include <QPushButton>
#include <QString>
#ifdef ENABLE_QWT
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QPalette>
#include <QPen>
#include <QPixmap>
#include <QPoint>
#include <QPointF>
#include <QRect>
#include <QRgb>
#include <QSize>
#include <QVector>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_marker.h>
#include <qwt_scale_draw.h>
#include <qwt_scale_widget.h>
#include <qwt_series_data.h>
#include <qwt_symbol.h>
#endif

FenetreGraphique::FenetreGraphique(QWidget* parent) :
        QDialog(parent), _ui(new Ui::FenetreGraphique)
{
    _ui->setupUi(this);

#ifdef ENABLE_QWT
    _ui->widgetGraphique = new QwtPlot(this);
    _ui->gridLayoutFenetreGraphique->addWidget(_ui->widgetGraphique, 1, 0, 1, 1);
#endif

    initialiserElementsGraphiques();
    actualiserElementsGraphiques();
}

FenetreGraphique::~FenetreGraphique()
{
    delete _ui;
}

const QList<Courbe>& FenetreGraphique::getListeDeCourbes() const
{
    return _listeDeCourbes;
}

const QList<Point>& FenetreGraphique::getListeDePointsManuels() const
{
    return _listeDePointsManuels;
}

const ParametresGraphique& FenetreGraphique::getParametresGraphique() const
{
    return _parametresGraphique;
}

const ParametresAffichage& FenetreGraphique::getParametresAffichage() const
{
    return _parametresAffichage;
}

const ParametresFichiers& FenetreGraphique::getParametresFichiers() const
{
    return _parametresFichiers;
}

void FenetreGraphique::setListeDeCourbes(const QList<Courbe>& listeDeCourbes)
{
    _listeDeCourbes = listeDeCourbes;
}

void FenetreGraphique::setListeDePointsManuels(const QList<Point>& listeDePointsManuels)
{
    _listeDePointsManuels = listeDePointsManuels;
}

void FenetreGraphique::setParametresGraphique(const ParametresGraphique& parametresGraphique)
{
    _parametresGraphique = parametresGraphique;
}

void FenetreGraphique::setParametresAffichage(const ParametresAffichage& parametresAffichage)
{
    _parametresAffichage = parametresAffichage;
}

void FenetreGraphique::setParametresFichiers(const ParametresFichiers& parametresFichiers)
{
    _parametresFichiers = parametresFichiers;
}

void FenetreGraphique::initialiserElementsGraphiques()
{
    const QDoubleValidator* nombreReel = new QDoubleValidator(this);
    _ui->lineEditAxeHorizontalBorneInferieure->setValidator(nombreReel);
    _ui->lineEditAxeHorizontalBorneSuperieure->setValidator(nombreReel);
    _ui->lineEditAxeHorizontalPasPrincipal->setValidator(nombreReel);
    _ui->lineEditAxeHorizontalPasSecondaire->setValidator(nombreReel);
    _ui->lineEditAxeVerticalBorneInferieure->setValidator(nombreReel);
    _ui->lineEditAxeVerticalBorneSuperieure->setValidator(nombreReel);
    _ui->lineEditAxeVerticalPasPrincipal->setValidator(nombreReel);
    _ui->lineEditAxeVerticalPasSecondaire->setValidator(nombreReel);
    _ui->buttonBox->button(QDialogButtonBox::Save)->setText("Enregistrer");
}

void FenetreGraphique::actualiserElementsGraphiques()
{
    const ParametresAxe& parametresAxeHorizontal =
            _parametresGraphique.getParametresAxeHorizontal();
    const ParametresAxe& parametresAxeVertical = _parametresGraphique.getParametresAxeVertical();

    _ui->lineEditAxeHorizontalBorneInferieure->setText(
            QString::number(parametresAxeHorizontal.getBorneInferieure()));
    _ui->lineEditAxeHorizontalBorneSuperieure->setText(
            QString::number(parametresAxeHorizontal.getBorneSuperieure()));
    _ui->lineEditAxeHorizontalPasPrincipal->setText(
            QString::number(parametresAxeHorizontal.getPasPrincipal()));
//    ui->lineEditAxeHorizontalPasSecondaire->setText(
//            QString::number(parametresAxeHorizontal.getPasSecondaire()));
    _ui->lineEditAxeHorizontalPasSecondaire->setText(QString::number(0.0));
    _ui->checkBoxAxeHorizontalGrillePrincipale->setChecked(
            parametresAxeHorizontal.getGrillePrincipale());
    _ui->checkBoxAxeHorizontalGrilleSecondaire->setChecked(
            parametresAxeHorizontal.getGrilleSecondaire());
    _ui->lineEditAxeVerticalBorneInferieure->setText(
            QString::number(parametresAxeVertical.getBorneInferieure()));
    _ui->lineEditAxeVerticalBorneSuperieure->setText(
            QString::number(parametresAxeVertical.getBorneSuperieure()));
    _ui->lineEditAxeVerticalPasPrincipal->setText(
            QString::number(parametresAxeVertical.getPasPrincipal()));
//    ui->lineEditAxeVerticalPasSecondaire->setText(
//            QString::number(parametresAxeVertical.getPasSecondaire()));
    _ui->lineEditAxeVerticalPasSecondaire->setText(QString::number(0.0));
    _ui->checkBoxAxeVerticalGrillePrincipale->setChecked(
            parametresAxeVertical.getGrillePrincipale());
    _ui->checkBoxAxeVerticalGrilleSecondaire->setChecked(
            parametresAxeVertical.getGrilleSecondaire());

    dessinerGraphique();
}

void FenetreGraphique::effacerGraphique()
{
#ifdef ENABLE_QWT
    QwtPlot* graphique = dynamic_cast<QwtPlot*>(_ui->widgetGraphique);

    const QColor couleurArrierePlan = QColor(Qt::white);
    const QBrush brosseArrierePlan = QBrush(couleurArrierePlan, Qt::SolidPattern);

    graphique->detachItems();
    graphique->setCanvasBackground(brosseArrierePlan);

    graphique->replot();
#endif
}

void FenetreGraphique::dessinerGraphique()
{
    const QList<Courbe>& listeDeCourbes = getListeDeCourbes();
    const QList<Point>& listeDePointsManuels = getListeDePointsManuels();
    const int nombreDeCourbes = listeDeCourbes.count();
    const int nombreDePointsManuels = listeDePointsManuels.count();

    effacerGraphique();
    dessinerRepereGraphique();
    dessinerGrilleGraphique();
    for (int itCourbe = 0; itCourbe < nombreDeCourbes; itCourbe++)
    {
        const Courbe& courbe = listeDeCourbes.at(itCourbe);
        dessinerCourbe(courbe);
    }
    for (int itPointManuel = 0; itPointManuel < nombreDePointsManuels; itPointManuel++)
    {
        const Point& pointManuel = listeDePointsManuels.at(itPointManuel);
        dessinerPointManuel(pointManuel);
    }
}

void FenetreGraphique::dessinerRepereGraphique()
{
#ifdef ENABLE_QWT
    QwtPlot* graphique = dynamic_cast<QwtPlot*>(_ui->widgetGraphique);

    const ParametresAxe& parametresAxeHorizontal =
            _parametresGraphique.getParametresAxeHorizontal();
    const ParametresAxe& parametresAxeVertical = _parametresGraphique.getParametresAxeVertical();
    const ParametresTrait& parametresAxes = _parametresAffichage.getParametresAxes();

    const int& epaisseurRepere = parametresAxes.getEpaisseurTrait();
    const QRgb& couleurRepere = parametresAxes.getCouleurTrait();
    const QBrush brosseRepere = QBrush(QColor(couleurRepere), Qt::SolidPattern);
    const QwtScaleWidget* axeRepere = new QwtScaleWidget();
    QFont policeRepere = axeRepere->font();
    QPalette paletteRepere = axeRepere->palette();
    policeRepere.setBold(epaisseurRepere > 1);
    paletteRepere.setBrush(QPalette::Text, brosseRepere);
    paletteRepere.setBrush(QPalette::WindowText, brosseRepere);

    graphique->setAxisScale(QwtPlot::xBottom, parametresAxeHorizontal.getBorneInferieure(),
            parametresAxeHorizontal.getBorneSuperieure(),
            parametresAxeHorizontal.getPasPrincipal());
    graphique->setAxisScale(QwtPlot::yLeft, parametresAxeVertical.getBorneInferieure(),
            parametresAxeVertical.getBorneSuperieure(), parametresAxeVertical.getPasPrincipal());

    QwtScaleWidget* axeHorizontalGraphique = graphique->axisWidget(QwtPlot::xBottom);
    QwtScaleDraw* dessinAxeHorizontalGraphique = graphique->axisScaleDraw(QwtPlot::xBottom);
    axeHorizontalGraphique->setFont(policeRepere);
    axeHorizontalGraphique->setPalette(paletteRepere);
    dessinAxeHorizontalGraphique->setPenWidth(epaisseurRepere);

    QwtScaleWidget* axeVerticalGraphique = graphique->axisWidget(QwtPlot::yLeft);
    QwtScaleDraw* dessinAxeVerticalGraphique = graphique->axisScaleDraw(QwtPlot::yLeft);
    axeVerticalGraphique->setFont(policeRepere);
    axeVerticalGraphique->setPalette(paletteRepere);
    dessinAxeVerticalGraphique->setPenWidth(epaisseurRepere);

    graphique->replot();
#endif
}

void FenetreGraphique::dessinerGrilleGraphique()
{
#ifdef ENABLE_QWT
    QwtPlot* graphique = dynamic_cast<QwtPlot*>(_ui->widgetGraphique);

    const ParametresAxe& parametresAxeHorizontal =
            _parametresGraphique.getParametresAxeHorizontal();
    const ParametresAxe& parametresAxeVertical = _parametresGraphique.getParametresAxeVertical();

    const QColor couleurGrillePrincipale = QColor(Qt::black);
    const QColor couleurGrilleSecondaire = QColor(Qt::gray);
    const QBrush brosseGrillePrincipale = QBrush(couleurGrillePrincipale, Qt::SolidPattern);
    const QBrush brosseGrilleSecondaire = QBrush(couleurGrilleSecondaire, Qt::SolidPattern);
    const QPen pinceauGrillePrincipale = QPen(brosseGrillePrincipale, 1, Qt::DotLine);
    const QPen pinceauGrilleSecondaire = QPen(brosseGrilleSecondaire, 1, Qt::DotLine);

    QwtPlotGrid* grilleGraphique = new QwtPlotGrid();
    grilleGraphique->enableX(parametresAxeHorizontal.getGrillePrincipale());
    grilleGraphique->enableXMin(parametresAxeHorizontal.getGrilleSecondaire());
    grilleGraphique->enableY(parametresAxeVertical.getGrillePrincipale());
    grilleGraphique->enableYMin(parametresAxeVertical.getGrilleSecondaire());
    grilleGraphique->setMajorPen(pinceauGrillePrincipale);
    grilleGraphique->setMinorPen(pinceauGrilleSecondaire);
    grilleGraphique->attach(graphique);

    graphique->replot();
#endif
}

void FenetreGraphique::dessinerCourbe(const Courbe& courbe)
{
    const int nombreDePointsCourbe = courbe.count();
    const Point& premierPoint = courbe.at(0);
    const Point& dernierPoint = courbe.at(nombreDePointsCourbe - 1);
    const ParametresTrait& parametresCourbes = _parametresAffichage.getParametresCourbes();
    const ParametresPoint& parametresPointsCourbes =
            _parametresAffichage.getParametresPointsCourbes();

    dessinerCourbeGraphique(courbe, parametresCourbes);
    dessinerPointGraphique(premierPoint, parametresPointsCourbes);
    dessinerPointGraphique(dernierPoint, parametresPointsCourbes);
}

void FenetreGraphique::dessinerPointManuel(const Point& pointManuel)
{
    const ParametresPoint& parametresPointManuels =
            _parametresAffichage.getParametresPointsManuels();

    dessinerPointGraphique(pointManuel, parametresPointManuels);
}

void FenetreGraphique::dessinerCourbeGraphique(const Courbe& courbe,
        const ParametresTrait& parametresCourbe)
{
#ifdef ENABLE_QWT
    QwtPlot* graphique = dynamic_cast<QwtPlot*>(_ui->widgetGraphique);

    const int& styleCourbe = parametresCourbe.getStyleTrait();
    const int& epaisseurCourbe = parametresCourbe.getEpaisseurTrait();
    const QRgb& couleurCourbe = parametresCourbe.getCouleurTrait();
    const QBrush brosseCourbe = QBrush(QColor(couleurCourbe), Qt::SolidPattern);
    const QPen pinceauCourbe = QPen(brosseCourbe, epaisseurCourbe,
            static_cast<Qt::PenStyle>(styleCourbe + 1), Qt::RoundCap, Qt::RoundJoin);

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
    courbeGraphique->setPen(pinceauCourbe);
    courbeGraphique->attach(graphique);

    graphique->replot();
#else
    Q_UNUSED(courbe)
    Q_UNUSED(parametresCourbe)
#endif
}

void FenetreGraphique::dessinerPointGraphique(const Point& point,
        const ParametresPoint& parametresPoint)
{
#ifdef ENABLE_QWT
    QwtPlot* graphique = dynamic_cast<QwtPlot*>(_ui->widgetGraphique);

    const int& stylePoint = parametresPoint.getStylePoint();
    const int& epaisseurPoint = parametresPoint.getEpaisseurPoint();
    const QRgb& couleurPoint = parametresPoint.getCouleurPoint();
    const QBrush brossePoint = QBrush(QColor(couleurPoint), Qt::SolidPattern);
    const QPen pinceauPoint = QPen(brossePoint, epaisseurPoint / 2, Qt::SolidLine);
    const QwtSymbol::Style symbolePoint =
            (stylePoint == ParametresPoint::CARRE) ? QwtSymbol::Rect :
            (stylePoint == ParametresPoint::CERCLE) ? QwtSymbol::Ellipse : QwtSymbol::NoSymbol;

    QwtPlotMarker* pointGraphique = new QwtPlotMarker();
    QwtSymbol* symbolePointGraphique = new QwtSymbol();
    symbolePointGraphique->setStyle(symbolePoint);
    symbolePointGraphique->setSize(epaisseurPoint);
    symbolePointGraphique->setPen(pinceauPoint);
    pointGraphique->setSymbol(symbolePointGraphique);
    pointGraphique->setValue(point.getPointReelX(), point.getPointReelY());
    pointGraphique->attach(graphique);

    graphique->replot();
#else
    Q_UNUSED(point)
    Q_UNUSED(parametresPoint)
#endif
}

void FenetreGraphique::exporterGraphique()
{
    const QString cheminFichierGraphique = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier image"),
            _parametresFichiers.getCheminFichierGraphique(),
            QString::fromUtf8("Fichier image Windows Bitmap (*.bmp);;"
                    "Fichier image JPEG (*.jpg *.jpeg);;"
                    "Fichier image PNG (*.png)"));
    if (cheminFichierGraphique.isEmpty())
        return;

    QFile fichierGraphique(cheminFichierGraphique);
    if (!fichierGraphique.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

#ifdef ENABLE_QWT
    QwtPlot* graphique = dynamic_cast<QwtPlot*>(_ui->widgetGraphique);
    const QPoint positionGraphique = graphique->mapToParent(graphique->rect().topLeft());
    const QSize tailleGraphique = graphique->size();
    const QRect rectangleGraphique = QRect(positionGraphique, tailleGraphique);

    QPixmap pixmap = QWidget::grab(rectangleGraphique);
    pixmap.save(cheminFichierGraphique);
#endif
}

void FenetreGraphique::on_lineEditAxeHorizontalBorneInferieure_textChanged(const QString& text)
{
    ParametresAxe parametresAxeHorizontal = _parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setBorneInferieure(text.toDouble());
    _parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeHorizontalBorneSuperieure_textChanged(const QString& text)
{
    ParametresAxe parametresAxeHorizontal = _parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setBorneSuperieure(text.toDouble());
    _parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeHorizontalPasPrincipal_textChanged(const QString& text)
{
    ParametresAxe parametresAxeHorizontal = _parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setPasPrincipal(text.toDouble());
    _parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeHorizontalPasSecondaire_textChanged(const QString& text)
{
    ParametresAxe parametresAxeHorizontal = _parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setPasSecondaire(text.toDouble());
    _parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    dessinerGraphique();
}

void FenetreGraphique::on_checkBoxAxeHorizontalGrillePrincipale_stateChanged(int state)
{
    ParametresAxe parametresAxeHorizontal = _parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setGrillePrincipale(state == Qt::Checked);
    _parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    dessinerGraphique();
}

void FenetreGraphique::on_checkBoxAxeHorizontalGrilleSecondaire_stateChanged(int state)
{
    ParametresAxe parametresAxeHorizontal = _parametresGraphique.getParametresAxeHorizontal();
    parametresAxeHorizontal.setGrilleSecondaire(state == Qt::Checked);
    _parametresGraphique.setParametresAxeHorizontal(parametresAxeHorizontal);
    dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeVerticalBorneInferieure_textChanged(const QString& text)
{
    ParametresAxe parametresAxeVertical = _parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setBorneInferieure(text.toDouble());
    _parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeVerticalBorneSuperieure_textChanged(const QString& text)
{
    ParametresAxe parametresAxeVertical = _parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setBorneSuperieure(text.toDouble());
    _parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeVerticalPasPrincipal_textChanged(const QString& text)
{
    ParametresAxe parametresAxeVertical = _parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setPasPrincipal(text.toDouble());
    _parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    dessinerGraphique();
}

void FenetreGraphique::on_lineEditAxeVerticalPasSecondaire_textChanged(const QString& text)
{
    ParametresAxe parametresAxeVertical = _parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setPasSecondaire(text.toDouble());
    _parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    dessinerGraphique();
}

void FenetreGraphique::on_checkBoxAxeVerticalGrillePrincipale_stateChanged(int state)
{
    ParametresAxe parametresAxeVertical = _parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setGrillePrincipale(state == Qt::Checked);
    _parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    dessinerGraphique();
}

void FenetreGraphique::on_checkBoxAxeVerticalGrilleSecondaire_stateChanged(int state)
{
    ParametresAxe parametresAxeVertical = _parametresGraphique.getParametresAxeVertical();
    parametresAxeVertical.setGrilleSecondaire(state == Qt::Checked);
    _parametresGraphique.setParametresAxeVertical(parametresAxeVertical);
    dessinerGraphique();
}

void FenetreGraphique::on_buttonBox_clicked(QAbstractButton* button)
{
    if (button == _ui->buttonBox->button(QDialogButtonBox::Save))
    {
        exporterGraphique();
    }
}
