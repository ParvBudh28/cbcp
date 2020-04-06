#include<iostream>
#define ll long long
using namespace std;


int main(){

	int x;
	int y;
	cin>>x>>y;
	int ans=0;
	for(int i=x;i<=y;i++){
		for(int j=x;j<=y;j++){
			ans=max(ans,(i^j));
		}
	}
	cout<<ans<<endl;

	return 0;
}