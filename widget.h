#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QLineF>

class Widget : public QWidget
{
	Q_OBJECT

public:
	explicit		Widget(QWidget *parent = 0);
					~Widget();

protected:
	void			paintEvent(QPaintEvent *event);

private:
	void			calculerRectangleEnglobant();

public slots:
	void			miseAjourLignes(const QList<QLineF> &lignes);

private:
	QList<QLineF>	m_lignesADessiner;
	QRectF			m_rectangleEnglobant;
};

#endif // WIDGET_H
