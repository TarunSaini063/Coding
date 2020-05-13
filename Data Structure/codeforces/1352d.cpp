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
		int n;
		cin >> n;
		vector<int> arr(n);
		for (auto &i : arr) cin >> i;
		int a, b = 0, s1 = 0, s2 = 0, i = 0, j = n - 1, mv = 1;
		a = arr[i++];
		s1 = a;
		while (i <= j)

		{
			b = 0;
			while (j >= i && b <= a)
			{
				b += arr[j--];
			}
			mv++;
			s2 += b;
			if (j < i) break;
			a = 0;
			while (i <= j && a <= b)
			{
				a += arr[i++];
			}
			s1 += a;
			mv++;
		}
		cout << mv << " " << s1 << " " << s2 << "\n";
	}
	return 0;
}