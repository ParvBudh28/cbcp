#include<iostream>
#define ll long long
using namespace std;

int main(){

	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll arr[n];
		ll pre[n];
		for(ll i=0;i<n;i++){
			pre[i]=0;
		}
		pre[0]=1;
		ll sum=0;
		for(ll i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
			sum%=n;
			sum=(sum+n)%n;
			pre[sum]++;
		}
		ll ans=0;
		for(ll i=0;i<n;i++){
			ans+=(pre[i]*(pre[i]-1))/2;
		}
		cout<<ans<<endl;
	}

	return 0;
}