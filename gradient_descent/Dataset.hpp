//
//  Dataset.hpp
//  gradient_descent
//
//  Created by ccchang on 2016/9/2.
//  Copyright © 2016年 張家銓. All rights reserved.
//

#ifndef Dataset_hpp
#define Dataset_hpp

#include <stdio.h>
#include <vector>

using namespace std;


class DATASET
{
public:
    DATASET();
    ~DATASET();
    void createTrainingData(int numOfData);
    void showTrainingData();
    double computeTargetFunction(int x1);
    vector<double> getX1Vector(){return m_vParameterX1;}
    vector<double> getYVector(){return m_vParameterY;}
private:
    vector<double> m_vParameterX1;
    vector<double> m_vParameterY;
    
};



#endif /* Dataset_hpp */
