//==============================================================================
// Name        : EcranPrincipal.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (14/06/2016)
// Description : Source file of the EcranPrincipal class
//==============================================================================

#include "EcranPrincipal.h"
#include "FenetreDocumentation.h"
#include "FenetreParametresAffichage.h"
#include "FenetreParametresConversion.h"
#include "FenetreParametresExport.h"
#include "FenetreParametresRecherche.h"
#include "ui_EcranPrincipal.h"
#include <cmath>
#include <QDoubleValidator>
#include <QFileDialog>
#include <QImage>
#include <QIntValidator>
#include <QList>
#include <QMessageBox>
#include <QModelIndexList>
#include <QPoint>
#include <QPointF>
#include <QString>
#include <QTableWidgetItem>

EcranPrincipal::EcranPrincipal(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::EcranPrincipal)
{
    this->ui->setupUi(this);
    this->connect(this->ui->vueGraphiqueEtude, SIGNAL(mousePressEventSignal(const QPointF)), this,
            SLOT(mousePressEventSlot(const QPointF)));
    this->connect(this->ui->vueGraphiqueEtude, SIGNAL(mouseMoveEventSignal(const QPointF)), this,
            SLOT(mouseMoveEventSlot(const QPointF)));
    this->initialiserElementsGraphiques();
    this->effacerElementsGraphiques();
}

EcranPrincipal::~EcranPrincipal()
{
    delete this->ui;
}

void EcranPrincipal::initialiserElementsGraphiques()
{
    this->ui->radioButtonNoirEtBlanc->setChecked(true);

    QIntValidator* nombreEntier = new QIntValidator(this);
    this->ui->lineEditPointX0XPixel->setValidator(nombreEntier);
    this->ui->lineEditPointX0YPixel->setValidator(nombreEntier);
    this->ui->lineEditPointX1XPixel->setValidator(nombreEntier);
    this->ui->lineEditPointX1YPixel->setValidator(nombreEntier);
    this->ui->lineEditPointY0XPixel->setValidator(nombreEntier);
    this->ui->lineEditPointY0YPixel->setValidator(nombreEntier);
    this->ui->lineEditPointY1XPixel->setValidator(nombreEntier);
    this->ui->lineEditPointY1YPixel->setValidator(nombreEntier);
    this->ui->lineEditPointDepartXPixel->setValidator(nombreEntier);
    this->ui->lineEditPointDepartYPixel->setValidator(nombreEntier);
    this->ui->lineEditPointArriveeXPixel->setValidator(nombreEntier);
    this->ui->lineEditPointArriveeYPixel->setValidator(nombreEntier);
    this->ui->lineEditPointManuelXPixel->setValidator(nombreEntier);
    this->ui->lineEditPointManuelYPixel->setValidator(nombreEntier);

    QDoubleValidator* nombreReel = new QDoubleValidator(this);
    this->ui->lineEditPointX0Valeur->setValidator(nombreReel);
    this->ui->lineEditPointX1Valeur->setValidator(nombreReel);
    this->ui->lineEditPointY0Valeur->setValidator(nombreReel);
    this->ui->lineEditPointY1Valeur->setValidator(nombreReel);
    this->ui->lineEditPointDepartXReel->setValidator(nombreReel);
    this->ui->lineEditPointDepartYReel->setValidator(nombreReel);
    this->ui->lineEditPointArriveeXReel->setValidator(nombreReel);
    this->ui->lineEditPointArriveeYReel->setValidator(nombreReel);
    this->ui->lineEditPointManuelXReel->setValidator(nombreReel);
    this->ui->lineEditPointManuelYReel->setValidator(nombreReel);
}

void EcranPrincipal::effacerElementsGraphiques()
{
    this->ui->radioButtonNoirEtBlanc->setChecked(true);

    this->ui->lineEditPointX0XPixel->clear();
    this->ui->lineEditPointX0YPixel->clear();
    this->ui->lineEditPointX0Valeur->clear();
    this->ui->lineEditPointX1XPixel->clear();
    this->ui->lineEditPointX1YPixel->clear();
    this->ui->lineEditPointX1Valeur->clear();
    this->ui->lineEditPointY0XPixel->clear();
    this->ui->lineEditPointY0YPixel->clear();
    this->ui->lineEditPointY0Valeur->clear();
    this->ui->lineEditPointY1XPixel->clear();
    this->ui->lineEditPointY1YPixel->clear();
    this->ui->lineEditPointY1Valeur->clear();

    this->ui->lineEditPointDepartXPixel->clear();
    this->ui->lineEditPointDepartYPixel->clear();
    this->ui->lineEditPointDepartXReel->clear();
    this->ui->lineEditPointDepartYReel->clear();
    this->ui->lineEditPointArriveeXPixel->clear();
    this->ui->lineEditPointArriveeYPixel->clear();
    this->ui->lineEditPointArriveeXReel->clear();
    this->ui->lineEditPointArriveeYReel->clear();
    this->ui->lineEditPointManuelXPixel->clear();
    this->ui->lineEditPointManuelYPixel->clear();
    this->ui->lineEditPointManuelXReel->clear();
    this->ui->lineEditPointManuelYReel->clear();

    this->ui->tableWidgetListePoints->clearContents();
    this->ui->tableWidgetListePoints->setRowCount(0);
    this->ui->tableWidgetListePoints->resizeColumnsToContents();

    this->ui->statusBar->clearMessage();

    this->activerBouton(0);

    this->effacerVueGraphiqueEtude();
}

void EcranPrincipal::actualiserElementsGraphiques()
{
    const Repere& repere = this->etude.getRepere();
    const int methodeConversion =
            this->etude.getParametres().getParametresConversion().getMethodeConversion();

    if ((methodeConversion == ParametresConversion::BRUTE)
            || (methodeConversion == ParametresConversion::NOIR_ET_BLANC))
    {
        this->ui->radioButtonNoirEtBlanc->setChecked(true);
    }
    else if (methodeConversion == ParametresConversion::NIVEAUX_DE_GRIS)
    {
        this->ui->radioButtonNiveauxDeGris->setChecked(true);
    }
    else if (methodeConversion == ParametresConversion::TEINTES_SATUREES)
    {
        this->ui->radioButtonTeintesSaturees->setChecked(true);
    }

    this->ui->lineEditPointX0XPixel->setText(QString::number(repere.getPointX0().getPointPixelX()));
    this->ui->lineEditPointX0YPixel->setText(QString::number(repere.getPointX0().getPointPixelY()));
    this->ui->lineEditPointX0Valeur->setText(QString::number(repere.getPointX0().getPointReelX()));
    this->ui->lineEditPointX1XPixel->setText(QString::number(repere.getPointX1().getPointPixelX()));
    this->ui->lineEditPointX1YPixel->setText(QString::number(repere.getPointX1().getPointPixelY()));
    this->ui->lineEditPointX1Valeur->setText(QString::number(repere.getPointX1().getPointReelX()));
    this->ui->lineEditPointY0XPixel->setText(QString::number(repere.getPointY0().getPointPixelX()));
    this->ui->lineEditPointY0YPixel->setText(QString::number(repere.getPointY0().getPointPixelY()));
    this->ui->lineEditPointY0Valeur->setText(QString::number(repere.getPointY0().getPointReelY()));
    this->ui->lineEditPointY1XPixel->setText(QString::number(repere.getPointY1().getPointPixelX()));
    this->ui->lineEditPointY1YPixel->setText(QString::number(repere.getPointY1().getPointPixelY()));
    this->ui->lineEditPointY1Valeur->setText(QString::number(repere.getPointY1().getPointReelY()));

    this->actualiserCoordonneesPoints();

    this->etude.restaurerImage();
    this->etude.convertirImage();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::creerNouvelleEtude()
{
    QString cheminFichierImageSource = QFileDialog::getOpenFileName(this,
            QString::fromUtf8("Sélection d'un fichier image"),
            this->etude.getParametres().getParametresFichiers().getCheminFichierImageSource(),
            QString::fromUtf8("Fichier image (*.bmp *.jpg *.jpeg *.png)"));
    if (cheminFichierImageSource.isEmpty())
        return;

    this->etude.clear();
    this->actualiserEtudeReference();

    Image image;
    image.setImageSource(QImage(cheminFichierImageSource));
    image.restaurerImage();
    this->etude.setImage(image);
    Parametres parametres;
    ParametresFichiers parametresFichiers = parametres.getParametresFichiers();
    parametresFichiers.setCheminFichierImageSource(cheminFichierImageSource);
    parametres.setParametresFichiers(parametresFichiers);
    this->etude.setParametres(parametres);

    this->effacerElementsGraphiques();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::chargerEtudeExistante()
{
    QString cheminFichierEtude = QFileDialog::getOpenFileName(this,
            QString::fromUtf8("Sélection d'un fichier étude"),
            this->etude.getParametres().getParametresFichiers().getCheminFichierEtude(),
            QString::fromUtf8("Fichier étude (*.ndc)"));
    if (cheminFichierEtude.isEmpty())
        return;

    this->etude.chargerEtude(cheminFichierEtude);
    this->actualiserEtudeReference();

    this->effacerElementsGraphiques();
    this->actualiserElementsGraphiques();
}

void EcranPrincipal::sauverEtudeCourante()
{
    QString cheminFichierEtude = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier étude"),
            this->etude.getParametres().getParametresFichiers().getCheminFichierEtude(),
            QString::fromUtf8("Fichier étude (*.ndc)"));
    if (cheminFichierEtude.isEmpty())
        return;

    this->etude.sauverEtude(cheminFichierEtude);
    this->actualiserEtudeReference();
}

void EcranPrincipal::exporterListeDePointsCourante()
{
    QString cheminFichierExport = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier export"),
            this->etude.getParametres().getParametresFichiers().getCheminFichierExport(),
            QString::fromUtf8("Fichier export (*.csv)"));
    if (cheminFichierExport.isEmpty())
        return;

    this->etude.exporterListeDePoints(cheminFichierExport);
}

void EcranPrincipal::exporterImageConvertieCourante()
{
    QString cheminFichierImageConvertie = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier image"),
            this->etude.getParametres().getParametresFichiers().getCheminFichierImageConvertie(),
            QString::fromUtf8("Fichier image Windows Bitmap (*.bmp);;"
                    "Fichier image JPEG (*.jpg *.jpeg);;"
                    "Fichier image PNG (*.png)"));
    if (cheminFichierImageConvertie.isEmpty())
        return;

    this->etude.exporterImageConvertie(cheminFichierImageConvertie);
}

void EcranPrincipal::verifierEtatSauvegardeEtude()
{
    if (this->etude.equals(this->etudeReference))
        return;

    QMessageBox* fenetreMessage = new QMessageBox(QMessageBox::Warning,
            QString::fromUtf8("Sauvegarde de l'étude courante"),
            QString::fromUtf8("Souhaitez-vous sauver l'étude courante ?"),
            QMessageBox::Yes | QMessageBox::No, this);
    fenetreMessage->setButtonText(QMessageBox::Yes, "Oui");
    fenetreMessage->setButtonText(QMessageBox::No, "Non");
    if (fenetreMessage->exec() == QMessageBox::No)
        return;

    this->sauverEtudeCourante();
}

void EcranPrincipal::actualiserEtudeReference()
{
    this->etudeReference = this->etude;
}

void EcranPrincipal::actualiserCoordonneesPoints()
{
    this->actualiserCoordonneesPointDepart();
    this->actualiserCoordonneesPointArrivee();
    this->actualiserCoordonneesPointManuel();
    this->actualiserCoordonneesListeDePoints();
}

void EcranPrincipal::actualiserCoordonneesPointDepart()
{
    const int pointPixelX = this->ui->lineEditPointDepartXPixel->text().toInt();
    const int pointPixelY = this->ui->lineEditPointDepartYPixel->text().toInt();
    double pointReelX = 0.0;
    double pointReelY = 0.0;
    this->etude.getRepere().pixelVersReel(pointPixelX, pointPixelY, pointReelX, pointReelY);
    this->ui->lineEditPointDepartXReel->setText(QString::number(pointReelX));
    this->ui->lineEditPointDepartYReel->setText(QString::number(pointReelY));
}

void EcranPrincipal::actualiserCoordonneesPointArrivee()
{
    const int pointPixelX = this->ui->lineEditPointArriveeXPixel->text().toInt();
    const int pointPixelY = this->ui->lineEditPointArriveeYPixel->text().toInt();
    double pointReelX = 0.0;
    double pointReelY = 0.0;
    this->etude.getRepere().pixelVersReel(pointPixelX, pointPixelY, pointReelX, pointReelY);
    this->ui->lineEditPointArriveeXReel->setText(QString::number(pointReelX));
    this->ui->lineEditPointArriveeYReel->setText(QString::number(pointReelY));
}

void EcranPrincipal::actualiserCoordonneesPointManuel()
{
    const int pointPixelX = this->ui->lineEditPointManuelXPixel->text().toInt();
    const int pointPixelY = this->ui->lineEditPointManuelYPixel->text().toInt();
    double pointReelX = 0.0;
    double pointReelY = 0.0;
    this->etude.getRepere().pixelVersReel(pointPixelX, pointPixelY, pointReelX, pointReelY);
    this->ui->lineEditPointManuelXReel->setText(QString::number(pointReelX));
    this->ui->lineEditPointManuelYReel->setText(QString::number(pointReelY));
}

void EcranPrincipal::actualiserCoordonneesListeDePoints()
{
    // TODO Gestion des accès aux éléments de la liste de points via des méthodes ajouterPoint(), supprimerPoint(), modifierPoint() et effacerPoints()

    QList<Point> listeDePoints;
    const int nombreDePoints = this->etude.getListeDePoints().count();
    for (int itPoint = 0; itPoint < nombreDePoints; itPoint++)
    {
        Point point = this->etude.getListeDePoints().at(itPoint);
        this->etude.getRepere().pixelVersReel(point);
        listeDePoints.append(point);
    }
    this->etude.setListeDePoints(listeDePoints);

    this->ui->tableWidgetListePoints->clearContents();
    this->ui->tableWidgetListePoints->setRowCount(nombreDePoints);
    for (int itPoint = 0; itPoint < nombreDePoints; itPoint++)
    {
        Point point = this->etude.getListeDePoints().at(itPoint);
        QTableWidgetItem* itemPointPixelX = new QTableWidgetItem(
                QString::number(point.getPointPixelX()));
        QTableWidgetItem* itemPointPixelY = new QTableWidgetItem(
                QString::number(point.getPointPixelY()));
        QTableWidgetItem* itemPointReelX = new QTableWidgetItem(
                QString::number(point.getPointReelX()));
        QTableWidgetItem* itemPointReelY = new QTableWidgetItem(
                QString::number(point.getPointReelY()));
        QTableWidgetItem* itemTypePoint = new QTableWidgetItem(point.getTypePointTexte());
        this->ui->tableWidgetListePoints->setItem(itPoint, 0, itemPointPixelX);
        this->ui->tableWidgetListePoints->setItem(itPoint, 1, itemPointPixelY);
        this->ui->tableWidgetListePoints->setItem(itPoint, 2, itemPointReelX);
        this->ui->tableWidgetListePoints->setItem(itPoint, 3, itemPointReelY);
        this->ui->tableWidgetListePoints->setItem(itPoint, 4, itemTypePoint);
    }
    this->ui->tableWidgetListePoints->resizeColumnsToContents();
}

void EcranPrincipal::effacerVueGraphiqueEtude()
{
    this->ui->vueGraphiqueEtude->effacer();
}

void EcranPrincipal::dessinerVueGraphiqueEtude()
{
    this->ui->vueGraphiqueEtude->dessiner(this->etude);
}

void EcranPrincipal::activerBouton(const QPushButton* pushButton)
{
    if (pushButton == 0 || !pushButton->isChecked())
    {
        this->ui->vueGraphiqueEtude->setDragMode(QGraphicsView::ScrollHandDrag);
        this->ui->pushButtonPointX0->setChecked(false);
        this->ui->pushButtonPointY0->setChecked(false);
        this->ui->pushButtonPointX1->setChecked(false);
        this->ui->pushButtonPointY1->setChecked(false);
        this->ui->pushButtonPointDepart->setChecked(false);
        this->ui->pushButtonPointArrivee->setChecked(false);
        this->ui->pushButtonPointManuel->setChecked(false);
        this->pushButtonActif = 0;
    }
    else
    {
        this->ui->vueGraphiqueEtude->setDragMode(QGraphicsView::NoDrag);
        if (this->pushButtonActif != 0 && this->pushButtonActif != pushButton)
        {
            this->pushButtonActif->setChecked(false);
        }
        this->pushButtonActif = (QPushButton*) pushButton;
    }
}

void EcranPrincipal::actualiserPoint(const QPointF& pointVueGraphique)
{
    if (this->pushButtonActif == this->ui->pushButtonPointX0
            || this->pushButtonActif == this->ui->pushButtonPointX1
            || this->pushButtonActif == this->ui->pushButtonPointY0
            || this->pushButtonActif == this->ui->pushButtonPointY1)
    {
        this->actualiserPointRepere(pointVueGraphique);
    }
    else if (this->pushButtonActif == this->ui->pushButtonPointDepart
            || this->pushButtonActif == this->ui->pushButtonPointArrivee
            || this->pushButtonActif == this->ui->pushButtonPointManuel)
    {
        this->actualiserPointCourbe(pointVueGraphique);
    }
}

void EcranPrincipal::actualiserPointRepere(const QPointF& pointVueGraphique)
{
    const int ppx = (int) floor(pointVueGraphique.x());
    const int ppy = (int) floor(pointVueGraphique.y());
    Repere repere = this->etude.getRepere();

    QString ppxTexte = QString::number(ppx);
    QString ppyTexte = QString::number(ppy);

    if (this->pushButtonActif == this->ui->pushButtonPointX0)
    {
        Point pointX0 = repere.getPointX0();
        pointX0.setPointPixelX(ppx);
        pointX0.setPointPixelY(ppy);
        repere.setPointX0(pointX0);
        this->etude.setRepere(repere);
        this->ui->lineEditPointX0XPixel->setText(ppxTexte);
        this->ui->lineEditPointX0YPixel->setText(ppyTexte);
        this->actualiserCoordonneesPoints();
        this->dessinerVueGraphiqueEtude();
        this->ui->lineEditPointX0Valeur->setFocus();
    }
    else if (this->pushButtonActif == this->ui->pushButtonPointX1)
    {
        Point pointX1 = repere.getPointX1();
        pointX1.setPointPixelX(ppx);
        pointX1.setPointPixelY(ppy);
        repere.setPointX1(pointX1);
        this->etude.setRepere(repere);
        this->ui->lineEditPointX1XPixel->setText(ppxTexte);
        this->ui->lineEditPointX1YPixel->setText(ppyTexte);
        this->actualiserCoordonneesPoints();
        this->dessinerVueGraphiqueEtude();
        this->ui->lineEditPointX1Valeur->setFocus();
    }
    else if (this->pushButtonActif == this->ui->pushButtonPointY0)
    {
        Point pointY0 = repere.getPointY0();
        pointY0.setPointPixelX(ppx);
        pointY0.setPointPixelY(ppy);
        repere.setPointY0(pointY0);
        this->etude.setRepere(repere);
        this->ui->lineEditPointY0XPixel->setText(ppxTexte);
        this->ui->lineEditPointY0YPixel->setText(ppyTexte);
        this->actualiserCoordonneesPoints();
        this->dessinerVueGraphiqueEtude();
        this->ui->lineEditPointY0Valeur->setFocus();
    }
    else if (this->pushButtonActif == this->ui->pushButtonPointY1)
    {
        Point pointY1 = repere.getPointY1();
        pointY1.setPointPixelX(ppx);
        pointY1.setPointPixelY(ppy);
        repere.setPointY1(pointY1);
        this->etude.setRepere(repere);
        this->ui->lineEditPointY1XPixel->setText(ppxTexte);
        this->ui->lineEditPointY1YPixel->setText(ppyTexte);
        this->actualiserCoordonneesPoints();
        this->dessinerVueGraphiqueEtude();
        this->ui->lineEditPointY1Valeur->setFocus();
    }
}

void EcranPrincipal::actualiserPointCourbe(const QPointF& pointVueGraphique)
{
    const int ppx = (int) floor(pointVueGraphique.x());
    const int ppy = (int) floor(pointVueGraphique.y());
    double prx = 0.0;
    double pry = 0.0;
    this->etude.getRepere().pixelVersReel(ppx, ppy, prx, pry);

    QString ppxTexte = QString::number(ppx);
    QString ppyTexte = QString::number(ppy);
    QString prxTexte = QString::number(prx);
    QString pryTexte = QString::number(pry);

    if (this->pushButtonActif == this->ui->pushButtonPointDepart)
    {
        this->ui->lineEditPointDepartXPixel->setText(ppxTexte);
        this->ui->lineEditPointDepartYPixel->setText(ppyTexte);
        this->ui->lineEditPointDepartXReel->setText(prxTexte);
        this->ui->lineEditPointDepartYReel->setText(pryTexte);
    }
    else if (this->pushButtonActif == this->ui->pushButtonPointArrivee)
    {
        this->ui->lineEditPointArriveeXPixel->setText(ppxTexte);
        this->ui->lineEditPointArriveeYPixel->setText(ppyTexte);
        this->ui->lineEditPointArriveeXReel->setText(prxTexte);
        this->ui->lineEditPointArriveeYReel->setText(pryTexte);
    }
    else if (this->pushButtonActif == this->ui->pushButtonPointManuel)
    {
        this->ui->lineEditPointManuelXPixel->setText(ppxTexte);
        this->ui->lineEditPointManuelYPixel->setText(ppyTexte);
        this->ui->lineEditPointManuelXReel->setText(prxTexte);
        this->ui->lineEditPointManuelYReel->setText(pryTexte);
    }
}

void EcranPrincipal::actualiserBarreStatut(const QPointF& pointVueGraphique)
{
    const int ppx = (int) floor(pointVueGraphique.x());
    const int ppy = (int) floor(pointVueGraphique.y());
    double prx = 0.0;
    double pry = 0.0;
    this->etude.getRepere().pixelVersReel(ppx, ppy, prx, pry);

    QString ppxTexte = QString::number(ppx);
    QString ppyTexte = QString::number(ppy);
    QString prxTexte = QString::number(prx);
    QString pryTexte = QString::number(pry);
    QString statusBarTexte = QString::fromUtf8("Pixel=(%1:%2) - Réel=(%3:%4)").arg(ppxTexte,
            ppyTexte, prxTexte, pryTexte);

    this->ui->statusBar->showMessage(statusBarTexte);
}

void EcranPrincipal::on_actionCreerEtude_triggered()
{
    this->verifierEtatSauvegardeEtude();
    this->creerNouvelleEtude();
}

void EcranPrincipal::on_actionChargerEtude_triggered()
{
    this->verifierEtatSauvegardeEtude();
    this->chargerEtudeExistante();
}

void EcranPrincipal::on_actionSauverEtude_triggered()
{
    this->sauverEtudeCourante();
}

void EcranPrincipal::on_actionExporterListePoints_triggered()
{
    this->exporterListeDePointsCourante();
}

void EcranPrincipal::on_actionExporterImage_triggered()
{
    this->exporterImageConvertieCourante();
}

void EcranPrincipal::on_actionQuitter_triggered()
{
    this->verifierEtatSauvegardeEtude();
    this->close();
}

void EcranPrincipal::on_actionParametresAffichage_triggered()
{
    Parametres parametres = this->etude.getParametres();
    ParametresAffichage parametresAffichage = parametres.getParametresAffichage();
    FenetreParametresAffichage* fenetreParametresAffichage = new FenetreParametresAffichage(this);
    fenetreParametresAffichage->setParametresAffichage(parametresAffichage);
    fenetreParametresAffichage->actualiserElementsGraphiques();
    if (fenetreParametresAffichage->exec() == QMessageBox::Rejected)
        return;
    parametresAffichage = fenetreParametresAffichage->getParametresAffichage();
    parametres.setParametresAffichage(parametresAffichage);
    this->etude.setParametres(parametres);

    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_actionParametresConversion_triggered()
{
    Parametres parametres = this->etude.getParametres();
    ParametresConversion parametresConversion = parametres.getParametresConversion();
    FenetreParametresConversion* fenetreParametresConversion = new FenetreParametresConversion(
            this);
    fenetreParametresConversion->setParametresConversion(parametresConversion);
    fenetreParametresConversion->actualiserElementsGraphiques();
    if (fenetreParametresConversion->exec() == QMessageBox::Rejected)
        return;
    parametresConversion = fenetreParametresConversion->getParametresConversion();
    parametres.setParametresConversion(parametresConversion);
    this->etude.setParametres(parametres);
}

void EcranPrincipal::on_actionParametresRecherche_triggered()
{
    Parametres parametres = this->etude.getParametres();
    ParametresRecherche parametresRecherche = parametres.getParametresRecherche();
    FenetreParametresRecherche* fenetreParametresRecherche = new FenetreParametresRecherche(this);
    fenetreParametresRecherche->setParametresRecherche(parametresRecherche);
    fenetreParametresRecherche->actualiserElementsGraphiques();
    if (fenetreParametresRecherche->exec() == QMessageBox::Rejected)
        return;
    parametresRecherche = fenetreParametresRecherche->getParametresRecherche();
    parametres.setParametresRecherche(parametresRecherche);
    this->etude.setParametres(parametres);
}

void EcranPrincipal::on_actionParametresExport_triggered()
{
    Parametres parametres = this->etude.getParametres();
    ParametresExport parametresExport = parametres.getParametresExport();
    FenetreParametresExport* fenetreParametresExport = new FenetreParametresExport(this);
    fenetreParametresExport->setParametresExport(parametresExport);
    fenetreParametresExport->actualiserElementsGraphiques();
    if (fenetreParametresExport->exec() == QMessageBox::Rejected)
        return;
    parametresExport = fenetreParametresExport->getParametresExport();
    parametres.setParametresExport(parametresExport);
    this->etude.setParametres(parametres);
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
            QString::fromUtf8("NumerisationDeCourbes - Version 1.0 (DD/MM/YYYY).\n"
                    "Réalisée par Alexis Foerster (alexis.foerster@gmail.com)."), QMessageBox::Ok,
            this);
    fenetreMessage->exec();
}

void EcranPrincipal::on_pushButtonConvertir_clicked()
{
    int methodeConversion = ParametresConversion::BRUTE;
    if (this->ui->radioButtonNoirEtBlanc->isChecked())
    {
        methodeConversion = ParametresConversion::NOIR_ET_BLANC;
    }
    else if (this->ui->radioButtonNiveauxDeGris->isChecked())
    {
        methodeConversion = ParametresConversion::NIVEAUX_DE_GRIS;
    }
    else if (this->ui->radioButtonTeintesSaturees->isChecked())
    {
        methodeConversion = ParametresConversion::TEINTES_SATUREES;
    }
    Parametres parametres = this->etude.getParametres();
    ParametresConversion parametresConversion = parametres.getParametresConversion();
    parametresConversion.setMethodeConversion(methodeConversion);
    parametres.setParametresConversion(parametresConversion);
    this->etude.setParametres(parametres);

    this->etude.convertirImage();

    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_pushButtonRestaurer_clicked()
{
    int methodeConversion = ParametresConversion::BRUTE;
    Parametres parametres = this->etude.getParametres();
    ParametresConversion parametresConversion = parametres.getParametresConversion();
    parametresConversion.setMethodeConversion(methodeConversion);
    parametres.setParametresConversion(parametresConversion);
    this->etude.setParametres(parametres);

    this->etude.restaurerImage();

    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX0XPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX0 = repere.getPointX0();
    pointX0.setPointPixelX(this->ui->lineEditPointX0XPixel->text().toInt());
    repere.setPointX0(pointX0);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX0YPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX0 = repere.getPointX0();
    pointX0.setPointPixelY(this->ui->lineEditPointX0YPixel->text().toInt());
    repere.setPointX0(pointX0);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX0Valeur_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX0 = repere.getPointX0();
    pointX0.setPointReelX(this->ui->lineEditPointX0Valeur->text().toDouble());
    repere.setPointX0(pointX0);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX1XPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX1 = repere.getPointX1();
    pointX1.setPointPixelX(this->ui->lineEditPointX1XPixel->text().toInt());
    repere.setPointX1(pointX1);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX1YPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX1 = repere.getPointX1();
    pointX1.setPointPixelY(this->ui->lineEditPointX1YPixel->text().toInt());
    repere.setPointX1(pointX1);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointX1Valeur_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX1 = repere.getPointX1();
    pointX1.setPointReelX(this->ui->lineEditPointX1Valeur->text().toDouble());
    repere.setPointX1(pointX1);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY0XPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY0 = repere.getPointY0();
    pointY0.setPointPixelX(this->ui->lineEditPointY0XPixel->text().toInt());
    repere.setPointY0(pointY0);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY0YPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY0 = repere.getPointY0();
    pointY0.setPointPixelY(this->ui->lineEditPointY0YPixel->text().toInt());
    repere.setPointY0(pointY0);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY0Valeur_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY0 = repere.getPointY0();
    pointY0.setPointReelY(this->ui->lineEditPointY0Valeur->text().toDouble());
    repere.setPointY0(pointY0);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY1XPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY1 = repere.getPointY1();
    pointY1.setPointPixelX(this->ui->lineEditPointY1XPixel->text().toInt());
    repere.setPointY1(pointY1);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY1YPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY1 = repere.getPointY1();
    pointY1.setPointPixelY(this->ui->lineEditPointY1YPixel->text().toInt());
    repere.setPointY1(pointY1);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_lineEditPointY1Valeur_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY1 = repere.getPointY1();
    pointY1.setPointReelY(this->ui->lineEditPointY1Valeur->text().toDouble());
    repere.setPointY1(pointY1);
    this->etude.setRepere(repere);

    this->actualiserCoordonneesPoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_pushButtonPointX0_clicked()
{
    this->activerBouton(this->ui->pushButtonPointX0);
}

void EcranPrincipal::on_pushButtonPointX1_clicked()
{
    this->activerBouton(this->ui->pushButtonPointX1);
}

void EcranPrincipal::on_pushButtonPointY0_clicked()
{
    this->activerBouton(this->ui->pushButtonPointY0);
}

void EcranPrincipal::on_pushButtonPointY1_clicked()
{
    this->activerBouton(this->ui->pushButtonPointY1);
}

void EcranPrincipal::on_lineEditPointDepartXPixel_textChanged()
{
    this->actualiserCoordonneesPointDepart();
}

void EcranPrincipal::on_lineEditPointDepartYPixel_textChanged()
{
    this->actualiserCoordonneesPointDepart();
}

void EcranPrincipal::on_lineEditPointArriveeXPixel_textChanged()
{
    this->actualiserCoordonneesPointArrivee();
}

void EcranPrincipal::on_lineEditPointArriveeYPixel_textChanged()
{
    this->actualiserCoordonneesPointArrivee();
}

void EcranPrincipal::on_lineEditPointManuelXPixel_textChanged()
{
    this->actualiserCoordonneesPointManuel();
}

void EcranPrincipal::on_lineEditPointManuelYPixel_textChanged()
{
    this->actualiserCoordonneesPointManuel();
}

void EcranPrincipal::on_pushButtonPointDepart_clicked()
{
    this->activerBouton(this->ui->pushButtonPointDepart);
}

void EcranPrincipal::on_pushButtonPointArrivee_clicked()
{
    this->activerBouton(this->ui->pushButtonPointArrivee);
}

void EcranPrincipal::on_pushButtonPointManuel_clicked()
{
    this->activerBouton(this->ui->pushButtonPointManuel);
}

void EcranPrincipal::on_pushButtonAjouter_clicked()
{
    const int pointPixelX = this->ui->lineEditPointManuelXPixel->text().toInt();
    const int pointPixelY = this->ui->lineEditPointManuelYPixel->text().toInt();
    double pointReelX = 0.0;
    double pointReelY = 0.0;
    this->etude.getRepere().pixelVersReel(pointPixelX, pointPixelY, pointReelX, pointReelY);

    QList<Point> listeDePoints = this->etude.getListeDePoints();
    Point point(pointPixelX, pointPixelY, pointReelX, pointReelY, Point::MANUEL);
    listeDePoints.append(point);
    this->etude.setListeDePoints(listeDePoints);

    this->actualiserCoordonneesListeDePoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_pushButtonRechercher_clicked()
{
    const QPoint pointPixelDepart = QPoint(this->ui->lineEditPointDepartXPixel->text().toInt(),
            this->ui->lineEditPointDepartYPixel->text().toInt());
    const QPoint pointPixelArrivee = QPoint(this->ui->lineEditPointArriveeXPixel->text().toInt(),
            this->ui->lineEditPointArriveeYPixel->text().toInt());
    const QList<QPoint> listeDePointsCourbe = this->etude.rechercherCourbe(pointPixelDepart,
            pointPixelArrivee);

    QList<Point> listeDePoints = this->etude.getListeDePoints();
    const int nombreDePointsCourbe = listeDePointsCourbe.count();
    for (int itPointCourbe = 0; itPointCourbe < nombreDePointsCourbe; itPointCourbe++)
    {
        Point pointCourbe = Point(listeDePointsCourbe.at(itPointCourbe), QPointF(),
                (itPointCourbe == 0) ? Point::COURBE_DEBUT :
                (itPointCourbe == (nombreDePointsCourbe - 1)) ? Point::COURBE_FIN : Point::COURBE);
        this->etude.getRepere().pixelVersReel(pointCourbe);
        listeDePoints.append(pointCourbe);
    }
    this->etude.setListeDePoints(listeDePoints);

    this->actualiserCoordonneesListeDePoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_pushButtonSupprimer_clicked()
{
    const QModelIndexList listeLignesSelectionnees =
            this->ui->tableWidgetListePoints->selectionModel()->selectedRows();

    QList<Point> listeDePoints = this->etude.getListeDePoints();
    const int nombreLignesSelectionnees = listeLignesSelectionnees.count();
    for (int itLigneSelectionnee = 0; itLigneSelectionnee < nombreLignesSelectionnees;
            itLigneSelectionnee++)
    {
        listeDePoints.removeAt(itLigneSelectionnee);
    }
    if (nombreLignesSelectionnees == 0)
    {
        listeDePoints.clear();
    }
    this->etude.setListeDePoints(listeDePoints);

    this->actualiserCoordonneesListeDePoints();
    this->dessinerVueGraphiqueEtude();
}

void EcranPrincipal::on_pushButtonGraphique_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonGraphique_clicked()
}

void EcranPrincipal::mousePressEventSlot(const QPointF pointVueGraphique)
{
    this->actualiserPoint(pointVueGraphique);

    this->activerBouton(0);
}

void EcranPrincipal::mouseMoveEventSlot(const QPointF pointVueGraphique)
{
    this->actualiserBarreStatut(pointVueGraphique);
}
