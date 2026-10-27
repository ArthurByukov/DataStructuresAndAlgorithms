#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

// чтение
std::vector<Matrix> readMatrices(const std::string& filename) {

	std::vector<Matrix> matrices;
	std::ifstream file(filename);
	if (file.is_open()) {


		std::string line;
		Matrix current;

		while (std::getline(file, line)) {
			if (!line.empty() && line.back() == '\r') line.pop_back();

			if (line.find_first_not_of(" \t") == std::string::npos) {
				if (!current.empty()) {
					matrices.push_back(std::move(current));
					current.clear();
				}
				continue;
			}

			std::istringstream iss(line);
			std::vector<int> row;
			int v;
			while (iss >> v) row.push_back(v);
			if (!row.empty()) current.push_back(std::move(row));
		}

		if (!current.empty()) matrices.push_back(std::move(current));
		return matrices;
	}
}

//запись 
void writeMatrices(const std::string& filename,
	const std::vector<Matrix>& matrices) {
	std::ofstream file(filename);   // перезапись
	if (!file.is_open())
		throw std::runtime_error("Не удалось открыть: " + filename);

	for (size_t k = 0; k < matrices.size(); ++k) {
		for (const auto& row : matrices[k]) {
			for (size_t j = 0; j < row.size(); ++j) {
				if (j > 0) file << ' ';
				file << row[j];
			}
			file << '\n';
		}
		if (k + 1 < matrices.size()) file << '\n';
	}
}

//cравнение матриц
bool equalMatrices(const Matrix& a, const Matrix& b) {
	if (a.size() != b.size()) return false;
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i].size() != b[i].size()) return false;
		if (a[i] != b[i]) return false;
	}
	return true;
}
//проверка содержит ли второй файл матрицы первого
bool contains(const std::vector<Matrix>& arr, const Matrix& m) {
	for (const auto& x : arr)
		if (equalMatrices(x, m)) return true;
	return false;
}

int main1() {


	auto file1 = readMatrices("a.txt");
	auto file2 = readMatrices("b.txt");


	for (const auto& m : file1) {
		if (!contains(file2, m)) {
			file2.push_back(m);
		}
	}

	writeMatrices("b.txt", file2);
	return 0;

}