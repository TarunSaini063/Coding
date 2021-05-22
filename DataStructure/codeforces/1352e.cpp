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
		int n, ans = 0;
		cin >> n;
		vector<int> arr(n + 1, 0), arr2(n);
		for (auto &i : arr2)
		{
			cin >> i;
			arr[i]++;
		}
		for (int i = 0; i < n; i++)
		{
			int sm = 0;
			for (int j = i; j < n; j++)
			{
				sm += arr2[j];
				if (j != i && sm <= n) ans += arr[sm], arr[sm] = 0;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}