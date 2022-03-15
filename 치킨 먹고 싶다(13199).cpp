#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int T, P, M, F, C;
int sang, du, coupon;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &P, &M, &F, &C);
		coupon = (M / P) * C;
		du = coupon / F;
		if (coupon >= F) sang = (coupon - F) / (F - C) + 1;
		printf("%d\n", sang - du);
	}
}