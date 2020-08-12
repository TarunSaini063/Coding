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
	// cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int i = 0, j = n - 1;
		while (j >= 0 && s[j] == 'W') j--;
		if (j < 0) {
			cout << 0;
			return 0;
		}
		while (i < j && s[i] == 'R') i++;
		if (i == j) {
			cout << 0;
			return 0;
		}
		int ans = 0;
		while (i < j) {
			ans++;
			s[i] = 'R';
			s[j] = 'W';
			j--;
			while (i < j && s[i] == 'R') i++;
			while (j > i && s[j] == 'W')j--;

		}
		cout << ans << "\n";
	}
	return 0;
}