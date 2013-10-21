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
class D
{
public:
	int x,y;
	void init(){scanf("%d%d", &x, &y);}
	bool operator ==(const D &o)const
	{
		return x == o.x && y == o.y;
	}
	bool operator <(const D &o)const
	{
		return x < o.x || x == o.x && y < o.y;
	}
}judge[5];
class S
{
public:
	D l,r;
}seg;
int n, T;
vector<S> vert, hori;
bool ok[1000][1000];
void Init()
{
	vert.clear();
	hori.clear();
	memset(ok, 0, sizeof ok);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		seg.l.init();
		seg.r.init();
		if (seg.r < seg.l)
			swap(seg.l, seg.r);
		if (seg.l.x == seg.r.x)
			vert.push_back(seg);
		else
			hori.push_back(seg);
	}
}
void Work()
{
	int ans = 0,n = vert.size(), m = hori.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (vert[i].l.x >= hori[j].l.x && vert[i].l.x <= hori[j].r.x && vert[i].l.y <= hori[j].l.y && vert[i].r.y >= hori[j].l.y)
				ok[i][j] = true; 
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
		{
			int cnt = 0;
			for (int k = 0; k < m; k++)
				if (ok[i][k] && ok[j][k]) 
					cnt++;
			ans += cnt * (cnt - 1) / 2;
		}
	printf("%d\n",ans);
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
