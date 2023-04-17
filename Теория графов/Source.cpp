#include "Header.h"

// Class Edge

Edge::Edge(int init_v1, int init_v2, float init_weight) {
	v1 = init_v1;
	v2 = init_v2;
	weight = init_weight;
}

Edge::~Edge() {}

void Edge::setEdge(int init_v1, int init_v2, float init_weight) {
	v1 = init_v1;
	v2 = init_v2;
	weight = init_weight;
}

void Edge::getEdge(int& init_v1, int& init_v2, float& init_weight) {
	init_v1 = v1;
	init_v2 = v2;
	init_weight = weight;
}

int Edge::first() {
	return v1;
}

int Edge::second() {
	return v2;
}

float Edge::getWeight() {
	return weight;
}

// Class Graph

Graph::Graph(std::string file_path, std::string file_type) {

}

Graph::~Graph() {
	transcedence_matrix.clear();
}

float Graph::weight(int vi, int vj) {
	for (Edge e : transcedence_matrix) {
		if (e.first() == vi && e.second() == vj) {
			return e.getWeight();
		}
	}
	return 0;
}

bool Graph::is_edge(int vi, int vj) {
	for (Edge e : transcedence_matrix) {
		if (e.first() == vi && e.second() == vj) {
			return true;
		}
	}
	return false;
}

std::vector<std::vector<float>> Graph::adjacency_matrix() {
	size_t size = transcedence_matrix.size();
	std::vector<std::vector<float>> matrix(size, std::vector<float>(size, 0));
	for (Edge e : transcedence_matrix) {
		matrix[e.first()][e.second()] = e.getWeight();
	}
	return matrix;
}

std::list<int> Graph::adjacency_list(int v) {
	std::list<int> result;
	for (Edge e : transcedence_matrix) {
		if (e.first() == v) {
			result.push_back(e.second());
		}
		else if (e.second() == v) {
			result.push_back(e.first());
		}
	}
	return result;
}

std::list<Edge> Graph::list_of_edges() {
	return transcedence_matrix;
}

std::list<Edge> Graph::list_of_edges(int v) {
	std::list<Edge> result;
	for (Edge e : transcedence_matrix) {
		if (e.first() == v || e.second() == v) {
			result.push_back(e);
		}
	}
	return result;
}

bool Graph::is_directed() {
	return directed;
}

// Class Cell

Cell::Cell(float init_x, float init_y) {
	x = init_x;
	y = init_y;
}

Cell::~Cell() {}

void Cell::getCell(float& init_x, float& init_y) {
	init_x = x;
	init_y = y;
}

void Cell::setCell(float init_x, float init_y) {
	x = init_x;
	y = init_y;
}

// Class Map

Map::Map(std::string file_path) {

}

Map::~Map() {
	array.clear();
}

float Map::get_hight(Cell c) {

}

std::list<Cell> Map::neighbours(Cell c) {

}
