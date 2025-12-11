#ifndef GRAPH_MATRIX_HPP
#define GRAPH_MATRIX_HPP

#include "Graph.hpp"

class GraphMatrix : public Graph {
private:
    bool** adjMatrix;

protected:
    virtual ostream& print(ostream&) const override;

public:
    GraphMatrix(int, GType);
    virtual ~GraphMatrix();

    virtual bool isEdge(int, int) const override;
    virtual void toggleEdge(int, int) override;
};

#endif
