#include <iostream>
#include <fstream>
#include <vector>

#include "wave.h"

using namespace std;

int main()
{
	/*
	// open file
	ifstream filein("entiers.txt");
	if(!filein.is_open())
	{
		cout << "file entiers.txt not found" << endl;
		return 1;
	}

	// read file content into vector
	vector<int> ints;
	int next_int;
	while(filein >> next_int)
	{
		ints.push_back(next_int);
	}

	// display vector
	for(int i = 0; i < ints.size(); i++)
	{
		cout << ints[i] << endl;
	}
	*/
	Wave test1;
    test1.read_wav("tetris_encrypted.wav");
	test1.write_wav("copy_tetris.wav");

	return 0;
}
