// Laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using Matrix = std::vector<std::vector<int>>;


std::vector<Matrix> ReadMatrix(const std::string& filename) {
    std::vector<Matrix> matrices;

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Can't open file: " + filename);
    }

    std::string line;
    Matrix current;

    while (std::getline(file, line)) {
       
        if (line.empty()) {
            if (!current.empty()) {
                matrices.push_back(std::move(current));
                current.clear();
            }
            continue;
        }

       
        std::istringstream iss(line);
        std::vector<int> row;
        int value;
        while (iss >> value) {
            row.push_back(value);
        }

        if (!row.empty()) {
            current.push_back(std::move(row));
        }
    }

   
    if (!current.empty()) {
        matrices.push_back(std::move(current));
    }

    return matrices;
}

std::vector<Matrix> AddMissingMatrix(const std::vector<Matrix>& matrix1, const std::vector<Matrix>& matrix2, const std::string& filename){

    std::vector<Matrix> newMatrix = matrix2;

    int lenghtMat1 = matrix1.size();
    int lenghtMat2 = matrix2.size();
    
    for (int i = 0; i < lenghtMat1; i++) {

        bool candfind = false;

        for (int j = 0; j < lenghtMat2; j++) {
            if (matrix1[i] == matrix2[j]) {
                candfind = true;
            }
        }

        if (candfind == false) {
            newMatrix.push_back(matrix1[i]);
        }

    }
    return newMatrix;

}

void writeMatrices(const std::string& filename,
    const std::vector<Matrix>& matrices) {
    std::ofstream file(filename);   
    if (file.is_open()) {

        for (size_t k = 0; k < matrices.size(); ++k) {
            const Matrix& m = matrices[k];

            for (const auto& row : m) {
                for (size_t j = 0; j < row.size(); ++j) {
                    if (j > 0) file << ' ';
                    file << row[j];
                }
                file << '\n';
            }


            if (k + 1 < matrices.size())
                file << '\n';
        }
    }
}

void printMatrices(const std::vector<Matrix>& matrices) {
    for (size_t k = 0; k < matrices.size(); ++k) {
        std::cout << "Matrix #" << k + 1 << " ("
            << matrices[k].size() << "x"
            << (matrices[k].empty() ? 0 : matrices[k][0].size())
            << "):\n";

        for (const auto& row : matrices[k]) {
            for (int x : row) std::cout << x << " ";
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

int main() {

    auto matrices1 = ReadMatrix("a.txt");
    auto matrices2 = ReadMatrix("b.txt");
    writeMatrices("b.txt", AddMissingMatrix(matrices1, matrices2, "b.txt"));
    
}