#ifndef READERSINGLETON_H
#define READERSINGLETON_H

#include <QTextStream>

class ReaderSingleton {
protected:
    ReaderSingleton();

    static ReaderSingleton* reader;

public:
    ReaderSingleton(ReaderSingleton& other) = delete; // not clonable

    void operator=(const ReaderSingleton&) = delete; // not assignable

    static ReaderSingleton* GetInstance();

private:
    QTextStream cin;
};

#endif // READERSINGLETON_H
