#ifndef RECTANGLES_H
#define RECTANGLES_H

#include "rectangle.h"
#include <QVector>
#include <initializer_list>


class Rectangles {
public:
    Rectangles();
    Rectangles(std::initializer_list<Rectangle*> list);

    friend QTextStream& operator<<(QTextStream& dbg, const Rectangles& r);

    void print();

    QVector<Rectangle*> getRectList() const;

private:
    QVector<Rectangle*> rectList;
};


#endif // RECTANGLES_H
