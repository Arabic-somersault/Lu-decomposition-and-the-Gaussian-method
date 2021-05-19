//
// Created by Сергей on 18.05.2021.
//

#include "ProfileMatrix.h"

std::vector<std::vector<double>> ProfileMatrix::getAi() {
    return ai;
}

std::vector<double> ProfileMatrix::getDiagonal() {
    return diagonal;
}

std::vector<std::vector<double>> ProfileMatrix::getAu() {
    return au;
}

void ProfileMatrix::printMatrix(const std::string &path) {
    std::ofstream fout;
    fout.open(path);
    //print diagonal
    for (int i = 0; i < diagonal.size(); i++) {
        fout << diagonal[i];
        if ( i != diagonal.size() - 1) {
            fout << " ";
        }
    }
    fout << '\n';

    //print ai
    for (auto & i : ai) {
        for (int j = 0; j < i.size(); j++) {
            fout << i[j];
            if ( j != i.size() - 1) {
                fout << " ";
            }
        }
        fout << "\n";
    }
    //print au
    for (auto & i : au) {
        for (int j = 0; j < i.size(); j++) {
            fout << i[j];
            if ( j != i.size() - 1) {
                fout << " ";
            }
        }
        fout << "\n";
    }

}


