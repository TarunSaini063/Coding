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
	vector<pair<pair<int, int>, int>>adj;
	vector<int> dis(n, INT_MAX);
	for (int i = 0; i < v; i++)
	{
		cin >> a >> b >> w;
		adj.pb(mk(mk(a, b), w));
	}
	cin >> s;
	dis[s] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < v; j++)
		{
			a = adj[j].ff.ff;
			b = adj[j].ff.ss;
			w = adj[j].ss;
			if (dis[a] != INT_MAX && dis[a] + w < dis[b])
				dis[b] = dis[a] + w;
		}
	}
	for (int i = 0; i < n; i++) cout << i << ' ' << dis[i] << '\n';
	for (int j = 0; j < v; j++)
	{
		a = adj[j].ff.ff;
		b = adj[j].ff.ss;
		w = adj[j].ss;
		if (dis[a] != INT_MAX && dis[a] + w < dis[b])
		{
			cout << "Contain -ive cycle\n";
			break;
		}
	}
	return 0;
}