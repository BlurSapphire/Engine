#include <iostream>
#include "../backend/window.h"

int main() {
    Window win;
    win.init();
    win.update();
    win.cleanup();
    return 0;
}
