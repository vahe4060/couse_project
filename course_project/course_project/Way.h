#pragma once
#include <iostream>
#include "Vertice.h"

class way
{
private:
	void swap(int& a, int& b);
	std::vector<int> path;
	int size = 0;

public:

	void operator +=(const vertice& v);

	inline int Size() { return size; }

	friend std::ostream& operator<<(std::ostream& os, const way& a);
	//friend bool operator==(const way& w1, const way& w2);
	friend way max(way& a, way& b);
};

