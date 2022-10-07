#ifndef APP_H
#define APP_H

#include <QVector>
#include <stdexcept>
#include "rectangles.h"
#include "rectangle.h"

class App {
public:
    App();
    bool isRunning;
    double l;
    double w;
    double tempW;
    double tempL;
    Rectangles list;


    bool readFloats();
    void printPrompt();
    void addToList();
    void loop();
    bool isNeagtive(double w, double l);
    bool isZero(double w, double l);
    Rectangle* createRect();
};

#endif // APP_H
