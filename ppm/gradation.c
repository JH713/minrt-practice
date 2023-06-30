#include <stdio.h>

int main(void)
{
	int w = 256;
	int h = 256;

	printf("P3\n%d %d\n255\n", w, h);
	int i, j;
	double r, g, b;
	j = h - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < w)
		{
			r = (double) i / (w - 1);
			g = (double) j / (h - 1);
			b = 0.25;
			printf("%d %d %d\n", (int) (255.999 * r), (int) (255.999 * g), (int) (255.999 * b));
			++i;
		}
		--j;
	}
	return (0);
}