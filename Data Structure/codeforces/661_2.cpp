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
		int n;
		cin >> n;
		vector<int>arr(n), brr(n);
		for (int &i : arr)cin >> i;
		for (int &i : brr)cin >> i;
		int c = *min_element(all(arr));
		int o = *min_element(all(brr));
		ll turn = 0;
		for (int i = 0; i < n; i++) {
			turn += max(arr[i] - c, brr[i] - o);
		}
		cout << turn << "\n";
	}
	return 0;
}