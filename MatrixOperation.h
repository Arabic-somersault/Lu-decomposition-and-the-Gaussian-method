//
// Created by Сергей on 19.05.2021.
//

#ifndef LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_MATRIXOPERATION_H
#define LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_MATRIXOPERATION_H
#include <vector>

class MatrixOperation {
public:
    static std::vector<double> mul(std::vector<double> a, std::vector<std::vector<double>> b);
    static std::vector<double> mul(std::vector<std::vector<double>> a,  std::vector<double> b);
    static double mul(std::vector<double> a, std::vector<double> b);
    static std::vector<double> mul(std::vector<double> a, double b);
    static std::vector<double> add(std::vector<double> a, std::vector<double> b);
    static std::vector<double> sub(std::vector<double> a, std::vector<double> b);
};


#endif //LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_MATRIXOPERATION_H
