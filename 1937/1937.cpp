#include<cstdio>
#include<cstring>
int n,a[100],f[100],min;
void DFS(int k)
{
	int i,j;
	if(a[k-1]>n||k==min)return;
	if(a[k-1]==n&&k<min)
	{
		for(i=0;i<k;i++)f[i]=a[i];
		min=k;return;
	}
	for(i=k-1;i>=0;i--)
	{
		a[k]=a[k-1]+a[i];
		DFS(k+1);
	}
}
void Work()
{
	memset(a,0,sizeof(a));
	a[0]=1;min=0X7FFFFFFF;
	DFS(1);
}
int main()
{
	freopen("1937.in","r",stdin);
	freopen("1937.out","w",stdout);
	scanf("%d",&n);
	while(n)
	{
		Work();
		scanf("%d",&n);
		for(int i=0;i<min-1;i++)
			printf("%d ",f[i]);
		printf("%d\n",f[min-1]);
	}
	return 0;
}
