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
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		int i = 0, n = sz(s), j = n - 1, cost = 0;
		while (i < n && s[i] == '0')i++;
		while (i < n) {
			while (i < n && s[i] == '1')i++;
			int gap = 0, j = i;
			while (j < n && s[j] == '0') {
				j++, gap++;
			}
			if (j == n) break;
			if (gap * b + a <= 2 * a) {
				for (int p = i; p < j; p++) s[p] = '1', cost += b;//, cout << p << " ";
			}
			i = j;
			// cout << i << " " << j;
		}
		// cout << s << " " << cost << "\n";
		i = 0;
		while (i < n && s[i] == '0')i++;
		while (i < n) {
			if (s[i] == '1') {
				cost += a;
				while (i < n && s[i] == '1') i++;
			}
			i++;
		}
		cout << cost << '\n';
	}
	return 0;
}