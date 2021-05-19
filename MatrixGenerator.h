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
public:

    MatrixGenerator(int n, int k) {
        this->n = n;
        this->k = k;
    }

    ProfileMatrix createMatrix(bool flag);
    static ProfileMatrix convert2profile(std::vector<std::vector<double>> v);
    static std::vector<std::vector<double>> profile2normal(ProfileMatrix matrix);




};


#endif //LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_MATRIXGENERATOR_H
