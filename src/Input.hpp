#include <bits/stdc++.h>
#include "Settings.hpp"
#include "Calculation.hpp"
#include "ErrorOutput.hpp"

char n;
std::ifstream stream;
void start(Settings&struckt, std::vector<Ant>&data,bool f);

bool isEmpty(std::ifstream& pFile) {
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void readFromFile(Settings&setting,std::vector<Ant>&ants) {
    stream.open("../settings.txt");
    if(isEmpty(stream)) ErrorMsgDisplay("file settings.txt is empty or not found.");
    while(stream.get(n)) {
        start(setting, ants,1);
    }
    stream.close();
}

void key(std::string&key) {
    int error_iteretion=0;
    while(stream.get(n)){
        if(n=='"') break;
        if(n==' ' or n=='\n') continue;
        ++error_iteretion;
        key+=n;
        if(error_iteretion>100){
            ErrorMsg("closing quote not found.");
            break;
        }
    }
}

void dev(std::vector<std::string>&devs) {
    if(n==']') ErrorMsg("end of array.");
    char b=n;
    std::string devv;
    while(stream.get(n)){
        char b=n;
        if(n==',' or n==']' or n=='}') break;
        if(n=='[') {
            while(n!=']') dev(devs);
            break;
        }
        if(n!='"' and n!=' ' and n!='\n') devv+=n;
    }
    devs.push_back(devv);
}

void start(Settings&setting, std::vector<Ant>&data,bool f) {
    std::string keys;
    std::vector<std::string> devs;
    while(stream.get(n)) {
        char b=n;
        if(n==' ' or n=='\n') continue;
        if(n=='"') key(keys);
        if(keys=="ant") {
                while (stream.get(n)) {
                    if(n==']') break;
                    if(n=='{') {
                        makeAnts(data);
                        while(true){
                            if(n=='}') break;
                            start(setting, data, 0);
                            if(n=='}') break;
                        }
                        if(n==']') break;
                    }
                }
        }
        if(n==':') dev(devs);
        if(n==',' or (n=='}' and f==0)){
            if(f) setting.Input(keys,devs);//input for "Settings"
            else data[data.size()-1].Input(keys,devs);//input for "Ant"
            break;
        }
        if(n=='}') break;
    }
}