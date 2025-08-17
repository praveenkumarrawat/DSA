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

    bool cycle(int src, map<int,list<int>>&adjList, unordered_map<int,bool>&visited){
        unordered_map<int,int>parent;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        // bool cycleDetected=false;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(int node:adjList[front]){
                if(!visited[node]){
                    q.push(node);
                    visited[node]=true;
                    parent[node]=front;
                }
                else if(visited[node] && parent[front]!=node){
                    cout<<"Cycle at node: "<<node<<endl;
                    return true;
                }
            }
        }
        return false;
    }

};
int main()
{
    map<int,list<int>>adjList;
    unordered_map<int,bool>visited;
    Graph g;
    g.addEdge(1,2,false,adjList);
    g.addEdge(1,3,false,adjList);
    g.addEdge(3,5,false,adjList);
    g.addEdge(3,4,false,adjList);
    g.addEdge(5,1,false,adjList);
   

    // g.print(adjList);

    cout<<"Cycle: "<< g.cycle(1,adjList,visited)<<endl;

    
    
 return 0;
}