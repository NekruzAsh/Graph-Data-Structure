#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <stdexcept>

using namespace std;

class Graph {
private:
	std::unordered_map<int, std::vector<int>> adjacencyList;
	int numVertices;

public:
	Graph(int numVertices);

	~Graph();

    void addVertex(int vertex);
    void removeVertex(int vertex);
    void addEdge(int startVertex, int endVertex);
    void removeEdge(int startVertex, int endVertex);
    bool hasEdge(int startVertex, int endVertex);
    std::vector<int> outEdges(int vertex);
    std::vector<int> inEdges(int vertex);

    const std::unordered_map<int, std::vector<int>>& getAdjacencyList() const {
        return adjacencyList;
    }

    void dfs(int startVertex);
    void bfs(int startVertex);
};

class GraphException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Graph Exception";
    }
};

class VertexNotFoundException : public GraphException {
public:
    virtual const char* what() const throw() {
        return "Vertex Not Found Exception";
    }
};

class EdgeNotFoundException : public GraphException {
public:
    virtual const char* what() const throw() {
        return "Edge Not Found Exception";
    }
};
