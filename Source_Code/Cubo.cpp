#include "Cubo.hpp"

using namespace std;
using namespace sf;

void Cubo::uptVertici(){
    
    typedef struct{
        int indici[4];
        float Zmedia;
        Color colore;
    }Faccia;

    const int facceMatrice[6][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {0,1,5,4},
        {2,3,7,6},
        {1,2,6,5},
        {0,3,7,4}
    };
    
    Color colorArr[6]={
        Color::Red,
        Color::Green,
        Color::Blue,
        Color::Yellow,
        Color::Magenta,
        Color::Cyan
    };

    vector<Faccia> facce;
    for (int i = 0; i < 6; i++) {
        Faccia f;
        float sommaZ = 0;
        for (int j = 0; j < 4; j++) {
            f.indici[j] = facceMatrice[i][j];
            sommaZ += verticiArr[f.indici[j]].z;
        }

        f.Zmedia = sommaZ / 4;
        f.colore = colorArr[i];
        facce.push_back(f);
    }

    sort(facce.begin(), facce.end(), [](const Faccia& a, const Faccia& b){
            return a.Zmedia < b.Zmedia;
        }
    );

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++){
            int indiceVer = facce[i].indici[j];
            Vector3f& v = verticiArr[indiceVer];
            corpo[i*4 + j].position = Vector2f(v.x + 400, v.y + 300);
            corpo[i*4 + j].color = facce[i].colore;
        }
    }
}

void Cubo::draw(RenderTarget &target, RenderStates states) const{
    target.draw(corpo, states);
}

Cubo::Cubo(float dim, float angRot) : corpo(Quads, 24), dim(dim), angRot(angRot), rotInizX(0), rotInizY(0)
{
    Vector3f v1(-dim/2,dim/2, 0);
    Vector3f v2(dim/2,dim/2, 0);
    Vector3f v3(dim/2,-dim/2, 0);
    Vector3f v4(-dim/2,-dim/2, 0);
    Vector3f v5(-dim/2,dim/2, -dim);
    Vector3f v6(dim/2,dim/2, -dim);
    Vector3f v7(dim/2,-dim/2, -dim);
    Vector3f v8(-dim/2,-dim/2, -dim);
    verticiOG = {v1, v2, v3, v4, v5, v6, v7, v8};
    verticiArr = verticiOG;

    uptVertici();
}

Cubo::~Cubo(){}

void Cubo::CalRotation(float rotInizX, float rotInizY)
{
    verticiArr = verticiOG;
    float rotX = rotInizX * PI/180.f;
    float rotY = rotInizY * PI/180.f;

    for(auto& v : verticiArr){
        float newY = v.y * cos(rotX) - v.z * sin(rotX);
        float newZ = v.y * sin(rotX) + v.z * cos(rotX);
        v.y = newY;
        v.z = newZ;

        float newX = v.x * cos(rotY) + v.z * sin(rotY);
        newZ = -v.x * sin(rotY) + v.z * cos(rotY);
        v.x = newX;
        v.z = newZ;
    }
    uptVertici();
}

void Cubo::Move(float angRot)
{
    if(Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)){
        rotInizY -= angRot;
    }
    if(Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)){
        rotInizY += angRot;
    }
    if(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)){
        rotInizX -= angRot;
    }
    if(Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)){
        rotInizX += angRot;
    }
    CalRotation(rotInizX, rotInizY);
}

void Cubo::RunCube(){
    Move(angRot);
}
