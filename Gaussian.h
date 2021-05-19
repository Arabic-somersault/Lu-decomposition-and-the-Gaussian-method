//
// Created by llSoK on 18.05.2021.
//

#ifndef LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_GAUSSIAN_H
#define LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_GAUSSIAN_H

#include <vector>
#include <cmath>
class Gaussian {
private:
    std::vector<std::vector<double>> mas;
    std::vector<double> v;
    int n;
public:
    void evaluate();
    Gaussian(const std::vector<std::vector<double>> &mas, std::vector<double> v);
};


#endif //LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_GAUSSIAN_H
