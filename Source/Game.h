#pragma once

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Util/FPSCounter.h"
#include "States/StateBase.h"

/**
    Main controlling class of the game.
    Handles state switches and the main loop, as well
    as counting the FPS
*/
class Game
{
    public:
        Game();

        void run();

        template<typename T, typename... Args>
        void pushState(Args&&... args);

        void popState();

        const sf::RenderWindow& getWindow() const;

    private:
        void handleEvent();
        void tryPop();

        StateBase& getCurrentState();

        sf::RenderWindow m_window;
        std::vector<std::unique_ptr<StateBase>> m_states;

        FPSCounter counter;

        bool m_shouldPop = false;

};

template<typename T, typename... Args>
void Game::pushState(Args&&... args)
{
    m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
}