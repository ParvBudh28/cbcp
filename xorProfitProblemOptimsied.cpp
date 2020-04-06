#include<iostream>
#include<math.h>
#define ll long long
using namespace std;


int main(){

	ll a,b;
	cin>>a>>b;

	if(a==b){
		cout<<"0"<<endl;
		return 0;
	}

	int aBits[64]={0};
	int bBits[64]={0};
	for(int i=0;i<64;i++){
		aBits[i]=((a>>i)&1);
		bBits[i]=((b>>i)&1);
	}
	ll k=0;
	for(int i=63;i>=0;i--){
		if(aBits[i]!=bBits[i]){
			k=i;
			break;
		}
	}
	ll ans=pow(2,k+1)-1;
	cout<<ans<<endl;

	return 0;
}