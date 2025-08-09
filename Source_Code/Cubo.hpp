#ifndef CUBO_HPP
#define CUBO_HPP

#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#define PI 3.14

class Cubo : public sf::Drawable{

    protected:
        sf::VertexArray corpo;
        std::vector<sf::Vector3f> verticiOG;
        std::vector<sf::Vector3f> verticiArr;
        float dim, angRot;
        float rotInizX, rotInizY;

        void uptVertici();
        virtual void draw(sf::RenderTarget &target, sf::RenderStates stati) const override; 

    public:
        Cubo(float dim, float angRot);
        virtual ~Cubo();

        void CalRotation(float rotInizX, float rotInizY);
        void Move(float angRot);
        void RunCube();
};

#endif