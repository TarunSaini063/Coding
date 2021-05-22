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
		int n, k, freq[26] = {0};
		cin >> n >> k;
		string s;
		cin >> s;
		for (auto i : s) freq[i - 'a']++;
		for (int len = n; len >= 1; len--)
		{
			int amt = len / __gcd(len, k); // eek rotation mai use hona vala count
			int tot = 0;
			for (auto i : freq) tot += (i / amt) * amt; // total char in making i/amt round
			if (tot >= len)
			{
				cout << len << '\n';
				break;
			}
		}

	}
	return 0;
}