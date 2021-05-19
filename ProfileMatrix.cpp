//
// Created by Сергей on 18.05.2021.
//

#include "ProfileMatrix.h"

std::vector<std::vector<double>> ProfileMatrix::GetAi() {
    return ai;
}

std::vector<double> ProfileMatrix::getDiagonal() {
    return diagonal;
}

std::vector<std::vector<double>> ProfileMatrix::GetAu() {
    return au;
};

