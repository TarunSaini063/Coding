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
string a, b;
int solve(int s, int e) {
	int res = 0;
	while (s < e) {
		while (s < e && a[s] == b[s]) s += 2;
		if (s < e) {
			res++;
			while (s < e && a[s] != b[s]) s += 2;
		}
	}
	return res;
}
int main(void)
{
	FIO
	int t = 1;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << solve(0, sz(a)) + solve(1, sz(a)) << '\n';
	}
	return 0;
}