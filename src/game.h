// #pragma once
#ifndef GAME_H
#define GAME_H

#include "game-state.h"

class Game 
{
    private:
    // Variables

    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    // Initialization

    void initWindow();
    void initStates();

    public:
        Game();
        virtual ~Game();

        // Functions

        // Regular

        void endApplication();
        
        // Update

        void updateDeltaTime();
        void updateSFMLEvents();
        void update();

        // Render

        void render();

        //Core

        void run();
};

#endif