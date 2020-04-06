#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define w(t) int t;cin>>t;while(t--)
#define fo(a,b) for(int i=a;i<b;i++)
using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}
int maxSize = 1000000;
bitset<1000005> prime;

void makeSieve() {


	for (int i = 3; i <= maxSize; i += 2) {
		prime.set(i);
	}

	for (int i = 3; i * i <= maxSize; i += 2) {
		if (prime[i]) {
			for (int j = i * i; j <= maxSize; j += i) {
				prime.reset(j);
			}
		}
	}

	prime.set(2);

}

unordered_map<int, int> noOfFactors;
void addFactors(int data) {

	if (prime[data]) {
		if (noOfFactors.count(data)) {
			noOfFactors[data]++;
		}
		else
			noOfFactors[data] = 1;
	}
	else {
		while (data > 1) {
			for (int i = 2; i * i <= data; i++) {
				if (prime[i]) {
					while (data % i == 0) {
						// cout << i << " ";
						if (noOfFactors.count(i))
							noOfFactors[i]++;
						else
							noOfFactors[i] = 1;

						data = data / i;
					}
				}
			}
			if (prime[data]) {
				if (noOfFactors.count(data)) {
					noOfFactors[data]++;
				}
				else {
					noOfFactors[data] = 1;
				}
				data = 1;
			}
		}
	}

}

int32_t main() {

	fastIO();

	makeSieve();

	w(t) {
		noOfFactors.clear();
		int n;
		cin >> n;
		fo(0, n) {

			int data;
			cin >> data;

			addFactors(data);
		}
		int ans = 1;
		for (auto it : noOfFactors) {
			ans *= (it.second + 1);
			ans = ans % mod;
		}
		cout << ans << endl;
	}

	return 0;
}