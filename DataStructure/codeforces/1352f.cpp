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
		int a, b, c, z = 0;
		cin >> c >> b >> a;
		string s = "";
		if (a != 0)
		{
			s += "11"; cout << 11;
			for (int i = 0; i < a - 1 ; i++)cout << 1;
			z++;
		}
		if (c != 0)
		{
			s += "00"; cout << "00";
			for (int i = 0; i < c - 1 ; i++)cout << "0";
			z++;
		}
		if (z == 2)b--;
		if (b != 0)
		{
			if (s == "") s = "0", cout << 0;
			z = s.back() - '0';
			z++;
			for (int i = 0; i < b ; i++, z++) cout << z % 2;
		}
		cout << "\n";
	}
	return 0;
}