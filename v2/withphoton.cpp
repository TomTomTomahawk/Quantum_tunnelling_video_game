#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <cmath>

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
    double Ec_max=2;

    double T; // Transmission
    double m_electron=9.109*pow(10,-31);
    double h= 6.62607015*pow(10,-34);
    double h_planck=1.054*pow(10,-24);
    double charge= 1.6*pow(10,-19);

    int windowSizeX = 800, windowSizeY = 600;

    //CircleShape electron(rayon_electron);
    //electron.setFillColor(Color::Blue);

    CircleShape photon(rayon_photon);
    photon.setFillColor(Color::Yellow);


    RenderWindow window(VideoMode(windowSizeX, windowSizeY), "projet MQ");
    window.setFramerateLimit(50);


//Sprites

    Image image;
    image.loadFromFile("electron.png");
    image.createMaskFromColor(Color::Black);
    Texture tex;
    tex.loadFromImage(image);
    Sprite sp;
    sp.setTexture(tex);
    sp.setScale(2*rayon_electron/sp.getLocalBounds().width, 2*rayon_electron/sp.getLocalBounds().height);
    sp.setOrigin(rayon_electron,rayon_electron);

//Background

    Image fond;
    fond.loadFromFile("background2.png");

//son affichage
    Texture tex_fond;
    tex_fond.loadFromImage(fond);
    Sprite sp_fond;
    sp_fond.setTexture(tex_fond);


//affichage Energie

    sf::Font font;

    if ( !font.loadFromFile( "./Arial.ttf" ) )
    {
        std::cout << "Error loading file" << std::endl;
        
        system( "pause" );
    }

    sf::Text text;

    text.setFont( font );
    
    text.setString( to_string(Ec) );

    text.setCharacterSize( 25 );
    
    text.setFillColor( sf::Color::White );
    
    text.setStyle( sf::Text::Style::Bold );
    
    text.setOutlineColor( sf::Color::Black );
    text.setOutlineThickness( 3 );
    text.setPosition(100,50);

//affichage Transmission

    sf::Font font2;

    if ( !font2.loadFromFile( "./Arial.ttf" ) )
    {
        std::cout << "Error loading file" << std::endl;
        
        system( "pause" );
    }

    sf::Text text_trans;

    text_trans.setFont( font );
    
    text_trans.setString( to_string(Ec) );

    text_trans.setCharacterSize( 25 );
    
    text_trans.setFillColor( sf::Color::White );
    
    text_trans.setStyle( sf::Text::Style::Bold );
    
    text_trans.setOutlineColor( sf::Color::Black );
    text_trans.setOutlineThickness( 3 );
    text_trans.setPosition(100,80);

//affichage hauteur du puit

    sf::Font font3;

    if ( !font2.loadFromFile( "./Arial.ttf" ) )
    {
        std::cout << "Error loading file" << std::endl;
        
        system( "pause" );
    }

    sf::Text text_puit;

    text_puit.setFont( font );
    
    text_puit.setString( to_string(Ec) );

    text_puit.setCharacterSize( 25 );
    
    text_puit.setFillColor( sf::Color::White );
    
    text_puit.setStyle( sf::Text::Style::Bold );
    
    text_puit.setOutlineColor( sf::Color::Black );
    text_puit.setOutlineThickness( 3 );
    text_puit.setPosition(100,110);


//Affichage puit

    double x1,x2,x3,x4,x5,x6;
    x1=windowSizeX;
    x2=windowSizeX+150;
    x3=windowSizeX+150;
    x4=windowSizeX+300;
    x5=windowSizeX+300;
    x6=windowSizeX+450;

    double y3, maxpuit, minpuit, y_puit;
    maxpuit=2;//hauteur maximal du puits
    minpuit=0;
    y_puit=590;//hauteur minimale, c'est a dire pas trop bas
    y3=(maxpuit - minpuit) *(rand()/(RAND_MAX+1.0));

    VertexArray phaut(LinesStrip,6);
    phaut[0].position = sf::Vector2f(x1, y_puit);
    phaut[1].position = sf::Vector2f(x2, y_puit);
    phaut[2].position = sf::Vector2f(x3, windowSizeY-(y3*windowSizeY/maxpuit));
    phaut[3].position = sf::Vector2f(x4, windowSizeY-(y3*windowSizeY/maxpuit));
    phaut[4].position = sf::Vector2f(x5, y_puit);
    phaut[5].position = sf::Vector2f(x6, y_puit);

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

    if (x_electron >= x1 && x_electron <= x6) {//jeu en periode de puits
        y_electron=windowSizeY-(Ec*windowSizeY)/Ec_max;
        double Ec_puit = (-maxpuit*y3)/y_puit +maxpuit;
	double epaisseur=pow(10,-9);

    if(Ec <Ec_puit){
         T=1/(1+Ec_puit*Ec_puit/
(4*Ec*charge*(Ec_puit-Ec))*pow(sinh(sqrt(2*m_electron*charge*(Ec_puit-Ec))/(h_planck)*epaisseur),2));//Transmission pour E<V0
}else {
        T=4*Ec*(Ec-Ec_puit)/((4*Ec*(Ec-Ec_puit))+Ec_puit*Ec_puit*pow(sin(sqrt(2*m_electron*charge*(Ec-Ec_puit)/h_planck)*(2*pow(10,-9))),2)); // Transmission pour E>V0
    }
    

    
        
    }
    else {//jeu comme d'hab
    

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y_electron > 0.0) {
            y_electron = y_electron -10;
            // move up...
        }    


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y_electron < windowSizeY-100.0) {
            y_electron = y_electron +10;
            // move up...
        }   
    
     
    
    if (x_photon >= windowSizeX) {//hauteur de lancement du photon et sa reinitialisation lorsqu'il depasse la fenetre
        x_photon=0;
        y_photon=600.0*(rand()/(RAND_MAX+1.0));
    }

    if (abs((x_photon+rayon_photon) - (x_electron+rayon_electron))<60 && abs((y_photon+rayon_photon) - (y_electron+rayon_electron))<60){

	if (Ec<2){
        
	Ec=Ec+0.03;
	}
        x_photon=x_photon+3;
    } else {
	if (Ec>0.003){
        Ec = Ec - 0.003;
	}
        x_photon=x_photon+10;
    }

}//fin scenario de jeu normal
    
    if (x6 <= 0) {//gerer la position du puit, 500 equivaut à 500 frames, soit 10 secondes car 50 f/s
    x1=windowSizeX;
    x2=windowSizeX+150;
    x3=windowSizeX+150;
    x4=windowSizeX+300;
    x5=windowSizeX+300;
    x6=windowSizeX+450;
    y3=(maxpuit - minpuit) *(rand()/(RAND_MAX+1.0));
    }

    x1=x1-1;
    x2=x2-1;
    x3=x3-1;
    x4=x4-1;
    x5=x5-1;
    x6=x6-1;
        
    phaut[0].position = sf::Vector2f(x1, y_puit);
    phaut[1].position = sf::Vector2f(x2, y_puit);
    phaut[2].position = sf::Vector2f(x3, windowSizeY-(y3*windowSizeY/maxpuit));
    phaut[3].position = sf::Vector2f(x4, windowSizeY-(y3*windowSizeY/maxpuit));
    phaut[4].position = sf::Vector2f(x5, y_puit);
    phaut[5].position = sf::Vector2f(x6, y_puit);

    
    //electron.setPosition(x_electron,y_electron);
    //window.draw(electron);

    window.draw(sp_fond);

    text.setString( "Ec_electron = " + to_string(Ec) + " eV");
    window.draw( text );

    text_trans.setString( "Transmission = " + to_string(T*100.0) + " %");
    window.draw( text_trans );

    text_puit.setString( "Hauteur du puits = " + to_string(y3) + " eV");
    window.draw( text_puit );

    sp.setPosition(x_electron+5,y_electron+5);
    window.draw(sp);

    photon.setPosition(x_photon,y_photon);
    window.draw(photon);

    window.draw(phaut);

    window.display();
    }//fin boucle while SFML


return 0;

}
