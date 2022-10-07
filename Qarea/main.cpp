#include <QTextStream>
#include <QVector>
#include <initializer_list>
#include <iostream>
#include "rectangle.h"
#include "rectangles.h"

int main() {
    QTextStream cout(stdout);
    QVector<Rectangle*> rectangles;

    rectangles.push_back(new Rectangle());
    rectangles.push_back(new Rectangle(7.5, 10.5));
    rectangles.push_back(new Rectangle(5.0, 2.0));

    for(int i = 0; i < rectangles.size(); i++) {
        cout << "Rectangle " << i + 1 << Qt::endl;
        cout << *rectangles[i] << Qt::endl;
        cout << "----------------------------" << Qt::endl;
    }

    // returning allocated memory
    for(int i = 0; i < rectangles.size(); i++) delete rectangles.at(i);

    Rectangle* r1 = new Rectangle(4.0, 2.0);
    Rectangles* rs = new Rectangles({r1, new Rectangle(1.0, 2.0), new Rectangle(7.0, 4.0)});

    cout << *rs;

    cout.flush();
    return 0;
}
