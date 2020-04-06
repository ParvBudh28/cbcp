#include<iostream>
#define ll long long
using namespace std;


int main(){

	int q;
	cin>>q;
	while(q--){

		int a,b;
		cin>>a>>b;
		ll ans=0;
		for(int i=a;i<=b;i++){
			ans+= __builtin_popcount(i);
		}
		cout<<ans<<endl;
	}

	return 0;
}