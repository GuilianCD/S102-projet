#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

#include "matrix.h"

class Vector
{
private:
    std::vector<int> innerVec;
public:
    Vector(std::vector<int> vec);

    //Thanks to https://stackoverflow.com/questions/37043078/c-overloading-array-operator#37043183
    //Allows use of the [] in both const and non const ways
    int& operator[](int i);
    int operator[](int i) const;
    
    void push_back(int i);
    int size() const;
};

Vector operator*(const Vector& vec, const Matrix& mat);
std::ostream& operator<<(std::ostream& os, const Vector& vec);


#endif