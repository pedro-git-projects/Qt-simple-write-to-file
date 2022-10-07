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
    Rectangles list;


    void readFloats();
    void printPrompt();
    void addToList();
    void loop();
    void setRunning(std::runtime_error err);
    Rectangle* createRect();
};

#endif // APP_H
