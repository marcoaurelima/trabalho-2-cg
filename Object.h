#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <SOIL/SOIL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

struct Face {
    unsigned v;
    unsigned vt;
    unsigned vn;
};

using Vertices = std::vector<std::vector<float>>; 
using Textures = std::vector<std::vector<float>>; 
using Normal   = std::vector<std::vector<float>>; 
using Faces    = std::vector<std::vector<Face>>; 

class Object
{
public:
    Object();
    ~Object();

    void loadFromFile(std::string filename);
    void loadTextureFile(std::string filename);
    void show();

private:
    Vertices vertices;
    Textures textures;
    Normal normal;
    Faces faces;
    GLuint texture {};
};

#endif