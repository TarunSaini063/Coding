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
		int n, k, pos, apos, mx = -1;
		cin >> n >> k;
		map<int, int> mp;
		for (int i = 1; i <= k + 1; i++) {
			cout << "? ";
			for (int j = 1; j <= k + 1; j++) {
				if (i != j)cout << j << " ";
			}
			cout << "\n";
			cout.flush();
			cin >> pos >> apos;
			mp[apos]++;
			mx = max(mx, apos);
		}
		cout << "! " << mp[mx] << "\n";
	}
	return 0;
}