#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    // unordered_map<int,list<int>>adjList;

    void addEdge(int u, int v, bool direction, map<int,list<int>>&adjList){
        if(direction){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void print(map<int,list<int>>&adjList){
        for(auto i: adjList){
            cout<<i.first<<" : ";
            for(auto nbr: i.second){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }

    void DFS(int src, map<int,list<int>>&adjList, unordered_map<int,bool>&visited){
        cout<<src<<" ";
        visited[src]=true;
        for(int node: adjList[src]){
            if(!visited[node]){
                DFS(node,adjList,visited);
            }
        }        
    }

};
int main()
{
    map<int,list<int>>adjList;
    unordered_map<int,bool>visited;
    Graph g;
    g.addEdge(1,2,true,adjList);
    g.addEdge(1,3,true,adjList);
    g.addEdge(2,4,true,adjList);
    g.addEdge(3,4,true,adjList);
    g.addEdge(3,5,true,adjList);
    g.addEdge(4,7,true,adjList);
    g.addEdge(5,7,true,adjList);

    g.addEdge(8,9,true,adjList);
    g.addEdge(9,10,true,adjList);

    g.addEdge(11,11,true,adjList);

    g.print(adjList);

    cout<<"DFS "<<endl;

    int disconnected_component = 0;

    for(auto &i:adjList){
        int node = i.first;
        if(!visited[node]){
            disconnected_component++;
            g.DFS(node,adjList,visited);
            cout<<endl;
        }
    }

    cout<<"disconnected_component: "<<disconnected_component<<endl;
    
 return 0;
}