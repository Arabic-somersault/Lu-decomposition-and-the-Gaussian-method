//
// Created by llSoK on 18.05.2021.
//

#include "luDecomposition.h"

void luDecomposition::evaluate() {
    L.resize(n);
    U.resize(n);
    for (int i = 0; i < n; i++) {
        L.resize(n);
        U.resize(n);
    }
    for (int i = 0; i < n; i++) {
        L[i][i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) {
                double sum = 0;

                for (int k = 0; k < j - 1; k++) {
                    sum += L[i][k] * U[k][j];
                }
                L[i][j] = (j - (i - al[i].size())) < 0 ? 0 : al[i][j - (i - al[i].size())];
                L[i][j] -= sum;
                L[i][j] /= U[i][j];
            }

            if (i <= j) {
                double sum = 0;
                for (int k = 0; k < i - 1; k++) {
                    sum += (L[i][k] * U[k][j]);
                }
                if (i < j) {
                    U[i][j] = (i - (j - au[j].size())) < 0 ? 0 : au[i - (j - au[j].size())][j];
                    U[i][j] -= sum;
                } else {
                    U[i][j] = d[i] - sum;
                }
            }
        }
    }
}

luDecomposition::luDecomposition(const std::vector<std::vector<double>> &A, int n) {

}
