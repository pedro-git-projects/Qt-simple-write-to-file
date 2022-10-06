#include "rectangle.h"
#include <QTextStream>
#include <QString>
#include <iostream>

Rectangle::Rectangle() {

}

Rectangle::Rectangle(double width, double length) {
    this->width = width;
    this->length = length;
}

double Rectangle::getWidth() const {
    return this->width;
}

double Rectangle::getLength() const {
    return this->length;
}

void Rectangle::setWidth(double width) {
    this->width = width;
}

void Rectangle::setLength(double length) {
    this->length = length;
}

double Rectangle::area() const {
    return this->length * this->width;
}

QTextStream& operator<<(QTextStream& dbg, const Rectangle& r) {
    QString w = QString::number(r.getWidth());
    QString l = QString::number(r.getLength());

    QString rectL = "Length:" + l;
    QString rectW = "Width:" + w;

   dbg << rectL + "\n"  +  rectW;

   return dbg;
}
