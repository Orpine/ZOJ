#  include<cstdio>
#  include<cstring>
#  include<cstdlib>
struct arr
{
       int  l,r,f,v,d;             
}a[100008];
int n,qa[100008],qb[100008],m;
int  Find(int i)  
{
     if  (a[i].f!=i)  a[i].f=Find(a[i].f);
     return a[i].f;     
}
void  Init()
{
      for  (int i=1;i<=n;i++)  
      {
           scanf("%d",&a[i].v);
           a[i].f=i;a[i].l=0;a[i].r=0;a[i].d=0;
      }
      scanf("%d",&m);
      for  (int i=1;i<=m;i++)  scanf("%d%d",&qa[i],&qb[i]);
}
int  Merge(int t1,int t2)
{
     if  (!t1||!t2) return t1+t2;
     int i,t;
     if (a[t1].v<a[t2].v) {i=t1;t1=t2;t2=i;}
     t=Merge(a[t1].r,t2);
     if  (a[t].d>a[a[t1].l].d) {i=t;t=a[t1].l;a[t1].l=i;}
     a[t1].r=t;
     a[t1].d=a[t].d+1;
     return t1;
}
int  Delete(int k)
{
     a[k].v/=2;
     int l=a[k].l,r=a[k].r,t;
     a[k].l=0;a[k].r=0;
     t=Merge(l,k);t=Merge(t,r);
     a[k].f=t;
}
void  Work()
{
      int i,root,f1,f2,t1,t2;
      for (i=1;i<=m;i++)
      {
          f1=Find(qa[i]);f2=Find(qb[i]);
          if  (f1!=f2)
          {
              t1=Delete(f1);t2=Delete(f2);
              root=Merge(t1,t2);
              a[t1].f=root;a[t2].f=root;
              printf("%d\n",a[root].v);
          }
          else  printf("%d\n",-1);
      }     
}
int  main()
{
	freopen("2334.in","r",stdin);
	freopen("2334.out","w",stdout);
     a[0].d=-1;
     while (scanf("%d",&n)!=EOF)
     {
           Init();
           Work();
     }     
     return 0;     
}
