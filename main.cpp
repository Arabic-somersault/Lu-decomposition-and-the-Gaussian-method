#include <iostream>
#include <cmath>
#include <conio.h>
#include <vector>
#include "Gaussian.h"
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

    Gaussian gaussian = Gaussian(mas, v);
    gaussian.evaluate();
    return 0;
}