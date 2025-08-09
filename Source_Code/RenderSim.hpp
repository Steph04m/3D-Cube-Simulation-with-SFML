#ifndef RENDERSIM_HPP
#define RENDERSIM_HPP

#include <iostream>
#include <cmath>
#include "Cubo.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class RenderSim{

    private:
        sf::RenderWindow* window;
        sf::VideoMode videoMode;
        sf::Event event;
        sf::Font font;
        sf::Clock clock;
        
        Cubo c1;
        float FPS;

        void initVariables();
        void initWindow();

    public:
        RenderSim();
        virtual ~RenderSim();

        bool WRunning() const;
        void WindowLoop();
        float ViewFPS();
        void render();
};

#endif