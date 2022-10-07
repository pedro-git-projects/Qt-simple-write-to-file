#include "app.h"

int main() {

    App* app = new App();
    app->loop();
    app->outputToFile();

    return 0;
}
