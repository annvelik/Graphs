#pragma once
#include <vector>
#include <list>
#include <string>

class Edge {
private:
	int v1;
	int v2;
	float weight;
public:
	Edge(int init_v1, int init_v2, float init_weight);

	~Edge();
	
	void setEdge(int init_v1, int init_v2, float init_weight);
	
	void getEdge(int& init_v1, int& init_v2, float& init_weight);

	int first();

	int second();

	float getWeight();
};

class Graph {
private:
	std::list<Edge> transcedence_matrix;
	bool directed;
public:
	Graph(std::string file_path, std::string file_type);

	~Graph();

	float weight(int vi, int vj);

	bool is_edge(int vi, int vj);

	std::vector<std::vector<float>> adjacency_matrix();

	std::list<int> adjacency_list(int v);

	std::list<Edge> list_of_edges();

	std::list<Edge> list_of_edges(int v);

	bool is_directed();
};

class Cell {
private:
	float x;
	float y;
public:
	Cell(float init_x, float init_y);

	~Cell();
	
	void getCell(float& init_x, float& init_y);
	
	void setCell(float init_x, float init_y);
};

class Map {
private:
	std::vector<Cell> array;
public:
	Map(std::string file_path);

	~Map();

	float get_hight(Cell c);
	
	std::list<Cell> neighbours(Cell c);
};