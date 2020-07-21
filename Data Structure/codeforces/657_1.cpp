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
string p = "abacaba";
int occur(string s) {
	int cnt = 0;
	ll y = 0;
	while (string::npos != (y = s.find(p, y))) {
		y++;
		cnt++;
	}
	return cnt;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s, ans;
		cin >> s;
		for (int i = 0; i <= n - 7; i++) {
			int j = 0, k = i;
			string tmp = s;
			while (j < 7) {
				if (tmp[k] == '?' || tmp[k] == p[j]) {
					if (tmp[k] == '?') tmp[k] = p[j];
					k++;
					j++;
				}
				else break;
			}
			int fl = 1;
			if (j < 7) fl = 0;
			int cnt = occur(tmp);
			fl &= cnt == 1;
			if (fl) {
				ans = tmp;
				break;
			}
		}
		if (sz(ans)) {
			cout << "YES\n";
			for (auto i : ans)
			{
				if (i == '?') i = 'z';
				cout << i;
			}
			cout << "\n";
		}
		else cout << "NO\n";
	}
	return 0;
}