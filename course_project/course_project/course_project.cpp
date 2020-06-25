// 9 Graph-kursayin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include "Graph.h"
#include <string>
#include <sstream> 

int Size(std::string line)
{
	std::stringstream ss;
	ss << line;

	int val;
	int size = 0;

	while (!ss.eof())
	{
		if (ss >> val)
		{
			size++;
		}
	}
	return size;
}

int main()
{
	graph G;
	
	std::ifstream input;
	input.open("../matrix.txt");
	if (!input) { 
		std::cerr << "no matrix detected\n";
		return 1;
	}

	std::string line;
	std::getline(input, line);

	int size = Size(line);

	vertice* v = new vertice[size];
	for (int i = 0; i < size; i++)
		G.add_vertice(&v[i]);


	int i = 0;
	while (!input.eof())
	{
		std::stringstream ss;
		ss << line;
		int val;

		int j = 0;
		while (!ss.eof())
		{
			if (ss >> val)
			{
				if (val == 1) {
					if (!are_connected(v[i], v[j])) connect(v[i], v[j]);
				}
			}
			j++;
		}
		std::getline(input, line);
		i++;
	}

	G.longest_path();
	std::cin.get();
}
// 0 3 2 4 1

//#include "functions.h"
//using namespace std;
//
//void f(int a[])
//{
//    for (int i = 0; i < 4; i++)
//        a[i] = 2;
//}
//int main()
//{
//    // Create a graph given in the above diagram 
//    vector<int> adj[6];
//    addEdge(adj, 1, 2);
//    addEdge(adj, 1, 3);
//    addEdge(adj, 3, 2);
//    addEdge(adj, 2, 4);
//    addEdge(adj, 3, 4);
//
//    cout<<findLongestPath(adj, 5);
//    return 0;
//}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
