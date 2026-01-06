#include <iostream>
using namespace std;

inline double prob(){return (double)rand()/RAND_MAX;}

bool is_connected(bool** graph,int size){
    int old_size=0,current_size=0;
    bool *close=new bool[size];
    bool *open=new bool[size];
    for(int i=0;i<size;i++)
    {
        close[i]=open[i]=false;
    }
    open[0]=true;
    while(current_size < size){
        old_size = current_size;
        for(int i=0; i<size; i++){
            if(open[i] && (close[i]==false)){
                close[i]=true;
                current_size++;
                for(int j=0; j<size; j++){
                    open[j] = open[j] || graph[i][j];
                }
            }
        }
        if (current_size == size) return true;
        if (old_size == current_size) return false;
    }
    return true;
}   

int main(){
    bool** graph;int size;
    cin>>size;//size of graph
    srand(time(0));//random seed
    graph= new bool*[size];//create graph
    for(int i=0;i<size;i++){
        graph[i]=new bool[size];
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j) graph[i][j]=false;
            else graph[i][j]=graph[j][i]=(prob()<0.20);
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    if(is_connected(graph,size)){
        cout << "Connected" << endl;
    }
    else{
        cout << "Not Connected" << endl;
    }
    return 0;
}