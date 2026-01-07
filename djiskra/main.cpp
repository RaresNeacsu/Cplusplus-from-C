#include <climits>
#include <iostream>
using namespace std;

double prob() { return (double)rand() / RAND_MAX; }

template <class T> class graph {
private:
  int V;
  T **adj;

public:
  int getV() const { return V; }
  graph(int n) {
    V = n;
    adj = new T *[n];
    for (int i = 0; i < n; i++) {
      adj[i] = new T[n];
      for (int j = 0; j < n; j++) {
        adj[i][j] = INT_MAX;
      }
    }
  }
  ~graph() {
    for (int i = 0; i < V; i++) {
      delete[] adj[i];
    }
    delete[] adj;
  }
  void addEdgeValue(int u, int v, T val) { adj[u][v] = adj[v][u] = val; }
  void print() const {
    for (int i = 0; i < getV(); i++) {
      for (int j = 0; j < getV(); j++) {
        if (adj[i][j] != INT_MAX)
          cout << i << "->" << j << " " << adj[i][j] << endl;
      }
    }
  }
  bool isAdjacent(int u, int v) const { return adj[u][v] != INT_MAX; }
  void generateRandomGraph(double density, T mindist, T maxdist) {
    for (int i = 0; i < V; i++) {
      for (int j = i; j < V; j++) {
        if (i == j)
          adj[i][j] = INT_MAX;
        else
          addEdgeValue(i, j,
                       (prob() < density)
                           ? rand() % static_cast<int>(maxdist - mindist) +
                                 mindist
                           : INT_MAX);
      }
    }
  }
  T getEdgeValue(int u, int v) const { return adj[u][v]; }
};
template <class T> class shortestpath {
public:
  T djiskra(const graph<T> &g, int src) {
    int V = g.getV();
    T *dist = new T[V];
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
      dist[i] = INT_MAX;
      visited[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++) {
      int u = -1;
      int minVal = INT_MAX;
      for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < minVal) {
          u = v;
          minVal = dist[v];
        }
      }
      if (u == -1 || dist[u] == INT_MAX)
        break;
      visited[u] = true;
      for (int v = 0; v < V; v++) {
        if (!visited[v] && g.isAdjacent(u, v)) {
          dist[v] = min(dist[v], dist[u] + g.getEdgeValue(u, v));
        }
      }
    }
    T sum = 0;
    int n = 0;
    for (int i = 0; i < V; i++) {
      if (dist[i] != INT_MAX && i != src) {
        sum += dist[i];
        n++;
      }
    }
    delete[] dist;
    delete[] visited;
    if (n == 0)
      return 0.0;
    return sum / n;
  }
};
int main() {
  srand(time(0));
  const int V = 50;
  const double mindist = 1.0;
  const double maxdist = 10.0;
  graph<double> g(V);
  g.generateRandomGraph(0.20, mindist, maxdist);
  // g.print();
  shortestpath<double> sp;
  cout<<"Monte Carlo Simulation"<<endl;
  cout<<"Density: 0.20"<<endl;
  cout << sp.djiskra(g, 0) << endl;
  g.generateRandomGraph(0.40, mindist, maxdist);
  // g.print();
  cout<<"Density: 0.40"<<endl;
  cout << sp.djiskra(g, 0) << endl;
  return 0;
}