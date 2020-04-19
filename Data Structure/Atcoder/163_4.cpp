#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define ff first
#define ss second
#define mod 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
int main(void)
{
    FIO    
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(ll i=k;i<=n+1;i++)
    {
        ll mx=((i*(n+n-i+1))%mod*(invmod(2)%mod))%mod;
        ll mn=((i*(i-1))%mod*(invmod(2)%mod))%mod; 
        ans=(ans%mod+mx-mn+1+mod)%mod;
    }
    cout<<ans<<"\n";
    return 0;
}
