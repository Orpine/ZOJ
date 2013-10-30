//Lib
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
//Macro
#define rep(i,a,b) for(int i=a,tt=b;i<=tt;++i)
#define rrep(i,a,b) for(int i=a,tt=b;i>=tt;--i)
#define erep(i,e,x) for(int i=x;i;i=e[i].next)
#define irep(i,x) for(__typedef(x.begin()) i=x.begin();i!=x.end();i++)
#define read() (strtol(ipos,&ipos,10))
#define sqr(x) ((x)*(x))
#define pb push_back
#define PS system("pause");
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;
const int oo=~0U>>1;
const double inf=1e20;
const double eps=1e-6;
string name="file",in=".in",out=".out";
//Var
struct T
{
	int x,k;	
}d[1008];
int n,m,y,sum,cas;
priority_queue<pdi> q;
double calc(int i){return (double)d[i].x/y-(double)d[i].k/m;}
void Init()
{
	while(!q.empty())q.pop();
	scanf("%d%d%d",&n,&m,&y);sum=m;
	rep(i,1,n)
	{
		scanf("%d",&d[i].x);
		d[i].k=(int)(m*(double)d[i].x/y);
		sum-=d[i].k;
		q.push(pdi(calc(i),i));
	}
}
void Work()
{
	pdi t;
	while(sum)
	{
		t=q.top();q.pop();
		d[t.second].k++;sum--;q.push(pdi(calc(t.second),t.second));
	}
	rep(i,1,n-1)printf("%d ",d[i].k);
	printf("%d\n",d[n].k);
	puts("");
}
int main()
{
//	freopen((name+in).c_str(),"r",stdin);
//	freopen((name+out).c_str(),"w",stdout);
	scanf("%d",&cas);
	while(cas--)
	{
		Init();
		Work();
	}
//	PS;
	return 0;
}
