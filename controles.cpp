#include "controles.h"
#include "ui_controles.h"

//------------------------------- Constructeur ---------------------------------

Controles::Controles(int iInitLargeur, int iInitIteration, QWidget *parent) :
	QWidget(parent, Qt::Tool),
	ui(new Ui::Controles),
	lectureEnCours(false)
{
	ui->setupUi(this);

	ui->largeurSlider->setValue(iInitLargeur);
	ui->iterationSlider->setValue(iInitIteration);
	updateButtonText(false);
}

//------------------------------- Destructeur ----------------------------------

Controles::~Controles()
{
	delete ui;
}

//--------------------------------- Méthodes -----------------------------------

void Controles::updateButtonText(bool actif)
{
	if(actif)
		ui->button->setText("Pause");
	else
		ui->button->setText("Démarrer");
}

//---------------------------------- Slots -------------------------------------

void Controles::on_button_clicked()
{
	lectureEnCours = !lectureEnCours;
	updateButtonText(lectureEnCours);
	ui->largeurSlider->setEnabled(!lectureEnCours);

	if(lectureEnCours)
	{
		emit lecture();
	}
	else
	{
		emit pause();
	}
}

void Controles::on_iterationSlider_valueChanged(int value)
{
	emit iterationMax(value);
}

void Controles::on_largeurSlider_valueChanged(int value)
{
	emit largeur(value);
}
