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
int n, sx, sy;
double rad;
class P
{
public:
	int x, y;
	P(int _x = 0, int _y = 0):x(_x), y(_y){}
	void init()
	{
		scanf("%d%d", &x, &y);
	}
	int operator %(const P &o)const
	{
		return x * o.y - y * o.x;
	}
	P operator -(const P &o)const
	{
		return P(x - o.x, y - o.y);
	}
};
P p[208];
//Program
double Dis(const P &a, const P &b)
{
	int x = a.x - b.x;
	int y = a.y - b.y;
	return sqrt(sqr(x) + sqr(y));
}
void Work()
{
	int ans = 0, cnt;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		p[i].init();
	}
	for(int i = 1; i <= n; i++)
	{
		cnt = 0;
		for(int j = 1; j <= n; j++)
		{
			if((p[i] - p[0]) % (p[j] - p[0]) >= 0)
			{
				if(Dis(p[j], p[0]) <= rad)
				{
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans);
}
int main()
{
	while(scanf("%d%d%lf", &sx, &sy, &rad), rad > 0)
	{
		p[0].x = sx;
		p[0].y = sy;
		Work();
	}
    return 0; 
}
