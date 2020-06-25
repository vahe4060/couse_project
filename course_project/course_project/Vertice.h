#pragma once

#include <vector>

struct vertice
{
private:
	static int vertice_count;
	int index_;

	int Hood_Size = 0;
	std::vector<vertice*> neighbours;

public:
	

	vertice();
	~vertice();

	friend void connect(vertice& v1, vertice& v2);
	friend bool are_connected(vertice& v1, vertice& v2);
	// getters
	vertice* neighbour(int i) const;  // retrurn i_th neighbour of (*this)
	inline int index() const { return index_; }
	inline int hood_size() const { return Hood_Size; }
	

	friend class graph;
};
