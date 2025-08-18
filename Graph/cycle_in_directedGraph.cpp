#include <bits/stdc++.h>

class Solution {
  public:
    
    void addEdge(int u, int v, map<int,list<int>>&adjList){
        adjList[u].push_back(v);
    }
    
    bool checkCycleDFS(int src, map<int,list<int>>&adjList,
        unordered_map<int,bool>&visited,unordered_map<int,bool>&trackDFS){
            trackDFS[src]=true;
            visited[src]=true;
            
            for(int node:adjList[src]){
                if(!visited[node]){
                    bool ans = checkCycleDFS(node,adjList,visited,trackDFS);
                    if(ans) return true;
                }
                else if(visited[node] && trackDFS[node]){
                    // cycle present 
                    return true;
                }
            }
            
            // backtrack - important
            trackDFS[src]=false;
            return false;
        }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        map<int,list<int>>adjList;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            addEdge(u,v,adjList);
        }
        
        unordered_map<int,bool>visited;
        unordered_map<int,bool>trackDFS;
        
        for(auto it:adjList){
            int src = it.first;
            if(!visited[src]){
                if(checkCycleDFS(src,adjList,visited,trackDFS)) return true;
            }
        }
        
        return false;
        
    }
};