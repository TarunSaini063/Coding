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
		string s;
		int n;
		cin >> n;
		cin >> s;
		int ans1 = 0, i = 0, ans = 0;
		while (i < n) {
			if (s[i] != '1') {
				i++;
				continue;
			}
			int j = i + 1;
			while (j < n && s[j] == '1')j++, ans1++;
			i = j;
		}
		i = 0;
		while (i < n) {
			if (s[i] != '0') {
				i++;
				continue;
			}
			int j = i + 1;
			while (j < n && s[j] == '0')j++, ans++;
			i = j;
		}
		cout << max(ans1, ans) << '\n';
	}
	return 0;
}