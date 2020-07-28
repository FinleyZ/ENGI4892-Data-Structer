#include <memory>
#include <vector>
#include <string>

template<typename V, typename E>
class Graph
{
public:
    using VertexID = size_t;

    VertexID addVertex(V vertex){
        Vertex v = new Vertex(vertex);
        vertices_.push_back(v.data_);
        return v.data_;
    }

    Graph& addEdge(VertexID from, VertexID to, E edge){
        Edge e;
        e.from_ = from;
        e.to_ = to;
        e.Value_ = edge;

        edges_[from][to] = edge;
        edges_[to][from] = edge;

        return this;
    }



private:
    struct Vertex{
        V data_;

        Vertex(V data){
            data_ = data;
        }

    };

    struct Edge{
        VertexID from_;
        VertexID to_;

        E Value_;
    };

    std::vector <V> vertices_;
    std::vector <Edge> edges_;
};
