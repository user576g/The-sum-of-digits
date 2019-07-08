#include <iostream>
using std::cin;
using std::cout;

const int n = 15;

typedef  unsigned long long unll;

inline void setArValue(unsigned char* ar, unsigned long long val) {
	unsigned long long d = val;
	int i = 0;
	for (; d != 0; ++i) {
		ar[n - 1 - i] = d % 10;
		d /= 10;
	}
	for (; i < n; ++i)
		ar[n - 1 - i] = 0;
}

int main() {
	unll A, B;
	cin >> A >> B;
	unsigned char arCount[n];
	unsigned char arB[n];
	setArValue(arCount, A);
	setArValue(arB, B);

	int countB = n;
	while (arB[n - countB] == 0 && countB > 0)
		--countB;
	unsigned long long i, sum = 0;
	for (i = A; i <= B; ++i) {
		for (int j = n - 1; j >= (n - countB); --j) {
			sum += arCount[j];
		}
		for (int j = n - 1; j >= (n - countB); --j) {
			if (arCount[j] < 9) {
				++arCount[j];
				break;
			}
			else
				arCount[j] = 0;
		}
	}
	cout << sum;
}
