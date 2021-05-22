#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int mxn = 2e5 + 1;
vector<int>adj[mxn];
int dis[mxn], n;
void dfs(int id) {
	int cnt = 1;
	for (int i : adj[id]) {
		dfs(i);
		cnt += dis[i];
	}
	dis[id] = cnt;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 2; i <= n; i++) {
			int x;
			cin >> x;
			adj[x].pb(i);
		}
		dfs(1);
		for (int i = 1; i <= n; i++) cout << dis[i] - 1 << " ";
	}
	return 0;
}