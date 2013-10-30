#include<cstdio>
void Init()
{
	memset(h,0,n*4+4);tot=0;
	memset(lable,0,n*4+4);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
}
void Work()
{
	lable[0]=-1;
	for(int i=1;i<=n;i++)
	{
		flag=0;
		for(int j=1;j<=n;j++)
			if(lable[j]>lable[flag]&&!vis[j])flag=j;
		ord[i]=flag;
		for(int j=h[flag];j;j=next[j])lable[node[j]]++;
	}
}
void Judge()
{
	for(int i=1;i<=n;i++)
	{
		x=ord[i]
	}
}
int main()
{
	for(scanf("%d%d",&n,&m)!=EOF&&(n&&m))
	{
		Init();
		Work();
		Judge();
	}
	return 0;
}
