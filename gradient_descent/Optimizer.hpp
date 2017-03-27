//
//  Optimizer.hpp
//  gradient_descent
//
//  Created by ccchang on 2016/9/2.
//  Copyright © 2016年 張家銓. All rights reserved.
//  An optimize object which uses gradient descent method
//

#ifndef Optimizer_hpp
#define Optimizer_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "Dataset.hpp"
using namespace std;

class OPTIMIZER
{
public:
    OPTIMIZER();
    ~OPTIMIZER();
    void setLearningRate(double learningRate) {m_dLearningRate = learningRate;}
    void loadData(DATASET ds);
    void startGradientDescent(int iIterations);
    void showPerformance();
    double getLeastSquareError();
    
private:
    double m_dLearningRate;
    double m_dW0;
    double m_dW1;
    vector<double> m_vParameterX1;
    vector<double> m_vParameterY;
};

#endif /* Optimizer_hpp */
