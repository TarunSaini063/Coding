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
int solve(vector<int> arr, int l, int n)
{

}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, fl = 0, fl1 = 0;
		cin >> n;
		vector<int> arr[n + 1], arr1(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			arr1[i] = x;
			fl1 = max(fl1, x);
		}
		for (int i = 1; i <= n; i++)
		{
			fl1 = max(fl1, arr1[i]);
			s.insert(arr1[i]);
			if (fl1 == (int)s.size() && fl1 == i)
				cout << i << ' ' << n - i << '\n';
		}
	}
	return 0;
}