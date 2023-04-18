#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include "CSet.h"

CSet::CSet() {
	N = 0;
}

CSet::CSet(int N, unsigned int* Set) {
	this->N = N;
	this->Set = new unsigned int[N];
	for (size_t i = 0; i < N; ++i) {
		this->Set[i] = Set[i];
	}
}

CSet::CSet(const CSet& CS) { // 0
	N = CS.N;
	this->Set = new unsigned int[N];
	for (size_t i = 0; i < N; ++i) {
		this->Set[i] = CS.Set[i];
	}
}

CSet::CSet(CSet&& CS) { // 0.1
	std::swap(N, CS.N);
	std::swap(Set, CS.Set);
}

unsigned int& CSet::operator[] (int index) { // 1
	return Set[index];
}

CSet& CSet::operator =(const CSet& Set2) 
{
	if (this != &Set2) 
	{
		N = Set2.N;
		if (Set != nullptr) {
			delete[] Set;
		}
			Set = new unsigned int[N]; 
			for (size_t i = 0; i < N; ++i) {
				Set[i] = Set2.Set[i];
		}
	}
	return *this; 
}
CSet& CSet::operator =(CSet&& Set2) 
{
	if (this != &Set2) 
	{
		std::swap(Set, Set2.Set);
		std::swap(N, Set2.N);
	}
	return *this; 
}

// Перегрузка префиксного инкремента/декремента

CSet& CSet::operator++() { // 2
	this->N++;
	return *this;
}

CSet& CSet::operator--() { // 3 
	this->N--;
	return *this;
}

// Перегрузка постфиксного инкремента/декремента

CSet& CSet::operator++(int value) { // 4
	CSet temp(*this);
	this->N++;
	return temp;
}

CSet& CSet::operator--(int value) { // 5
	CSet temp(*this);
	this->N--;
	return temp;
}

CSet operator+(const CSet& Set1, const CSet& Set2) { // 6
	// В объединении множеств нет дубликатов, поэтому решил использовать контейнер set
	std::set<unsigned int> merged_set;
	std::vector<unsigned int> vec_for_mergedSet;

	merged_set.insert(Set1.Set, Set1.Set + Set1.N);
	merged_set.insert(Set2.Set, Set2.Set + Set2.N);

	for (const auto& pos : merged_set) {
		vec_for_mergedSet.push_back(pos);
	}

	CSet ob(vec_for_mergedSet.size(), Set1.Set);

	for (size_t i = 0; i < vec_for_mergedSet.size(); ++i) {
		ob.Set[i] = vec_for_mergedSet[i];
	}


	return ob;

}

CSet operator- (const CSet& Set1, const CSet& Set2) { // 7

	// Отсортируем два массива для того чтобы проверить нахождение элементов одного множества в другом
	// Если одно множество не содержит в себе элементы другого, то пересечением будет пустое множество

	// Сделаем проверку элементов множества на наличие элементов другого, иначе пустое множество

	std::vector<unsigned int> vec_for_interSet;
	std::vector<unsigned int> vec;

	std::set<unsigned int> set_for_Set1;
	std::set<unsigned int> set_for_Set2;

	set_for_Set1.insert(Set1.Set, Set1.Set + Set1.N);
	set_for_Set2.insert(Set2.Set, Set2.Set + Set2.N);

	std::set_intersection(set_for_Set1.begin(), set_for_Set1.end(), set_for_Set2.begin(), set_for_Set2.end(), std::back_inserter(vec_for_interSet));
	
	for (const auto& pos : vec_for_interSet) {
		vec.push_back(pos);
	}

	CSet ob(vec.size(), Set1.Set);

	for (size_t i = 0; i < vec.size(); ++i) {
		ob.Set[i] = vec[i];
	}

	return ob;
}


CSet::~CSet() {
	if (Set != nullptr) {
		delete[] Set;
	}
}

std::ostream& operator<<(std::ostream& os, const CSet& ob) {
	os << "Размерность N/M: " << ob.N << std::endl;
	os << "Элементы множества: " << std::endl;
	for (size_t i = 0; i < ob.N; ++i) {
		os << ob.Set[i] << std::endl;
	}

	return os;
}
