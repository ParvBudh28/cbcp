#include<iostream>
using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

void revereString(string &a) {
	// reverse the string
	int aLen = a.length();
	for (int i = 0; i < (aLen / 2); i++) {
		swap(a[i], a[aLen - i - 1]);
	}
}

int main() {

	fastIO();

	int n;
	cin >> n;
	string ans = "";
	while (n > 0) {
		int digit = n % 10;
		n /= 10;
		ans += ((char)digit + '0');
	}
	revereString(ans);
	cout << ans << endl;

	return 0;
}