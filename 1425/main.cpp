#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;
int T, n, m, ans, dis, mark;
bool belong[1008];
int a[1008], b[1008], f[1008][1008];
void Init()
{
	memset(f, 0, sizeof f);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
}
void Work()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			for (int k = 1; k <= i; k++)
				for (int l = 1; l <= j; l++)
					if (a[k] == b[j] && a[i] == b[l] && a[i] != a[k])
						f[i][j] = max(f[i][j], f[k - 1][l - 1] + 2);
		}			
	}
	printf("%d\n", f[n][m]);
} 
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		Init();
		Work();
	}
	return 0;
}
