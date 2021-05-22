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
void solve(void)
{
	string s;
	cin >> s;
	int n = s.size();
	int  start = 0, ans = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'K') {
			if (s.substr(i, 4) == "KICK") {
				cnt++;
			}
		}
		else if (s[i] == 'S') {
			if (s.substr(i, 5) == "START") {
				ans += cnt;
			}
		}
	}
	cout << ans << "\n";
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}