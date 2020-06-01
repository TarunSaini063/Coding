#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
int main(void)
{
	FIO
	int n, v, a, b, w, s;
	cin >> n >> v;
	vector<pair<int, int>>adj[n];
	vector<int> dis(n, INT_MAX);
	for (int i = 0; i < v; i++)
	{
		cin >> a >> b >> w;
		adj[a].pb(mk(b, w));
		adj[b].pb(mk(a, w));
	}
	cin >> s;
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(mk(0, s));
	while (!q.empty())
	{
		int u = q.top().ss;
		q.pop();
		for (auto i : adj[u])
		{
			int v = i.ff;
			int w = i.ss;
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push(mk(dis[v], v));
			}
		}
	}
	for (int i = 0; i < n; i++) cout << i << ' ' << dis[i] << '\n';
	return 0;
}