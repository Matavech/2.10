#include "point.h"
#include <QPainter>
Point::Point(float x,float y, int size,int thickness,bool isDragged)
    : x(x),y(y),size(size),thickness(thickness),isDragged(isDragged)
{}
float Point::getX() const
{
    return x;
}

void Point::setX(float newX)
{
    x = newX;
}

float Point::getY() const
{
    return y;
}

void Point::setY(float newY)
{
    y = newY;
}

bool Point::validate(){
    return (x > 0 && y > 0);
}

int Point::getThickness() const
{
    return thickness;
}

void Point::setThickness(int newThickness)
{
    thickness = newThickness;
}

int Point::getSize() const
{
    return size;
}

void Point::setSize(int newSize)
{
    size = newSize;
}

float Point::distance2(const QPoint &point){
     float xQuad = ((point.x() - x) * (point.x() - x));
     float yQuad = ((point.y() - x) * (point.y() - y));
     return (xQuad + yQuad);
}

bool Point::getIsDragged() const
{
    return isDragged;
}

void Point::setIsDragged(bool newIsDragged)
{
    isDragged = newIsDragged;
}


     ;
void Point::draw(QPainter *painter){
    int sizeModif = size / 2;
    QPen pen;
    pen.setWidth(thickness);
    (*painter).setPen(pen);
    (*painter).drawLine(x - sizeModif,y,x + sizeModif,y);
    (*painter).drawLine(x,y - sizeModif ,x,y + sizeModif);
}

void Point::connectPoints(QPainter *painter,Point *point){
    QPen pen;
    pen.setWidth(1);
    (*painter).setPen(pen);
    (*painter).drawLine((*point).x,(*point).y,x,y);
}


