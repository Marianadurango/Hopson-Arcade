#pragma once

#include <SFML/Graphics.hpp>

/*
    Class to represent a single invader
*/
class Invader
{
    public:
        enum class Type
        {
            Squid,
            Flat,
            Bug
        };

        Invader(const sf::Vector2f& initialLocation, Type type);

        void move(float x, float y);

        const sf::Vector2f& getPosition() const { return m_location; }
        bool isAlive() const { return m_isAlive; }
        Type getType() const { return m_type; }

        void hit() { m_isAlive = false; }

        sf::FloatRect getBox() const;

    private:
        sf::Vector2f m_location;
        bool m_isAlive = true;
        Type m_type;

    public:
        constexpr static float WIDTH = 48;
        constexpr static float HEIGHT = 32;
};