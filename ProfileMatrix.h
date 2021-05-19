//
// Created by Сергей on 18.05.2021.
//
#include <vector>
#include <fstream>
#include <string>
#ifndef LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_PROFILEMATRIX_H
#define LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_PROFILEMATRIX_H


class ProfileMatrix {
private:
    std::vector<double> diagonal;
    std::vector<std::vector<double>> ai, au;
public:
    ProfileMatrix(const std::vector<double> &diagonal, std::vector<std::vector<double>> &ai, std::vector<std::vector<double>> &au) {
        this->diagonal = diagonal;
        this-> ai = ai;
        this-> au = au;
    }
    std::vector<double> getDiagonal();
    std::vector<std::vector<double>> getAi();
    std::vector<std::vector<double>> getAu();
    void printMatrix(const std::string &path);

};


#endif //LU_DECOMPOSITION_AND_THE_GAUSSIAN_METHOD_PROFILEMATRIX_H
