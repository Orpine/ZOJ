//Header
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>

using namespace std;

//Macro
#define rep(i, a, b) for (size_t i = a; i <= b; ++i)
#define drep(i, a, b) for (size_t i = a; i >= b; --i)
#define irep(i, e, x) for (size_t i = x; i; i = e[i].next)
#define sqr(x) ((x) * (x))

typedef long long ll;
const int oo = ~0u>>2;
const double inf = 1e300;
const double eps = 1e-6;

//Variable
int n, m;
ll f[2][2088];
int a[20], b[20];
//Program
bool Judge(int x, int y)
{
	for(int i = 0; i < n; i++)
	{
		a[i] = (x & (1 << i)) >> i;
		b[i] = (y & (1 << i)) >> i;
	}
	for(int i = 0; i < n; i++)
	{
		if(a[i] == 0)
		{
			if(b[i] == 0)
				return false;
		}
		else
		{
			if(b[i] == 1)
			{
				if(i == n - 1)
					return false;
				else if(a[i + 1] == 1 && b[i + 1] == 1)
					i++;
				else
					return false;
			}
		}
	}
	return true;
}
void Work()
{
	memset(f, 0, sizeof f);
	if(n < m)
		swap(n, m);
	int flag = 0;
	f[0][(1 << n) - 1] = 1;
	for(int cnt = 1; cnt <= m; cnt++)
	{
		for(int i = 0; i < 1 << n; i++)
			if(f[flag][i] != 0)
			{
				for(int j = 0; j < 1 << n; j++)
				{
					if(Judge(i, j))
						f[flag ^ 1][j] += f[flag][i];
				}
			}
		memset(f[flag], 0, sizeof f[flag]);
		flag ^= 1;
	}
	printf("%lld\n", f[flag][(1 << n) - 1]);
}
int main()
{
	while(scanf("%d%d", &m, &n), m != 0 && n != 0)
	{
		if(m * n % 2 == 1)
			printf("0\n");
		else 
			Work();
	}
    return 0; 
}
