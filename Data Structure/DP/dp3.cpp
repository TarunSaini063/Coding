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
bool partition(vector<int> a,int sum,int t){
    if(sum==0 ){
        return true;
    }
    if(sum!=0 && t==0){
        return false;
    }
    if(a[t-1]>sum){
    return  partition(a,sum,t-1) ;
    }
  return partition(a,sum-a[t-1],t-1)||partition(a,sum,t-1);
    
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll sm=0;
		vector<int> arr(n);
		for(auto &j : arr) cin>>j,sm+=j;
		if(sm%2==1) {
			cout<<"NO"<<"\n";
			continue;
		}
		sm/=2;
		if(partition(arr,sm,n)==true) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
	return 0;
}