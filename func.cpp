#ifndef FUNC_CPP
#define FUNC_CPP

#include <math.h>

#include "vector.h"
#include "func.h"

Wave applyMatrixToWave(const Matrix& mat, const Wave& wave){
    int cut = mat.width();

    std::vector<short> newWaveform;
    //Need to have enough size to contain all of the 'wave.size()' elements, in vectors of 'cut' size
    //And with integer division, it could go below that if the size is not a multiple of cut
    std::vector<Vector> vecs (std::ceil(wave.size() / (float)cut), Vector({}));

    int i;

    for (i = 0; i < wave.size(); i++)
    {
        vecs.at(i / cut).push_back(wave[i]);
    }
    
    //Add 0 until it's filled to the correct size.
    //The correct size 
    for (; i < cut * vecs.size(); i++)
    {
        vecs.at(i / cut).push_back(0);
    }
    
    
    for (i = 0; i < vecs.size(); i++)
    {
        vecs[i] = vecs[i] * mat;

        for (int j = 0; j < vecs[i].size(); j++)
        {
            newWaveform.push_back(vecs[i][j]);
        }   
    }

    return Wave(newWaveform);
}

Wave addHiddenMsg(Wave& wave, const std::string &hiddenMsg, int cleMsg){
    using namespace std;
    int j=0;
    for (int i = 0; i < wave.size()/hiddenMsg.size()-1; i++){
        if (i % cleMsg == 0 && j < hiddenMsg.size()){
            wave[i] = hiddenMsg[j];
            j++;
        }
    }
}



/*
Wave hideMessageLSB(const Wave& wave, const std::string& message_original) {
    std::string message = message_original;
    //Add a true 0 for when you read it
    message += '\0';

    //In a byte there are 8 bits
    //So to hide the message we need those many bits
    if(message.size()*8 > wave.size()){
        throw std::invalid_argument("Message should be at most 8 times shorter than the waveform :/");
    }

    std::vector<short> newWave;

    //Signed because >> will put 1 on the left since it already has a 1 there.
    signed char base = 0xFF, mask;
    char c;

    int i;
    for(i = 0; i < message.size(); i++){
        mask = base;
        //Isolate each bit, one by one
        for(int j = 0; j < 8-1; j++){
            //Take the current bit
            signed char n = mask & message[i];
            //move it to the least significant bit
            n >>= j;
        
            newWave.push_back(wave[(i*8)+j] & n);

            mask << 1;
        }
    }

    return Wave(newWave);
}

std::string readMessageLSB(const Wave& wave) {
    std::string message = "";

    char last = '\0';

    unsigned char curr;

    while(last != '\0'){

    }
}
*/


#endif