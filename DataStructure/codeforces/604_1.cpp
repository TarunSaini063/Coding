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
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int fl = 0;
		int n = s.size();
		if ((int)s.size() == 1) {
			if (s[0] == '?') cout << "a\n";
			else cout << s << '\n';
			continue;
		}
		for (int i = 1; i < (int)s.size() - 1; i++)
		{
			if (s[i] == '?') {
				if (s[i + 1] == '?') {
					if (s[i - 1] == 'a') s[i] = 'b';
					else s[i] = 'a';
				}
				else {
					if (s[i + 1] != 'a' && s[i - 1] != 'a')s[i] = 'a';
					else if (s[i + 1] != 'b' && s[i - 1] != 'b')s[i] = 'b';
					else if (s[i + 1] != 'c' && s[i - 1] != 'c')s[i] = 'c';
				}
			}
			else
			{
				if (s[i] == s[i - 1] || s[i] == s[i + 1]) {
					fl = 1;
					break;
				}
			}
		}
		if (s[0] == '?') {
			if (s[1] == 'a') s[0] = 'b';
			else s[0] = 'a';
		}
		if (s[n - 1] == '?') {
			if (s[n - 2] == 'a') s[n - 1] = 'b';
			else s[n - 1] = 'a';
		}
		if (fl) cout << "-1\n";
		else cout << s << '\n';

	}
	return 0;
}