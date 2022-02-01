#include "genitor.h"

int getRandomNumber(int min, int max){
    const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int fromMatrixToVector(int i, int j, int N){
   if (i <= j)
      return i * N - (i - 1) * i / 2 + j - i;
   else
      return j * N - (j - 1) * j / 2 + i - j;
}

void MatrixPrinter(struct flattenmatrix &FlattenMatrix, ostream& outp){
  int s = 0;
	int val;

  outp << '\t';
  for (int i = 0; i < 20; i++){
    outp << FlattenMatrix.Aminoacids[i] << '\t';
  }
  outp << endl;

	for (int i = 0; i < 20; i++) {
    outp << FlattenMatrix.Aminoacids[i] <<  '\t';
		for (int j = 0; j < 20; j++) {
      val = fromMatrixToVector(i, j, 20);
			outp << FlattenMatrix.Values[val] << '\t';
		}
		outp << '\n';
	}
}

void MatrixReader(struct flattenmatrix &FlattenMatrix, ifstream &is){
  for (int i = 0; i < 20; i++){
		is >> FlattenMatrix.Aminoacids[i];
	}

	int k = 0;
  string line;

	for (int i = 1; i < 21; i++){
		for (int j = 0; j < 21; j++){
			if (j < i){
				is >> line;
				continue;
			}else{
				is >> FlattenMatrix.Values[k];
				k += 1;
			}
		}
	}
}

flattenmatrix MatrixMutatorNew(struct flattenmatrix &FlattenMatrix, const int &aminoacid_number){
  int maxnum = fromMatrixToVector(20, 20, 20);
  int haram = fromMatrixToVector(aminoacid_number, aminoacid_number, 20);
  int factor = getRandomNumber(0, 2);

  for (int i = 0; i < maxnum; i++){
    if (i != haram){
      factor = getRandomNumber(0, 2);
      FlattenMatrix.Values[i] -= 1;
      FlattenMatrix.Values[i] += factor;
    }
  }
  return FlattenMatrix;
}

flattenmatrix MatrixCrosser(struct flattenmatrix &FlattenMatrix1, struct flattenmatrix &FlattenMatrix2){
  int maxnum = fromMatrixToVector(20, 20, 20);
  int haram = fromMatrixToVector(aminoacid_number, aminoacid_number, 20);
  int factor = getRandomNumber(0, 2);

  return FlattenMatrix1;
}

flattenmatrix MatrixScaler(struct flattenmatrix &FlattenMatrix, const int &numRows, const int &numCols, const int &aminoacid_number, const int &scaling_value){
	float scaling_factor;
  int val;
  int maxnum = fromMatrixToVector(20, 20, 20);

	scaling_factor = scaling_value/FlattenMatrix.Values[fromMatrixToVector(aminoacid_number, aminoacid_number, 20)];
	for (int i = 0; i < maxnum; i++){
			FlattenMatrix.Values[i] = static_cast<int>(FlattenMatrix.Values[i]*scaling_factor);
	}
	return FlattenMatrix;
}
