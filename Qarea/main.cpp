#include <QTextStream>
#include <iostream>
#include <QVector>
#include <QFile>
#include "app.h"

int main() {
    QFile outputFile("areas.txt");
    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&outputFile);

    App* app = new App();
    app->loop();

    auto areasVec = app->list.getAreas();

    for(int i = 0; i < areasVec.size(); i++) {
        std::cout << "Outputing to file..." << std::endl;
        out << areasVec[i] << Qt::endl;
    }

    outputFile.flush();
    outputFile.close();

    return 0;
}
