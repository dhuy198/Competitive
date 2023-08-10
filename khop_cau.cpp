#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
int n, m;
int low[maxN], num[maxN];
int bridge = 0, joint = 0;
bool isJoint[maxN];
vector<int> adj[maxN];
int timeDfs = 0;

void dfs(int u, int parent)
{
    int child = 0;
    num[u] = low[u] = ++timeDfs;
    for (int v : adj[u])
    {
        if (v == parent)
            continue; // khong quay lai dinh goc de xet
        child++;      // tang so nut con cua nut u
        if (!num[v])
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            // tinh so canh cau
            if (low[v] == num[v])
                bridge++;
            // tinh so dinh khop
            if (u == parent)
            {
                if (child > 1)
                    isJoint[u] = true;
            }
            else if (low[v] >= num[u]) // u khong la goc cay dfs
            {
                isJoint[u] = true;
            }
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
    }
}
