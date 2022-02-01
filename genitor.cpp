#include "genitor.h"
using namespace std;

int main(int argc, char **argv) {

	//cast random values
	srand(static_cast<unsigned int>(time(0)));

	puts("Enter PATH to input sij matrix (tab-delimited columns only), PATH to output normalized matrix, binary flag of mutations usage");

	if (argc < 4){
		cout << "\nNot enough inputs!" << endl;
		exit (1);
	} else if (argc == 4) {
		printf("%s %s %s\n", argv[1], argv[2], argv[3]);
		cout << "\n Mutator started" << endl;
	} else if (argc == 5) {
		printf("%s %s %s %s\n", argv[1], argv[2], argv[3], argv[4]);
		cout << "\n Crosser started" << endl;
	} else {
		cout << "\n Too much inputs!" << endl;
	}

	matrix Matrix;
	flattenmatrix FlattenMatrix;
	float scaling_factor;
	ifstream inp(argv[1]);
	ofstream outp(argv[2]);

	MatrixReader(FlattenMatrix, inp);

	cout << "DEFAULT\n" << endl;
	MatrixPrinter(FlattenMatrix, cout);
	FlattenMatrix = MatrixScaler(FlattenMatrix, numRows, numCols, aminoacid_number, scaling_value);
	cout << "SCALED\n" << endl;
	MatrixPrinter(FlattenMatrix, cout);
	if (strcmp(argv[3], "0") == 0){
		cout << "No mutations!\n" << endl;
		MatrixPrinter(FlattenMatrix, outp);
	}else{
		cout << "Mutations!\n" << endl;
		FlattenMatrix = MatrixMutatorNew(FlattenMatrix, aminoacid_number);
		MatrixPrinter(FlattenMatrix, outp);
		MatrixPrinter(FlattenMatrix, cout);
	}

	return 0;
}
