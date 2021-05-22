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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int od = 0, ev = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 2) {
				if ((s[i - 1] - '0') % 2 == 1) od++;
			}
			else {
				ev += (s[i - 1] - '0') % 2 == 0;
			}
		}
		if (n % 2 == 0)
		{
			if (ev != 0) cout << "2\n";
			else cout << "1\n";
		}
		else {
			if (od != 0) cout << "1\n";
			else cout << "2\n";
		}
	}
	return 0;
}