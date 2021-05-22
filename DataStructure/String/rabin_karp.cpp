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
vector<int> get_occur(string pattern, string text) {
	int P = sz(pattern);
	int T = sz(text);
	ll arr[max(P, T)];
	arr[0] = 1;
	for (int i = 1; i < max(P, T); i++) {
		arr[i] = (arr[i - 1] * 31) % mod;
	}
	ll hash_pat = 0;
	for (int i = 0; i < P; i++) {
		hash_pat = (hash_pat + arr[i] * (pattern[i] - 'a' + 1)) % mod;
	}
	ll hash_text[T + 1] = {0};
	for (int i = 0; i < T; i++) {
		hash_text[i + 1] = (hash_text[i] + (text[i] - 'a' + 1) * arr[i]) % mod;
	}
	vector<int> occur;
	for (int i = 0; i + P <= T; i++) {
		ll tmp = (hash_text[i + P] - hash_text[i] + mod) % mod;
		if (tmp == hash_pat * arr[i] % mod) occur.pb(i);
	}
	return occur;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		string pattern, text;
		cin >> text >> pattern;
		auto i = get_occur(pattern, text);
		for (auto j : i) cout << j << " ";
		cout << "\n";
	}
	return 0;
}