#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>>adjList;

    void addEdge(int u, int v, bool direction){
        if(direction){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void print(){
        for(auto i: adjList){
            cout<<i.first<<" : ";
            for(auto nbr: i.second){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }

};
int main()
{
    Graph g;
    g.addEdge(0,1,true);
    g.addEdge(0,2,true);
    g.addEdge(2,7,true);
    g.addEdge(2,3,true);
    g.addEdge(2,4,true);
    g.addEdge(7,1,true);

    g.print();
 return 0;
}