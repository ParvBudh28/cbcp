#include<iostream>
#define ll long long
using namespace std;

ll** multiply(ll** a1,ll** a2){
	ll** ans;
	ans=new ll*[2];
	for(int i=0;i<2;i++){
		ans[i]=new ll[2];
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			ll sum=0;
			for(int k=0;k<2;k++){
				sum+=a1[i][k]*a2[k][j];
			}
			ans[i][j]=sum;
		}
	}
	return ans;
}

ll** pow(ll** t,ll n){
	// if(n==1)
	if(n==1){
		return t;
	}
	ll** temp;
	temp=new ll*[2];
	for(int i=0;i<n;i++){
		temp[i]=new ll[2];
	}

	// if n is odd
	if(n&1){
		temp=pow(t,n-1);
		temp=multiply(temp,t);
		return temp;
	}
	// if n is even
	else{
		temp=pow(t,n/2);
		temp=multiply(temp,temp);
		return temp;
	}
}

int main(){
	// initialise a1
	ll** a1;
	a1=new ll*[2];
	for(int i=0;i<2;i++){
		a1[i]=new ll[2];
		for(int j=0;j<2;j++){
			a1[i][j]=2;
		}
	}

	// initialise a2
	ll** a2;
	a2=new ll*[2];
	for(int i=0;i<2;i++){
		a2[i]=new ll[2];
		for(int j=0;j<2;j++){
			a2[i][j]=5;
		}
	}

	ll** ans;
	ans=new ll*[2];
	for(int i=0;i<2;i++){
		ans[i]=new ll[2];
	}

	a1[0][0]=0;
	a1[0][1]=1;
	a1[1][0]=1;
	a1[1][1]=1;

	// ans=multiply(a1,a2);
	ans=pow(a1,3);

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}