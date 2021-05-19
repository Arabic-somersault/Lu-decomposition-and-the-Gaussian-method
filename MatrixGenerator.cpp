//
// Created by Сергей on 18.05.2021.
//

#include "MatrixGenerator.h"
#include <ctime>
#include <cmath>
const int RANDOM_NUMBER = 5;
const int DEFAULT_NUMBER = 100;


ProfileMatrix MatrixGenerator::createMatrix(bool flag) {
    std::vector<std::vector<double>>result;
    srand(time(nullptr));
    result.resize(n);
    for (int i = 0; i < n; i++) {
        result[i].resize(n);
    }
    if (flag) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = rand() % DEFAULT_NUMBER;
            }
        }
        return MatrixGenerator::convert2profile(result);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            result[i][j] = -rand() % RANDOM_NUMBER;
            sum += -result[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        result[i][i] = sum;
    }
    result[0][0] += pow(10, -k);
    return MatrixGenerator::convert2profile(result);
}


ProfileMatrix MatrixGenerator::convert2profile(std::vector<std::vector<double>> v) {
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

std::vector<std::vector<double>> MatrixGenerator::profile2normal(ProfileMatrix matrix) {
    int n = matrix.getDiagonal().size();
    std::vector<double> d = matrix.getDiagonal();
    std::vector<std::vector<double>> ai = matrix.getAi();
    std::vector<std::vector<double>> au = matrix.getAu();
    std::vector<std::vector<double>> result(n, std::vector<double>(n));
    for (int i = 0; i < n; i++) {
        result[i][i] = d[i];
    }
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < i && i - j > ai[i].size()) {
            result[i][j] = 0;
        }
        for (int t = 0; t < ai[i].size(); t++) {
            result[i][j + t] = ai[i][t];
        }
    }
    for (int j = 0; j < n; j++) {
        int i = 0;
        while (i < j && j - i > au[j].size()) {
            result[i][j] = 0;
        }
        for (int t = 0; t < au[j].size(); t++) {
            result[i + t][j] = au[j][t];
        }
    }
    return result;
}


