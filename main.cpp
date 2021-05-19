#include <iostream>
#include <vector>
#include "Gaussian.h"
#include "ProfileMatrix.h"
#include "MatrixGenerator.h"
#include "MatrixOperation.h"
#include <fstream>
#include <filesystem>
using namespace std;


const string PATH = "/Users/sj/CLionProjects/Lu-decomposition-and-the-Gaussian-method/";

void printX(const std::string &path, std::vector<double> v) {
    std::ofstream fout(path);
    for (double i : v) {
        fout << i << " ";
    }
}

int main() {
    std::__fs::filesystem::remove_all(PATH + "/tests");
    std::__fs::filesystem::create_directory(PATH + "/tests");
    for (int i = 0; i < 5; i++) {
        int n = i + 5;
        MatrixGenerator generator = MatrixGenerator(n, 0);
        ProfileMatrix temp = generator.createMatrix(true);

        string tempPath = PATH + "/tests/testN" + to_string(n);
        std::__fs::filesystem::create_directory(tempPath);
        temp.printMatrix(tempPath + "/matrix.txt");
        std::vector<double>x;
        for (int j = 0; j < n; j++) {
            x.push_back((double)(j + 1));
        }
        printX(tempPath + "/vectorX.txt",  x);
        std::vector<double> result = MatrixOperation::mul(MatrixGenerator::profile2normal(temp), x);
        printX(tempPath + "/result.txt", result);

    }
    return 0;
}


