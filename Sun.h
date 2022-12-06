#ifndef SUN_H
#define SUN_H

#pragma once

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Object.h"

// #include <SOIL/SOIL.h>

// #define QTD_FACES 200

struct LightParameters
{
    LightParameters(){}
    LightParameters(GLfloat diffuse, GLfloat specular, GLfloat positional,  GLfloat global)
    : diffuse(diffuse), specular(specular), positional(positional), global(global){}

    GLfloat diffuse;
    GLfloat specular;
    GLfloat positional;
    GLfloat global;
};

class Sun
{
public:
    Sun(GLdouble size, LightParameters lp, std::string texturePath);
    ~Sun();

    void illuminate();

private:
    GLdouble size{};

    LightParameters lp;
    
    GLfloat* ambientLight;
    GLfloat* diffuseLight;
    GLfloat* specularlight;
    GLfloat* positionalLight;
    GLfloat* globalLight;

    Object sphere;
};

#endif