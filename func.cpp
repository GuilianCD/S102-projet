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
        vecs.at(i / cut).push_back(wave.getValAt(i));
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

#endif