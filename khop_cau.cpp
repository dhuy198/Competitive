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

int32_t main()
{
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
            dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
        if (isJoint[i])
            cout << i << ' ';
}