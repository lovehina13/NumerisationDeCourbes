#ifndef FENETREPARAMETRESRECHERCHE_H_
#define FENETREPARAMETRESRECHERCHE_H_

#include <QDialog>

namespace Ui
{
class FenetreParametresRecherche;
}

class FenetreParametresRecherche : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreParametresRecherche(QWidget* parent = 0);
    ~FenetreParametresRecherche();

    // TODO Implémentation de la classe FenetreParametresRecherche

private:
    Ui::FenetreParametresRecherche* ui;
};

#endif /* FENETREPARAMETRESRECHERCHE_H_ */
