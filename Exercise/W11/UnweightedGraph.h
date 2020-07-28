#include <vector>
#include <set>
#include <queue>

template <typename V>
class UnweightedGraph{
public:
    using VertexID = size_t;

    VertexID addVertex(V value){
        VertexID id = vertices_.size();

        vertices_.push_back()(std::move(value));
        adjacencies_.emplace_back();

        return id;
    }

    UnweightedGraph& addEdge(VertexID from, VertexID to){
        adjacencies_[from].insert(to);
        adjacencies_[to].insert(from);

        return *this;
    }

    const V& operator[] (size_t index) const {
        return vertices_[index];
    }


    std::vector<size_t> shortestDistance(VertexID source){
        const size_t INF = std::numeric_limits<size_t>::max();
        const size_t N = vertices_.size();

        std::vector<size_t> distances(N,INF);
        std::vector<VertexID>paths(N);
        std::queue<VertexID> worklist;

        distances[source] = 0;
        worklist.push(source);

        while (not worklist.empty()){
            VertexID v = worklist.front();
            worklist.pop();

            for (VertexID n : adjacencies_){
                if (distances[n] == INF){
                    distances[n] = adjacencies_[v] + 1;
                    paths[n] = v;
                    worklist.push(n);
                }
            }
        }
    }

private:

    std::vector<V> vertices_;
    std::vector<std::set<VertexID>> adjacencies_;

};


