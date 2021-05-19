//
// Created by llSoK on 18.05.2021.
//

#include "Gaussian.h"
#include <cmath>
#include <iostream>

void Gaussian::evaluate() {

    for (int p = 0; p < n; p++) {
        int max = p;
        for (int i = p + 1; i < n; i++) {
            if (std::abs(mas[i][p]) > std::abs(mas[max][p])) {
                max = i;
            }
        }
        std::swap(mas[p], mas[max]);
        std::swap(v[p], v[max]);

        // pivot within A and b
        for (int i = p + 1; i < n; i++) {
            double alpha = mas[i][p] / mas[p][p];
            v[i] -= alpha * v[p];
            for (int j = p; j < n; j++) {
                mas[i][j] -= alpha * mas[p][j];
            }
        }
    }

    // back substitution
    std::vector<double> x(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += mas[i][j] * x[j];
        }
        x[i] = (v[i] - sum) / mas[i][i];
    }

    for (auto i : x) {
        std::cout << i << ' ';
    }
}

Gaussian::Gaussian(const std::vector<std::vector<double>> &mas, std::vector<double> v) {
    this->mas = mas;
    this->v = v;
    this->n = v.size();
}
