#include <stdio.h>

int calc_dist_pow(int ax, int ay, int cx, int cy)
{
	return ((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy));
}

int is_in_circle(int ax, int ay, int cx, int cy, int r)
{
	if (calc_dist_pow(ax, ay, cx, cy) < r * r)
		return (1);
	return (0);
}

int main(void)
{
	int t, start_x, start_y, end_x, end_y;
	int n, c_x, c_y, r, result, tmp1, tmp2;
	
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
		result = 0;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d %d %d", &c_x, &c_y, &r);
			tmp1 = is_in_circle(start_x, start_y, c_x, c_y, r);
			tmp2 = is_in_circle(end_x, end_y, c_x, c_y, r);
			if (tmp1 != tmp2)
				result++;
		}
		printf("%d\n", result);
	}
	return (0);
}