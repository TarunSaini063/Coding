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
bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.ss!=b.ss) return a.ss>b.ss;
	return a.ff>b.ff;
}
int main(void)
{
	FIO	
	int n,x,q;
	cin>>n;
	vector<int>arr(200001,0);
	for(int i=0;i<n;i++){
		cin>>x;
		arr[x+100000]++;
	}
	vector<pair<int,int>> v;
	for(int i=0;i<200001;i++) v.pb(mk(i-100000,arr[i]));
	sort(all(v),cmp);
	cin>>q;
	while(q--)
	{
		cin>>n;
		cout<<v[n-1].ff<<endl;
	}
	return 0;
}