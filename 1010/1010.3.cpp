#include<cstdio>
#include<cmath>
#include<vector>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
class point
{
	public:
		double x,y;
		point(){};
		point(double x1,double y1){x=x1;y=y1;}
		double operator %(const point &b){return x*b.y-b.x*y;}
		double operator *(const point &b){return x*b.x+y*b.y;}
		point operator +(const point &b){return point(x+b.x,y+b.y);}
		point operator -(const point &b){return point(x-b.x,y-b.y);}
		point operator *(const double k){return point(x*k,y*k);}
		point operator /(const double k){return point(x/k,y/k);}
}p[2000];
double ans,eps=1e-6;
int n;
int Judge(double p){if(fabs(p)<eps)return 0;return p>0?1:-1;}
int Cross(point &a,point &b,point &c)
{
	double p=(b-a)%(c-a);
	if(p<eps)return 0;
	return p>0?1:-1;
}
//int between(point &a,point &b,point &c){return Judge((b-a)*(c-a));}
int Between(point &a,point &b,point &c)
{
	if(fabs((a-c)%(b-c))>eps)return 0;
	if(min(b.x,c.x)<=a.x&&max(b.x,c.x)>=a.x&&min(b.y,c.y)<=a.y&&max(b.y,c.y)>=a.y) return true;
	return 0;
}
int Crossed(point &a,point &b,point &c,point &d)
{
	if((Cross(a,b,c)^Cross(a,b,d))==-2&&(Cross(c,d,a)^Cross(c,d,b))==-2)return 1;	
	if(Between(a,c,d)||Between(b,c,d)||Between(c,a,b)||Between(d,a,b))return 1;
	return 0;
}
bool Check()
{
/*	for(int i=1;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(Crossed(p[i],p[i+1],p[j],p[j+1]))return 0;
	if(Crossed(p[1],p[2],p[n-1],p[n]))return 0;
	return 1;*/
	int i1,j,j1;
	for(int i=1;i<=n;i++) 
	{
		if(i==n) i1=1;else i1=i+1;
		if(i==1) j=n;else j=i-1;
		if(i1==n) j=1;else j=i1+1;
		for(j=1;j<=n;j++)
		{
			if(j==n) j1=1;else j1=j+1;
			if(j==i1||j1==i||j==i) continue;
			if(Crossed(p[i],p[i1],p[j],p[j1])) {return 0;}
		}
	}

}
void Work()
{
	double ans=0;
	for(int i=1;i<n;i++)ans+=(p[i+1]%p[i]);
	ans+=p[n]%p[1];
	ans=fabs(ans);
	printf("%.2lf\n",ans/2.0);
}
int main()
{
	freopen("1010.in","r",stdin);
	freopen("1010.out","w",stdout);
	int t=0;
	double x1,y1;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)break;
		printf("Figure %d: ",++t);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x1,&y1);
			p[i]=point(x1,y1);
		}
		if(n<=2){printf("Impossible\n");continue;}
		p[++n]=point(p[1].x,p[1].y);
		if(Check())Work();
		else printf("Impossible\n");
	}
	return 0;
}
