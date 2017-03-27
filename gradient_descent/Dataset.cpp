//
//  Dataset.cpp
//  gradient_descent
//
//  Created by ccchang on 2016/9/2.
//  Copyright © 2016年 張家銓. All rights reserved.
//

#include "Dataset.hpp"
#include <iostream>

DATASET::DATASET()
{
    
}

DATASET::~DATASET()
{
    
}

double DATASET::computeTargetFunction(int x1)
{
    double dResult = 0.9871239847891273 * x1 + 1.4768543;
    //Y    =            w1     * x1 +    w0
    return dResult;
}

void DATASET::createTrainingData(int numOfData)
{
    for(int i=1;i<=numOfData;i++)
    {
        m_vParameterX1.push_back(i);
        m_vParameterY.push_back(computeTargetFunction(i));
    }
    return ;
}

void DATASET::showTrainingData()
{
    for(int i=0;i<m_vParameterY.size();i++)
    {
        cout << "X1: " << m_vParameterX1[i] << " Y1: " << m_vParameterY[i] << endl;
    }
}




