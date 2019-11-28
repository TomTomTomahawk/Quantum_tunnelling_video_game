#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>

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


    double Ec=0;

    int windowSizeX = 800, windowSizeY = 600;

    CircleShape electron(rayon_electron);
    electron.setFillColor(Color::Blue);

    CircleShape photon(rayon_photon);
    photon.setFillColor(Color::Yellow);

    VertexArray phaut(LinesStrip,6);
    phaut[0].position = sf::Vector2f(0, 300);
    phaut[1].position = sf::Vector2f(100, 300);
    phaut[2].position = sf::Vector2f(100, 150);
    phaut[3].position = sf::Vector2f(250, 150);
    phaut[4].position = sf::Vector2f(250, 300);
    phaut[5].position = sf::Vector2f(400, 300);
    
    VertexArray pbas(LinesStrip,6);
    pbas[0].position = sf::Vector2f(0, 300);
    pbas[1].position = sf::Vector2f(100, 300);
    pbas[2].position = sf::Vector2f(100, 450);
    pbas[3].position = sf::Vector2f(250, 450);
    pbas[4].position = sf::Vector2f(250, 300);
    pbas[5].position = sf::Vector2f(400, 300);
    

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
        window.clear(Color::Black);
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y_electron > 0.0) {
            y_electron = y_electron -10;
            // move up...
        }    


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y_electron < 500) {
            y_electron = y_electron +10;
            // move up...
        }   
    
    if (
    
    if (x_photon >= windowSizeX) {
        x_photon=0;
        y_photon=600.0*(rand()/(RAND_MAX+1.0));
    }

    if (abs((x_photon+rayon_photon) - (x_electron+rayon_electron))<60 && abs((y_photon+rayon_photon) - (y_electron+rayon_electron))<60){
        Ec=Ec+0.1;
        x_photon=x_photon+3;
    } else {
        Ec = Ec - 0.01;
        x_photon=x_photon+10;
    }
    
    electron.setPosition(x_electron,y_electron);
    window.draw(electron);

    photon.setPosition(x_photon,y_photon);
    window.draw(photon);

    text.setString( to_string(Ec) );
    window.draw( text );


    window.draw(phaut);
    window.draw(pbas);
    window.display();
    }//fin boucle while SFML


return 0;

}
