#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    // unordered_map<int,list<int>>adjList;

    void addEdge(int u, int v, bool direction, unordered_map<int,list<int>>&adjList){
        if(direction){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void print(unordered_map<int,list<int>>&adjList){
        for(auto i: adjList){
            cout<<i.first<<" : ";
            for(auto nbr: i.second){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }

    void BFS(int src, unordered_map<int,list<int>>adjList, unordered_map<int,bool>&visited){
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cout<<front<<" ";
            for(int nbr:adjList[front]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }

        }
    }

};
int main()
{
    unordered_map<int,list<int>>adjList;
    unordered_map<int,bool>visited;
    Graph g;
    g.addEdge(1,2,true,adjList);
    g.addEdge(1,3,true,adjList);
    g.addEdge(2,4,true,adjList);
    g.addEdge(3,4,true,adjList);
    g.addEdge(3,5,true,adjList);
    g.addEdge(4,7,true,adjList);
    g.addEdge(5,7,true,adjList);

    g.print(adjList);

    g.BFS(1,adjList,visited);

    
 return 0;
}