#include <stdio.h>
#pragma warning(disable:4996)

void prob8()
{
	/*
	Tipareste exponentul la care numarul prim p apare in descompunerea
    in factori primi a numarului N = 1*2*...*n (n natural nenul dat).
	*/
	int n, p, d, ex = 0, sem = 0, aux;
	printf("Introduceti numarul n: ");
	scanf("%d", &n);
	printf("Introduceti numarul prim p: ");
	scanf("%d", &p);
	aux = n;
	for (d = 2;d <= n / 2 && sem == 0;d = d + 1)
	{
		ex = 0;
		if (aux % d == 0)
		{
			while (aux % d == 0)
			{
				aux = aux / d;
				ex = ex + 1;
			}
			if (d == p)
				sem = 1;
		}
	}
	if (sem == 1)
		printf("Exponentul lui p: %d\n", ex);
	else printf("Exponentul lui p: 0\n");
}

void prob6()
{
	/*
	Tiparste triunghiul lui Pascal, cu toate combinarile C(m,k) de m obiecte
	luate cite k, k = 0, 1, ..., m, in linia m, pentru m = 1, 2, ..., n.
	*/
	int n, i, j, in, jn, x, ijn, c;
	printf("Introduceti un numar n: ");
	scanf("%d", &n);
	printf("1");
	for (i = 1; i <= n; i++)
	{
		printf("\n");
		for (j = 0; j <= i; j++)
		{
			in = 1;
			x = 1;
			while (x <= i)
			{
				in = in * x;
				x++;
			}
			jn = 1;
			x = 1;
			while (x <= j)
			{
				jn = jn * x;
				x++;
			}
			ijn = 1;
			x = 1;
			while (x <= i - j)
			{
				ijn = ijn * x;
				x++;
			}
			c = in / (jn * ijn);
			printf("%d ", c);
		}

	}
	printf("\n");
}
int main()
{	
	int cmd;
	while (1)
	{
		printf("Selectati o optiune: 0, 1, 2\n");
		scanf("%d", &cmd);
		while ((getchar()) != '\n')
			continue;
		if (cmd == 0)
			return 0;
		if (cmd == 1)
			prob8();
		if (cmd == 2)
			prob6();
	}
}