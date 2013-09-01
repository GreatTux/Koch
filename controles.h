#ifndef CONTROLES_H
#define CONTROLES_H

#include <QWidget>

namespace Ui {
class Controles;
}

class Controles : public QWidget
{
	Q_OBJECT
	
public:
	explicit		Controles(int iInitLargeur, int iInitIteration, QWidget *parent = 0);
					~Controles();

signals:
	void			lecture();
	void			pause();
	void			iterationMax(int);
	void			largeur(int);

public slots:
	void			updateButtonText(bool actif);
	
private slots:
	void			on_button_clicked();
	void			on_iterationSlider_valueChanged(int value);
	void			on_largeurSlider_valueChanged(int value);

private:
	Ui::Controles	*ui;
	bool			lectureEnCours;
};

#endif // CONTROLES_H
