#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <armadillo>
using namespace std;
using namespace arma;

double curve(double x, Mat<double> K, const unsigned int _DEGREE){
    double sum = 0;
    for(int n = 0; n <= _DEGREE; n++){
        sum += K(n)*pow(x,n);
    }
    return sum;
}

double cost(Mat<double> K,
            const unsigned int _DEGREE,
            const unsigned int _POINTS,
            const double* _XVALS,
            const double* _YVALS){
    double sum = 0;
    for(int i = 0; i < _POINTS; i++){
        sum += pow(curve(_XVALS[i], K, _DEGREE) - _YVALS[i],2);
    }
    return (sum / _POINTS);
}

Mat<double> fitCurve(const unsigned int _DEGREE,
                     const unsigned int _POINTS,
                     const double* _XVALS,
                     const double* _YVALS){
    Mat<double> A = zeros(_POINTS,_DEGREE+1);
    Mat<double> B = zeros(_POINTS,1);
    for(int y = 0; y < _POINTS; y++){
        for(int x = 0; x <= _DEGREE; x++){
            A(y,x) = pow(_XVALS[y],x);
        }
        B(y) = _YVALS[y];
    }
    Mat<double> K = solve(A.t() * A, A.t() * B);
    A.print("A:");
    B.print("B:");
    K.print("K:");

    return K;
}



struct _RegressionWrapper{
    const unsigned int _DEGREE;
    unsigned int _NUMTEST;  //number testing points
    unsigned int _NUMTRAIN; //number training points
    Mat<double> _TESTX;  //testing x-vals
    Mat<double> _TESTY;  //testing y-vals
    Mat<double> _TRAINX; //training x-vals
    Mat<double> _TRAINY; //training y-vals
    Mat<double> _COEFF; //coefficients


    _RegressionWrapper():_DEGREE(0){}
    ~_RegressionWrapper(){}
    _RegressionWrapper(const unsigned int degree):_DEGREE(degree){}
    _RegressionWrapper(const unsigned int degree, const string fname, const char delimiter,
                       const double _SCALEX=0.0000001, const double _SCALEY=0.0000001)
    :_DEGREE(degree){
        ifstream fs(fname, fstream::in);
        string line, cell;
        unsigned int numTest1,numTest2,index,section;
        getline(fs,line);
        stringstream ss(line);
        ss >> numTest1;
        ss >> _NUMTRAIN;
        ss >> numTest2;
        _NUMTEST = numTest1 + numTest2;

        _TESTX = zeros(_NUMTEST);
        _TESTY = zeros(_NUMTEST);
        _TRAINX = zeros(_NUMTRAIN);
        _TRAINY = zeros(_NUMTRAIN);

        index = 0;
        section = 0;
        bool word;
        while(getline(fs,line)){
            cell = "";
            word = false;

            for(int i = 0; i < line.size(); i++){
                if(line[i]!='\t'){
                    cell += line[i];
                } else {
                    if(section == 0){ //Test Section 1
                        if(word) {_TESTX(index) = (stoi(cell) * _SCALEX);}
                        else {_TESTY(index) = (stoi(cell) * _SCALEY);}
                        if(index == numTest1-1){
                            section++;
                            index = 0;
                        }
                    } else if(section == 1){ //Training
                        if(word) {_TRAINX(index) = stoi(cell) * _SCALEX;}
                        else {_TRAINY(index) = (stoi(cell) * _SCALEY);}
                        if(index == _NUMTRAIN-1){
                            section++;
                            index = numTest1-1;
                        }
                    } else if(section == 2){ //Test Section 2
                        if(word) {_TESTX(index) = (stoi(cell) * _SCALEX);}
                        else {_TESTY(index) = (stoi(cell)) * _SCALEY;}
                    }
                    cell="";
                    word = !word;
                }
            }
            index++;
        }
    }

    Mat<double>& fitCurve(bool _SHOW = false){
        Mat<double> A = zeros(_NUMTRAIN,_DEGREE+1);
        Mat<double> B = zeros(_NUMTRAIN);
        for(int y = 0; y < _NUMTRAIN; y++){
            for(int x = 0; x <= _DEGREE; x++){
                A(y,x) = pow(_TRAINX(y),x);
            }
            B(y) = _TRAINY(y);
        }
        _COEFF = solve(A.t() * A, A.t() * B);

        if(_SHOW){
            A.print("A: ");
            B.print("Y: ");
            _COEFF.print("K: ");
        }

        return _COEFF;
    }

    void display(){
        _TESTX.print("_TESTX: ");
        _TESTY.print("_TESTY: ");
        _TRAINX.print("_TRAINX: ");
        _TRAINY.print("_TRAINY: ");
        _COEFF.print("_COEFF: ");
    }
};

int main(int argc, const char **argv) {
    const unsigned int DEGREE = 3;
    const string FNAME = "./Data/USPopData.tsv";
    const char DELIMITER = '\t';

    _RegressionWrapper rw(DEGREE,FNAME,DELIMITER);
    rw.display();
    rw.fitCurve(true);
    rw.display();



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
