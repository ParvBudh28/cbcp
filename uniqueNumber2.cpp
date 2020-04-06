#include<iostream>
#define ll long long
using namespace std;


int main(){

	int n;
	cin>>n;

	int arr[n];
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		ans^=arr[i];
	}

	// find the first set bit from right
	int bit;
	for(int i=0;i<32;i++){
		if(ans&(1<<i)){
			bit=i;
			break;
		}
	}
	int tempAns=0;
	for(int i=0;i<n;i++){
		if((1<<bit)&arr[i]){
			tempAns^=arr[i];
		}
	}
	ans=tempAns^ans;
	if(ans<tempAns){
		cout<<ans<<" "<<tempAns<<endl;
	}
	else{
		cout<<tempAns<<" "<<ans<<endl;
	}

	return 0;
}