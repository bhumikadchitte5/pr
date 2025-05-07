//Recursive DFS
#include <iostream>
using namespace std;
const int MAX = 100; 
int n, v;
int g[MAX][MAX]; 
int vis[MAX];    

void dfs(int v) {
    cout << v << " ";
    vis[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (g[v][i] == 1 && vis[i] == 0) {
            dfs(i);
        }
    }
}
int main() {
    cout << "Enter no. of nodes: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    cout << "Enter the Starting Vertex: ";
    cin >> v;

    cout << "DFS Traversal: ";
    dfs(v);
    cout << endl;

    return 0;
}
//Recursive BFS
#include <iostream>
#include <queue>
using namespace std;
#define MAX 10
void rec_bfs(int adj[MAX][MAX],bool vis[MAX],queue<int> &q,int v){
    if(q.empty())
    {
        return;
    }
    int node=q.front();
    q.pop();
    cout<<node<<" ";
    for(int i=1;i<=v;i++){
        if(adj[node][i]==1 && !vis[i]){
            vis[i]=true;
            q.push(i);
        }
    }
    rec_bfs(adj,vis,q,v);

}
void start_bfs(int adj[MAX][MAX],int start,int v){
    bool vis[MAX]={false};
    queue<int> q;
    vis[start]=true;
    q.push(start);
    rec_bfs(adj,vis,q,v);
}
int main(){
    int v;
    cout<<"Enter no.of Vertex: ";
    cin>>v;
    int adj[MAX][MAX],start;
    cout<<"Enter ip: ";
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cin>>adj[i][j];
        }
    }
    cout<<"Enter Starting Vertex: ";
    cin>>start;
    
    start_bfs(adj,start,v);
    return 0;
    
}


// 0
// 1
// 0
// 0
// 1
// 1
// 0
// 1
// 1
// 1
// 0
// 1
// 0
// 1
// 0
// 0
// 1
// 1
// 0
// 1
// 1
// 1
// 0
// 1
// 0