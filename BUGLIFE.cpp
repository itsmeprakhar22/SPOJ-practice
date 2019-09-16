#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v){
        this->V=v;
        l= new list<int>[V];
    }

    void addEdge(int u,int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir)
        l[v].push_back(u);
    }
    
    bool isBipartite(int s, bool* &visited){
        queue<int> q;
        q.push(s);
        int* color = new int[V];
        for(int i=0;i<V;i++) color[i]=-1;
        color[s]=0;
        bool ans=true;
        while(!q.empty()){
            int front = q.front();
            visited[front]=true;
            q.pop();
            for(auto neighbor: l[front]){
                if(color[neighbor]==-1){
                //Assign alternate color to the adjacent nodes
                    color[neighbor]= 1-color[front];
                    q.push(neighbor);
                }
                //Check two consecutive same colors
                else if(color[front]==color[neighbor])
                {
                    ans=false;
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    int t,k=1; cin>>t;
    while(t--){
        cout<<"Scenario #"<<k<<":"<<endl;
    int V,E; cin>>V>>E;
    Graph g(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u-1,v-1);
    }
    bool ans=true;
    bool* visited= new bool[V]{false};
    for(int i=0;i<V;i++){
        if(!visited[i]){
            ans=ans&g.isBipartite(i,visited);
        }
    }
    if(ans){
        cout<<"No suspicious bugs found!\n";
    }
    else
    cout<<"Suspicious bugs found!\n";
    k++;
}
}
