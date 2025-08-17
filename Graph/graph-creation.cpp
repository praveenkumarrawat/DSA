#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&mat,int u, int v, int directed){
    if(directed){
        mat[u][v]=1;
    }
    else{
        mat[u][v]=1;
        mat[v][u]=1;
    }
}

void print(vector<vector<int>>&mat){
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{   
    int v= 4;
    vector<vector<int>>mat(v,vector<int>(v,0));
    addEdge(mat,0,1,false);
    addEdge(mat,1,3,false);
    addEdge(mat,3,2,false);
    addEdge(mat,2,1,false);
    print(mat);
 return 0;
}