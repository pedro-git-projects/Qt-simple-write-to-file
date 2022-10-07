# Rectangle Area Calculator with File Output

## Objective

I create this project in order to familiarize myself with Qt's basic functionalities, thus, instead of making use of the C++ standard library, whenever possible I've used its Qt counter parts such as:

- QVector
- QTextStream
- QString
- QFile

The program is very simple, it asks the user for an arbirtrary number of width and height inputs, generates the corresponding rectangles, calculates their area and prints the output to a file called areas.txt.

## Implementation

Classes:

### Rectangle

This class represents a rectangle object and has two private members: *width* and *heigth*, both being double floating point precision types.
The QTextStream insertion operator, **<<** was overloaded in order to facilitate printing the object.

### Rectangles

This class is simply a QVector of pointers to Rectangle types and has a QVector of double called areas.

Here **std::initializer_list** was used in the constructor so as to be able to populate the QVector with as many Rectangle* as we'd like.

Once again the QTextStream insertion **<<** operator was overloaded.

### App

In order to further organize the code the class App was created. Its internal state tracks if the app is running and the current user inserted values.

This class further defines the following member functions:

```cpp
bool readFloats();
void printPrompt();
void addToList();
void loop();
bool isNeagtive(double w, double l);
bool isZero(double w, double l);
Rectangle* createRect();
void outputToFile();
```

being thus able to greatly simplify the main function, which ends up being:

```cpp
#include "app.h"

int main() {

    App* app = new App();
    app->loop();
    app->outputToFile();

    return 0;
}
```
