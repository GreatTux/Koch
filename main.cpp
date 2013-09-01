#include "widget.h"
#include "controles.h"
#include "processeur.h"
#include <QApplication>
#include <QDesktopWidget>

#define DEFAUT_LARGEUR	600
#define DEFAUT_ITER_MAX	4

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QDesktopWidget desktop;
	QRectF tailleEcran = desktop.availableGeometry();

	Controles controles(DEFAUT_LARGEUR, DEFAUT_ITER_MAX);
	Processeur processeur(DEFAUT_LARGEUR, DEFAUT_ITER_MAX);
	Widget w;

	QObject::connect(&controles, &Controles::largeur, &processeur, &Processeur::changerLargeur);
	QObject::connect(&controles, &Controles::lecture, &processeur, &Processeur::demarrerAnim);
	QObject::connect(&controles, &Controles::pause, &processeur, &Processeur::arreterAnim);
	QObject::connect(&controles, &Controles::iterationMax, &processeur, &Processeur::changerValeurMax);
	QObject::connect(&processeur, &Processeur::data, &w, &Widget::miseAjourLignes);

	w.resize(800,800);
	controles.show();
	w.show();

	controles.move(tailleEcran.width()/2 - (controles.frameSize().width()+w.frameSize().width())/2, 50);
	w.move(controles.x()+controles.frameSize().width(), 50);

	QObject::connect(&a, &QGuiApplication::lastWindowClosed, &QCoreApplication::quit);

	return a.exec();
}
