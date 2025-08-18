#include <bits/stdc++.h>

class Solution {
  public:
    
    void addEdge(int u, int v, bool direction, map<int,list<int>>&adjList){
        if(direction){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
  
    bool cycleUsingDFS(int src,int srcParent, map<int,list<int>>&adjList, unordered_map<int,bool>&visited){

        // parent[src]=srcParent;
        visited[src]=true;
        for(int node: adjList[src]){
            if(!visited[node]){
                if(cycleUsingDFS(node,src,adjList,visited)) return true;
            }
            else if(visited[node] && srcParent!=node){
                // cycle present
                return true;
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,bool>visited;
        map<int,list<int>>adjList;
        // unordered_map<int,int>parent;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            addEdge(u,v,false,adjList);
        }
        
        for(auto &it : adjList){
            if(!visited[it.first]){
                if(cycleUsingDFS(it.first,-1,adjList,visited)) return true;
            }
        }
        
        return false;
    }
};