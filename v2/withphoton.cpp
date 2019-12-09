//ligne de compilation : c++ -Wextra -Wall ".cpp" -o ".x" -lsfml-graphics -lsfml-window -lsfml-system

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
	double Ec_Joules;
    double Ec_max=1;

    double T; // Transmission
    double m=9.109*pow(10,-31);
    double h= 6.62607015*pow(10,-34);
    double hbar=h/(2*M_PI);
	double k1;
	double k2;
	double d;//longueur de la barriere
	double random;//on va comparer T a un nombre entre 0 et 1 pour voir si transmis
	int pass;//deviendra 1 si passage, 2 si echec

    int windowSizeX = 800, windowSizeY = 600;


    CircleShape photon(rayon_photon);
    photon.setFillColor(Color::Yellow);


    RenderWindow window(VideoMode(windowSizeX, windowSizeY), "A probabilistic universe");
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
    text.setPosition(20,20);

//affichage hauteur du puits

    sf::Font font2;

    if ( !font2.loadFromFile( "./Arial.ttf" ) )
    {
        std::cout << "Error loading file" << std::endl;
        
        system( "pause" );
    }

    sf::Text text_puits;

    text_puits.setFont( font );
    
    text_puits.setString( to_string(Ec) );

    text_puits.setCharacterSize( 25 );
    
    text_puits.setFillColor( sf::Color::White );
    
    text_puits.setStyle( sf::Text::Style::Bold );
    
    text_puits.setOutlineColor( sf::Color::Black );
    text_puits.setOutlineThickness( 3 );
    text_puits.setPosition(20,50);

//affichage Transmission

    sf::Font font3;

    if ( !font3.loadFromFile( "./Arial.ttf" ) )
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
    text_trans.setPosition(20,80);

//affichage statut du jeu, si Game over ou pas, etc.

    sf::Font font4;

    if ( !font4.loadFromFile( "./Arial.ttf" ) )
    {
        std::cout << "Error loading file" << std::endl;
        
        system( "pause" );
    }

    sf::Text text_status;

    text_status.setFont( font );

    text_status.setCharacterSize( 40 );
    
    text_status.setFillColor( sf::Color::White );
    
    text_status.setStyle( sf::Text::Style::Bold );
    
    text_status.setOutlineColor( sf::Color::Black );
    text_status.setOutlineThickness( 3 );
    text_status.setPosition(windowSizeX/4,windowSizeY/2);


//Affichage puit

    double x1,x2,x3,x4,x5,x6;
    x1=windowSizeX;
    x2=windowSizeX+150;
    x3=windowSizeX+150;
    x4=windowSizeX+300;
    x5=windowSizeX+300;
    x6=windowSizeX+450;

    double U, U_Joules, maxpuits, minpuits, y_puits;
    maxpuits=1;//hauteur maximal du puits
    minpuits=0;
    y_puits=600;//hauteur minimale, c'est a dire pas trop bas
    U=(maxpuits - minpuits) *(rand()/(RAND_MAX+1.0));//hauteur de puits aleatoire entre 0 et 1 eV

    VertexArray phaut(LinesStrip,6);
    phaut[0].position = sf::Vector2f(x1, y_puits);
    phaut[1].position = sf::Vector2f(x2, y_puits);
    phaut[2].position = sf::Vector2f(x3, windowSizeY-(U*windowSizeY/maxpuits));//conversion des eV en pixels
    phaut[3].position = sf::Vector2f(x4, windowSizeY-(U*windowSizeY/maxpuits));
    phaut[4].position = sf::Vector2f(x5, y_puits);
    phaut[5].position = sf::Vector2f(x6, y_puits);

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

if (x_electron >=x1 && x_electron <=x5 && pass!=2){
    if (x_electron >= x1 && x_electron <= x4 - 2*rayon_electron) {//jeu en periode de puits

text_status.setString( "God is playing dice..." );
	if (y_electron+rayon_electron < windowSizeY-(Ec*windowSizeY)/Ec_max){
	
	y_electron = y_electron +4;
	
	}

	if (y_electron + rayon_electron > windowSizeY-(Ec*windowSizeY)/Ec_max){
	
	y_electron = y_electron -4;
	
	}

	Ec_Joules=Ec*1.60218*pow(10,-19);
	U_Joules=U*1.60218*pow(10,-19);
	k1= sqrt((2*m*Ec_Joules)/(hbar*hbar));
	k2=sqrt((2*m*(Ec_Joules-U_Joules))/(hbar*hbar));
	d=(x5-x2)*pow(10,-11);//Conversion des pixels en distance. 1 pixel = 10^-11 metre

    if(Ec_Joules > U_Joules){
        T=(4.0*k1*k1*k2*k2)/(4.0*k1*k1*k2*k2+(k1*k1-k2*k2)*(k1*k1-k2*k2)*sin(k2*d)*sin(k2*d)); // Transmission pour E>V0
    } else {
    
        T=1/(1+U_Joules*U_Joules/(4*Ec_Joules*(U_Joules-Ec_Joules))*pow(sinh(sqrt(2*m*(U_Joules-Ec_Joules))/(hbar)*d),2)); //Transmission pour E<V0  

    }
random = rand()/(RAND_MAX+1.0);//on genere un nombre aleatoire que l'on va ensuite comparer a T    
  
    }


	if (x_electron >= x4 - 2*rayon_electron && x_electron <= x5) {//jeu en periode de puits	

	
		if (T>random){
    			text_status.setString( "Carry on" );
			pass=1;
			
		} else {

	pass=2;

		
		}

	}
}

if(pass==2){
	x_electron=x_electron-2;
	text_status.setString( "Not this time, sorry mate" );

	if (x_electron <-200){
		T=0;
		text_status.setString( "Press Space to play again" );
	}
}


if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {//restart le jeu avec un nouveau puits
                x_electron=400;
    		y_electron=300;
		Ec=0;
		pass=0;

    		x6=0;
	text_status.setString( "" );
            
        }    



    if ((x_electron <=x1 || x_electron >=x5) && pass!=2) {//jeu en periode normale, sans puits
text_status.setString( "" );//on clear le texte

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y_electron > 0.0) {
            y_electron = y_electron -10;
            // move up...
        }    


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y_electron < windowSizeY-100.0) {
            y_electron = y_electron +10;
            // move down...
        }   
    
     
    
    if (x_photon >= windowSizeX) {//hauteur de lancement du photon et sa reinitialisation lorsqu'il depasse la fenetre
        x_photon=0;
        y_photon=600.0*(rand()/(RAND_MAX+1.0));
    }

    if (abs((x_photon+rayon_photon) - (x_electron+rayon_electron))<60 && abs((y_photon+rayon_photon) - (y_electron+rayon_electron))<60){

	if (Ec<Ec_max-0.008){
        
	Ec=Ec+0.008;
	} else {
	Ec=Ec_max;
	}
        x_photon=x_photon+3;
    } else {
	if (Ec>0.0008){
        Ec = Ec - 0.0008;
	} else {
	Ec=0;
	}
        x_photon=x_photon+10;
    }

}//fin scenario de jeu normal
    
    if (x6 <= 0) {//gerer la position du puits, 500 equivaut à 500 frames, soit 10 secondes car 50 f/s
    x1=windowSizeX;
    x2=windowSizeX+150;
    x3=windowSizeX+150;
    x4=windowSizeX+300;
    x5=windowSizeX+300;
    x6=windowSizeX+450;
    U=(maxpuits - minpuits) *(rand()/(RAND_MAX+1.0));
    }

    x1=x1-1;
    x2=x2-1;
    x3=x3-1;
    x4=x4-1;
    x5=x5-1;
    x6=x6-1;
        
    phaut[0].position = sf::Vector2f(x1, y_puits);
    phaut[1].position = sf::Vector2f(x2, y_puits);
    phaut[2].position = sf::Vector2f(x3, windowSizeY-(U*windowSizeY/maxpuits));
    phaut[3].position = sf::Vector2f(x4, windowSizeY-(U*windowSizeY/maxpuits));
    phaut[4].position = sf::Vector2f(x5, y_puits);
    phaut[5].position = sf::Vector2f(x6, y_puits);

    


    window.draw(sp_fond);

    text.setString( "Electron's kinetic energy = " + to_string(Ec) + " eV");
    window.draw( text );

    text_trans.setString( "Transmission probability = " + to_string(T*100.0) + " %");
    window.draw( text_trans );

    text_puits.setString( "Barrier's height = " + to_string(U) + " eV");
    window.draw( text_puits );

    sp.setPosition(x_electron+5,y_electron+5);
    window.draw(sp);

    photon.setPosition(x_photon,y_photon);
    window.draw(photon);

    window.draw(phaut);
window.draw( text_status );

    window.display();
    }//fin boucle while SFML


return 0;

}
