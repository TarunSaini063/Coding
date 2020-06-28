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
int minSwaps(int arr[], int N) {
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		v.push_back({arr[i], i});
	}
	sort(v.begin(), v.end());
	vector<bool> vis(N, false);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (vis[i] || v[i].second == i) continue;
		int cir = 0, j = i;
		while (!vis[j]) {
			cir++;
			vis[j] = true;
			j = v[j].second;
		}
		if (cir > 0) ans += cir - 1;
	}
	return ans;
}
int main(void)
{
	FIO
	int n;
	cin >> n;
	int arr[n];
	for (auto &i : arr) cin >> i;
	cout << minSwaps(arr, n) << "\n";
	return 0;
}