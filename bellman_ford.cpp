#include<bits/stdc++.h>

using namespace std;

const int v=5;

struct V{
    int d=INT_MAX;
    struct V* pi=nullptr;
};

//this is equivalent to initialize single source function
//in bellman ford algo
vector<struct V*> vertex(v+1,(struct V*)malloc(sizeof(struct V)));

vector<vector<pair<int,int>>> adj= vector<vector<pair<int,int>>>(v+1,vector<pair<int,int>>());

void add_edge(int u,int v,int w){
    adj[u].push_back({v,w});
}

void relax(int u,int v,int w){
    cout<<"relax :: "<<u<<":"<<v<<":"<<w<<endl;
    if(vertex[v]->d > vertex[v]->d+w){
        vertex[v]->d = vertex[u]->d+w;
        vertex[v]->pi = vertex[u];
    }
}

bool bellman_ford(){
    vertex[1]->d=0;

    for(int i=1;i<=v;i++){
        for(auto &j:adj[i]){
            cout<<"bell : "<<i<<":"<<j.first<<endl;
            relax(i,j.first,j.second);
        }    
    }

    cout<<"done\n";
    for(int i=1;i<=v;i++){
        for(auto &e:adj[i]){
            if(vertex[e.first]->d > vertex[i]->d+e.second)
                return false;
        }
    }

    return true;
}

int main(){
    vector<vector<int>> edges = {
        {1,2,6},
        {1,3,7},
        {2,4,5},
        {4,2,-2},
        {3,5,9},
        {4,5,7},
        {5,1,2},
        {3,4,-3},
        {2,5,-4},
        {2,3,8}
    };

    for(auto &e:edges){
        add_edge(e[0],e[1],e[2]);
    }

    cout<<bellman_ford();
    return 0;
}