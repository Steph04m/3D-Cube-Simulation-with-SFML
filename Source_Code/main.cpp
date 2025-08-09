#include "Cubo.hpp"
#include "RenderSim.hpp"

using namespace sf;

int main(int argc, char* argv[])
{
    RenderSim r;
    while(r.WRunning()){
        r.WindowLoop();
        r.render();
    }
}
