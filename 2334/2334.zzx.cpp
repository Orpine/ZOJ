#include <cstdio>
#include <cstring>
#include <cstdlib>

int n,m;
int fa[100005],dist[100005],key[100005],lc[100005],rc[100005];

void Init()
{
     int i,j;
     for (i=1;i<=n;i++)
     {
         scanf("%d",key+i);
         fa[i]=i;
         lc[i]=rc[i]=dist[i]=0;
     }
}

int find(int x)
{
    if (x==fa[x]) return x;
    else return find(fa[x]);
}

int Merge(int a,int b)  //合并根为a和b的两棵二叉树，返回合并后的根节点 
{
    if (!a||!b) return a+b;
    int y;
    if (key[b]>key[a]) {y=a;a=b;b=y;}
    rc[a]=Merge(rc[a],b);
    if (dist[rc[a]]>dist[lc[a]])
       {y=rc[a];rc[a]=lc[a];lc[a]=y;}
    dist[a]=dist[rc[a]]+1;
    return a;
}

void Work()
{
     int x,y,fx,fy,p,t;
     scanf("%d%d",&x,&y);
     fx=find(x);
     fy=find(y);
     if (fx!=fy)
     {
        if (key[fx]>key[fy]) p=fx;else p=fy;
        printf("%d\n",key[p]/2);
        key[p]/=2;
        fa[lc[p]]=fa[rc[p]]=t=Merge(lc[p],rc[p]);
        lc[p]=rc[p]=0;
        fa[p]=fa[t]=t=Merge(t,p);
        fa[t]=fa[fx+fy-p]=Merge(t,fx+fy-p);
     }
     else printf("-1\n");
}

int main()
{
    dist[0]=-1;
    while (scanf("%d",&n)!=EOF)
    {
          Init();
          for (scanf("%d",&m);m;m--)
              Work();
    }
    return 0;
}
/*
左偏树的应用。
可以合并两个堆。
注意fa的维护。（很多情况下，左偏树要与并查集联用） 
*/ 
