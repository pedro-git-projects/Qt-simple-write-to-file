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

    void addToList(Rectangle* rect);

    QVector<Rectangle*> getRectList() const;
    void setAreas();
    QVector<double> getAreas();
    void printAreas();

private:
    QVector<Rectangle*> rectList;
    QVector<double> areas;
};


#endif // RECTANGLES_H
