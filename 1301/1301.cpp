#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
using namespace std;
struct S
{
	int light,
		pre,// pos pre action in queue
		act,// 0 present move 1 present on 2 present off
		pos;
	bool operator <(const S &o)const
	{
		return pos < o.pos || (pos == o.pos && light < o.light);
	}
}queue[100000], x, y;
map<S,bool> hashmap;
int n, s, d, ans;
bool mmap[20][20], smap[20][20];
void Init()
{
	memset(mmap, 0, sizeof mmap);
	memset(smap, 0, sizeof smap);
	int a, b;
	for (int i = 1; i <= d; ++i)
	{
		scanf("%d%d", &a, &b);
		mmap[a][b] = mmap[b][a] = true;
	}
	for (int i = 1; i <= s; i++)
	{
		scanf("%d%d", &a, &b);
		smap[a][b] = true;
	}
}
int BFS(int st)
{
	hashmap.clear();
	queue[1].light = 1;
	queue[1].pre = 0;
	queue[1].pos = 1;
	int l = 1, r = 1;
	while (l <= r)
	{
		x = queue[l];
		if (x.pos == n && x.light == (1 << (n - 1)))
		{
			return l;
		}
		//move
		for (int i = 1; i <= n; i++)
			if(mmap[x.pos][i] && (x.light & (1 << (i - 1))))
			{
				y = x;
				y.pos = i;
				y.pre = l;
				y.act = 0;
				if(hashmap.find(y) == hashmap.end())
				{
					hashmap[y] = true;
					queue[++r] = y;
				}
			}
		//on
		for (int i = 1; i <= n; i++)
			if(i != x.pos && smap[x.pos][i] && (x.light & (1 << (i - 1))) == 0)
			{
				y = x;
				y.pre = l;
				y.act = i;
				y.light = x.light | (1 << (i - 1));
				if(hashmap.find(y) == hashmap.end())
				{
					hashmap[y] = true;
					queue[++r] = y;
				}
			}
		//off
		for (int i = 1; i <= n; i++)
			if(i != x.pos && smap[x.pos][i] && (x.light & (1 << (i - 1))))
			{
				y = x;
				y.pre = l;
				y.act = -i;
				y.light = x.light ^ (1 << (i - 1));
				if(hashmap.find(y) == hashmap.end())
				{
					hashmap[y] = true;
					queue[++r] = y;
				}
			}
		l++;
	}
	return -1;
}
void Print(int x, int st)
{
	if (queue[x].pre != 0)
	{
		Print(queue[x].pre, st + 1);
	}
	else
	{
		printf("The problem can be solved in %d steps:\n", st);
	}
	if(queue[x].pre != 0)
	{
		if (queue[x].act == 0)
		{
			printf("- Move to room %d.\n", queue[x].pos);
		}
		else if (queue[x].act > 0)
		{
			printf("- Switch on light in room %d.\n", queue[x].act);
		}
		else
		{
			printf("- Switch off light in room %d.\n", -queue[x].act);
		}
	}
}
void Work()
{
	ans = BFS(1);
	if(ans == -1)
	{
		printf("The problem cannot be solved.\n");
	}
	else
	{
		Print(ans, 0);
	}
}
int main()
{
	for(int T = 1;;T++)
	{
		scanf("%d%d%d", &n, &d, &s);
		if (n == 0 && d == 0 && s == 0)
		{
			break;
		}
		printf("Villa #%d\n", T);
		Init();
		Work();
		puts("");
	}
}