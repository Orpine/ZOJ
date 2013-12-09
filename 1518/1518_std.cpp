#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 1010;
int parent[maxn],t[maxn],f[maxn];
bool status[maxn];//status[k]表示子节点与双亲节点状态是否相同，1表示相同，0表示不同
int find(int k)
{
    if(parent[k]<0)
        return k;
    int t = find(parent[k]);
    status[k]=status[k]?status[parent[k]]:!status[parent[k]];//根据双亲节点状态，更改子节点状态
    parent[k]=t;
    return t;
}
bool merge(int a,int b,bool isT)//isT表示两个句子之间是说真，还是假
{
    int l = find(a);
    int r = find(b);
    if(l==r)
    {
        if(status[a]==status[b])//如果a,b的状态相同，则根据isT来判断是否相悖，如果a说b假，那就相悖
            return isT;
        else//如果a,b的状态不同，如果a说b真，那就相悖
            return !isT;
    }
    if(status[a]==status[b])//根据a,b的状态是否相同和a与b之间的真假声明，来改变l集合根节点的状态
        status[l]=isT;
    else
        status[l]=!isT;
    parent[l]=r;
    return true;
}
int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.ans", "w", stdout);
    int n;
    int i,j,r;
    char str[10];
    while(scanf("%d",&n)&&n!=0)
    {
        memset(status,1,n+1);//使根节点状态为1
        memset(parent,-1,sizeof(int)*(n+1));
        bool flag = true;
        for(i=1; i<=n; i++)
        {
            getchar();
            scanf("Sentence %d is %s",&j,str);
            if(flag&&str[0]=='t')
                flag=merge(i,j,1);//表示i说j为真
            if(flag&&str[0]=='f')
                flag=merge(i,j,0); //表示i说j为假
        }
        if(!flag)
            printf("Inconsistent\n");
        else
        {
            int ans=0;
            memset(t,0,sizeof(int)*(n+1));
            memset(f,0,sizeof(int)*(n+1));
            for(int k=1; k<=n; k++)//找出各个节点的根节点来代表该集合，并统计1的个数和0的个数
            {
                r = find(k);
                if(status[k])
                    t[r]++;
                else
                    f[r]++;
            }
            for(int k=1; k<=n; k++)//将各集合的max(1的个数，0的个数）加起来
                ans+=max(t[k],f[k]);
            printf("%d\n",ans);
        }
    }
}
