#pragma once

class CSet {
	int N;
	unsigned int* Set = nullptr;

public:

	CSet();
	CSet(int N, unsigned int* Set);
	CSet(const CSet& CS);
	CSet(CSet&& CS);
	CSet& operator++();
	CSet& operator--();
	CSet& operator++(int value);
	CSet& operator--(int value);
	unsigned int& operator[] (int index);
	CSet& operator =(const CSet& Set2);
	CSet& operator =(CSet&& v2);
	friend CSet operator+ (const CSet& Set1, const CSet& Set2);
	friend CSet operator- (const CSet& Set1, const CSet& Set2);
	friend std::ostream& operator<<(std::ostream& os, const CSet& ob);
	~CSet();
};
