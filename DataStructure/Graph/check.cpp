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
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
void check1(int *a,int *b)
{
	int *c;
	*c=*a;
	*a=*b;
	*b=*c;
}
void check2(int* a,int* b)
{
	int* c;
	*c=*a;
	*a=*b;
	*b=*c;
}
int main(void)
{
	FIO	
	int a,b,a1,b1;
	a=a1=10;
	b=b1=20;
	check1(&a,&b);
	check2(&a1,&b1);
	cout<<a<<" "<<b<<"\n"<<a1<<" "<<b1<<"\n";
	return 0;
}