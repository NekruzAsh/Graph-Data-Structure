/*

	CS2028C Lab 12
	
	Group 01
	
	Arvish Pandey
	Nekruz Ashrapov
	
*/

#include <iostream>
#include "Graph.h"

using namespace std;

void printMenu() {
    std::cout << "\n*----------------------------------------------------*\n";
    std::cout << "Press 1 to add a vertex to the graph." << std::endl;
    std::cout << "Press 2 to remove a vertex from the graph." << std::endl;
    std::cout << "Press 3 to add an edge to the graph." << std::endl;
    std::cout << "Press 4 to remove an edge from the graph." << std::endl;
    std::cout << "Press 5 to find an edge in the graph." << std::endl;
    std::cout << "Press 6 to find the out edges of a vertex." << std::endl;
    std::cout << "Press 7 to find the in edges of a vertex." << std::endl;
    std::cout << "Press 8 to print the adjacency list." << std::endl;
    std::cout << "Press 9 to perform DFS: Depth First Search." << std::endl;
    std::cout << "Press 10 to perform BFS: Breadth First Search." << std::endl;
    std::cout << "Press 11 to quit." << std::endl;
    std::cout << "\n*----------------------------------------------------*\n";
}

int main() {
    int choice;
    Graph graph(0);

    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int vertex;
            std::cout << "Enter vertex to add: ";
            std::cin >> vertex;
            graph.addVertex(vertex);
            break;
        }
        case 2: {
            int vertex;
            std::cout << "Enter vertex to remove: ";
            std::cin >> vertex;
            try {
                graph.removeVertex(vertex);
            }
            catch (const VertexNotFoundException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 3: {
            int startVertex, endVertex;
            std::cout << "Enter start vertex: ";
            std::cin >> startVertex;
            std::cout << "Enter end vertex: ";
            std::cin >> endVertex;
            try {
                graph.addEdge(startVertex, endVertex);
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 4: {
            int startVertex, endVertex;
            std::cout << "Enter start vertex: ";
            std::cin >> startVertex;
            std::cout << "Enter end vertex: ";
            std::cin >> endVertex;
            try {
                graph.removeEdge(startVertex, endVertex);
            }
            catch (const EdgeNotFoundException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 5: {
            int startVertex, endVertex;
            std::cout << "Enter start vertex: ";
            std::cin >> startVertex;
            std::cout << "Enter end vertex: ";
            std::cin >> endVertex;
            bool hasEdge = graph.hasEdge(startVertex, endVertex);
            std::cout << "Edge exists: " << std::boolalpha << hasEdge << std::endl;
            break;
        }
        case 6: {
            int vertex;
            std::cout << "Enter vertex: ";
            std::cin >> vertex;
            std::cout << "Out edges of vertex " << vertex << ": ";
            for (int v : graph.outEdges(vertex)) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 7: {
            int vertex;
            std::cout << "Enter vertex: ";
            std::cin >> vertex;
            std::cout << "In edges of vertex " << vertex << ": ";
            for (int v : graph.inEdges(vertex)) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
            break;
        }
        case 8: {
            std::cout << "Adjacency List:" << std::endl;
            for (const auto& pair : graph.getAdjacencyList()) {
                std::cout << pair.first << " -> ";
                for (int vertex : pair.second) {
                    std::cout << vertex << " -> ";
                }
                std::cout << std::endl;
            }
            break;
        }
        case 9: {
            int start;
            std::cout << "Enter start vertex: " << std::endl;
            cin >> start;
            std::cout << "DFS: " << std::endl;
            try {
                graph.dfs(start);
            }
            catch (const VertexNotFoundException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 10: {
            int start;
            std::cout << "Enter start vertex: " << std::endl;
            cin >> start;
            std::cout << "BFS: " << std::endl;
            try {
                graph.bfs(start);
            }
            catch (const VertexNotFoundException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        }
        case 11:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 11);

    return 0;
}