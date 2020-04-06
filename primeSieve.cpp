#include<bits/stdc++.h>
#define int long long int
using namespace std;

bitset<1000005> prime;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

}

void makeSieve() {


	for (int i = 3; i < 1000005; i += 2) {
		prime.set(i);
	}

	for (int i = 3; i * i < 1000005; i += 2) {
		if (prime[i]) {
			for (int j = i * i; j < 1000005; j += i) {
				prime.reset(j);
			}
		}
	}

	prime.set(2);

}


int32_t main() {

	fastIO();

	makeSieve();

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			cout << i << " ";
		}
	}
	cout << "\n";


	return 0;
}