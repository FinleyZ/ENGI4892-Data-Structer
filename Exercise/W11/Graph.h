#include <vector>

template <typename V, typename E>
class Graph{
public:
    using VertexID = size_t ;

    VertexID addVertex(V value){
        VertexID id = vertices_.size();
        vertices_.push_back()(std::move(value));
        return id;
    }

    Graph& addEdge(VertexID from, VertexID to, E value){
        Edge e = {.from = from, .to = to, .data = std::move(value)};
        edges_.push_back(std::move(e));
        return *this;
    }

    std::vector<VertexID> neighbours(VertexID v){
        std::vector<VertexID> neighbours;

        for (const Edge &e : edges_) {
            if (e.from == v){
                neighbours.push_back(e.to);
            } else if (e.to ==v){
                neighbours.push_back(e.from);
            }
        }

        return neighbours;

    }

    std::vector<size_t> shortestDistance(VertexID source){
        const size_t N = vertices_.size();
        const size_t INF = std::numeric_limits<size_t>().max();

        std::vector<size_t> distances(N,INF);
        std::vector<VertexID> path(N);
        std::vector<bool> done(N, false);

        distances[source] = 0;

        for (size_t dist = 0; dist < N; dist++) {
            for(VertexID v = 0; v < N; v++){
                if (done[v] or distances[v] != dist){
                    continue;
                }

                for (VertexID n : neighbours(v)){
                    if (distances[n] == INF){
                        distances[n] = dist + 1;
                        path[n] = v;
                    }
                }
                done[v] = true;
            }

        }
        return distances;
    }

private:
    struct Edge{
        VertexID from;
        VertexID to;
        E data;
    };

    std::vector<V> vertices_;
    std::vector<Edge> edges_;

};
