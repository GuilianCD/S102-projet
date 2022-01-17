#include <fstream>
#include <iostream>
#include <vector>

#include "func.h"
#include "matrix.h"
#include "wave.h"

int main(){
    using namespace std; 
    
    Wave encrypted;
    encrypted.read_wav("tetris_encrypted.wav");

    int cleMsg=10;
    string msgCache = "potato 2000 harvestor from the futur";
    addHiddenMsg(encrypted, msgCache, cleMsg);
    encrypted.readHiddenMsg(encrypted,cleMsg,msgCache.size());


    return 0;
}