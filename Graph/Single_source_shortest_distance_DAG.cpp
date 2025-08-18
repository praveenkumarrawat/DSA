#include <bits/stdc++.h>
class Solution {
    public:
    void addEdge(int u, int v, int wt, map<int,list<pair<int,int>>>&adjList){
        adjList[u].push_back({v,wt});
    }

    void topoSortDFS(int src,map<int,list<pair<int,int>>>&adjList,
        unordered_map<int,bool>&visited, stack<int>&st){
            visited[src]=true;
            for(auto nbr:adjList[src]){
                if(!visited[nbr.first]){
                    topoSortDFS(nbr.first,adjList,visited,st);
                }
            }
            st.push(src);
        }

    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        map<int,list<pair<int,int>>>adjList;
        unordered_map<int,bool>visited;
        stack<int>st;
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            addEdge(u,v,wt,adjList);
        }

        topoSortDFS(0,adjList,visited,st);

        vector<int>dist(N,INT_MAX);
        dist[0]=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto nbr: adjList[node]){
                int dest = nbr.first;
                int cost = nbr.second;
                if (dist[node] + cost < dist[dest]) {
                    dist[dest] = dist[node] + cost;
                }
            }

        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        
        return dist;
    }
};

