#include <QTextStream>
#include <QVector>
#include <QFile>
#include "rectangle.h"
#include "rectangles.h"
#include "app.h"

bool isRunning = true;

int main() {
    QFile outputFile("areas.txt");
    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream cout(stdout);


    QTextStream out(&outputFile);

    App* app = new App();

   app->loop();
  // cout << app->list;
   app->list.printAreas();


    /*
    QTextStream cin(stdin);

    cout << "Enter '0' to quit" << Qt::endl;
    float w, l;
    while(isRunning) {
        cout << "-> Please enter the rectangle width and length separated by space" << Qt::endl;
        cin >> w >> l;
        //if(w == 0 || l == 0) isRunning = false;
        if(!(cin.status() == QTextStream::Ok)) {
            cout.setStatus(QTextStream::Ok);
            cout << "-> Please enter float values!" << Qt::endl;
            cin >> w >> l;
        }
    }


    Rectangle* r1 = new Rectangle(4.0, 2.0);
    Rectangles* rs = new Rectangles({r1, new Rectangle(1.0, 2.0), new Rectangle(7.0, 4.0)});

    cout << *rs;

    cout.flush();
    */
    outputFile.close();
    return 0;
}
