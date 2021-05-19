#include <iostream>
#include <cmath>
#include <vector>
#include "Gaussian.h"
#include "ProfileMatrix.h"
#include "MatrixGenerator.h"
using namespace std;

int main() {

    vector<vector<double>> mas;
    vector<double> v;
    int n, x;
    cin >> n;
    mas.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            mas[i].emplace_back(x);
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.emplace_back(x);
    }

    ProfileMatrix temp = MatrixGenerator::convert2profile(mas);



    Gaussian gaussian = Gaussian(mas, v);
    gaussian.evaluate();
    return 0;
}