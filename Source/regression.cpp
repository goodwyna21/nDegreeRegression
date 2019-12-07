#ifndef _REGRESSION_H
#define _REGRESSION_H


#include <iostream>
#include <string>
#include <sstream>
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

#endif
