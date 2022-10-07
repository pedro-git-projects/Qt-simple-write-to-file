#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QTextStream>

class Rectangle {
public:
    Rectangle(); // 1 x 1 square
    Rectangle(double width, double length);

    double getWidth() const;
    double getLength() const;

    void setWidth(double width);
    void setLength(double length);

    double area() const;
    friend QTextStream& operator<<(QTextStream& dbg, const Rectangle& r);

private:
    double width;
    double length;
};

#endif // RECTANGLE_H
