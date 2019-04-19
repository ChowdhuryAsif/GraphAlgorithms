#include <bits/stdc++.h>
using namespace std;

#define mx      100005

vector <int> graph[mx];
int dist[mx];

void bfs(int src)
{
    queue <int> Q;
    Q.push(src);
    dist[src] = 0;

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        int sz = graph[u].size();
        for(int i=0; i<sz; i++){
            int v = graph[u][i];

            if(dist[v] == -1){
                Q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
}

void reset()
{
    for(int i=0; i<mx; i++)
        graph[i].clear();

    memset(dist, -1, sizeof(dist));
}

int main()
{
    int n, m; cin >> n >> m;

    reset();

    while(m--){
        int u, v; cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int src; cin >> src;

    bfs(src);

    for(int i=1; i<=n; i++)
        cout << "Distance of " << i << " from source, " << dist[i] << endl;
    return 0;
}
