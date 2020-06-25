#include "Way.h"

void way::swap(int& a, int& b)
{
	int temp = a;
	a =b;
	b = temp;
}

void way::operator +=(const vertice& v)
{

	path.emplace_back(v.index());
	size++;
}

//void way::reverse()
//{
//	for (unsigned int i = 0; i < path.size() / 2; i++)
//		swap(path[i], path[path.size() - 1 - i]);
//}

std::ostream& operator<<(std::ostream& os, const way& a)
{
	for (auto i = a.path.rbegin(); i != a.path.rend() - 1; ++i)
	{
		os  << *i << " - " ;
	}
	std::cout << a.path[0];
	return os;
}


way max(way& a, way& b)
{
	if (a.size > b.size) return a;
	return b;
}

//bool operator==(const way& w1, const way& w2)
//{
//	if(w1.size != w2.size)	return false;
//
//	for (int i = 0; i < w1.size; i++)
//	{
//		if (w1.path[i] != w2.path[i]) goto label;
//	}
//	return true;
//
//	label:
//	for (int j = 0; j < w1.size; j++)
//	{
//		if (w1.path[j] != w2.path[w1.size - 1 - j]) return false;
//	}
//	return true;
//}

/*
1 2 3 4 5 6
6 2 4 3 5 1
*/