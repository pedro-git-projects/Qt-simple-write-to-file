#include <QTextStream>
#include <QVector>
#include "rectangle.h"

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

    cout.flush();
    return 0;
}
