#include <bits/stdc++.h>

int numFromString(std::string num);

struct Settings {
    int fps=120;//значение по умолчанию
    int slowdown=0;//значние по умолчанию
    bool sound=false;
    bool walls=0;//занчение по умолчанию
    int sizeOfSquare=10;//значение по умолчанию
    std::vector<int> windowResolution={1000,1000};//размер экрана 1000x1000 по умолчанию
    int boost=1;

    int cases(std::string s) {
        std::vector<std::string> base={"fps","slowdown","walls","sizeOfSquare","windowResolution","boost","sound"};
        for(int i=0;i<base.size();++i){
            if(s==base[i]) return i;
        }
        std::cout<<"ошибка имен структуры Settings: "<<s<<" - параметры будут по умолчанию\n";
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
                sizeOfSquare=numFromString(dev[0]);
                break;
            case 4: {
                windowResolution[0]=numFromString(dev[0]);
                windowResolution[1]=numFromString(dev[1]);
            }
                break;
            case 5: 
                if(numFromString(dev[0])>1) boost=numFromString(dev[0]);
                break;
            case 6:
                if(dev[0]=="True" or dev[0]=="true" or dev[0]=="1") sound=true;
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