
#ifndef MATRIX_CPP
#define MATRIX_CPP

#include <fstream>
#include "matrix.h"

Matrix::Matrix(std::vector<int> vec, int rep) {
    this->innerMatrix = std::vector<std::vector<int> >(vec.size() / rep, std::vector<int>(rep, 0));

    for (int i = 0; i < vec.size(); i++) {
        this->innerMatrix[i / rep][i % rep] = vec[i];
    }
}

Matrix Matrix::fromString(const std::string& str) {
    int width, height;
    std::vector<int> contents;
    int cpt = 0;

    std::string memory = "";

    while (cpt < str.length()) {
        if (str[cpt] == 'x') {
            width = std::stoi(memory);
            memory = "";
        } else if (str[cpt] == ':') {
            height = std::stoi(memory);
            memory = "";
        } else if (str[cpt] == ',') {
            contents.push_back(std::stoi(memory));
            memory = "";
        } else {
            memory += str[cpt];
        }
        cpt++;
    }
    //For the final element
    contents.push_back(std::stoi(memory));

    if ((width * height) != contents.size()) {
        throw std::invalid_argument("fromString() : Expected the same number of elements in the matrix as the width times the height.");
    }

    return Matrix(contents, width);
}

Matrix Matrix::readFromFile(const std::string& filename){
    // open file
	std::ifstream filein(filename);
	if(!filein.is_open())
	{
		throw std::invalid_argument("Expected a valid filename for Matrix::readFromFile()");
	}

    // read file content into vector
	std::vector<int> ints;
	int next_int;
	while(filein >> next_int)
	{
		ints.push_back(next_int);
	}

    // First two ints are the width and height of the matrix
    int width = ints[0];
    int height = ints[1];
    std::vector<int> content;

    for (int i = 2; i < ints.size(); i++)
    {
        content.push_back(ints[i]);
    }

    if(content.size() != width * height){
        throw std::invalid_argument("readFromFile() : Expected the same number of elements in the matrix as the width times the height.");
    }

    return Matrix(content, width);
}


int Matrix::width() const {
    return this->innerMatrix[0].size();
}
int Matrix::height() const {
    return this->innerMatrix.size();
}
std::vector<int> Matrix::getLine(int i) const {
    return this->innerMatrix[i];
}

void Matrix::setValAt(int x, int y, int val) {
    if(x >= this->width() || y >= this->height()){
        throw std::invalid_argument("(x,y) must represent a valid value of the matrix");
    } 

    //Invert x and y, because x is horizontal movement
    //And y is vertical movement
    this->innerMatrix[y][x] = val;
}

int Matrix::getValAt(int x, int y) const {
    //Invert x and y, because x is horizontal movement
    //And y is vertical movement
    // Also .at() because it's safe to use
    return this->innerMatrix.at(y).at(x);
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    os << "Displaying " << mat.width() << "x" << mat.height() << " matrix :" << std::endl;
    for (int i = 0; i < mat.height(); i++) {
        for (int e : mat.getLine(i)) {
            os << " " << e << " ";
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

#endif