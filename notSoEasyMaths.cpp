#include<iostream>
#include<math.h>
#define ll long long
using namespace std;


int main(){

	int t;
	int prime[]={2,3,5,7,11,13,17,19};
	int size=sizeof(prime)/sizeof(int);
	// cout<<size<<endl;
	cin>>t;
	while(t--){

		ll n;
		cin>>n;
		ll ans=0;
		for(int i=1;i<pow(2,size);i++){
			int noOfBits= __builtin_popcount(i);
			ll product=1;
			for(int j=0;j<8;j++){
				if((i>>j)&1){
					product*=prime[j];
				}
			}
			// cout<<product<<endl;
			if(noOfBits&1){
				ans+=(n/product);
			}
			else{
				ans-=(n/product);
			}
		}

		cout<<ans<<endl;

	}

	return 0;
}