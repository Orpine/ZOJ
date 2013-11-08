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
int sa, sb, sc, n;
int ans;
char mmap[100][100];
int dis[100][100][100];
//Program
class P
{
public:
    int a, b, c;
    P(int _a = 0, int _b = 0, int _c = 0):a(_a), b(_b), c(_c){}
};
int BFS()
{
    int a, b, c;
    queue<P> Q;
    Q.push(P(sa, sb, sc));
    dis[sa][sb][sc] = 0;
    while(!Q.empty())
    {
        P x = Q.front();
        Q.pop();
        a = x.a;
        b = x.b;
        c = x.c;
        if(a == b && b == c)
        {
            return dis[a][a][a];
        }
        for(int i = 1; i <= n; i++)
        {
            if(i != a && mmap[a][i] == mmap[b][c] && dis[i][b][c] > dis[a][b][c] + 1)
            {
                dis[i][b][c] = dis[a][b][c] + 1;
                Q.push(P(i, b, c));
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(i != b && mmap[b][i] == mmap[a][c] && dis[a][i][c] > dis[a][b][c] + 1)
            {
                dis[a][i][c] = dis[a][b][c] + 1;
                Q.push(P(a, i, c));
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(i != c && mmap[c][i] == mmap[a][b] && dis[a][b][i] > dis[a][b][c] + 1)
            {
                dis[a][b][i] = dis[a][b][c] + 1;
                Q.push(P(a, b, i));
            }
        }
    }
    return -1;
}
void Work()
{
    char s[10];
    ans = 0;
    scanf("%d%d%d", &sa, &sb, &sc);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%s", s + 1);
            mmap[i][j] = s[1];
        }
    }
    memset(dis, 55, sizeof dis);
    ans = BFS();
    if(ans == -1)
    {
        puts("impossible");
    }
    else
    {
        printf("%d\n", ans);
    }
}
int main()
{
	while(scanf("%d", &n), n != 0)
	{
		Work();
	}
    return 0; 
}
