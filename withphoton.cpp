#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;



int main()
{

    double x_electron,y_electron; // position du cercle
    x_electron=400;
    y_electron=300;
    int rayon_electron = 50; // rayon du cercle

    double x_photon,y_photon; // position du cercle
    x_photon=0;
    y_photon=300;
    int rayon_photon = 10; // rayon du cercle

    int windowSizeX = 800, windowSizeY = 600;

    CircleShape electron(rayon_electron);
    electron.setFillColor(Color::Blue);
    electron.setOrigin(rayon_electron,rayon_electron);

    CircleShape photon(rayon_photon);
    photon.setFillColor(Color::Yellow);
    photon.setOrigin(rayon_photon,rayon_photon);


    RenderWindow window(VideoMode(windowSizeX, windowSizeY), "projet MQ");
    window.setFramerateLimit(50);

    // on fait tourner le programme tant que la fenêtre n’a pas été fermée

    while (window.isOpen()) {
        // on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération d
        Event event;
        while (window.pollEvent(event)) {
            // fermeture de la fenêtre lorsque l’utilisateur le souhaite
            if (event.type == Event::Closed)
            window.close();
        }
        window.clear(Color::White);
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            y_electron = y_electron -10;
            // move up...
        }    


        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            y_electron = y_electron +10;
            // move up...
        }   
    
    x_photon=x_photon+10;    
    
    electron.setPosition(x_electron,y_electron);
    window.draw(electron);

    photon.setPosition(x_photon,y_photon);
    window.draw(photon);

    window.display();
    }


return 0;

}
