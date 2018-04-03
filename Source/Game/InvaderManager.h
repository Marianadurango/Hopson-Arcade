#pragma once

#include "Invader.h"
#include "../DisplayInfo.h"
#include "Projectile.h"

#include <vector>

/**
    Class to manage the drawing and updating of invaders
*/
class InvaderManager
{
    public:
        InvaderManager();

        //Moves all of the invaders to the left or right, if the clock has reached a certain time
        void tryStepInvaders();

        //Draws all of the alive invaders
        void drawInvaders(sf::RenderTarget& target);

        //Tries to collide the invaders with the projectiles
        //Returns the points of collision
        std::vector<sf::Vector2f> tryCollideWithProjectiles(std::vector<Projectile>& projectiles);

    private:
        //Checks the invaders position to see if all the aliens should move down
        bool shouldMoveDown(const Invader& invader) const;

        std::vector<Invader> m_invaders;
        sf::Clock m_stepTimer;
        sf::Time m_stepGap;
        sf::RectangleShape m_invaderSprite;
        unsigned m_currFrame = 0;
        unsigned m_aliveInvaders;

        bool m_isMovingLeft = false;
        bool m_moveDown = false;
};