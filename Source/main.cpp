#include "regression.cpp"
#include <fstream>

using namespace std;


const unsigned int DEGREE = 5;
const string FNAME = "./Data/Populations.dat";
const char DELIMITER = '\t';

void readDataFile(_RegressionWrapper& rw, const string fname){
    ifstream fs(fname, ios::in);

    if(!fs){
        cout << "Can't open file: '" << fname << "'\n";
        exit(1);
    }

    int temp;

    

    while(fs >> temp){

    }
}


void readDataFile(_RegressionWrapper& rw, const string fname, const char delimiter,
                  const double _SCALEX=1, const double _SCALEY=0.0000001){
    ifstream fs(fname, fstream::in);
    string line, cell;
    unsigned int numTest1,numTest2;
    fs >> numTest1;
    fs >> rw._NUMTRAIN;
    fs >> numTest2;
    rw._NUMTEST = numTest1 + numTest2;

    rw._TESTX = zeros(rw._NUMTEST);
    rw._TESTY = zeros(rw._NUMTEST);
    rw._TRAINX = zeros(rw._NUMTRAIN);
    rw._TRAINY = zeros(rw._NUMTRAIN);

    for(int i = 0; i < numTest1; i++){
        rw._TESTX[i] = i;
        fs >> rw._TESTY[i];
        rw._TESTY[i] *= _SCALEY;
    }
    for(int i = 0; i < rw._NUMTRAIN; i++){
        rw._TRAINX[i] = i + numTest1;
        fs >> rw._TRAINY[i];
        rw._TRAINY[i] *= _SCALEY;
    }
    for(int i = 0; i < numTest2; i++){
        rw._TESTX[i + numTest1] = (i + rw._NUMTRAIN);
        fs >> rw._TESTY[i + numTest1];
        rw._TESTY[i + numTest1] *= _SCALEY;
    }
}

int main(int argc, const char **argv) {
    _RegressionWrapper rw(DEGREE);
    readDataFile(rw,FNAME,DELIMITER);
    rw.display();
    rw.fitCurve(true);
    rw.display();
    for(int i = 0; i < DEGREE; i++){
        cout << rw._COEFF(i) << ", ";
    }



    /*
    // Create a 4x4 random matrix and print it on the screen
    Mat<double> A = zeros(2,2);
    A << 1 << 2 << endr
      << 3 << 7 << endr;
    A.print("A:");
    Mat<double> B = zeros(2,1);
    B << 3 << endr << 10 << endr;
    B.print("B:");

    // Multiply A with his transpose:
    Mat<double> X = solve(A,B);
    X.print("X:");
    */

    return 0;
}
