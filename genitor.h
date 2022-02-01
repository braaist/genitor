#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <random>
#include <string>
#include <ctime>

using namespace std;

const int numRows=20;
const int numCols=20;
const int aminoacid_number = 10;
const int scaling_value = 4;

struct matrix {
	char Aminoacids[20];
	float Values[20][20];
};

struct flattenmatrix {
	char Aminoacids[20];
	float Values[210];
};

int getRandomNumber(int min, int max);

int fromMatrixToVector(int i, int j, int N);

void MatrixReader(struct flattenmatrix &Matrix, ifstream &is);

void MatrixPrinter(struct flattenmatrix &FlattenMatrix, ostream& outp);

flattenmatrix MatrixMutatorNew(struct flattenmatrix &FlattenMatrix, const int &aminoacid_number);

flattenmatrix MatrixCrosser(struct flattenmatrix &FlattenMatrix1, struct flattenmatrix &FlattenMatrix2);

flattenmatrix MatrixScaler(struct flattenmatrix &FlattenMatrix,
                    const int &numRows,
                    const int &numCols,
                    const int &aminoacid_number,
                    const int &scaling_value);
