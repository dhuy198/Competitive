#include <bits/stdc++.h>
using namespace std;

struct dsu // toi uu theo kich thuoc (size)
{
    vector<int> sz, parent;
    void init(int n)
    {
        sz = vector<int>(n + 1, 1);
        parent = vector<int>(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int root(int u)
    {
        if (u == parent[u])
            return u;
        int p = root(parent[u]);
        parent[u] = p;
        return p;
    }
    void unite(int a, int b)
    {
        a = root(a), b = root(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};

struct dsu // toi uu theo do cao cua cay
{
    vector<int> height, parent;
    void init(int n)
    {
        height = vector<int>(n + 1, 1);
        parent = vector<int>(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int root(int u) { return u == parent[u] ? u : parent[u] = root(parent[u]); }
    void unite(int a, int b)
    {
        a = root(a), b = root(b);
        if (a == b)
            return;
        if (height[a] < height[b])
            swap(a, b);
        parent[b] = a;
        if (height[a] == height[b])
            height[a]++;
    }
};
