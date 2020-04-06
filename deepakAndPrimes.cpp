#include<bits/stdc++.h>
#define int long long
using namespace std;

bitset<100000000> prime;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

void makeSieve() {

	// int count = 1;
	for (int i = 3; i < 100000000; i += 2) {
		prime.set(i);
	}

	for (int i = 3; i * i < 100000000; i += 2) {
		if (prime[i]) {
			for (int j = i * i; j < 100000000; j += i) {
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
	int count = 0;
	int i;
	for (i = 2; i <= 100000000; i++) {
		if (prime[i])
			count++;

		if (count == n)
			break;
	}

	cout << i << endl;

	return 0;
}