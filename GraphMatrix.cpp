#include "GraphMatrix.hpp"
#include <iostream>
using namespace std;

GraphMatrix::GraphMatrix(int numV, GType type) : Graph(numV, 0, type)
{
    adjMatrix = new bool* [v];
    for (int i = 0; i < v; i++) {
        adjMatrix[i] = new bool[v];
        for (int j = 0; j < v; j++) {
            adjMatrix[i][j] = false;
        }
    }
}

GraphMatrix::~GraphMatrix()
{
    for (int i = 0; i < v; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

bool GraphMatrix::isEdge(int i, int j) const
{
    if (i < 0 || j < 0 || i >= v || j >= v) {
        return false;
    }
    return adjMatrix[i][j];
}

void GraphMatrix::toggleEdge(int i, int j)
{
    if (i < 0 || j < 0 || i >= v || j >= v) {
        return;
    }

    if (adjMatrix[i][j] == false) {
        adjMatrix[i][j] = true;
        e++;

        if (graphType == UNDIRECTED && i != j) {
            adjMatrix[j][i] = true;
        }
    }
    else {
        adjMatrix[i][j] = false;
        e--;

        if (graphType == UNDIRECTED && i != j) {
            adjMatrix[j][i] = false;
        }
    }
}

ostream& GraphMatrix::print(ostream& os) const
{
    os << "    ";
    for (int i = 0; i < v; i++) {
        os << i << " ";
    }
    os << endl;

    os << "---";
    for (int i = 0; i < v; i++) {
        os << "--";
    }
    os << endl;

    for (int i = 0; i < v; i++) {
        os << i << " | ";
        for (int j = 0; j < v; j++) {
            os << adjMatrix[i][j] << " ";
        }
        os << endl;
    }

    return os;
}
