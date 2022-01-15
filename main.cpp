#include <fstream>
#include <iostream>
#include <vector>

#include "wave.h"

#include "matrix.h"
#include "vector.h"

Wave applyMatrixToWave(const Matrix& mat, const Wave& wave){
    int cut = mat.width();

    std::vector<Vector> vecs (wave.size() / cut, Vector());

    int i;

    for (i = 0; i < wave.size(); i++)
    {
        vecs.at(i / cut).push_back(wave.getValAt(i));
    }
    
    for (i = 0; i < vecs.size(); i++)
    {
        vecs[i] = vecs[i] * mat;

        for (int j = 0; j < vecs[i].size(); j++)
        {
            /* code */
        }
        
    }
    
}

int main(){
    using namespace std;

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


    return 0;
}