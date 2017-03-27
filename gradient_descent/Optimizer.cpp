//
//  Optimizer.cpp
//  gradient_descent
//
//  Created by ccchang on 2016/9/2.
//  Copyright © 2016年 張家銓. All rights reserved.
//

#include "Optimizer.hpp"

OPTIMIZER::OPTIMIZER()
{
    m_dLearningRate = 0.000001;
    m_dW0 = 0;
    m_dW1 = 0;
}

OPTIMIZER::~OPTIMIZER()
{
    
}

void OPTIMIZER::loadData(DATASET ds)
{
    m_vParameterY = ds.getYVector();
    m_vParameterX1 = ds.getX1Vector();
}

double OPTIMIZER::getLeastSquareError()
{
    double sumOfError = 0;
    int N = static_cast<int>(m_vParameterY.size());
    for(int i=0;i<N;i++)
    {
        sumOfError += (m_vParameterY[i]-(m_dW1 * m_vParameterX1[i] + m_dW0)) *
                      (m_vParameterY[i]-(m_dW1 * m_vParameterX1[i] + m_dW0));
    }
    sumOfError /= static_cast<double>(N);
    return sumOfError;
}

void OPTIMIZER::showPerformance()
{
    cout << fixed << setprecision(7);
    cout << "w1=" << m_dW1
         << " w0=" << m_dW0
         << " least square error=" << getLeastSquareError() << endl;
}

void OPTIMIZER::startGradientDescent(int iIterations)
{
    double w0_gradient;
    double w1_gradient;
    double dError;
    int N = static_cast<int>(m_vParameterY.size());
    int iRounds = 1;
    while(iRounds <= iIterations)
    {
        w0_gradient = 0;
        w1_gradient = 0;
        for(int i=0;i<N;i++)
        {
            dError = (m_vParameterY[i] - ((m_dW1 * m_vParameterX1[i]) + m_dW0));
            w0_gradient += -(2/static_cast<double>(N)) * dError;
            w1_gradient += -(2/static_cast<double>(N)) * m_vParameterX1[i] * dError;
        }
        m_dW0 = m_dW0 - (m_dLearningRate * w0_gradient);
        m_dW1 = m_dW1 - (m_dLearningRate * w1_gradient);
        cout << "Iteration:" << iRounds << " ";
        showPerformance();
        iRounds++;
    }
    return ;
}
