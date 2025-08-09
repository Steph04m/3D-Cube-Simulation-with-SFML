#include "RenderSim.hpp"

using namespace std;
using namespace sf;

//Metodi privati
void RenderSim::initVariables(){
    this->window = nullptr;
}

void RenderSim::initWindow(){
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    this->window = new RenderWindow(this->videoMode, "Simulazione Cubo");
}

//Metodi Pubblici
RenderSim::RenderSim(): c1(200,1){
    initVariables();
    initWindow();
}

RenderSim::~RenderSim(){
    delete this->window;
}

bool RenderSim::WRunning() const{
    return this->window->isOpen();
}

void RenderSim::WindowLoop(){
    while(this->window->pollEvent(this->event)){
        switch(this->event.type){
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                if(this->event.key.code == Keyboard::Escape){
                    this->window->close();
                    break;
                }
            default:
                break;
        }
    }    
}

float RenderSim::ViewFPS(){
    float time = clock.restart().asSeconds();
    FPS = 1.0f / time;
    return FPS;
}

void RenderSim::render(){
    
    //Per aggiungere roba allo schermo
    if(!font.loadFromFile("files_used/arial.ttf")){
        cerr << "Error: Font file not found." << endl;
        exit(EXIT_FAILURE); 
    }
    Text t1("Cubo 3D colorato", font, 30);
    t1.setPosition(10, 0);
    
    //FPS
    Text t2;
    t2.setFont(font);
    t2.setCharacterSize(30);
    t2.setPosition(10, 560);
    t2.setString("FPS: " + to_string(static_cast<int>(ViewFPS())));
  
    this->window->clear(Color::Black);
    this->window->setFramerateLimit(144);

    this->window->draw(t1);
    this->window->draw(t2);
    c1.RunCube();
    this->window->draw(c1);

    this->window->display();
}
