# Langton's ant on SFML (C++) #

## Description

[Langton's ant](https://en.wikipedia.org/wiki/Langton%27s_ant) is a two-dimensional universal Turing machine with a very simple set of rules but complex emergent behavior. It was invented by Chris Langton in 1986 and runs on a square lattice of black and white cells. The universality of Langton's ant was proven in 2000. The idea has been generalized in several different ways, such as turmites which add more colors and more states. 

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

The project is built on the [SFML](https://www.sfml-dev.org/index.php) C++ graphics library, so you need to download this library from the [official site](https://www.sfml-dev.org/download/sfml/2.5.1/). In this project I used SFML version 2.5.1 (GCC - 64-bit) for Linux.

### Installing

download [SFML library](https://www.sfml-dev.org/download/sfml/2.5.1/) or you can use the already installed library in the project

## Running the project

```
g++ -c main.cpp ; g++ main.o -o sfml-app -L <SFML library directory(for example: SFML-2.5.1/lib)> -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio ; ./sfml-app
```

# Instructions for the settings.txt file 

through the file settings.txt you can change the behavior of the program by changing the number of "ants", their color, the rule of behavior, and so on.
settings.txt has a json construct (it could have looked like settings.json but I did it via .txt ) so stick to the json format rules when changing values in the file.

example settings.txt design:

```
{
    "fps":"60",
    "slowdown":"0",
    "walls":"True",
    "sizeOfPixele":"10",
    "windowResolution":["1900","1000"],
    "boost":"10",
    "ant":[
        {
        "amount":"1",
        "name":"....er",
        "x":"center",
        "y":"center",
        "color":["255","255","0"],
        "rules":"LR",
        "rotation":"0"},
        {
        "amount":"4",
        "mod":"1",
        }
    ]
}
```








