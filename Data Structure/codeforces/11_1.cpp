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
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> pos, neg;
		int zero = 0, p = 0, ne = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == 0) zero++;
			else if (x > 0) pos.pb(x), p += x;
			else neg.pb(x), ne += x;
		}
		if (p + ne == 0) cout << "NO\n";
		else {
			cout << "YES\n";
			sort(all(neg), greater<int>());
			sort(all(pos));
			if (abs(ne) > p)
			{	for (int i : neg) cout << i << " ";
				for (int i : pos) cout << i << ' ';
			}
			else {
				for (int i : pos) cout << i << ' ';
				for (int i : neg) cout << i << " ";
			}
			while (zero--) cout << "0 ";
			cout << "\n";
		}
	}
	return 0;
}
