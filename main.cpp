#include <bits/stdc++.h>
using namespace std;

FILE* f;
const int n = 100000000;
int* a, * tmp;

inline int read() {
	register char t = 0;
	register int x = 0, y = 1;
	do {
		t = getc(f);
		if (t == 45) y = -1;
	} while (t < 48 || t>57);
	do {
		x = (x << 3) + (x << 1) + t - 48;
		t = getc(f);
	} while (t >= 48 && t <= 57);
	return x * y;
}

inline long long calc10(int x) {
	if (x == 0) return 1;
	if (x == 1) return 10;
	register long long ans[12] = { 1,10 };
	for (register int i = 2; i <= x; i++) {
		ans[i] = ans[i >> 1];
		ans[i] *= ans[i];
		if (i & 1) ans[i] = (ans[i] << 3) + (ans[i] << 1);
	}
	return ans[x];
}

int main() {
	register char* file_path = new char[1000];
	cin.getline(file_path, 1000);
	f = fopen(file_path, "r");
	delete[]file_path;
	a = new int[n + 1];
	tmp = new int[n + 1];
	for (register int i = 1; i <= n; i++) *(a + i) = read();
	fclose(f);
	for (register int i = 0; i < 10; i++) {
		register long long r = calc10(i);
		register int cnt[10] = { 0 };
		memset(tmp, 0, sizeof(tmp));
		for (register int j = 1; j <= n; j++) cnt[(a[j] / r) % 10]++;
		for (register int j = 1; j < 10; j++) cnt[j] += cnt[j - 1];
		for (register int j = n; j >= 1; j--) tmp[cnt[(a[j] / r) % 10]--] = a[j];
		for (register int j = 1; j <= n; j++) a[j] = tmp[j];
	}
	delete[]tmp;
	ofstream fout("sort.txt");
	for (register int i = 1; i <= n; i++) fout << a[i] << endl;
	delete[]a;
	return 0;
}