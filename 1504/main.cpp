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
typedef pair<double,double> pdd;
#define sqr(x) ((x) * (x))
const double eps = 1e-6;
int n, cnt;
double x, y;
char s[100];
vector<pdd> v[40];
double Dis(pdd a, pdd b)
{
	return sqrt(sqr(a.first - b.first) + sqr(a.second - b.second));
}
bool Judge(pdd a, pdd b, pdd c)
{
	return fabs(Dis(a, b) - Dis(a, c)) < eps && fabs(Dis(b, c) - Dis(a, c)) < eps;
}
int main()
{
	while(scanf("%d", &n),n!=0)
	{
		for (int i = 0; i < 30; i++) v[i].clear();
		scanf("%s", s + 1);
		cnt = 0; y = sqrt(3.0);
		for (int i = 1; i <= n; i++)
		{
			x = -i + 1;
			y -= sqrt(3.0);
			for (int j = 1; j <= i; j++)
			{
				v[s[++cnt] - 'a'].push_back(pair<double,double>(x,y));
				x += 2;
			}
		}
		bool flag = false;
		for (int i = 0; i < 26; i++)
		{
			if (v[i].size() == 3 && Judge(v[i][0],v[i][1],v[i][2]))
			{
				printf("%c", i + 'a');
				flag = true;
			}
		}
		if (!flag) puts("LOOOOOOOOSER!");
		else puts("");
	}
	return 0;
} 
