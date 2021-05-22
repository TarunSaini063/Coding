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
	int n;
	cin >> n;
	vector<int> arr(n);
	for (auto &i : arr) cin >> i;
	ll ans = 0;
	vector<ll> pre(n + 1, 0);
	for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];
	int i = 0, j = 0;
	set<ll> s = {0};
	while (i < n)
	{
		while (j < n && s.find(pre[j + 1]) == s.end())
		{
			j++;
			s.insert(pre[j]);
		}
		ans += j - i;
		s.erase(pre[i++]);
	}
	cout << ans << "\n";
	return 0;
}