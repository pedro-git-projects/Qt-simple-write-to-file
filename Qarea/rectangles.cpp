#include "rectangles.h"
#include "rectangle.h"
#include <QString>
#include <QTextStream>
#include <QVector>
#include <initializer_list>
#include <iostream>

Rectangles::Rectangles() {
}

Rectangles::Rectangles(std::initializer_list<Rectangle*> list) {
    QVector<Rectangle*> rList;
    rList = list;
    this->rectList = rList;
}


QVector<Rectangle*> Rectangles::getRectList() const {
    return this->rectList;
}

QTextStream& operator<<(QTextStream& dbg, const Rectangles& r) {
    QVector<Rectangle*> list = r.getRectList();
    QString acc;
    for(int i = 0; i < list.size(); i++) {
        QString w = QString::number(list[i]->getWidth());
        QString l = QString::number(list[i]->getLength());

        QString rectL = "Length:" + l;
        QString rectW = "Width:" + w;

        acc += rectL + "\n" + rectW + "\n";
    }
    dbg << acc;
    return dbg;
}
