//
// Created by Сергей on 18.05.2021.
//

#include "MatrixGenerator.h"
#include <ctime>
#include <cmath>
const int RANDOM_NUMBER = 5;


void MatrixGenerator::createMatrix() {
    srand(time(nullptr));
    int sum = 0;
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            matrix[i][j] = -rand() % RANDOM_NUMBER;
            sum += -matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        matrix[i][i] = sum;
    }
    matrix[0][0] += pow(10, -k);
}

std::vector<std::vector<double>> MatrixGenerator::getMatrix() {
    return matrix;
}

ProfileMatrix MatrixGenerator::convert2profile(const std::vector<std::vector<double>> &v) {
    std::vector<double>diagonal;
    std::vector<std::vector<double>> ai, au;
    for (int i = 0; i < v.size(); i++) {
        diagonal.emplace_back(v[i][i]);
    }
    for (int i = 0; i < v.size(); i++) {
        int j = 0;
        std::vector<double>temp;
        while (j < i && v[i][j] == 0) {
            j++;
        }
        for (int t = j; t < i; t++) {
            temp.emplace_back(v[i][t]);
        }
        ai.push_back(temp);
    }

    for (int j = 0; j < v.size(); j++) {
        int i = 0;
        std::vector<double>temp;
        while (i < j && v[i][j] == 0) {
            i++;
        }
        for (int t = i; t < j; t++) {
            temp.emplace_back(v[t][j]);
        }
        au.push_back(temp);
    }
    return ProfileMatrix(diagonal, ai, au);
}


