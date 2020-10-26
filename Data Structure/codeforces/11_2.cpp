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
		int n, k, sum = 0, ai = -1, aj = -1, len = 0;
		cin >> n >> k;
		string s;
		cin >> s;
		for (int i = 0, j = 0; i < n; i++) {
			if (s[i] == 'L') sum++;
			while (sum > k) {
				if (s[j] == 'L') sum--;
				j++;
			}
			if (len < i - j + 1) {
				len = i - j + 1;
				ai = j;
				aj = i;
			}
		}
		for (int i = ai; i <= aj; i++) {
			s[i] = 'W';
		}
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'W') {
				sum++;
				if (i > 0 && s[i - 1] == 'W') sum++;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}