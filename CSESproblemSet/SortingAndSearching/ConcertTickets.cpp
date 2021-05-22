#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
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
int main(void)
{
	FIO
	int t = 1;
	// cin>>t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		set<pair<int, int>> s;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s.insert(mk(x, i));
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			auto it = s.lower_bound(mk(x + 1, 0));
			if (it == s.begin()) cout << "-1\n";
			else {
				it--;
				cout << it->first << "\n";
				s.erase(it);
			}
		}
	}
	return 0;
}