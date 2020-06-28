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


int n, m;
const int mxn = 2e5 + 10;
int id[mxn], sz[mxn];


int root(int i) {
	return id[i] == i ? i : id[i] = root(id[i]);
}

void uni(int i, int j) {
	int p = root(i);
	int q = root(j);
	if (p == q) return;
	if (sz[p] < sz[q]) swap(p, q);
	sz[p] += sz[q];
	id[q] = p;
}


int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int u, v;
		cin >> n >> m;
		vector<pair<ll, ll>> pci(n);
		for (int i = 0; i < n; i++) {
			cin >> pci[i].ff;
		}
		for (int i = 0; i < n; i++) {
			cin >> pci[i].ss;
			ll gd = __gcd(pci[i].ff, pci[i].ss);
			pci[i].ff /= gd, pci[i].ss /= gd;
		}


		pair<ll, ll> mxpci = pci[0];

		for (int i = 1; i < n; i++)
		{
			if (mxpci.ff * pci[i].ss <= pci[i].ff * mxpci.ss) {

				mxpci = pci[i];
			}
		}

		for (int i = 1; i <= n; i++) sz[i] = 1, id[i] = i;

		for (int i = 0; i < m; i++)
		{
			cin >> u >> v;
			if (mxpci == pci[u - 1] && mxpci == pci[v - 1])
			{
				uni(u, v);
			}

		}

		int sres = 0, res;

		for (int i = 1; i <= n; i++) {
			int p = root(i);
			if (sz[p] >= sres) {
				sres = sz[p];
				res = p;
			}
		}

		cout << sres << "\n";
		for (int i = 1; i <= n; i++) {
			if (root(i) == res) cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}