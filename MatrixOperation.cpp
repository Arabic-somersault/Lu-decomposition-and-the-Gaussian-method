//
// Created by Сергей on 19.05.2021.
//

#include "MatrixOperation.h"

#include <utility>

std::vector<double> MatrixOperation::mul(std::vector<double> a, std::vector<std::vector<double>> b) {
    int n = a.size();
    std::vector<double> c(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i] += a[j] * b[i][j];
        }
    }
    return c;
}

std::vector<double> MatrixOperation::mul(std::vector<std::vector<double>> a, std::vector<double> b) {
    return mul(std::move(b), std::move(a));
}

double MatrixOperation::mul(std::vector<double> a, std::vector<double> b) {
    int n = a.size();
    double c = 0;
    for (int i = 0; i < n; ++i) {
        c += a[i] * b[i];
    }
    return c;
}

std::vector<double> MatrixOperation::add(std::vector<double> a, std::vector<double> b) {
    int n = a.size();
    std::vector<double> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] + b[i];
    }
    return c;
}

std::vector<double> MatrixOperation::sub(std::vector<double> a, std::vector<double> b) {
    int n = a.size();
    std::vector<double> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] - b[i];
    }
    return c;
}

std::vector<double> MatrixOperation::mul(std::vector<double> a, double b) {
    int n = a.size();
    std::vector<double> c(n);
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] * b;
    }
    return c;
}