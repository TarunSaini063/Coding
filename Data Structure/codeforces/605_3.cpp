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
	string s;
	cin >> s;
	char c;
	ll sz;
	int freq[26] = {0};
	for (int i = 0; i < k; i++) {
		cin >> c;
		freq[c - 'a'] = 1;
	}
	ll ans = 0;
	string curr = "";
	for (int i = 0; i < n; i++)
	{
		if (freq[s[i] - 'a'] == 0) {
			sz = curr.size();
			ans += (sz + 1) * sz / 2;
			curr = "";
		}
		else curr += s[i];
	}
	sz = curr.size();
	ans += (sz + 1) * sz / 2;
	cout << ans << "\n";
	return 0;
}