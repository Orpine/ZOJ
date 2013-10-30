#include<cstdio>
#include<cstring>
struct st
{
	int lc,rc,key,dist,fa;
}tree[100008];
int n,m;
int getf(int x)
{
	if(tree[x].fa!=x) tree[x].fa=getf(tree[x].fa);
	return tree[x].fa;
}
int gd(int a){return tree[a].dist;}
int merge(int a,int b)
{
	if(!a||!b)return a+b;
	if(tree[a].key<tree[b].key)	{a^=b;b^=a;a^=b;};
	tree[a].rc=merge(tree[a].rc,b);
	if(gd(tree[a].rc)>gd(tree[a].lc))
		{tree[a].lc^=tree[a].rc;tree[a].rc^=tree[a].lc;tree[a].lc^=tree[a].rc;};
	tree[a].dist=gd(tree[a].rc)+1;
	return a;
}
int Delete(int x)
{
	tree[x].key/=2;
	int l=tree[x].lc,r=tree[x].rc;
	tree[x].lc=0;tree[x].rc=0;
	int t=merge(l,x);t=merge(t,r);
	tree[x].fa=t;
	return t;
}
int process(int a,int b)
{
	a=getf(a);b=getf(b);
	if(a==b)return -1;
	int t1=Delete(a),t2=Delete(b);
	int t=merge(t1,t2);
	tree[t1].fa=t;	tree[t2].fa=t;
	return tree[t].key;
}
int Init()
{
	memset(tree,0,sizeof(tree));
	tree[0].dist=-1;
	if(scanf("%d",&n)==EOF)return 0;
	for(int i=1;i<=n;i++){scanf("%d",&tree[i].key);tree[i].dist=0;tree[i].fa=i;}
}
void Work()
{
	int a,b;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",process(a,b));
	}
}
int main()
{
	freopen("2334.in","r",stdin);
	freopen("2334.out","w",stdout);
	while(Init())
		Work();	
	return 0;
}
