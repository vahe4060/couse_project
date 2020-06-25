#pragma once
#include <vector>
#include "Vertice.h"
#include "Way.h"

class graph {
	int Size;
	std::vector< vertice*> vertices;
	void idk(const vertice* v, bool vis[], std::vector<way>& paths);


public:
	
	graph();
	~graph();

	void add_vertice(vertice* v);
	void longest_path();

};

