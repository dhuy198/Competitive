#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
int n, m;
int scc = 0, timeDfs = 0;
int low[maxN];      // dinh thap nhat ma low[u] co the den voi khong qua 1 lan di cung nguoc
int num[maxN];      // luu thoi gian dfs cua dinh thu u
bool deleted[maxN]; // cac dinh cua tplt manh da bi xoa
vector<int> adj[maxN];
stack<int> st; // thu tu cac dinh thuoc 1 tplt manh

void dfs(int u)
{
    timeDfs++;
    st.push(u);
    num[u] = low[u] = timeDfs;
    for (int v : adj[u])
    {
        if (deleted[v])
            continue;
        if (!num[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if (num[u] == low[u])
    {
        scc++;
        int v;
        while (v != u)
        {
            v = st.top();
            st.pop();
            deleted[v] = true;
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
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!num[i])
        {
            dfs(i);
        }
    }
    cout << scc;
}