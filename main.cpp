#include <GL/glu.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <climits>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Planet.h"
#include "Sun.h"
#include "Orbits.h"
#include "SpaceShip.h"
#include "Object.h"

const GLint w = 1280, h = 720;

void initValues()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    const GLfloat params[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, params);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glViewport(0, 0, w, h);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
    initValues();
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;

    sf::Window window(sf::VideoMode(w, h), "Trabalho 2 de Computacao Grafica", sf::Style::Default, settings);
    window.setMouseCursorVisible(false);
    window.setVerticalSyncEnabled(true);

    Sun sun(500, LightParameters{35.0, 0.0, 35.0, 0.2}, "textures/sun.jpg");

    const float offset = 7;

    Planet mercury(3.11, 0.2500, (GLfloat)(60.0 * offset), 4.879, "textures/mercury.jpg");
    Planet venus(3.6, 0.09836, (GLfloat)(65.2 * offset), 12.104, "textures/venus.jpg");
    Planet earth(3.3574, 0.06000, (GLfloat)(69.3 * offset), 12.742, "textures/earth.jpg");
    Planet mars(3.866, 0.03157, (GLfloat)(77.2 * offset), 6.779, "textures/mars.jpg");
    Planet jupyter(4.5583, 0.0499, (GLfloat)(132.2 * offset), 139.820, "textures/jupiter.jpg");
    Planet saturn(3.6840, 0.0207, (GLfloat)(197.1 * offset), 116.460, "textures/saturn.jpg");
    Planet uranus(1.4794, 0.0071, (GLfloat)(341.3 * offset), 50.724, "textures/uranus.jpg");
    Planet neptune(0.9719, 0.0036, (GLfloat)(504.0 * offset), 49.244, "textures/neptune.jpg");

    Orbits orbits;
    orbits.add(mercury.getOrbitValue());
    orbits.add(venus.getOrbitValue());
    orbits.add(earth.getOrbitValue());
    orbits.add(mars.getOrbitValue());
    orbits.add(jupyter.getOrbitValue());
    orbits.add(saturn.getOrbitValue());
    orbits.add(uranus.getOrbitValue());
    orbits.add(neptune.getOrbitValue());

    SpaceShip ship(glm::vec3(3, 3, 3), Size(w, h));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }

            if (event.type == sf::Event::Resized)
            {
                glViewport(0, 0, (GLsizei)w, (GLsizei)h);
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        sun.illuminate();

        mercury.show();
        venus.show();
        earth.show();
        mars.show();
        jupyter.show();
        saturn.show();
        uranus.show();
        neptune.show();

        orbits.show();

        ship.show(window);

        window.display();
    }

    return EXIT_SUCCESS;
}
