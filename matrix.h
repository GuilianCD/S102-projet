#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>
#include <vector>

class Matrix {
   private:
    std::vector<std::vector<int> > innerMatrix;

   public:
    /**
     * @brief Construct a new Matrix object, using a vector of ints (which contains all the matrix's content, 
     * read line first column second (line 1 column 1, line 1 column 2, etc...)), and an int indicating
     * how many numbers each line holds (3 means there are 3 numbers on each line)
     * 
     * @param vec the contents of the matrix, in a single vector
     * @param rep the width of the matrix
     */
    Matrix(std::vector<int> vec, int rep);

    ///* Getters etc

    /**
     * @brief returns the width of the matrix (which is also the number of columns)
     * @return int 
     */
    int width() const;
    /**
     * @brief returns the height of the matrix (which is also the number of lines)
     * @return int 
     */
    int height() const;
    std::vector<int> getLine(int i) const;

    int getValAt(int x, int y) const;

    ///* Setters etc
    
    void setValAt(int x, int y, int val);

    ///* Static functions

    /**
     * @brief Constructs a matrix from a file. It basically boils down to reading the 
     * contents of the file and calling the constructor.
     * 
     * @param filename the location of the file from which to read from on disk
     * @return Matrix 
     */
    static Matrix readFromFile(const std::string& filename);

    /**
     * @brief Constructs a matrix from a string. Assumes the string is correct ; that is, the
     * string follows the "NxM:V" template, where N is the width, M is the height, and V the comma-separated 
     * content. For example : "2x3:1,2,3,4,5,6" would translate to ((1,2),(3,4),(5,6)) (1,2 is the first line)
     * 
     * It was decided to use a static function to avoid repeating code from the Matrix constructor taking a 
     * vector and a matrix-width
     */
    static Matrix fromString(const std::string& str);

    
};

std::ostream& operator<<(std::ostream& os, const Matrix& mat);

#endif