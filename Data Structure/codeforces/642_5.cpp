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
//#ifndef ONLINE_JUDGE
//	freopen("input1.txt","r",stdin);
//	freopen("output1.txt","w",stdout);
//#endif
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int one = 0;
		for (auto i : s) one += (i == '1');
		int ans = one;
		for (int i = 0; i < k; i++)
		{
			int curr = 0;
			for (int j = i; j < n; j += k)
			{
				if (s[j] == '1') curr++;
				else curr--;
				curr = max(curr, 0);
				ans = min(ans, one - curr);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}