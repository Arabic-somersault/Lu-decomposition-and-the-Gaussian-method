//
// Created by Сергей on 18.05.2021.
//
#include <vector>
#include <tuple>
#include <ProfileMatrix.h>

#ifndef LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_MATRIXGENERATOR_H
#define LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_MATRIXGENERATOR_H


class MatrixGenerator {
private:
    int n;
    int k;
    std::vector<std::vector<double>> matrix;

    void createMatrix();

public:

    MatrixGenerator(int n, int k) {
        this->n = n;
        this->k = k;
        createMatrix();
    }


    static ProfileMatrix convert2profile(const std::vector<std::vector<double>> &v);
    std::vector<std::vector<double>> getMatrix();




};


#endif //LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_MATRIXGENERATOR_H
