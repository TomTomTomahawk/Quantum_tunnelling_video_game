#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>

using namespace std;
using namespace sf;



int main()
{

    int windowSizeX = 800, windowSizeY = 600;

    RenderWindow window(VideoMode(windowSizeX, windowSizeY), "projet MQ");
    window.setFramerateLimit(50);


//Affichage puit

    int x1,x2,x3,x4,x5,x6;
    x1=windowSizeX;
    x2=windowSizeX+150;
    x3=windowSizeX+150;
    x4=windowSizeX+300;
    x5=windowSizeX+300;
    x6=windowSizeX+450;

    int y3, maxpuit, minpuit;
    maxpuit=600;
    minpuit=5;

    y3=150;

    VertexArray phaut(LinesStrip,6);
    phaut[0].position = sf::Vector2f(x1, 300);
    phaut[1].position = sf::Vector2f(x2, 300);
    phaut[2].position = sf::Vector2f(x3, y3);
    phaut[3].position = sf::Vector2f(x4, y3);
    phaut[4].position = sf::Vector2f(x5, 300);
    phaut[5].position = sf::Vector2f(x6, 300);


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
    

    if (x6 <= 0) {//gerer la position du puit, 500 equivaut à 500 frames, soit 10 secondes car 50 f/s
    x1=windowSizeX;
    x2=windowSizeX+150;
    x3=windowSizeX+150;
    x4=windowSizeX+300;
    x5=windowSizeX+300;
    x6=windowSizeX+450;
    y3=(int)((maxpuit - minpuit) *(rand()/(RAND_MAX+1.0)));

    }

    x1=x1-6;
    x2=x2-6;
    x3=x3-6;
    x4=x4-6;
    x5=x5-6;
    x6=x6-6;

    phaut[0].position = sf::Vector2f(x1, 300);
    phaut[1].position = sf::Vector2f(x2, 300);
    phaut[2].position = sf::Vector2f(x3, y3);
    phaut[3].position = sf::Vector2f(x4, y3);
    phaut[4].position = sf::Vector2f(x5, 300);
    phaut[5].position = sf::Vector2f(x6, 300);



    window.draw(phaut);

    window.display();
    }//fin boucle while SFML


return 0;

}
