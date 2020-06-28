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
	int t = 1;
	while (t--)
	{
		ll K, cnt[10] = {0};
		cin >> K;
		string s = "codeforces";
		for (int i = 0;; i++)
		{
			long long now = 1;
			for (int j = 0; j < 10; j++)now *= cnt[j];
			if (now >= K)break;
			cnt[i % 10]++;
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < cnt[i]; j++)cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}