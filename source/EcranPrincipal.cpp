//==============================================================================
// Name        : EcranPrincipal.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.2.0 (03/10/2020)
// Description : Source file of the EcranPrincipal class
//==============================================================================

#include "EcranPrincipal.h"
#include "ui_EcranPrincipal.h"
#include "FenetreDocumentation.h"
#include "FenetreGraphique.h"
#include "FenetreParametresAffichage.h"
#include "FenetreParametresConversion.h"
#include "FenetreParametresExport.h"
#include "FenetreParametresRecherche.h"
#include "Image.h"
#include "Parametres.h"
#include "ParametresAffichage.h"
#include "ParametresConversion.h"
#include "ParametresExport.h"
#include "ParametresFichiers.h"
#include "ParametresGraphique.h"
#include "ParametresRecherche.h"
#include "Point.h"
#include "Repere.h"
#include <cmath>
#include <QDialog>
#include <QDoubleValidator>
#include <QFileDialog>
#include <QGraphicsView>
#include <QImage>
#include <QIntValidator>
#include <QList>
#include <QMessageBox>
#include <QModelIndexList>
#include <QPoint>
#include <QString>
#include <QTableWidgetItem>

EcranPrincipal::EcranPrincipal(QWidget* parent) :
        QMainWindow(parent), _ui(new Ui::EcranPrincipal), _pushButtonActif(nullptr)
{
    _ui->setupUi(this);
    connect(_ui->vueGraphiqueEtude, SIGNAL(mousePressEventSignal(const QPointF)), this,
            SLOT(mousePressEventSlot(const QPointF)));
    connect(_ui->vueGraphiqueEtude, SIGNAL(mouseMoveEventSignal(const QPointF)), this,
            SLOT(mouseMoveEventSlot(const QPointF)));
    initialiserElementsGraphiques();
    effacerElementsGraphiques();
}

EcranPrincipal::~EcranPrincipal()
{
    delete _ui;
}

void EcranPrincipal::initialiserElementsGraphiques()
{
    _ui->radioButtonNoirEtBlanc->setChecked(true);

    const QIntValidator* nombreEntier = new QIntValidator(this);
    _ui->lineEditPointX0XPixel->setValidator(nombreEntier);
    _ui->lineEditPointX0YPixel->setValidator(nombreEntier);
    _ui->lineEditPointX1XPixel->setValidator(nombreEntier);
    _ui->lineEditPointX1YPixel->setValidator(nombreEntier);
    _ui->lineEditPointY0XPixel->setValidator(nombreEntier);
    _ui->lineEditPointY0YPixel->setValidator(nombreEntier);
    _ui->lineEditPointY1XPixel->setValidator(nombreEntier);
    _ui->lineEditPointY1YPixel->setValidator(nombreEntier);
    _ui->lineEditPointDepartXPixel->setValidator(nombreEntier);
    _ui->lineEditPointDepartYPixel->setValidator(nombreEntier);
    _ui->lineEditPointArriveeXPixel->setValidator(nombreEntier);
    _ui->lineEditPointArriveeYPixel->setValidator(nombreEntier);
    _ui->lineEditPointManuelXPixel->setValidator(nombreEntier);
    _ui->lineEditPointManuelYPixel->setValidator(nombreEntier);

    const QDoubleValidator* nombreReel = new QDoubleValidator(this);
    _ui->lineEditPointX0Valeur->setValidator(nombreReel);
    _ui->lineEditPointX1Valeur->setValidator(nombreReel);
    _ui->lineEditPointY0Valeur->setValidator(nombreReel);
    _ui->lineEditPointY1Valeur->setValidator(nombreReel);
    _ui->lineEditPointDepartXReel->setValidator(nombreReel);
    _ui->lineEditPointDepartYReel->setValidator(nombreReel);
    _ui->lineEditPointArriveeXReel->setValidator(nombreReel);
    _ui->lineEditPointArriveeYReel->setValidator(nombreReel);
    _ui->lineEditPointManuelXReel->setValidator(nombreReel);
    _ui->lineEditPointManuelYReel->setValidator(nombreReel);

#ifndef ENABLE_QWT
    _ui->pushButtonGraphique->setEnabled(false);
#endif
}

void EcranPrincipal::effacerElementsGraphiques()
{
    _ui->radioButtonNoirEtBlanc->setChecked(true);

    _ui->lineEditPointX0XPixel->clear();
    _ui->lineEditPointX0YPixel->clear();
    _ui->lineEditPointX0Valeur->clear();
    _ui->lineEditPointX1XPixel->clear();
    _ui->lineEditPointX1YPixel->clear();
    _ui->lineEditPointX1Valeur->clear();
    _ui->lineEditPointY0XPixel->clear();
    _ui->lineEditPointY0YPixel->clear();
    _ui->lineEditPointY0Valeur->clear();
    _ui->lineEditPointY1XPixel->clear();
    _ui->lineEditPointY1YPixel->clear();
    _ui->lineEditPointY1Valeur->clear();

    _ui->lineEditPointDepartXPixel->clear();
    _ui->lineEditPointDepartYPixel->clear();
    _ui->lineEditPointDepartXReel->clear();
    _ui->lineEditPointDepartYReel->clear();
    _ui->lineEditPointArriveeXPixel->clear();
    _ui->lineEditPointArriveeYPixel->clear();
    _ui->lineEditPointArriveeXReel->clear();
    _ui->lineEditPointArriveeYReel->clear();
    _ui->lineEditPointManuelXPixel->clear();
    _ui->lineEditPointManuelYPixel->clear();
    _ui->lineEditPointManuelXReel->clear();
    _ui->lineEditPointManuelYReel->clear();

    _ui->tableWidgetListePoints->clearContents();
    _ui->tableWidgetListePoints->setRowCount(0);
    _ui->tableWidgetListePoints->resizeColumnsToContents();

    _ui->statusBar->clearMessage();

    activerBouton(nullptr);

    repositionnerVueGraphiqueEtude();
    effacerVueGraphiqueEtude();
}

void EcranPrincipal::actualiserElementsGraphiques()
{
    const Repere& repere = _etude.getRepere();
    const Parametres& parametres = _etude.getParametres();
    const ParametresConversion& parametresConversion = parametres.getParametresConversion();
    const int& methodeConversion = parametresConversion.getMethodeConversion();

    if ((methodeConversion == ParametresConversion::BRUTE)
            || (methodeConversion == ParametresConversion::NOIR_ET_BLANC))
    {
        _ui->radioButtonNoirEtBlanc->setChecked(true);
    }
    else if (methodeConversion == ParametresConversion::NIVEAUX_DE_GRIS)
    {
        _ui->radioButtonNiveauxDeGris->setChecked(true);
    }
    else if (methodeConversion == ParametresConversion::TEINTES_SATUREES)
    {
        _ui->radioButtonTeintesSaturees->setChecked(true);
    }

    _ui->lineEditPointX0XPixel->setText(QString::number(repere.getPointX0().getPointPixelX()));
    _ui->lineEditPointX0YPixel->setText(QString::number(repere.getPointX0().getPointPixelY()));
    _ui->lineEditPointX0Valeur->setText(QString::number(repere.getPointX0().getPointReelX()));
    _ui->lineEditPointX1XPixel->setText(QString::number(repere.getPointX1().getPointPixelX()));
    _ui->lineEditPointX1YPixel->setText(QString::number(repere.getPointX1().getPointPixelY()));
    _ui->lineEditPointX1Valeur->setText(QString::number(repere.getPointX1().getPointReelX()));
    _ui->lineEditPointY0XPixel->setText(QString::number(repere.getPointY0().getPointPixelX()));
    _ui->lineEditPointY0YPixel->setText(QString::number(repere.getPointY0().getPointPixelY()));
    _ui->lineEditPointY0Valeur->setText(QString::number(repere.getPointY0().getPointReelY()));
    _ui->lineEditPointY1XPixel->setText(QString::number(repere.getPointY1().getPointPixelX()));
    _ui->lineEditPointY1YPixel->setText(QString::number(repere.getPointY1().getPointPixelY()));
    _ui->lineEditPointY1Valeur->setText(QString::number(repere.getPointY1().getPointReelY()));

    actualiserCoordonneesPoints();

    _etude.restaurerImage();
    _etude.convertirImage();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::creerNouvelleEtude()
{
    const QString cheminFichierImageSource = QFileDialog::getOpenFileName(this,
            QString::fromUtf8("Sélection d'un fichier image"),
            _etude.getParametres().getParametresFichiers().getCheminFichierImageSource(),
            QString::fromUtf8("Fichier image (*.bmp *.jpg *.jpeg *.png)"));
    if (cheminFichierImageSource.isEmpty())
        return;

    effacerElementsGraphiques();

    _etude.clear();
    actualiserEtudeReference();

    Image image;
    image.setImageSource(QImage(cheminFichierImageSource));
    image.restaurerImage();
    _etude.setImage(image);
    Parametres parametres;
    ParametresFichiers parametresFichiers = parametres.getParametresFichiers();
    parametresFichiers.setCheminFichierImageSource(cheminFichierImageSource);
    parametres.setParametresFichiers(parametresFichiers);
    _etude.setParametres(parametres);

    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::chargerEtudeExistante()
{
    const QString cheminFichierEtude = QFileDialog::getOpenFileName(this,
            QString::fromUtf8("Sélection d'un fichier étude"),
            _etude.getParametres().getParametresFichiers().getCheminFichierEtude(),
            QString::fromUtf8("Fichier étude (*.ndc)"));
    if (cheminFichierEtude.isEmpty())
        return;

    effacerElementsGraphiques();

    _etude.chargerEtude(cheminFichierEtude);
    actualiserEtudeReference();

    actualiserElementsGraphiques();
}

void EcranPrincipal::sauverEtudeCourante()
{
    const QString cheminFichierEtude = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier étude"),
            _etude.getParametres().getParametresFichiers().getCheminFichierEtude(),
            QString::fromUtf8("Fichier étude (*.ndc)"));
    if (cheminFichierEtude.isEmpty())
        return;

    _etude.sauverEtude(cheminFichierEtude);
    actualiserEtudeReference();
}

void EcranPrincipal::exporterListeDePointsCourante()
{
    const QString cheminFichierExport = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier export"),
            _etude.getParametres().getParametresFichiers().getCheminFichierExport(),
            QString::fromUtf8("Fichier export (*.csv)"));
    if (cheminFichierExport.isEmpty())
        return;

    _etude.exporterListeDePoints(cheminFichierExport);
}

void EcranPrincipal::exporterImageConvertieCourante()
{
    const QString cheminFichierImageConvertie = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier image"),
            _etude.getParametres().getParametresFichiers().getCheminFichierImageConvertie(),
            QString::fromUtf8("Fichier image Windows Bitmap (*.bmp);;"
                    "Fichier image JPEG (*.jpg *.jpeg);;"
                    "Fichier image PNG (*.png)"));
    if (cheminFichierImageConvertie.isEmpty())
        return;

    _etude.exporterImageConvertie(cheminFichierImageConvertie);
}

void EcranPrincipal::chargerParametresExistants()
{
    const QString cheminFichierParametres = QFileDialog::getOpenFileName(this,
            QString::fromUtf8("Sélection d'un fichier paramètres"),
            _etude.getParametres().getParametresFichiers().getCheminFichierParametres(),
            QString::fromUtf8("Fichier paramètres (*.prm)"));
    if (cheminFichierParametres.isEmpty())
        return;

    _etude.chargerParametres(cheminFichierParametres);

    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::sauverParametresCourants()
{
    const QString cheminFichierParametres = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier paramètres"),
            _etude.getParametres().getParametresFichiers().getCheminFichierParametres(),
            QString::fromUtf8("Fichier paramètres (*.prm)"));
    if (cheminFichierParametres.isEmpty())
        return;

    _etude.sauverParametres(cheminFichierParametres);
}

void EcranPrincipal::verifierEtatSauvegardeEtude()
{
    if (_etude.equals(_etudeReference))
        return;

    QMessageBox* fenetreMessage = new QMessageBox(QMessageBox::Warning,
            QString::fromUtf8("Sauvegarde de l'étude courante"),
            QString::fromUtf8("Souhaitez-vous sauver l'étude courante ?"),
            QMessageBox::Yes | QMessageBox::No, this);
    fenetreMessage->setButtonText(QMessageBox::Yes, "Oui");
    fenetreMessage->setButtonText(QMessageBox::No, "Non");
    if (fenetreMessage->exec() == QMessageBox::No)
        return;

    sauverEtudeCourante();
}

void EcranPrincipal::actualiserEtudeReference()
{
    _etudeReference = _etude;
}

void EcranPrincipal::actualiserCoordonneesPoints()
{
    actualiserCoordonneesPointDepart();
    actualiserCoordonneesPointArrivee();
    actualiserCoordonneesPointManuel();
    actualiserCoordonneesListeDePoints();
}

void EcranPrincipal::actualiserCoordonneesPointDepart()
{
    if (_ui->lineEditPointDepartXPixel->text().isEmpty()
            || _ui->lineEditPointDepartYPixel->text().isEmpty())
    {
        _ui->lineEditPointDepartXReel->clear();
        _ui->lineEditPointDepartYReel->clear();
        return;
    }

    const Parametres& parametres = _etude.getParametres();
    const ParametresAffichage& parametresAffichage = parametres.getParametresAffichage();
    const char formatNotationNombresCaractere =
            parametresAffichage.getFormatNotationNombresCaractere();
    const int& nombreChiffresSignificatifs = parametresAffichage.getNombreChiffresSignificatifs();

    const int pointPixelX = _ui->lineEditPointDepartXPixel->text().toInt();
    const int pointPixelY = _ui->lineEditPointDepartYPixel->text().toInt();
    double pointReelX = 0.0;
    double pointReelY = 0.0;
    _etude.getRepere().pixelVersReel(pointPixelX, pointPixelY, pointReelX, pointReelY);
    _ui->lineEditPointDepartXReel->setText(
            QString::number(pointReelX, formatNotationNombresCaractere,
                    nombreChiffresSignificatifs));
    _ui->lineEditPointDepartYReel->setText(
            QString::number(pointReelY, formatNotationNombresCaractere,
                    nombreChiffresSignificatifs));
}

void EcranPrincipal::actualiserCoordonneesPointArrivee()
{
    if (_ui->lineEditPointArriveeXPixel->text().isEmpty()
            || _ui->lineEditPointArriveeYPixel->text().isEmpty())
    {
        _ui->lineEditPointArriveeXReel->clear();
        _ui->lineEditPointArriveeYReel->clear();
        return;
    }

    const Parametres& parametres = _etude.getParametres();
    const ParametresAffichage& parametresAffichage = parametres.getParametresAffichage();
    const char formatNotationNombresCaractere =
            parametresAffichage.getFormatNotationNombresCaractere();
    const int& nombreChiffresSignificatifs = parametresAffichage.getNombreChiffresSignificatifs();

    const int pointPixelX = _ui->lineEditPointArriveeXPixel->text().toInt();
    const int pointPixelY = _ui->lineEditPointArriveeYPixel->text().toInt();
    double pointReelX = 0.0;
    double pointReelY = 0.0;
    _etude.getRepere().pixelVersReel(pointPixelX, pointPixelY, pointReelX, pointReelY);
    _ui->lineEditPointArriveeXReel->setText(
            QString::number(pointReelX, formatNotationNombresCaractere,
                    nombreChiffresSignificatifs));
    _ui->lineEditPointArriveeYReel->setText(
            QString::number(pointReelY, formatNotationNombresCaractere,
                    nombreChiffresSignificatifs));
}

void EcranPrincipal::actualiserCoordonneesPointManuel()
{
    if (_ui->lineEditPointManuelXPixel->text().isEmpty()
            || _ui->lineEditPointManuelYPixel->text().isEmpty())
    {
        _ui->lineEditPointManuelXReel->clear();
        _ui->lineEditPointManuelYReel->clear();
        return;
    }

    const Parametres& parametres = _etude.getParametres();
    const ParametresAffichage& parametresAffichage = parametres.getParametresAffichage();
    const char formatNotationNombresCaractere =
            parametresAffichage.getFormatNotationNombresCaractere();
    const int& nombreChiffresSignificatifs = parametresAffichage.getNombreChiffresSignificatifs();

    const int pointPixelX = _ui->lineEditPointManuelXPixel->text().toInt();
    const int pointPixelY = _ui->lineEditPointManuelYPixel->text().toInt();
    double pointReelX = 0.0;
    double pointReelY = 0.0;
    _etude.getRepere().pixelVersReel(pointPixelX, pointPixelY, pointReelX, pointReelY);
    _ui->lineEditPointManuelXReel->setText(
            QString::number(pointReelX, formatNotationNombresCaractere,
                    nombreChiffresSignificatifs));
    _ui->lineEditPointManuelYReel->setText(
            QString::number(pointReelY, formatNotationNombresCaractere,
                    nombreChiffresSignificatifs));
}

void EcranPrincipal::actualiserCoordonneesListeDePoints()
{
    // TODO Déplacement de l'actualisation des éléments de la liste de points

    const Parametres& parametres = _etude.getParametres();
    const ParametresAffichage& parametresAffichage = parametres.getParametresAffichage();
    const char formatNotationNombresCaractere =
            parametresAffichage.getFormatNotationNombresCaractere();
    const int& nombreChiffresSignificatifs = parametresAffichage.getNombreChiffresSignificatifs();

    QList<Point> listeDePoints = _etude.getListeDePoints();
    const int nombreDePoints = listeDePoints.count();
    for (int itPoint = 0; itPoint < nombreDePoints; itPoint++)
    {
        Point point = listeDePoints.at(itPoint);
        _etude.getRepere().pixelVersReel(point);
        listeDePoints.replace(itPoint, point);
    }
    _etude.setListeDePoints(listeDePoints);

    _ui->tableWidgetListePoints->clearContents();
    _ui->tableWidgetListePoints->setRowCount(nombreDePoints);
    for (int itPoint = 0; itPoint < nombreDePoints; itPoint++)
    {
        const Point& point = listeDePoints.at(itPoint);
        QTableWidgetItem* itemPointPixelX = new QTableWidgetItem(
                QString::number(point.getPointPixelX()));
        QTableWidgetItem* itemPointPixelY = new QTableWidgetItem(
                QString::number(point.getPointPixelY()));
        QTableWidgetItem* itemPointReelX = new QTableWidgetItem(
                QString::number(point.getPointReelX(), formatNotationNombresCaractere,
                        nombreChiffresSignificatifs));
        QTableWidgetItem* itemPointReelY = new QTableWidgetItem(
                QString::number(point.getPointReelY(), formatNotationNombresCaractere,
                        nombreChiffresSignificatifs));
        QTableWidgetItem* itemTypePoint = new QTableWidgetItem(point.getTypePointTexte());
        _ui->tableWidgetListePoints->setItem(itPoint, 0, itemPointPixelX);
        _ui->tableWidgetListePoints->setItem(itPoint, 1, itemPointPixelY);
        _ui->tableWidgetListePoints->setItem(itPoint, 2, itemPointReelX);
        _ui->tableWidgetListePoints->setItem(itPoint, 3, itemPointReelY);
        _ui->tableWidgetListePoints->setItem(itPoint, 4, itemTypePoint);
    }
    _ui->tableWidgetListePoints->resizeColumnsToContents();
}

void EcranPrincipal::repositionnerVueGraphiqueEtude()
{
    _ui->vueGraphiqueEtude->repositionner();
}

void EcranPrincipal::effacerVueGraphiqueEtude()
{
    _ui->vueGraphiqueEtude->effacer();
}

void EcranPrincipal::dessinerVueGraphiqueEtude()
{
    _ui->vueGraphiqueEtude->dessiner(_etude);
}

void EcranPrincipal::activerBouton(const QPushButton* pushButton)
{
    if (!pushButton || !pushButton->isChecked())
    {
        _ui->vueGraphiqueEtude->setDragMode(QGraphicsView::ScrollHandDrag);
        _ui->pushButtonPointX0->setChecked(false);
        _ui->pushButtonPointY0->setChecked(false);
        _ui->pushButtonPointX1->setChecked(false);
        _ui->pushButtonPointY1->setChecked(false);
        _ui->pushButtonPointDepart->setChecked(false);
        _ui->pushButtonPointArrivee->setChecked(false);
        _ui->pushButtonPointManuel->setChecked(false);
        _pushButtonActif = nullptr;
    }
    else
    {
        _ui->vueGraphiqueEtude->setDragMode(QGraphicsView::NoDrag);
        if (_pushButtonActif && _pushButtonActif != pushButton)
        {
            _pushButtonActif->setChecked(false);
        }
        _pushButtonActif = const_cast<QPushButton*>(pushButton);
    }
}

void EcranPrincipal::actualiserPoint(const QPointF& pointVueGraphique)
{
    if (_pushButtonActif == _ui->pushButtonPointX0 || _pushButtonActif == _ui->pushButtonPointX1
            || _pushButtonActif == _ui->pushButtonPointY0
            || _pushButtonActif == _ui->pushButtonPointY1)
    {
        actualiserPointRepere(pointVueGraphique);
    }
    else if (_pushButtonActif == _ui->pushButtonPointDepart
            || _pushButtonActif == _ui->pushButtonPointArrivee
            || _pushButtonActif == _ui->pushButtonPointManuel)
    {
        actualiserPointCourbe(pointVueGraphique);
    }
}

void EcranPrincipal::actualiserPointRepere(const QPointF& pointVueGraphique)
{
    const int ppx = static_cast<int>(floor(pointVueGraphique.x()));
    const int ppy = static_cast<int>(floor(pointVueGraphique.y()));
    Repere repere = _etude.getRepere();

    const QString ppxTexte = QString::number(ppx);
    const QString ppyTexte = QString::number(ppy);

    if (_pushButtonActif == _ui->pushButtonPointX0)
    {
        Point pointX0 = repere.getPointX0();
        pointX0.setPointPixelX(ppx);
        pointX0.setPointPixelY(ppy);
        repere.setPointX0(pointX0);
        _etude.setRepere(repere);
        _ui->lineEditPointX0XPixel->setText(ppxTexte);
        _ui->lineEditPointX0YPixel->setText(ppyTexte);
        actualiserCoordonneesPoints();
        dessinerVueGraphiqueEtude();
        _ui->lineEditPointX0Valeur->setFocus();
    }
    else if (_pushButtonActif == _ui->pushButtonPointX1)
    {
        Point pointX1 = repere.getPointX1();
        pointX1.setPointPixelX(ppx);
        pointX1.setPointPixelY(ppy);
        repere.setPointX1(pointX1);
        _etude.setRepere(repere);
        _ui->lineEditPointX1XPixel->setText(ppxTexte);
        _ui->lineEditPointX1YPixel->setText(ppyTexte);
        actualiserCoordonneesPoints();
        dessinerVueGraphiqueEtude();
        _ui->lineEditPointX1Valeur->setFocus();
    }
    else if (_pushButtonActif == _ui->pushButtonPointY0)
    {
        Point pointY0 = repere.getPointY0();
        pointY0.setPointPixelX(ppx);
        pointY0.setPointPixelY(ppy);
        repere.setPointY0(pointY0);
        _etude.setRepere(repere);
        _ui->lineEditPointY0XPixel->setText(ppxTexte);
        _ui->lineEditPointY0YPixel->setText(ppyTexte);
        actualiserCoordonneesPoints();
        dessinerVueGraphiqueEtude();
        _ui->lineEditPointY0Valeur->setFocus();
    }
    else if (_pushButtonActif == _ui->pushButtonPointY1)
    {
        Point pointY1 = repere.getPointY1();
        pointY1.setPointPixelX(ppx);
        pointY1.setPointPixelY(ppy);
        repere.setPointY1(pointY1);
        _etude.setRepere(repere);
        _ui->lineEditPointY1XPixel->setText(ppxTexte);
        _ui->lineEditPointY1YPixel->setText(ppyTexte);
        actualiserCoordonneesPoints();
        dessinerVueGraphiqueEtude();
        _ui->lineEditPointY1Valeur->setFocus();
    }
}

void EcranPrincipal::actualiserPointCourbe(const QPointF& pointVueGraphique)
{
    const Parametres& parametres = _etude.getParametres();
    const ParametresAffichage& parametresAffichage = parametres.getParametresAffichage();
    const char formatNotationNombresCaractere =
            parametresAffichage.getFormatNotationNombresCaractere();
    const int& nombreChiffresSignificatifs = parametresAffichage.getNombreChiffresSignificatifs();

    const int ppx = static_cast<int>(floor(pointVueGraphique.x()));
    const int ppy = static_cast<int>(floor(pointVueGraphique.y()));
    double prx = 0.0;
    double pry = 0.0;
    _etude.getRepere().pixelVersReel(ppx, ppy, prx, pry);

    const QString ppxTexte = QString::number(ppx);
    const QString ppyTexte = QString::number(ppy);
    const QString prxTexte = QString::number(prx, formatNotationNombresCaractere,
            nombreChiffresSignificatifs);
    const QString pryTexte = QString::number(pry, formatNotationNombresCaractere,
            nombreChiffresSignificatifs);

    if (_pushButtonActif == _ui->pushButtonPointDepart)
    {
        _ui->lineEditPointDepartXPixel->setText(ppxTexte);
        _ui->lineEditPointDepartYPixel->setText(ppyTexte);
        _ui->lineEditPointDepartXReel->setText(prxTexte);
        _ui->lineEditPointDepartYReel->setText(pryTexte);
    }
    else if (_pushButtonActif == _ui->pushButtonPointArrivee)
    {
        _ui->lineEditPointArriveeXPixel->setText(ppxTexte);
        _ui->lineEditPointArriveeYPixel->setText(ppyTexte);
        _ui->lineEditPointArriveeXReel->setText(prxTexte);
        _ui->lineEditPointArriveeYReel->setText(pryTexte);
    }
    else if (_pushButtonActif == _ui->pushButtonPointManuel)
    {
        _ui->lineEditPointManuelXPixel->setText(ppxTexte);
        _ui->lineEditPointManuelYPixel->setText(ppyTexte);
        _ui->lineEditPointManuelXReel->setText(prxTexte);
        _ui->lineEditPointManuelYReel->setText(pryTexte);
    }
}

void EcranPrincipal::actualiserBarreStatut(const QPointF& pointVueGraphique)
{
    const Parametres& parametres = _etude.getParametres();
    const ParametresAffichage& parametresAffichage = parametres.getParametresAffichage();
    const char formatNotationNombresCaractere =
            parametresAffichage.getFormatNotationNombresCaractere();
    const int& nombreChiffresSignificatifs = parametresAffichage.getNombreChiffresSignificatifs();

    const int ppx = static_cast<int>(floor(pointVueGraphique.x()));
    const int ppy = static_cast<int>(floor(pointVueGraphique.y()));
    double prx = 0.0;
    double pry = 0.0;
    _etude.getRepere().pixelVersReel(ppx, ppy, prx, pry);

    const QString ppxTexte = QString::number(ppx);
    const QString ppyTexte = QString::number(ppy);
    const QString prxTexte = QString::number(prx, formatNotationNombresCaractere,
            nombreChiffresSignificatifs);
    const QString pryTexte = QString::number(pry, formatNotationNombresCaractere,
            nombreChiffresSignificatifs);
    const QString statusBarTexte = QString::fromUtf8("Pixel=(%1:%2) - Réel=(%3:%4)").arg(ppxTexte,
            ppyTexte, prxTexte, pryTexte);

    _ui->statusBar->showMessage(statusBarTexte);
}

void EcranPrincipal::on_actionCreerEtude_triggered()
{
    verifierEtatSauvegardeEtude();
    creerNouvelleEtude();
}

void EcranPrincipal::on_actionChargerEtude_triggered()
{
    verifierEtatSauvegardeEtude();
    chargerEtudeExistante();
}

void EcranPrincipal::on_actionSauverEtude_triggered()
{
    sauverEtudeCourante();
}

void EcranPrincipal::on_actionExporterListePoints_triggered()
{
    exporterListeDePointsCourante();
}

void EcranPrincipal::on_actionExporterImage_triggered()
{
    exporterImageConvertieCourante();
}

void EcranPrincipal::on_actionQuitter_triggered()
{
    verifierEtatSauvegardeEtude();
    close();
}

void EcranPrincipal::on_actionParametresAffichage_triggered()
{
    Parametres parametres = _etude.getParametres();
    ParametresAffichage parametresAffichage = parametres.getParametresAffichage();
    FenetreParametresAffichage* fenetreParametresAffichage = new FenetreParametresAffichage(this);
    fenetreParametresAffichage->setParametresAffichage(parametresAffichage);
    fenetreParametresAffichage->actualiserElementsGraphiques();
    if (fenetreParametresAffichage->exec() == QDialog::Rejected)
        return;
    parametresAffichage = fenetreParametresAffichage->getParametresAffichage();
    parametres.setParametresAffichage(parametresAffichage);
    _etude.setParametres(parametres);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_actionParametresConversion_triggered()
{
    Parametres parametres = _etude.getParametres();
    ParametresConversion parametresConversion = parametres.getParametresConversion();
    FenetreParametresConversion* fenetreParametresConversion = new FenetreParametresConversion(
            this);
    fenetreParametresConversion->setParametresConversion(parametresConversion);
    fenetreParametresConversion->actualiserElementsGraphiques();
    if (fenetreParametresConversion->exec() == QDialog::Rejected)
        return;
    parametresConversion = fenetreParametresConversion->getParametresConversion();
    parametres.setParametresConversion(parametresConversion);
    _etude.setParametres(parametres);
}

void EcranPrincipal::on_actionParametresRecherche_triggered()
{
    Parametres parametres = _etude.getParametres();
    ParametresRecherche parametresRecherche = parametres.getParametresRecherche();
    FenetreParametresRecherche* fenetreParametresRecherche = new FenetreParametresRecherche(this);
    fenetreParametresRecherche->setParametresRecherche(parametresRecherche);
    fenetreParametresRecherche->actualiserElementsGraphiques();
    if (fenetreParametresRecherche->exec() == QDialog::Rejected)
        return;
    parametresRecherche = fenetreParametresRecherche->getParametresRecherche();
    parametres.setParametresRecherche(parametresRecherche);
    _etude.setParametres(parametres);
}

void EcranPrincipal::on_actionParametresExport_triggered()
{
    Parametres parametres = _etude.getParametres();
    ParametresExport parametresExport = parametres.getParametresExport();
    FenetreParametresExport* fenetreParametresExport = new FenetreParametresExport(this);
    fenetreParametresExport->setParametresExport(parametresExport);
    fenetreParametresExport->actualiserElementsGraphiques();
    if (fenetreParametresExport->exec() == QDialog::Rejected)
        return;
    parametresExport = fenetreParametresExport->getParametresExport();
    parametres.setParametresExport(parametresExport);
    _etude.setParametres(parametres);
}

void EcranPrincipal::on_actionChargerParametres_triggered()
{
    chargerParametresExistants();
}

void EcranPrincipal::on_actionSauverParametres_triggered()
{
    sauverParametresCourants();
}

void EcranPrincipal::on_actionDocumentation_triggered()
{
    FenetreDocumentation* fenetreDocumentation = new FenetreDocumentation(this);
    fenetreDocumentation->exec();
}

void EcranPrincipal::on_actionAbout_triggered()
{
    QMessageBox* fenetreMessage = new QMessageBox(QMessageBox::Information,
            QString::fromUtf8("NumerisationDeCourbes"),
            QString::fromUtf8("NumerisationDeCourbes - Version 1.2.0 (03/10/2020).\n"
                    "Réalisée par Alexis Foerster (alexis.foerster@gmail.com)."), QMessageBox::Ok,
            this);
    fenetreMessage->exec();
}

void EcranPrincipal::on_pushButtonConvertir_clicked()
{
    int methodeConversion = ParametresConversion::BRUTE;
    if (_ui->radioButtonNoirEtBlanc->isChecked())
    {
        methodeConversion = ParametresConversion::NOIR_ET_BLANC;
    }
    else if (_ui->radioButtonNiveauxDeGris->isChecked())
    {
        methodeConversion = ParametresConversion::NIVEAUX_DE_GRIS;
    }
    else if (_ui->radioButtonTeintesSaturees->isChecked())
    {
        methodeConversion = ParametresConversion::TEINTES_SATUREES;
    }
    Parametres parametres = _etude.getParametres();
    ParametresConversion parametresConversion = parametres.getParametresConversion();
    parametresConversion.setMethodeConversion(methodeConversion);
    parametres.setParametresConversion(parametresConversion);
    _etude.setParametres(parametres);

    _etude.convertirImage();

    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_pushButtonRestaurer_clicked()
{
    const int methodeConversion = ParametresConversion::BRUTE;
    Parametres parametres = _etude.getParametres();
    ParametresConversion parametresConversion = parametres.getParametresConversion();
    parametresConversion.setMethodeConversion(methodeConversion);
    parametres.setParametresConversion(parametresConversion);
    _etude.setParametres(parametres);

    _etude.restaurerImage();

    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX0XPixel_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointX0 = repere.getPointX0();
    pointX0.setPointPixelX(_ui->lineEditPointX0XPixel->text().toInt());
    repere.setPointX0(pointX0);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX0YPixel_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointX0 = repere.getPointX0();
    pointX0.setPointPixelY(_ui->lineEditPointX0YPixel->text().toInt());
    repere.setPointX0(pointX0);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX0Valeur_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointX0 = repere.getPointX0();
    pointX0.setPointReelX(_ui->lineEditPointX0Valeur->text().toDouble());
    repere.setPointX0(pointX0);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX1XPixel_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointX1 = repere.getPointX1();
    pointX1.setPointPixelX(_ui->lineEditPointX1XPixel->text().toInt());
    repere.setPointX1(pointX1);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX1YPixel_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointX1 = repere.getPointX1();
    pointX1.setPointPixelY(_ui->lineEditPointX1YPixel->text().toInt());
    repere.setPointX1(pointX1);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX1Valeur_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointX1 = repere.getPointX1();
    pointX1.setPointReelX(_ui->lineEditPointX1Valeur->text().toDouble());
    repere.setPointX1(pointX1);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY0XPixel_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointY0 = repere.getPointY0();
    pointY0.setPointPixelX(_ui->lineEditPointY0XPixel->text().toInt());
    repere.setPointY0(pointY0);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY0YPixel_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointY0 = repere.getPointY0();
    pointY0.setPointPixelY(_ui->lineEditPointY0YPixel->text().toInt());
    repere.setPointY0(pointY0);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY0Valeur_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointY0 = repere.getPointY0();
    pointY0.setPointReelY(_ui->lineEditPointY0Valeur->text().toDouble());
    repere.setPointY0(pointY0);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY1XPixel_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointY1 = repere.getPointY1();
    pointY1.setPointPixelX(_ui->lineEditPointY1XPixel->text().toInt());
    repere.setPointY1(pointY1);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY1YPixel_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointY1 = repere.getPointY1();
    pointY1.setPointPixelY(_ui->lineEditPointY1YPixel->text().toInt());
    repere.setPointY1(pointY1);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY1Valeur_textChanged()
{
    Repere repere = _etude.getRepere();
    Point pointY1 = repere.getPointY1();
    pointY1.setPointReelY(_ui->lineEditPointY1Valeur->text().toDouble());
    repere.setPointY1(pointY1);
    _etude.setRepere(repere);

    actualiserCoordonneesPoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_pushButtonPointX0_clicked()
{
    activerBouton(_ui->pushButtonPointX0);
}

void EcranPrincipal::on_pushButtonPointX1_clicked()
{
    activerBouton(_ui->pushButtonPointX1);
}

void EcranPrincipal::on_pushButtonPointY0_clicked()
{
    activerBouton(_ui->pushButtonPointY0);
}

void EcranPrincipal::on_pushButtonPointY1_clicked()
{
    activerBouton(_ui->pushButtonPointY1);
}

void EcranPrincipal::on_lineEditPointDepartXPixel_textChanged()
{
    actualiserCoordonneesPointDepart();
}

void EcranPrincipal::on_lineEditPointDepartYPixel_textChanged()
{
    actualiserCoordonneesPointDepart();
}

void EcranPrincipal::on_lineEditPointArriveeXPixel_textChanged()
{
    actualiserCoordonneesPointArrivee();
}

void EcranPrincipal::on_lineEditPointArriveeYPixel_textChanged()
{
    actualiserCoordonneesPointArrivee();
}

void EcranPrincipal::on_lineEditPointManuelXPixel_textChanged()
{
    actualiserCoordonneesPointManuel();
}

void EcranPrincipal::on_lineEditPointManuelYPixel_textChanged()
{
    actualiserCoordonneesPointManuel();
}

void EcranPrincipal::on_pushButtonPointDepart_clicked()
{
    activerBouton(_ui->pushButtonPointDepart);
}

void EcranPrincipal::on_pushButtonPointArrivee_clicked()
{
    activerBouton(_ui->pushButtonPointArrivee);
}

void EcranPrincipal::on_pushButtonPointManuel_clicked()
{
    activerBouton(_ui->pushButtonPointManuel);
}

void EcranPrincipal::on_pushButtonAjouter_clicked()
{
    const int pointPixelX = _ui->lineEditPointManuelXPixel->text().toInt();
    const int pointPixelY = _ui->lineEditPointManuelYPixel->text().toInt();
    double pointReelX = 0.0;
    double pointReelY = 0.0;
    _etude.getRepere().pixelVersReel(pointPixelX, pointPixelY, pointReelX, pointReelY);

    QList<Point> listeDePoints = _etude.getListeDePoints();
    Point point(pointPixelX, pointPixelY, pointReelX, pointReelY, Point::MANUEL);
    listeDePoints.append(point);
    _etude.setListeDePoints(listeDePoints);

    actualiserCoordonneesListeDePoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_pushButtonRechercher_clicked()
{
    const QPoint pointPixelDepart = QPoint(_ui->lineEditPointDepartXPixel->text().toInt(),
            _ui->lineEditPointDepartYPixel->text().toInt());
    const QPoint pointPixelArrivee = QPoint(_ui->lineEditPointArriveeXPixel->text().toInt(),
            _ui->lineEditPointArriveeYPixel->text().toInt());
    const QList<Courbe> listeDeCourbes = _etude.rechercherCourbes(pointPixelDepart,
            pointPixelArrivee);

    QList<Point> listeDePoints = _etude.getListeDePoints();
    const int nombreDeCourbes = listeDeCourbes.count();
    for (int itCourbe = 0; itCourbe < nombreDeCourbes; itCourbe++)
    {
        const Courbe& courbe = listeDeCourbes.at(itCourbe);
        const int nombreDePointsCourbe = courbe.count();
        for (int itPointCourbe = 0; itPointCourbe < nombreDePointsCourbe; itPointCourbe++)
        {
            const Point& pointCourbe = courbe.at(itPointCourbe);
            listeDePoints.append(pointCourbe);
        }
    }
    _etude.setListeDePoints(listeDePoints);

    actualiserCoordonneesListeDePoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_pushButtonSupprimer_clicked()
{
    const QModelIndexList listeLignesSelectionnees =
            _ui->tableWidgetListePoints->selectionModel()->selectedRows();

    QList<Point> listeDePoints = _etude.getListeDePoints();
    const int nombreLignesSelectionnees = listeLignesSelectionnees.count();
    for (int itLigneSelectionnee = (nombreLignesSelectionnees - 1); itLigneSelectionnee >= 0;
            itLigneSelectionnee--)
    {
        listeDePoints.removeAt(listeLignesSelectionnees.at(itLigneSelectionnee).row());
    }
    if (nombreLignesSelectionnees == 0)
    {
        listeDePoints.clear();
    }

    const QList<Courbe> listeDeCourbes = _etude.getListeDeCourbes();
    const int nombreDeCourbes = listeDeCourbes.count();
    for (int itCourbe = 0; itCourbe < nombreDeCourbes; itCourbe++)
    {
        Courbe listeDePointsCourbe = listeDeCourbes.at(itCourbe);
        int nombreDePointsCourbe = listeDePointsCourbe.count();
        for (int itPointCourbe = (nombreDePointsCourbe - 1); itPointCourbe >= 0; itPointCourbe--)
        {
            const Point& pointCourbe = listeDePointsCourbe.at(itPointCourbe);
            if (!listeDePoints.contains(pointCourbe))
            {
                listeDePointsCourbe.removeAt(itPointCourbe);
            }
        }
        nombreDePointsCourbe = listeDePointsCourbe.count();
        if (nombreDePointsCourbe > 1)
        {
            Point premierPointCourbe = listeDePointsCourbe.at(0);
            Point dernierPointCourbe = listeDePointsCourbe.at(nombreDePointsCourbe - 1);
            const int itPremierPointCourbe = listeDePoints.indexOf(premierPointCourbe);
            const int itDernierPointCourbe = listeDePoints.indexOf(dernierPointCourbe);
            premierPointCourbe.setTypePoint(Point::COURBE_DEBUT);
            dernierPointCourbe.setTypePoint(Point::COURBE_FIN);
            listeDePoints[itPremierPointCourbe] = premierPointCourbe;
            listeDePoints[itDernierPointCourbe] = dernierPointCourbe;
        }
        else if (nombreDePointsCourbe > 0)
        {
            Point pointCourbe = listeDePointsCourbe.at(0);
            const int itPointCourbe = listeDePoints.indexOf(pointCourbe);
            pointCourbe.setTypePoint(Point::MANUEL);
            listeDePoints[itPointCourbe] = pointCourbe;
        }
    }

    _etude.setListeDePoints(listeDePoints);

    actualiserCoordonneesListeDePoints();
    dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_pushButtonGraphique_clicked()
{
    const QList<Courbe> listeDeCourbes = _etude.getListeDeCourbes();
    const QList<Point> listeDePointsManuels = _etude.getListeDePointsManuels();
    const ParametresGraphique parametresGraphiques = _etude.getParametresGraphiques();
    Parametres parametres = _etude.getParametres();
    ParametresAffichage parametresAffichage = parametres.getParametresAffichage();
    ParametresFichiers parametresFichiers = parametres.getParametresFichiers();
    FenetreGraphique* fenetreGraphique = new FenetreGraphique(this);
    fenetreGraphique->setListeDeCourbes(listeDeCourbes);
    fenetreGraphique->setListeDePointsManuels(listeDePointsManuels);
    fenetreGraphique->setParametresGraphique(parametresGraphiques);
    fenetreGraphique->setParametresAffichage(parametresAffichage);
    fenetreGraphique->setParametresFichiers(parametresFichiers);
    fenetreGraphique->actualiserElementsGraphiques();
    if (fenetreGraphique->exec() == QDialog::Rejected)
        return;
    parametresFichiers = fenetreGraphique->getParametresFichiers();
    parametres.setParametresFichiers(parametresFichiers);
    _etude.setParametres(parametres);
}

void EcranPrincipal::mousePressEventSlot(const QPointF pointVueGraphique)
{
    actualiserPoint(pointVueGraphique);

    activerBouton(nullptr);
}

void EcranPrincipal::mouseMoveEventSlot(const QPointF pointVueGraphique)
{
    actualiserBarreStatut(pointVueGraphique);
}
