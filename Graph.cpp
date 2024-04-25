#include "Graph.h"

Graph::Graph(int num) : numVertices(num) {}

Graph::~Graph() {}

void Graph::addVertex(int vertex) {
    if (adjacencyList.find(vertex) == adjacencyList.end()) {
        adjacencyList[vertex] = std::vector<int>();
    }
}

void Graph::removeVertex(int vertex) {
    if (adjacencyList.find(vertex) != adjacencyList.end()) {
        adjacencyList.erase(vertex);
        for (auto& pair : adjacencyList) {
            auto& edges = pair.second;
            edges.erase(std::remove(edges.begin(), edges.end(), vertex), edges.end());
        }
    }
    else {
        throw VertexNotFoundException();
    }
}

void Graph::addEdge(int startVertex, int endVertex) {
    addVertex(startVertex);
    addVertex(endVertex);
    adjacencyList[startVertex].push_back(endVertex);
}

void Graph::removeEdge(int startVertex, int endVertex) {
    if (adjacencyList.find(startVertex) != adjacencyList.end()) {
        auto& edges = adjacencyList[startVertex];
        auto it = std::find(edges.begin(), edges.end(), endVertex);
        if (it != edges.end()) {
            edges.erase(it);
        }
        else {
            throw EdgeNotFoundException();
        }
    }
    else {
        throw VertexNotFoundException();
    }
}

bool Graph::hasEdge(int startVertex, int endVertex) {
    if (adjacencyList.find(startVertex) != adjacencyList.end()) {
        auto& edges = adjacencyList[startVertex];
        return std::find(edges.begin(), edges.end(), endVertex) != edges.end();
    }
    return false;
}

std::vector<int> Graph::outEdges(int vertex) {
    if (adjacencyList.find(vertex) != adjacencyList.end()) {
        return adjacencyList[vertex];
    }
    else {
        throw VertexNotFoundException();
    }
}


std::vector<int> Graph::inEdges(int vertex) {
    std::vector<int> inEdgesList;
    for (auto& pair : adjacencyList) {
        auto& edges = pair.second;
        if (std::find(edges.begin(), edges.end(), vertex) != edges.end()) {
            inEdgesList.push_back(pair.first);
        }
    }
    return inEdgesList;
}

void Graph::dfs(int start) {
    std::unordered_set<int> visited;
    std::stack<int> dfsStack;

    dfsStack.push(start);

    if (adjacencyList.find(start) == adjacencyList.end()) {
        throw VertexNotFoundException();
    }

    while (!dfsStack.empty()) {
        int currentVertex = dfsStack.top();
        dfsStack.pop();

        if (visited.find(currentVertex) == visited.end()) {
            std::cout << currentVertex << " ";
            visited.insert(currentVertex);

            for (int adjacentVertex : adjacencyList[currentVertex]) {
                if (visited.find(adjacentVertex) == visited.end()) {
                    dfsStack.push(adjacentVertex);
                }
            }
        }
    }

    std::cout << std::endl;
}

void Graph::bfs(int start) {
    std::unordered_set<int> visited;
    std::queue<int> bfsQueue;

    bfsQueue.push(start);

    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();

        if (visited.find(currentVertex) == visited.end()) {
            std::cout << currentVertex << " "; 
            visited.insert(currentVertex);

            for (int adjacentVertex : adjacencyList[currentVertex]) {
                if (visited.find(adjacentVertex) == visited.end()) {
                    bfsQueue.push(adjacentVertex);
                }
            }
        }
    }

    std::cout << std::endl;
}