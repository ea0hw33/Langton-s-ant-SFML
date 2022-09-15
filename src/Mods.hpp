#include <string>

std::string Mods(int cases) {

    switch (cases) {
    case 0: 
        return "LR";
    break;
    case 1:
        return "RRLLLRLRL";
    break;
    case 2: {
        return "RLLLLRRRLLL";
    }
    break;
    default:
        return "LR";
    };
} 