#include<iostream>
#include<math.h>
#define ll long long
using namespace std;


int main(){

	int n;
	cin>>n;
	int arr[n];

	int count[64]={0};

	for(int i=0;i<n;i++){
		cin>>arr[i];
		int data=arr[i];
		int index=0;
		while(data>0){
			if((data)&1){
				count[index]++;
			}
			data=data>>1;
			index++;
		}
	}

	ll ans=0;
	for(int i=0;i<64;i++){
		count[i]%=3;
		// cout<<count[i]<<" ";
		if(count[i]==1){
			ans+=pow(2LL,i);	
		}
	}
	cout<<ans<<endl;

	return 0;
}