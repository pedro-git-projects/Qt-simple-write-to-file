#include "app.h"

#include <QTextStream>
#include <iostream>
#include <stdexcept>
#include "rectangle.h"

App::App() {
    this->isRunning = true;
}

void App::printPrompt() {
    QTextStream cout(stdout);
    cout << "-> Please enter the rectangle width and length separated by space" << Qt::endl;
}

void App::readFloats() {
    QTextStream cin(stdin);
    this->printPrompt();
    cin >> this->w >> this->l;

    if(cin.status() != QTextStream::Ok) {
        cin.resetStatus();
        throw std::runtime_error("-> Please make sure you enter a float");
    }
}

Rectangle* App::createRect() {
    try {
        this->readFloats();
        Rectangle* r = new Rectangle{this->w, this->l};
        return r;
    }

    catch(const std::runtime_error& err) {
        std::cout << err.what() << std::endl;
        return nullptr;
    }
}

void App::addToList() {
    Rectangle* r = this->createRect();
    if(r != nullptr) this->list.addToList(r);
}
