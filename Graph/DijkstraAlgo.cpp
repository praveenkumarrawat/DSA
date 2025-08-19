#include <bits/stdc++.h>


class Solution {
  public:
    void addEdge(int u, int v, int wt, map<int,list<pair<int,int>>>&adjList){
        adjList[u].push_back({v,wt});
        adjList[v].push_back({u,wt});
    }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        map<int,list<pair<int,int>>>adjList;
        
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            addEdge(u,v,wt,adjList);
        }
        
        vector<int>ans(V,INT_MAX);
        ans[src]=0;
        
        set<pair<int,int>>st; //wt,node
        st.insert({0,src});
        // initial state
        while(!st.empty()){
            auto it = st.begin();
            int node_wt = it->first;
            int node = it->second;
            st.erase(it);
            
            if(node_wt > ans[node]) continue;
            
            // explore all the nbr's
            for(auto nbr:adjList[node]){
                int nbr_node = nbr.first;
                int nbr_wt = nbr.second;
                
                if(node_wt + nbr_wt <ans[nbr_node]){
                    ans[nbr_node]=node_wt + nbr_wt;
                    st.insert({ans[nbr_node],nbr_node});
                }
            
            }
            
        }
        return ans;
        
    }
};