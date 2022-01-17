#include <fstream>
#include <iostream>
#include <vector>
#include <math.h>

#include "wave.h"

#include "matrix.h"
#include "vector.h"

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

int main(){
    using namespace std;

    Wave encrypted;
    encrypted.read_wav("tetris_encrypted.wav");

    Matrix decrypt = Matrix::readFromFile("decryption_key.txt");

    Wave decrypted = applyMatrixToWave(decrypt, encrypted);

    decrypted.write_wav("tetris_decrypted.wav");

/*
    Wave w ({0, 1, 2, 1, 0, -1, -2});
	Matrix m ({2, 5, 1, 3}, 2);

    w = applyMatrixToWave(m, w);

    for(short e = 0; e < w.size(); e++) {
        cout << w.getValAt(e) << " ";
    }
    cout << endl;

    return 0;

    Wave test1;
    test1.read_wav("tetris_encrypted.wav");
    test1.write_wav("copy_tetris.wav");

	Matrix mat1 ({2, 5, 1, 3}, 2);
	Vector vec1 ({3, 5});

	vec1 = vec1 * mat1;

	cout << vec1 << endl;

	Matrix mat2 = Matrix::fromString("2x3:1,2,3,4,5,6");

    cout << mat2 << endl;

    Matrix encrypt = Matrix::readFromFile("encryption_key.txt");

    cout << encrypt << endl;


    return 0;*/
}