#include<cstdio>
#include<cstring>
struct arr
{
	int a,b,v;
}edge[1000008];
int start[1000008],next[1000008],node[1000008],value[1000008],dist[1000008],queue[5000008],inq[1000008];
int p,q,n,tot;
void add(int a,int b,int v)
{
	node[++tot]=b;
	next[tot]=start[a];
	start[a]=tot;
	value[tot]=v;
}
void Init()
{
	memset(start,0,sizeof(start));tot=0;
	scanf("%d%d",&p,&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].v);
		add(edge[i].a,edge[i].b,edge[i].v);
	}
}
int Work()
{
	memset(dist,1,sizeof(dist));
	int l=0,r=1,ans=0;
	queue[++l]=1;
	dist[1]=0;
	while(l<=r)
	{
		int x=queue[l];
		for(int t=start[x];t;t=next[t])
		{
			if(dist[x]+value[t]<dist[node[t]])
			{
				dist[node[t]]=dist[x]+value[t];
				if(!inq[node[t]]) queue[++r]=node[t];
			}
		}
		++l;
	}
	for(int i=1;i<=p;i++)
		ans+=dist[i];
	return ans;
}
void Change()
{
	memset(start,0,sizeof(start));tot=0;
	for(int i=1;i<=q;i++)
		add(edge[i].b,edge[i].a,edge[i].v);
}
int main()
{
	freopen("2008.in","r",stdin);
	freopen("2008.out","w",stdout);
	for(scanf("%d",&n);n;n--)
	{
		Init();
		int ans=Work();
		Change();
		printf("%d\n",ans+Work());
	}
	return 0;
}
