#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;



int main()
{

    double x,y; // position du cercle
    x=400;
    y=300;
    int rayon = 50; // rayon du cercle
    int windowSizeX = 800, windowSizeY = 600;

    CircleShape cercle(rayon);
    cercle.setFillColor(Color::Blue);
    cercle.setOrigin(rayon,rayon);

    RenderWindow window(VideoMode(windowSizeX, windowSizeY), "Un cercle aléatoire");
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
        y = y-10;
        // move up...
    }    


    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        y = y+10;
        // move down...
    }   
    
    cercle.setPosition(x,y);
    window.draw(cercle);
    window.display();
    }
return 0;

}

