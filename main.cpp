#include <fstream>
#include <iostream>
#include <vector>

#include "func.h"
#include "matrix.h"

int main(){
    using namespace std;

    Wave encrypted;
    encrypted.read_wav("tetris_encrypted.wav");

    Matrix decrypt = Matrix::readFromFile("decryption_key.txt");

    Wave decrypted = applyMatrixToWave(decrypt, encrypted);

    decrypted.write_wav("tetris_decrypted.wav");

    return 0;
}