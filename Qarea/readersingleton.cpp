#include "readersingleton.h"

#include <QString>
#include <QTextStream>


ReaderSingleton::ReaderSingleton() {
    QTextStream cin(stdin);
    this->cin = cin;
}

ReaderSingleton* ReaderSingleton::GetInstance() {
    if(reader == nullptr) reader = new ReaderSingleton();
    return reader;
}

