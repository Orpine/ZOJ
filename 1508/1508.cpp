#include<cstdio>
#include<cstring>
int tot,n,max,min=1<<30,start[50008],next[50008],node[50008],value[50008],
	      dis[50008],q[200008],inq[50008];
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
void add(int a,int b,int v)
{
	node[++tot]=b;
	value[tot]=v;
	next[tot]=start[a];
	start[a]=tot;
}
void Init()
{
	memset(start,0,sizeof(start));tot=0;
	int a,b,v;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&v);
		add(b+1,a,-v);
		max=Max(max,b+1);
		min=Min(min,a);
	}		
	for(int i=1;i<=max;i++){add(i-1,i,1);add(i,i-1,0);}
}
void Work()
{
	memset(dis,1,sizeof(dis));
	int l=0,r=1;
	dis[0]=0;
	q[l++]=0;
	while(l<=r)
	{
		int x=q[l];
		for(int t=start[x];t;t=next[t])
		{
			if(dis[x]+value[t]<dis[node[t]])
			{
				dis[node[t]]=dis[x]+value[t];
				if(!inq[node[t]]){q[++r]=node[t];}
			}
		}
		l++;
	}
	printf("%d\n",dis[max]-dis[min]);
}
int main()
{
	freopen("1508.in","r",stdin);
	freopen("1508.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{	
		Init();
		Work();
	}
	return 0;
}
