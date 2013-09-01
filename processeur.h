#ifndef PROCESSEUR_H
#define PROCESSEUR_H

#include <QObject>
#include <QList>
#include <QLineF>
#include <QTimer>

class Processeur : public QObject
{
	Q_OBJECT
public:
	explicit		Processeur(int iInitLargeur, int iInitIter, QObject *parent = 0);

signals:
	void			data(const QList<QLineF> &lignes);

private:
	void			initGenZero();
	QPointF			calculSommet(QPointF pointA, QPointF pointB);

public slots:
	void			genererSuivant();
	void			changerValeurMax(int iGenMax);
	void			changerLargeur(int iLargeur);
	void			demarrerAnim();
	void			arreterAnim();

private:
	int				m_iCptGeneration;
	int				m_iGenerationMax;
	int				m_largeur;
	QList<QLineF>	m_lineList;
	QTimer			m_timer;
};

#endif // PROCESSEUR_H
