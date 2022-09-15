#include <vector>
#include <string>
#include "Mods.hpp"
#include "ErrorOutput.hpp"

struct Ant {
    //default values
    int x;
    int y;
    int mod=0;
    int amount=0;
    int rotation=0;
    int lastIndexOfColor;
    int firstIndexOfColor;
    std::string name;
    std::string rules="LR";
    std::vector<int> color{255,255,255};
    std::vector<std::vector<int>> colorGradation;

    int FindAnt(std::vector<Ant>&ants, int index) {
        for(int i = 0; i < ants.size(); ++i) {
            if(index <= ants[i].lastIndexOfColor) 
                return i;
        }

        ErrorMsg("ant not found.");
    } 

    int cases(std::string key) {
        std::vector<std::string> base = {"name","x","y","color","mod","rules","rotation","amount"};
        for(int i = 0;i < base.size(); ++i) {
            if(key==base[i]) return i;
        }
        ErrorMsgOfStruct("Ant",key);
    }

    void Input(std::string key, std::vector<std::string> dev) {
        int cass=-1;
        cass=cases(key);
        switch (cass)
        {
            case 0:
                name=dev[0];
                break;
            case 1: {
                if(!(dev[0]=="center" or dev[0]=="Center")) 
                x=numFromString(dev[0]);
            }
                break;
            case 2: {
                if(!(dev[0]=="center" or dev[0]=="Center")) 
                y=numFromString(dev[0]);
            }
                break;
            case 3:{
                color[0]=numFromString(dev[0]);
                color[1]=numFromString(dev[1]);
                color[2]=numFromString(dev[2]);
            }
                break;
            case 4: {
                mod=numFromString(dev[0]);
                rules=Mods(mod);
            }
                break;
            case 5:
                rules=dev[0];
                break;
            case 6:
                rotation=numFromString(dev[0]);
                break;
            case 7:
                amount=numFromString(dev[0]);
                break;
            default:
                break;
        }
    }

    void Rotation(int index){
        char C=rules[index];
        if(C=='L'){
            --rotation;
        }
        else if(C=='R'){
            ++rotation;
        }
    }
        
    void CalculatePosition(std::vector<std::vector<int>>&matrix, Settings&setting, std::vector<Ant>&ants){
        int index;
        index=FindAnt(ants,matrix[x][y]);
        index=matrix[x][y]-ants[index].firstIndexOfColor+1;
        if(index>=rules.size()) {matrix[x][y]=0; index=0;}
        Rotation(index);
        matrix[x][y]=firstIndexOfColor+index;
        if(rotation==-1) rotation=3;
        else if(rotation==4) rotation=0;
        if(x<setting.windowResolution[0]/setting.sizeOfPixele-1 and x>0 and y<(setting.windowResolution[1]/setting.sizeOfPixele-1) and y>0)
            switch (rotation)
            {
                case 0: --x;
                    break;
                case 1: ++y;
                    break;
                case 2: ++x;
                    break;
                case 3: --y;
                    break;
                default:
                    break;
            }
        if (setting.walls){
            if(x==setting.windowResolution[0]/setting.sizeOfPixele-1){++rotation; --x;}
            if(x==0){++rotation;++x;}
            if(y==setting.windowResolution[1]/setting.sizeOfPixele-1){++rotation; --y;}
            if(y==0){++rotation;++y;}
        }
    }

};

std::vector<Ant> ants; 
void makeAnts(std::vector<Ant>&data) {
    Ant a;
    a.x = settings.windowResolution[0]/(settings.sizeOfPixele*2);
    a.y = settings.windowResolution[1]/(settings.sizeOfPixele*2);
        data.push_back(a);
}

void indexOfColors(std::vector<Ant>&ants) {
    int index=0;
    for(int i=0;i<ants.size();++i){
        ++index;
        ants[i].firstIndexOfColor=index;
        index+=ants[i].rules.size()-1;
        ants[i].lastIndexOfColor=index;
    }
}

std::vector<int> FindColor(std::vector<Ant>&ants, int index) {
    std::vector<std::vector<int>> color;
    for(int i=0; i<ants.size();++i) {
        if(index<=ants[i].lastIndexOfColor) 
            return ants[i].colorGradation[index-ants[i].firstIndexOfColor];
    }
    ErrorMsg("color not found.");
}

std::vector<std::vector<int>> generatGradationOfColor(std::vector<int> color, std::string rool) {
    std::vector<std::vector<int>> colors;
    for(int i=0; i<rool.size();++i) {
        for(int j=0; j<3;++j) if(color[j]>25) color[j]-=25;
        colors.push_back(color);
    }
    return colors;
}
