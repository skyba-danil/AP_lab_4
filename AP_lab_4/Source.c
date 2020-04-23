#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 64
#define SWAP(a,b) if ((a)!=(b)) {a^=b; b^=a; a^=b;}


int KilkistN();
int Kilkist1();
void StworMas(int, int, char[]);
void move(char*, int, int);

int main()
{
	system("chcp 1251");

	char mas[MAXN];
	int n = KilkistN();
	int k = Kilkist1();
	StworMas(n, k, mas);
	move(mas, 0, n);
}

int KilkistN()
{
	int n;
	printf("Print N: ");
	scanf_s("%i", &n);
	return n;
}

int Kilkist1()
{
	int k;
	printf("Print K: ");
	scanf_s("%i", &k);
	return k;
}

void StworMas(int n, int k, char mas[])
{
	int i = 0;
	while (i < n)
	{
		while (i < k)
		{
			mas[i] = '1';
			i++;
		}
		if (k == n) break;
		mas[i] = '0';
		i++;
	}
	mas[i] = '\0';
}

void move(char* a, int n, int size)
{
	static int count = 0;

	if (n == size - 1)
		printf("%d:\t%s\n", ++count, a);
	else
		for (int i = n; i < size; i++)
		{
			for (int j = n; j < i; j++)
				if (a[j] == a[i]) goto next;
			SWAP(a[i], a[n]);
			move(a, n + 1, size);
			SWAP(a[i], a[n]);
		next:;
		}
}