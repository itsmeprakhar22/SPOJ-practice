#include <bits/stdc++.h>
#define int long long
using namespace std;

class Graph{
    int V;
    //adjList of node->(node,cost)
    list<pair<int,int> > *l;
public:
    Graph(int v){
        this->V=v;
        l= new list<pair<int,int> >[V];
    }

    void addEdge(int u, int v, int cost, int bidir=true){
        l[u].push_back(make_pair(v,cost));
        if(bidir){
            l[v].push_back({u,cost});
        }
    }

    int dfsHelper(int src,bool* visited,int* count, int &ans){
        visited[src]=true;
        count[src]=1;
        //Recursively find size of children
        for(auto node: l[src]){
            int v= node.first;
            if(!visited[v]){
                count[src]+=dfsHelper(v,visited,count,ans);
                int no_subtree_nodes= count[v];
                int edgeCost= node.second;
                ans+=2*min(no_subtree_nodes, V-no_subtree_nodes)*edgeCost;
            }
        }
        return count[src];
    }
    int dfs(){
        bool* visited= new bool[V]{0};
        int* count= new int[V]{0};
        int ans=0;
        dfsHelper(0,visited,count,ans);
        return ans;
    }
};

signed main(){
    int t,k=1; cin>>t;
    while(t--){
        int n; cin>>n;
        Graph g(n);
        for(int i=0;i<n-1;i++){
            int u,v,cost; cin>>u>>v>>cost;
            g.addEdge(u-1,v-1,cost);
        }
        cout<<"Case #"<<k<<": "<<g.dfs()<<endl;
        k++;
    }
}
