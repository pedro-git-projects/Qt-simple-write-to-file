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
    float l;
    float w;
    float tempW;
    float tempL;
    Rectangles list;


    void readFloats();
    void printPrompt();
    void addToList();
    void loop();
    bool isNeagtive(float w, float l);
    Rectangle* createRect();
};

#endif // APP_H
