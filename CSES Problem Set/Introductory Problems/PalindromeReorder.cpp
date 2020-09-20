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
	int t = 1;
	// cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int freq[26] = {0};
		for (char c : s) {
			freq[c - 'A']++;
		}
		string left = "";
		for (int i = 0; i < 26; i++) {
			left += string(freq[i] / 2, i + 'A');
			freq[i] %= 2;
		}
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			if (freq[i] != 0) {
				cnt++;
				left += (i + 'A');
			}
		}
		if (cnt > 1) cout << "NO SOLUTION\n";
		else {
			cout << left;
			if (cnt != 0) left.pop_back();
			reverse(all(left));
			cout << left << "\n";
		}
	}
	return 0;
}