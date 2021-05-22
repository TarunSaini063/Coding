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
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, fl = 0;
		cin >> n >> k;
		string s;
		cin >> s;
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < k; i++) {
			if (s[i] == '1')a++;
			else if (s[i] == '0') b++;
		}
		if (a > k / 2 || b > k / 2) {
			fl = 1;
		}
		else {
			for (int i = k; i < n; i++) {
				if (s[i] == '?' && s[i - k] != '?') {
					s[i] = s[i - k];
				}
				if (s[i] != '?' && s[i - k] != '?')
				{
					if (s[i] != s[i - k]) {
						fl = 1;
						break;
					}
				}
				if (s[i] == '1')a++;
				else if (s[i] == '0') b++;
				if (s[i - k] == '1')a--;
				else if (s[i - k] == '0') b--;
				if (a > k / 2 || b > k / 2) {
					fl = 1;
				}
			}
		}
		if (fl) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}