#include<bits/stdc++.h>
#define int long long
using namespace std;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

string stringMultiply(string a, int n) {
	string res = "";
	int carry = 0;
	int len = a.length();
	for (int i = 0; i < len; i++) {

		int product;
		int number = a[len - i - 1] - '0';
		product = number * n + carry;
		carry = product / 10;
		product = product % 10;
		res += (char(product) + '0');
	}

	while (carry > 0) {
		int lastDigit = carry % 10;
		carry /= 10;
		res += ((char)lastDigit + '0');
	}
	// cout << "before reversing: " << res << endl;
	// reverse the string
	int resLen = res.length();
	for (int i = 0; i < (resLen / 2); i++) {
		swap(res[i], res[resLen - i - 1]);
	}
	// cout << "after reversing: " << res << endl;

	return res;
}

int32_t main() {

	fastIO();

	int n;
	cin >> n;
	string ans = "1";
	for (int i = 2; i <= n; i++) {
		ans = stringMultiply(ans, i);
	}

	cout << ans << endl;

	return 0;
}