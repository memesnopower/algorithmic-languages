#include <iostream>
#include "CSet.h"
#include <vector>
#include <fstream>


int main() {
	setlocale(LC_ALL, "rus");
	
	//std::vector<CSet> vecCSet;
	int N, M; // Размерности двух множеств



	std::ifstream input("D:/text/input.txt");
	std::ofstream output("D:/text/output.txt");

	input >> N;
	input >> M;

	unsigned int* arr1 = new unsigned int[N];
	unsigned int* arr2 = new unsigned int[M];

	for (size_t i = 0; i < N; ++i) {
		input >> arr1[i];
	}

	CSet ob1(N, arr1);

	output << "Первое множество-> " << std::endl;
	output << ob1 << std::endl;

	for (size_t i = 0; i < M; ++i) {
		input >> arr2[i];
	}

	CSet ob2(M, arr2);

	output << "Второе множество-> " << std::endl;
	output << ob2 << std::endl;

	// Тест operator[]

	CSet ob3(N, arr1);
	ob3[0] = 100;

	output << "Тест operator[]-> " << std::endl;
	output << "Элементу ob3[0]=100" << std::endl;
	output << ob3 << std::endl;

	// Тест конструктора копирования

	CSet ob_copy(N, arr1);
	ob_copy = ob1;

	output << "Тест конструктора копирования-> " << std::endl;
	output << ob_copy << std::endl;

	CSet ob_move(N, arr1);
	CSet ob4(N, arr1);
	ob4 = std::move(ob_move);

	output << "Тест конструктора перемещения-> " << std::endl;
	output << ob4 << std::endl;

	CSet ob_merged(N, arr1);
	CSet ob5(N, arr1);
	CSet ob6(M, arr2);
	ob_merged = ob5 + ob6;

	output << "Тест operator+ или же объединение множеств-> " << std::endl;
	output << ob_merged << std::endl;

	CSet ob_intersection(N, arr1);
	CSet ob7(N, arr1);
	CSet ob8(M, arr2);
	ob_intersection = ob7 - ob8;

	output << "Тест operator- или же пересечение множеств-> " << std::endl;
	output << ob_intersection << std::endl;


	ob7++;
	// ob7[N] = rand();
	std::cout << ob7 << std::endl;

	//std::cout << ob10 << std::endl;

	delete[] arr1;
	delete[] arr2;

}
