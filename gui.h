#include "raylib.h"
#ifndef GUI_H
#define GUI_H

class Gui{
    public:
        Gui();
        float progress{0.f};
        void createProgressBar();
        void updateProgressBar();
};

#endif