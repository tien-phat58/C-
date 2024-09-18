#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

#define ii pair <int, int>
#define fi first
#define se second

#define pb push_back
#define FOR(i, a, b) for (int i = a; i < b; i++)

using ll = long long;

using namespace std;

const int INF = 1e9 + 1;

priority_queue <ii, vector <ii>, greater <ii>> Q;
vector <ll> d(101, INF);
vector <ii> adj[MAX];

int n, m;
int pre[MAX];

void in_out()
{
    freopen("DIJKSTRA_CHUAN.INP", "r", stdin);
    freopen("DIJKSTRA_CHUAN.OUT", "w", stdout);
}

void input()
{
    cin >> n >> m;
    FOR(i, 0, m)
    {
        int p, q, k;
        cin >> p >> q >> k;
        adj[p].pb({q, k});
        adj[q].pb({p, k});
    }
}

void dijkstra_and_solve()
{
    Q.push({0, 1});
    d[1] = 0;
    pre[1] = 1;
    while (!Q.empty())
    {
        ii top = Q.top();
        Q.pop();
        int u = top.se, khoang_cach = top.fi;
        if (khoang_cach > d[u]) continue;
        for (auto it : adj)
        {
            int v = it.fi, w = it.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                Q.pb({d[v], v});
            }
        }
    }
    vector <int> path;
    while (1)
    {
        path.pb(t);
        if (t == 1) break;
        t = pre[t];
    }
    reverse(path.begin(), path.end());
    for (int x : path) cout << x << " ";
}

int main()
{
    //in_out;
    intput();
    dijkstra_and_solve();
    return 0;
}
