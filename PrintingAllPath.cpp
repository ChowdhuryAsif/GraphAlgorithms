#include <bits/stdc++.h>
using namespace std;

#define mx      100005

vector <int> graph[mx];
int dist[mx];

bool isNotVisited(int n, vector <int> path)
{
    int sz = path.size();
    for(int i=0; i<sz; i++){
        if(path[i] == n)
            return false;
    }
    return true;
}

void printPath(vector <int> path)
{
    int sz = path.size();
    for(int i=0; i<sz; i++)
        cout << path[i] << " ";

    cout << endl;
}

void generatePath(int src, int dst)
{
    queue < vector<int> > Q;
    vector <int> path;
    path.push_back(src);
    Q.push(path);

    while(!Q.empty()){
        path = Q.front();
        Q.pop();

        int last = path[path.size()-1];
        if(last == dst)
            printPath(path);

        int sz = graph[last].size();
        for(int i=0; i<sz; i++){
            if(isNotVisited(graph[last][i], path)){
                vector <int> newPath(path);
                newPath.push_back(graph[last][i]);
                Q.push(newPath);
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

    int src, dst; cin >> src >> dst;

    generatePath(src, dst);

    return 0;
}
