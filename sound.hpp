 #include <SFML/Audio.hpp>
 #include <string>


 std::string FindSound(int rotation){
    std::string music;
    switch (rotation)
    {
    case 0:
        music="0.wav";
        break;
    case 1:
        music="1.wav";
        break;
    case 2:
        music="2.wav";
        break;
    case 3:
        music="3.wav";
        break;
    default:
        music="1.wav";
        break;
    }
    return music;
}