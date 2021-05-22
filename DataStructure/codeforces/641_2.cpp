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
		int n, x;
		cin >> n;
		vector<int> arr(n + 1);
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			arr[i + 1] = x;
		}
		int curr = 1;
		int lis[n + 1];
		lis[1] = lis[0] = 1;
		for (int i = 2; i <= n; i++)
		{
			lis[i] = 1;
			for (int j = 1; j * j <= i; j++)
			{
				if (i % j == 0)
				{
					if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
					{

						lis[i] = lis[j] + 1;//, cout << i << " " << j << "\n";
					}
					if (i / j != j && arr[i] > arr[i / j] && lis[i] < lis[i / j] + 1)
					{

						lis[i] = lis[i / j] + 1;//, cout << i << " " << i / j << "\n";
					}

				}
			}
			curr = max(curr, lis[i]);
		}
		cout << curr << "\n";
	}
	return 0;
}