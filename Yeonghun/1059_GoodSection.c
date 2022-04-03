#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	int answer = 0;
	int n;
	int range_min=10000, range_max=10000;
	scanf("%d", &num);	//입력된 집합S의 개수

	int* S = (int*)malloc(sizeof(int) * num);
	int* sorted_S = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &S[i]);
	}

	scanf("%d", &n);

	for (int i = 0; i < num; i++) {
		int min = 1001;
		int index_min;
		for (int j = 0; j < num; j++) {
			if (min > S[j]) {
				index_min = j;
				min = S[j];
			}
		}
		sorted_S[i] = min;
		S[index_min] = 1001;
	}

	if (sorted_S[0] > n) {
		range_min = 1;
		range_max = sorted_S[0] - 1;
	}
	else if (sorted_S[num-1] < n) {
		range_min = sorted_S[num - 1]+1;
		range_max = 1000;
	}
	else {
		for (int i = 0; i < num - 1; i++) {
			if (sorted_S[i] < n && n < sorted_S[i + 1]) {
				range_min = sorted_S[i] + 1;
				range_max = sorted_S[i + 1] - 1;
				break;
			}
		}
	}

	for (int i = range_min; i <= n; i++) {
		answer = answer + (range_max - i)-(n-i-1);
		if (i == n) answer -= 1;
	}
	
	printf("%d\n", answer);

	return 0;
}
