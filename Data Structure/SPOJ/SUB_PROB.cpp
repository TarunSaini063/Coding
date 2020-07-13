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
	while (t--)
	{
		string m, s1;
		cin >> m;
		int n = sz(m);
		vector<ll> pow(n + 1), arr(n + 1, 0);
		pow[0] = 1;
		for (int i = 1; i <= n; i++) {
			pow[i] = (pow[i - 1] * 53) % mod;
		}
		set<ll> s;
		for (int i = 0; i < n; i++) {
			arr[i + 1] = (arr[i] + ((m[i] - 'A' + 1) * pow[i]) % mod);
		}
		for (int l = 1; l <= n; l++) {
			for (int i = 0; i + l <= n; i++)
			{
				ll tmp = (arr[i + l] - arr[i] + mod) % mod;
				tmp = (tmp * pow[n - i - 1]) % mod;
				s.insert(tmp);
			}
		}
		int n1;
		cin >> n1;
		while (n1--) {
			cin >> s1;
			ll tmp = 0;
			for (int i = 0; i < sz(s1); i++) {
				tmp = (tmp + pow[i] * (s1[i] - 'A' + 1) % mod) % mod;
			}
			if (s.find(tmp) != s.end()) cout << "Y\n";
			else cout << "N\n";
			// cout.flush();
		}
	}
	return 0;
}