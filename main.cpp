#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>
#include "InputAndOutput.hpp"

int main() {
    readFromFile(settings,antss);
    int sizeOfAntss=antss.size();
    for(int i = 0; i<sizeOfAntss;++i)
        for(int j = 0;j<antss[i].amount;++j)
            antss.push_back(antss[i]);  
    for(int i=0; i<antss.size();++i)
        antss[i].colorGradation=generatGradationOfColor(antss[i].color,antss[i].rools);

    indexOfColors(antss);
    
    int size=settings.sizeOfSquare;
    int width=settings.windowResolution[0];
    int height=settings.windowResolution[1];

    std::vector<std::vector<int>> matrix; 
    matrix.resize(height/size);
    for (int i = 0; i < height/size; i++) 
        matrix[i].resize(width/size,0);

    sf::Music music;
    sf::RenderWindow window(sf::VideoMode(width, height), "Langton ant");
    sf::RectangleShape squar(sf::Vector2f(size,size));
    sf::RectangleShape ant(sf::Vector2f(size,size));
    ant.setFillColor(sf::Color::Red);
    squar.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        for(int boost=0; boost<settings.boost; ++boost)
            for(int id=0; id<antss.size();++id) 
                antss[id].CalculatePosition(matrix,settings,antss);

        window.setFramerateLimit(settings.fps);
        sf::sleep(sf::milliseconds(settings.slowdown));
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       for (int x = 0; x < height/size; x++)
            for(int y = 0; y < width/size; y++) {
                if(matrix[x][y]!=0) {
                    squar.setPosition(x*size,y*size);
                    std::vector<int> color=FindColor(antss,matrix[x][y]);
                    squar.setFillColor(sf::Color(color[0],color[1],color[2]));
                    window.draw(squar);
                }
            }
        
        for(int id=0;id<antss.size();++id) {
            ant.setPosition(antss[id].x*size,antss[id].y*size);
            window.draw(ant);
            if(settings.sound){
                music.openFromFile(FindSound(antss[id].rotation)); music.play();
                while(music.getStatus()) continue;
            }
        }

        window.display();
        window.clear();
    }
    return 0;
}
