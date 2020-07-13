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
		string s;
		cin >> s;
		map<char, int> mp;
		map<char, char> mp1;
		mp1['R'] = 'P';
		mp1['S'] = 'R';
		mp1['P'] = 'S';
		for (auto i : s) {
			mp[i]++;
		}
		char c, mn = 0;
		for (auto i : mp) {
			if (mn <= i.ss) {
				mn = i.ss;
				c = i.ff;
			}
		}
		for (int i = 0; i < sz(s); i++) cout << mp1[c];
		cout << "\n";
	}
	return 0;
}