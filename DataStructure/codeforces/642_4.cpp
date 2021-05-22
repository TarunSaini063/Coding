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
bool cmp(pair<int, int> a, pair<int, int> b)
{
	int x = a.ss - a.ff;
	int y = b.ss - b.ff;
	if (x > y) return true;
	if (x < y) return false;
	return a.ff <= b.ff;
}
vector<pair<int, int>> arr;
void solve(int i, int j)
{
	arr.push_back({i, j});
	int i1 = j - i + 1;
	int k;
	if (i1 % 2 == 0)
	{
		k = (i + j - 1) / 2;
	}
	else k = (i + j) / 2;
	if (k > i) solve(i, k - 1);
	if (k < j) solve(k + 1, j);
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		arr.clear();
		solve(1, n);
		sort(all(arr), cmp);
		vector<int> tp(n + 1);
		int z = 0;
		for (auto i : arr)
		{
			int i1 = i.ss - i.ff + 1;
			int k;
			if (i1 % 2 == 0)
			{
				k = (i.ss + i.ff - 1) / 2;
			}
			else k = (i.ss + i.ff) / 2;
			tp[k] = (++z);
		}
		for (int i = 1; i <= n; i++)cout << tp[i] << " ";
		cout << "\n";
	}
	return 0;
}