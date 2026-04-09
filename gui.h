#include "raylib.h"
#ifndef GUI_H
#define GUI_H

class Gui{
    public:
        // Progress bar
        Gui();
        float progress{0.f};
        void createProgressBar(int win_width, int win_height);
        void updateProgressBar();
};

class AbilityScoreGui{
    public:
        // Progress bars for ability scores
        AbilityScoreGui();
        float progress{0.f};
        void createProgressBar(int win_width, int win_height);
        void updateProgressBar(Gui);

};

#endif