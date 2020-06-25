#include "Graph.h"

graph::graph()
{
	Size = 0;
}
graph::~graph()
{
	vertices.clear();
}



void graph::add_vertice(vertice* v)
{
	vertices.push_back(v);
	Size++;
}


/*
0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 1
1 0 0 1 0 1 0 0
0 1 1 0 1 0 1 0
0 0 0 1 0 0 1 1
0 0 1 0 0 0 1 0
0 0 0 0 1 1 0 1
0 1 0 0 1 0 1 0

*/

void graph::idk(const vertice* v,bool vis[], std::vector<way>& paths)
{
	vis[v->index()] = true;
	bool* visited = new bool[vertice::vertice_count];


	for (int i = 0; i < v->Hood_Size; i++)
	{
		if (!vis[v->neighbour(i)->index()])
		{
			for (int j = 0; j < vertice::vertice_count; j++)
				visited[j] = vis[j];

			std::vector<way> temp;
			idk(v->neighbour(i), visited, temp);

			if ((paths).empty()) 
			{
				paths = temp;
			}
			else if ((paths[0]).Size() < (temp[0]).Size())
			{
				paths.clear();
				for (auto i : temp)
				{
					paths.push_back(i);
				}
			}
			else if ((paths[0]).Size() == (temp[0]).Size())
			{
				for (auto i : temp)
				{
					paths.push_back(i);
				}
			}
		}
	} 
	
	if ((paths).empty())
	{
		way t;
		t += (*v);
		paths.push_back(t);
	}
	else
	{
		for (int i = 0; i < paths.size(); i++)
		{
			paths[i] += (*v);
		}
	}
}



void graph::longest_path()
{
	way Max;
	bool* visited = new bool[vertice::vertice_count];
	for (int i = 0; i < vertice::vertice_count; i++)
		visited[i] = false;

	std::vector<way> paths;

	for (int i = 0; i < Size; i++)
	{
		std::vector<way> temp;
		for (int i = 0; i < vertice::vertice_count; i++)
			visited[i] = false;

		idk(vertices[i], visited, temp);
		
		if (paths.empty()) paths = temp;

		else if (paths[0].Size() < temp[0].Size())
		{
			paths.clear();
			paths = temp;
		}
		else if (paths[0].Size() == temp[0].Size())
		{
			for (auto j : temp)
			{
				paths.push_back(j);
			}
		}
	}


	for (auto i : paths)
	{
		std::cout << i << std::endl;
	}

	delete[] visited;
}


