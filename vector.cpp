#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <iostream>

#include "vector.h"

int& Vector::operator[](int i) {
    return this->innerVec.at(i);
}
int Vector::operator[](int i) const {
    return this->innerVec.at(i);
}

Vector::Vector(std::vector<int> vec) {
    this->innerVec = vec;
}

void Vector::push_back(int i) {
    this->innerVec.push_back(i);
}

int Vector::size() const {
    return this->innerVec.size();
}

Vector operator*(const Vector& vec, const Matrix& mat) {
    if (vec.size() != mat.height()) {
        throw std::invalid_argument("Expected matrix and vector to be of the same size");
    }

    Vector ret(std::vector<int>(vec.size(), 0));

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < mat.width(); j++) {
            ret[i] += vec[j] * mat.getValAt(j, i);
        }
    }

    return ret;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "Displaying vector of size " << vec.size() << " :" << std::endl;
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << std::endl;
    }
    os << std::endl;
    return os;
}

#endif
