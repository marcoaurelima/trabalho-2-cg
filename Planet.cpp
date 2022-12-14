#include "Planet.h"

Planet::Planet(GLfloat rotationVelocity, GLfloat translationVelocity, GLfloat orbitRadius, GLdouble size, std::string texturePath)
{
    this->translationVelocity = translationVelocity;
    this->rotationVelocity = rotationVelocity;
    this->orbitRadius = orbitRadius;
    this->size = size;

    // Fazer leitura da textura
    texture = SOIL_load_OGL_texture(
        texturePath.c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y);

    if (texture == 0)
    {
        std::cout << "Erro ao carregar a textura: " << texturePath << "\n"
                  << SOIL_last_result() << "\n";
    }

    obj.loadFromFile("models/esfera.obj");
    obj.loadTextureFile(texturePath);
}

Planet::~Planet()
{
}


void Planet::createSphere(GLdouble radius)
{
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    gluQuadricTexture(quadric, GL_TRUE);
    gluSphere(quadric, radius, QTD_FACES, QTD_FACES);
    gluDeleteQuadric(quadric);
}


void Planet::show()
{
    rotation += rotationVelocity;
    translation += translationVelocity;
    
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, texture);
    glPushMatrix();
    glTranslatef(0,0,0);
    glRotatef(translation, 0, 1, 0);
    glTranslatef(orbitRadius, 0.0, 0);
    glRotatef(rotation, 0, 1, 0);
    glTranslatef(0,0,0);
    glScalef(size,size,size);
    glTranslatef(0,0,0);

    obj.show();

    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

GLdouble Planet::getOrbitValue()
{
    return (GLdouble) orbitRadius;
}