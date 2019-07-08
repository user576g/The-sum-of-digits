#include <iostream>
using std::cin;
using std::cout;

typedef unsigned long long unll;
const int n = 15;

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
	unsigned long long A, B;
	cout << "\n\nInput first number of range: ";
	cin >> A;
	cout << "Input last number of range: ";
	cin >> B;
	if (A > B){
		cout << "Last number can`t be less than first\n\n";
		return 0;
	}

	unsigned char arCount[n];
	unsigned char arB[n];

	setArValue(arCount, A);
	setArValue(arB, B);

	int countB = n;
	while (arB[n - countB] == 0 && countB > 0)
		--countB;
	unsigned long long sum = 0;
	unsigned long long decSum[n];
	decSum[n - 1] = 0; unll degree = 1;
	for (int j = n - 1; j > (n - countB); --j) {
		decSum[j - 1] = 0;
		for (int k = 0; k <= 9; ++k) {
			decSum[j - 1] += k * degree + decSum[j];
		}
		if (arCount[n - countB] < arB[n - countB])
			while (arCount[j] != 0) {
				int before = 0;
				for (int k = (n - countB); k <= j; ++k) {
					before += arCount[k];
				}
				sum += before * degree + decSum[j];
				for (int k = j; k >= (n - countB); --k)
					if (arCount[k] < 9) {
						++arCount[k];
						break;
					}
					else
						arCount[k] = 0;
			}
		degree *= 10;
	}

	for (int j = n - countB; j < n; ++j) {
		if (arCount[j] == arB[j]) {
			degree /= 10;
			continue;
		}

		bool isZeros = true;
		for (int k = n - 1; k > j; --k)
			if (arCount[k] != 0) {
				isZeros = false;
				break;
			}

		if (!isZeros) {
			unll tDegree = 1;
			for (int k = n - 1; k > j; --k) {
				while (arCount[k] != 0) {
					int before = 0;
					for (int d = (n - countB); d <= k; ++d) {
						before += arCount[d];
					}
					sum += before * tDegree + decSum[k];
					for (int d = k; d >= (n - countB); --d)
						if (arCount[d] < 9) {
							++arCount[d];
							break;
						}
						else
							arCount[d] = 0;
				}
				tDegree *= 10;
			}
		}

		while (arCount[j] < arB[j]) {
			int before = 0;
			for (int k = (n - countB); k <= j; ++k) {
				before += arCount[k];
			}
			sum += before * degree + decSum[j];

			for (int k = j; k >= (n - countB); --k)
				if (arCount[k] < 9) {
					++arCount[k];
					break;
				}
				else
					arCount[k] = 0;
		}
		degree /= 10;
	}
	for (int k = (n - countB); k < n; ++k)
		sum += arCount[k];
	cout << "The sum of digits of all numbers in range: " << sum << "\n\n";

    	cout << "Press any number and Enter to continue...";
	char s[201];
    	cin >> s;
    	cout << "\n\n";
}
