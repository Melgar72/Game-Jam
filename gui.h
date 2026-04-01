#include "raylib.h"
#ifndef GUI_H
#define GUI_H

class Gui{
    public:
        // Progress bar
        Gui();
        float progress{0.f};
        void createProgressBar();
        void updateProgressBar();
};

class AbilityScoreGui{
    public:
        // Progress bars for ability scores
        AbilityScoreGui();
        float progress{0.f};
        void createProgressBar();
        void updateProgressBar(Gui);

};

#endif