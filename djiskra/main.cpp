#include <iostream>
#include <climits>
using namespace std;

class graph{
    private:
    int N;
    int **adj;
    public:
    graph(int n){
        N = n;
        adj = new int*[n];
        for (int i = 0; i < n; i++)
        {
            adj[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = INT_MAX;
            }
        }
    }
    ~graph(){
        delete[] adj;
    }
    void addEdgeValue(int u, int v,int val){
        adj[u][v] = val;
    }
    void print(){
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if(adj[i][j] != INT_MAX)
                cout << i << "->" << j << " " << adj[i][j] << endl;
            }
        }
    }
};

int main()
{
    graph g(5);
    g.addEdgeValue(0, 1, 1);
    g.addEdgeValue(0, 2, 4);
    g.addEdgeValue(1, 2, 2);
    g.addEdgeValue(1, 3, 6);
    g.addEdgeValue(2, 3, 3);
    g.addEdgeValue(2, 4, 5);
    g.addEdgeValue(3, 4, 2);
    g.addEdgeValue(4, 0, 7);
    g.addEdgeValue(4, 1, 6);
    g.addEdgeValue(4, 2, 3);
    g.addEdgeValue(4, 3, 1);
    g.addEdgeValue(4, 4, 0);
    g.print();
    return 0;
}