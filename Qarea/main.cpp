#include <QTextStream>
#include "rectangle.h"

int main() {
    QTextStream cout(stdout);

    Rectangle r1;
    Rectangle r2(5.0, 2.0);

    cout << r2 << Qt::endl;

    cout.flush();
    return 0;
}
