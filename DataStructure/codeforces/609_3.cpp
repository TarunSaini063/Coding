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
	int n, k;
	cin >> n >> k;
	string s, res = "";
	cin >> s;
	for (int i = 0; i < n; i++) res += s[i % k];
	if (res < s) {
		for (int i = k - 1; ++s[i] > '9'; i--) s[i] = '0';
	}
	for (int i = 0; i < n; i++) res[i] = s[i % k];
	cout << n << "\n" << res << "\n";
	return 0;
}