//
// Created by llSoK on 18.05.2021.
//

#ifndef LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_LUDECOMPOSITION_H
#define LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_LUDECOMPOSITION_H

#include <vector>
class luDecomposition {
private:
    std::vector<std::vector<double>> A, L, U;
    std::vector<std::vector<double>> al, au;
    std::vector<double> d;
    int n;
public:
    luDecomposition(const std::vector<std::vector<double>> &a, int n);

    void evaluate();
};


#endif //LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_LUDECOMPOSITION_H
