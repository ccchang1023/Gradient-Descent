//
//  main.cpp
//  gradient_descent
//
//  Created by ccchang on 2016/9/2.
//  Copyright © 2016年 張家銓. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iomanip>
#include "Dataset.hpp"
#include "Optimizer.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    DATASET ds;
    ds.createTrainingData(100);
    //ds.showTrainingData();
    OPTIMIZER opt;
    opt.loadData(ds);
    opt.setLearningRate(0.0001);
    opt.startGradientDescent(20000);
    return 0;
}


