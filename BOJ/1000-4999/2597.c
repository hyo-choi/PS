#include <stdio.h>

int main(void)
{
	double rl, rr, bl, br, yl, yr;
	double result, fold_len;

	scanf("%lf", &result);
	scanf("%lf %lf %lf %lf %lf %lf", &rl, &rr, &bl, &br, &yl, &yr);
	fold_len = rl == rr ? 0 : (rl + rr) / 2;
	result = fold_len > result - fold_len ? fold_len : result - fold_len;
	bl += (bl < fold_len ? fold_len - bl : 0) * 2 - fold_len;
	br += (br < fold_len ? fold_len - br : 0) * 2 - fold_len;
	yl += (yl < fold_len ? fold_len - yl : 0) * 2 - fold_len;
	yr += (yr < fold_len ? fold_len - yr : 0) * 2 - fold_len;
	fold_len = bl == br ? 0 : (bl + br) / 2;
	result = fold_len > result - fold_len ? fold_len : result - fold_len;
	yl += (yl < fold_len ? fold_len - yl : 0) * 2 - fold_len;
	yr += (yr < fold_len ? fold_len - yr : 0) * 2 - fold_len;
	fold_len = yl == yr ? 0 : (yl + yr) / 2;
	result = fold_len > result - fold_len ? fold_len : result - fold_len;
	printf("%.1lf\n", result);
	return (0);
}