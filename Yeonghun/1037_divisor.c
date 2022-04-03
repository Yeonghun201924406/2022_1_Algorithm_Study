#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long gcd(long long a, long long b) {
	long long tmp, n;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main() {
	int num;
	long long answer = 1;
	long long int min_dec = INT_MAX;

	scanf("%d", &num);

	long long* arr_num = (long long*)malloc(sizeof(long long) * num);
	for (int i = 0; i < num; i++) {
		scanf("%llu", &arr_num[i]);
	}

	answer = arr_num[0];
	for (int i = 1; i < num; i++) {
		long long tmp_gcd = gcd(answer, arr_num[i]);
		answer = answer * arr_num[i] / tmp_gcd;
	}

	for (int i = 0; i < num; i++) {
		if (min_dec > arr_num[i]) min_dec = arr_num[i];
	}


	for (int i = 0; i < num; i++) {
		if (answer == arr_num[i]) {
			answer *= min_dec;
			break;
		}
	}
	printf("%llu\n", answer);

	return 0;

}
