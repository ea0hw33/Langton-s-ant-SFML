#include <vector>
#include <iostream>
#include <string>
#include "ErrorOutput.hpp"

int numFromString(std::string num);

struct Settings {
    //default values
    int fps=120;
    int slowdown=0;
    bool sound=false;
    bool walls=0;
    int sizeOfPixele=10;
    std::vector<int> windowResolution={1000,1000};//screen size 1000x1000 by default
    int boost=1;

    int cases(std::string key) {
        std::vector<std::string> base={"fps","slowdown","walls","sizeOfPixele","windowResolution","boost"};
        for(int i=0;i<base.size();++i){
            if(key==base[i]) return i;
        }
        ErrorMsgOfStruct("Settings",key);
    }

    void Input(std::string key,std::vector<std::string> dev) {
        int cass=cases(key);
        switch (cass)
        {
            case 0:
                fps=numFromString(dev[0]);
                break;
            case 1:
                slowdown=numFromString(dev[0]);
                break;
            case 2: {
                if(dev[0]=="true" or dev[0]=="True" or dev[0]=="1") walls=true;
                else walls=false;
            }
                break;
            case 3:
                sizeOfPixele=numFromString(dev[0]);
                break;
            case 4: {
                windowResolution[0]=numFromString(dev[0]);
                windowResolution[1]=numFromString(dev[1]);
            }
                break;
            case 5: 
                if(numFromString(dev[0])>1) boost=numFromString(dev[0]);
                break;
            default:
                break;
        }
    }
};

Settings settings;

int numFromString(std::string num) {
    return atoi(num.c_str());
}