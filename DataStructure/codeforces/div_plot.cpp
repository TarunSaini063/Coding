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
ld ae, bc, cd, da;
ld A1(ld x1)
{
	ld y = (cd - x1) * (da - bc) / (cd * 1.0);
	ld area1 = (da + bc + y) * x1 / 2.0;
	return area1;
}
ld A3(ld area1)
{
	ld  x3 = 2 * area1 / bc - (ae - cd);
	x3 /= 2.0;
	ld area3 = bc * (2 * x3 + ae - cd ) / 2.0;
	return x3;
}
int main(void
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
	FIO
	cin >> ae;
	cin >> bc;
	cin >> cd;
	cin >> da;
	ld area = bc * cd + (ae - cd) * bc / 2.0 + (da - bc) * cd / 2.0;
	cout << "Total Area :" << area  << "\n\n" << flush;
	ld areaeq = area / 3.0;
	cout << fixed << setprecision(10) << "Area / 3: " << area / 3.0 << "\n\n" << flush;
	ld x1, area1, x3;
	ld l = 0, h = cd;
	while (h - l > 0.0000001)
	{
		x1 = (h + l) / 2.0;
		area1 = A1(x1);
		if (area1 > areaeq) h = x1;
		else if (area1 == areaeq) break;
		else l = x1;
	}
	x3 = A3(area1);
	ld area3 = area1;
	ld area2 = area - area1 - area3;
	ld x2 = cd - x1 - x3;
	ld y1 = 2 * area1 / x1 - da;
	ld y3 = x3 * (ae - bc) / cd + bc;
	cout << fixed << setprecision(10) << "plot 1\nx1= " << x1 << " y1= " << y1 << "\n" << "\nArea: " << area1 << "\nError: " << areaeq - area1 << "\n" << flush;
	cout << fixed << setprecision(10) << "\n\nplot 2\nx2= " << x2 << " y2= " << y3 << "\nArea: " << area2 << "\nError: " << areaeq - area2 << "\n" << flush;
	cout << fixed << setprecision(10) << "\n\nplot 3\nx3= " << x3 << " y3= " << y3 << " (" << ae - cd + x3 << ")" << "---|" << "\nArea: " << area3 << "\nError: " << areaeq - area3 << "\n" << flush;
	return 0;
}