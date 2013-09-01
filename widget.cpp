#include "widget.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
	QWidget(parent)
{
	this->setStyleSheet("background-color: white;");
}

Widget::~Widget()
{
}

void Widget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.save();
	painter.setRenderHint(QPainter::Antialiasing);

	painter.translate(this->width()/2.0 - m_rectangleEnglobant.center().x(),
					  this->height()/2.0 - m_rectangleEnglobant.center().y());

	painter.setPen(QPen(Qt::black, 0.0));

	for(int i=0; i<m_lignesADessiner.size(); ++i)
	{
		painter.drawLine(m_lignesADessiner.at(i));
	}

	painter.restore();
}

void Widget::calculerRectangleEnglobant()
{
	qreal xMin = INT_MAX, xMax = INT_MIN, yMin = INT_MAX, yMax = INT_MIN;

	for(int i=0; i<m_lignesADessiner.size(); ++i)
	{
		xMin = qMin(xMin, m_lignesADessiner.at(i).x1());
		xMin = qMin(xMin, m_lignesADessiner.at(i).x2());

		xMax = qMax(xMax,  m_lignesADessiner.at(i).x1());
		xMax = qMax(xMax,  m_lignesADessiner.at(i).x2());

		yMin = qMin(yMin, m_lignesADessiner.at(i).y1());
		yMin = qMin(yMin, m_lignesADessiner.at(i).y2());

		yMax = qMax(yMax,  m_lignesADessiner.at(i).y1());
		yMax = qMax(yMax,  m_lignesADessiner.at(i).y2());
	}

	m_rectangleEnglobant.setLeft(xMin);
	m_rectangleEnglobant.setTop(yMin);
	m_rectangleEnglobant.setRight(xMax);
	m_rectangleEnglobant.setBottom(yMax);
}

void Widget::miseAjourLignes(const QList<QLineF> &lignes)
{
	m_lignesADessiner = lignes;
	calculerRectangleEnglobant();
	update();
}
