//==============================================================================
// Name        : EcranPrincipal.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0 (14/06/2016)
// Description : Source file of the EcranPrincipal class
//==============================================================================

#include "EcranPrincipal.h"
#include "Point.h"
#include "Repere.h"
#include "ui_EcranPrincipal.h"
#include <QList>
#include <QTableWidgetItem>

EcranPrincipal::EcranPrincipal(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::EcranPrincipal)
{
    this->ui->setupUi(this);
    this->actualiserCoordonneesPoints();
}

EcranPrincipal::~EcranPrincipal()
{
    delete this->ui;
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
    // TODO Gérer les accès aux éléments à la liste de points via ajouterPoint(), supprimerPoint(), modifierPoint() et effacerPoints()

    QList<Point> listeDePoints;
    const int nombreDePoints = this->etude.getListeDePoints().size();
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
        this->ui->tableWidgetListePoints->setItem(itPoint, 0, itemPointPixelX);
        this->ui->tableWidgetListePoints->setItem(itPoint, 1, itemPointPixelY);
        this->ui->tableWidgetListePoints->setItem(itPoint, 2, itemPointReelX);
        this->ui->tableWidgetListePoints->setItem(itPoint, 3, itemPointReelY);
    }
    this->ui->tableWidgetListePoints->resizeColumnsToContents();
}

void EcranPrincipal::on_actionCreer_toggled()
{
    // TODO void EcranPrincipal::on_actionCreer_toggled()
}

void EcranPrincipal::on_actionCharger_toggled()
{
    // TODO void EcranPrincipal::on_actionCharger_toggled()
}

void EcranPrincipal::on_actionSauver_toggled()
{
    // TODO void EcranPrincipal::on_actionSauver_toggled()
}

void EcranPrincipal::on_actionExporter_toggled()
{
    // TODO void EcranPrincipal::on_actionExporter_toggled()
}

void EcranPrincipal::on_actionQuitter_toggled()
{
    // TODO void EcranPrincipal::on_actionQuitter_toggled()
}

void EcranPrincipal::on_actionParametresAffichage_toggled()
{
    // TODO void EcranPrincipal::on_actionParametresAffichage_toggled()
}

void EcranPrincipal::on_actionParametresConversion_toggled()
{
    // TODO void EcranPrincipal::on_actionParametresConversion_toggled()
}

void EcranPrincipal::on_actionParametresRecherche_toggled()
{
    // TODO void EcranPrincipal::on_actionParametresRecherche_toggled()
}

void EcranPrincipal::on_actionParametresExport_toggled()
{
    // TODO void EcranPrincipal::on_actionParametresExport_toggled()
}

void EcranPrincipal::on_actionDocumentation_toggled()
{
    // TODO void EcranPrincipal::on_actionDocumentation_toggled()
}

void EcranPrincipal::on_actionAbout_toggled()
{
    // TODO void EcranPrincipal::on_actionAbout_toggled()
}

void EcranPrincipal::on_radioButtonNoirEtBlanc_clicked()
{
    // TODO void EcranPrincipal::on_radioButtonNoirEtBlanc_clicked()
}

void EcranPrincipal::on_radioButtonNiveauxDeGris_clicked()
{
    // TODO void EcranPrincipal::on_radioButtonNiveauxDeGris_clicked()
}

void EcranPrincipal::on_radioButtonTeintesSaturees_clicked()
{
    // TODO void EcranPrincipal::on_radioButtonTeintesSaturees_clicked()
}

void EcranPrincipal::on_pushButtonConvertir_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonConvertir_clicked()
}

void EcranPrincipal::on_pushButtonRestaurer_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonRestaurer_clicked()
}

void EcranPrincipal::on_lineEditPointX0XPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX0 = repere.getPointX0();
    pointX0.setPointPixelX(this->ui->lineEditPointX0XPixel->text().toInt());
    repere.setPointX0(pointX0);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointX0YPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX0 = repere.getPointX0();
    pointX0.setPointPixelY(this->ui->lineEditPointX0YPixel->text().toInt());
    repere.setPointX0(pointX0);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointX0Valeur_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX0 = repere.getPointX0();
    pointX0.setPointReelX(this->ui->lineEditPointX0Valeur->text().toDouble());
    repere.setPointX0(pointX0);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointX1XPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX1 = repere.getPointX1();
    pointX1.setPointPixelX(this->ui->lineEditPointX1XPixel->text().toInt());
    repere.setPointX1(pointX1);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointX1YPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX1 = repere.getPointX1();
    pointX1.setPointPixelY(this->ui->lineEditPointX1YPixel->text().toInt());
    repere.setPointX1(pointX1);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointX1Valeur_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointX1 = repere.getPointX1();
    pointX1.setPointReelX(this->ui->lineEditPointX1Valeur->text().toDouble());
    repere.setPointX1(pointX1);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointY0XPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY0 = repere.getPointY0();
    pointY0.setPointPixelX(this->ui->lineEditPointY0XPixel->text().toInt());
    repere.setPointY0(pointY0);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointY0YPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY0 = repere.getPointY0();
    pointY0.setPointPixelY(this->ui->lineEditPointY0YPixel->text().toInt());
    repere.setPointY0(pointY0);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointY0Valeur_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY0 = repere.getPointY0();
    pointY0.setPointReelY(this->ui->lineEditPointY0Valeur->text().toDouble());
    repere.setPointY0(pointY0);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointY1XPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY1 = repere.getPointY1();
    pointY1.setPointPixelX(this->ui->lineEditPointY1XPixel->text().toInt());
    repere.setPointY1(pointY1);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointY1YPixel_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY1 = repere.getPointY1();
    pointY1.setPointPixelY(this->ui->lineEditPointY1YPixel->text().toInt());
    repere.setPointY1(pointY1);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
}

void EcranPrincipal::on_lineEditPointY1Valeur_textChanged()
{
    Repere repere = this->etude.getRepere();
    Point pointY1 = repere.getPointY1();
    pointY1.setPointReelY(this->ui->lineEditPointY1Valeur->text().toDouble());
    repere.setPointY1(pointY1);
    this->etude.setRepere(repere);
    this->actualiserCoordonneesPoints();
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
}

void EcranPrincipal::on_pushButtonRechercher_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonRechercher_clicked()
}

void EcranPrincipal::on_pushButtonSupprimer_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonSupprimer_clicked()
}

void EcranPrincipal::on_pushButtonGraphique_clicked()
{
    // TODO void EcranPrincipal::on_pushButtonGraphique_clicked()
}
