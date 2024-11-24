// 9 Graph-kursayin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include "Graph.h"
#include <string>
#include <sstream> 

int Size(const std::string &line)
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

int main(int argc, char **argv)
{
	graph G;
	
	std::ifstream input;
	input.open("matrix.txt");
	if (!input) { 
		std::cerr << "matrix.txt not found\n";
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
}
