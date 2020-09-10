#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll int
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int N = 4e3;
ll n, m, k;
vector<ll> gr[N];
vector<ll> v;
ll par[N + 1][N + 1];

void restore_path(ll a, ll b) {
	if (b == 1) {
		v.push_back(b);
		return;
	}
	restore_path(par[a][b], a);
	v.push_back(b);
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m >> k;
		ll i, x, y, z;
		for (i = 0; i < m; i++) {
			cin >> x >> y;
			gr[x].push_back(y);
			gr[y].push_back(x);
		}
		set< pair<ll, pair<ll, ll>> > ban;
		for (i = 0; i < k; i++) {
			cin >> x >> y >> z;
			ban.insert({x, {y, z}});
		}
		queue< pair<ll, ll> > q;
		q.push({0, 1});
		bool vis[n + 1][n + 1] = {{false}};
		vis[0][1] = 1;
		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for (auto it : gr[y]) {
				z = it;
				if (!vis[y][z] && ban.find({x, {y, z}}) == ban.end()) {
					vis[y][z] = true;
					par[y][z] = x;
					q.push({y, z});
					if (z == n) {
						restore_path(y, z);
						cout << v.size() - 1 << "\n";
						for (auto it : v)
							cout << it << " ";
						cout << "\n";
						return 0;
					}
				}
			}
		}
		cout << "-1\n";
	}
	return 0;
}

