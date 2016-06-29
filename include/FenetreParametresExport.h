#ifndef FENETREPARAMETRESEXPORT_H_
#define FENETREPARAMETRESEXPORT_H_

#include <QDialog>

namespace Ui
{
class FenetreParametresExport;
}

class FenetreParametresExport : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreParametresExport(QWidget* parent = 0);
    ~FenetreParametresExport();

    // TODO Implémentation de la classe FenetreParametresExport

private:
    Ui::FenetreParametresExport* ui;
};

#endif /* FENETREPARAMETRESEXPORT_H_ */
