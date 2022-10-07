#include "app.h"

#include <QTextStream>
#include <QFile>
#include <iostream>
#include <stdexcept>
#include "rectangle.h"

App::App() {
    this->isRunning = true;
}

void App::printPrompt() {
    QTextStream cout(stdout);
    cout << "-> Enter '-1' to exit" << Qt::endl;
    cout << "-> Please enter the rectangle width and length separated by space" << Qt::endl;
}

bool App::isNeagtive (double w, double l) {
    bool result = (w < 0 || l < 0) ? true : false;
    return result;
}

bool App::isZero (double w, double l) {
    bool result = (w == 0 || l ==  0) ? true : false;
    return result;
}

bool App::readFloats() {
    QTextStream cin(stdin);
    this->printPrompt();
    cin >> tempW >> tempL;

    if(!(this->isNeagtive(tempW, tempL)) && !(this->isZero(tempW, tempL))) {
        this->w = tempW;
        this->l = tempL;
        return true;
    } else if(this->isNeagtive(tempW, tempL) && !(this->isZero(tempW, tempL))) {
        this->isRunning = false;
        return false;
    } else {
        return false;
    }

    if(cin.status() != QTextStream::Ok) {
        cin.resetStatus();
        throw std::runtime_error("-> Please make sure you enter a float");
        return false;
    }
    return false;
}

Rectangle* App::createRect() {
    try {
        bool result = this->readFloats();
        if(result) {
            Rectangle* r = new Rectangle{this->w, this->l};
            std::cout << "CREATED" << std::endl;
            return r;
        }
        return nullptr;
    }

    catch(const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        return nullptr;
    }
}

void App::addToList() {
    Rectangle* r = this->createRect();
    if(r == nullptr) throw std::runtime_error("");
    this->list.addToList(r);
}

void App::loop() {
    while(this->isRunning) {
        try {
            this->addToList();
        }
        catch(std::runtime_error& err) {
            std::cerr << err.what() << std::endl;
        }
    }

    this->list.setAreas();
}

void App::outputToFile() {
    QFile outputFile("areas.txt");
    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&outputFile);

    auto areasVec = this->list.getAreas();

    std::cout << "Outputing to file..." << std::endl;
    for(int i = 0; i < areasVec.size(); i++) {
        out << areasVec[i] << Qt::endl;
    }

    outputFile.flush();
    outputFile.close();
}
