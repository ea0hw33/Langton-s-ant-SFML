#ifndef _MSG_ERROR_
#define _MSG_ERROR_
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

bool error=false;

void ErrorMsg(std::string errorMsg) {
    std::cout<<errorMsg<<'\n';
}

void ErrorMsgOfStruct(std::string nameOfStruct,std::string object) {
    std::cout<<nameOfStruct<<" struct names error: "<<object<<" - parameter not found, some parameter(s) will be default\n";
}

void ErrorMsgDisplay(std::string errorMsg) {
    error=true;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "ErrorMsg");
    while (window.isOpen()) {
        sf::Font font;
        font.loadFromFile("font/arial.ttf");
        sf::Text text(errorMsg,font,40);
        text.setPosition (180, 500);
        text.setFillColor(sf::Color(255,255,255));
        sf::Event event;
        while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        window.draw(text);
        window.display();
        window.clear();
    }
}
#endif