#include <bits/stdc++.h>
using namespace std;
int node, edge;

#define mx  105

vector <int> graph[mx];
vector <int> topSortList;
int updatedDst[mx];
bool vis[mx];
int dp[mx];

void reset()
{
    topSortList.clear();
    for(int i=0; i<mx; i++){
        graph[i].clear();
        vis[i] = dp[i] = 0;
        updatedDst[i] = i;
    }
}

void dfs(int node)
{
    vis[node] = true;
    int sz = graph[node].size();
    for(int i=0; i<sz; i++){
        int next = graph[node][i];
        if(!vis[next])
            dfs(next);
    }
    topSortList.push_back(node);
}

void calculateLength()
{
    for(int i=0; i<topSortList.size(); i++){
        int u = topSortList[i];

        //sort(graph[u].begin(), graph[u].end());
        int sz = graph[u].size();
        for(int j=0; j<sz; j++){
            int v = graph[u][j];
            if(dp[u] <= dp[v] + 1){

                if(dp[u] == dp[v] + 1)
                    updatedDst[u] = min(updatedDst[u], updatedDst[v]);
                else
                    updatedDst[u] = updatedDst[v];
                dp[u] = dp[v] + 1;
            }
        }
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int cs = 0;
    while(true){
        scanf("%d", &node);
        if(!node) break;

        reset();

        int src;
        scanf("%d", &src);

        int u, v;
        while(true){
            scanf("%d %d", &u, &v);

            if(!u and !v) break;

            graph[u].push_back(v);
            //graph[v].push_back(u);
        }

        dfs(src);

        calculateLength();

        int dst;
        for(int i=1; i<=node; i++)
            if(dp[i] == 0){
                dst = i;
                break;
            }

        if(cs)
            printf("\n");

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n", ++cs, src, dp[src], updatedDst[src]);
    }
    cout << endl;

    return 0;
}
