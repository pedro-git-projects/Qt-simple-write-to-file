#ifndef APP_H
#define APP_H

#include <QVector>
#include "rectangles.h"

class App {
public:
    App();
    bool isRunning;
    float l;
    float w;
    Rectangles list;


    void readFloats();
    void printPrompt();
    void addToList();
    Rectangle* createRect();
};

#endif // APP_H
