#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdio.h>
#include "Input.hpp"

int main() {
    readFromFile(settings,ants);
    int sizeOfAnts=ants.size();
    for(int i = 0; i<sizeOfAnts;++i)
        for(int j = 0;j<ants[i].amount-1;++j)
            ants.push_back(ants[i]);  
    for(int i=0; i<ants.size();++i)
        ants[i].colorGradation=generatGradationOfColor(ants[i].color,ants[i].rules);

    indexOfColors(ants);

    int size=settings.sizeOfPixele;
    int width=settings.windowResolution[0];
    int height=settings.windowResolution[1];

    std::vector<std::vector<int>> matrix; 
    matrix.resize(width/size);
    for (int i = 0; i < width/size; i++) 
        matrix[i].resize(height/size,0);

    sf::RenderWindow window(sf::VideoMode(width, height), "Langton ant");
    sf::RectangleShape pixel(sf::Vector2f(size,size));
    sf::RectangleShape ant(sf::Vector2f(size,size));
    ant.setFillColor(sf::Color::Red);

    if(!error)
        while (window.isOpen()) {
            for(int boost=0; boost<settings.boost; ++boost)
                for(int id=0; id<ants.size();++id) 
                    ants[id].CalculatePosition(matrix,settings,ants);

            window.setFramerateLimit(settings.fps);
            sf::sleep(sf::milliseconds(settings.slowdown));
            sf::Event event;
            
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

        for (int x = 0; x < width/size; x++)
                for(int y = 0; y < height/size; y++) {
                    if(matrix[x][y]!=0) {
                        pixel.setPosition(x*size,y*size);
                        std::vector<int> color=FindColor(ants,matrix[x][y]);
                        pixel.setFillColor(sf::Color(color[0],color[1],color[2]));
                        window.draw(pixel);
                    }
                }
            
            for(int id=0;id<ants.size();++id) {
                ant.setPosition(ants[id].x*size,ants[id].y*size);
                window.draw(ant);
            }

            window.display();
            window.clear();
        }
    return 0;
}