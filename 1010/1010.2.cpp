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
	if(fabs(p)<eps)return 0;
	return p>0?1:-1;
}
int between(point &a,point &b,point &c){return Judge((b-a)*(c-a));}
int Crossed(point &a,point &b,point &c,point &d)
{
	double s1,s2,s3,s4;
	int d1,d2,d3,d4;
	d1=Judge(s1=Cross(a,b,c));
	d2=Judge(s2=Cross(a,b,d));
	d3=Judge(s3=Cross(c,d,a));
	d4=Judge(s4=Cross(c,d,b));
	if( (d1^d2)==-2&&(d3^d4)==-2)
	{
//		p.x=(c.x*s2-d.x*s2)/(s1+s2);
//		p.y=(c.y*s2-d.y*s2)/(s1+s2);
		return 1;
	}
	if( (d1==0&&between(c,a,b)<=0)||
		(d2==0&&between(d,a,b)<=0)||
		(d3==0&&between(a,c,d)<=0)||
		(d4==0&&between(b,c,d)<=0)
	)return 2;
	return 0;
}
bool Check()
{
	int i,j,j1,i1;
	for(i=1;i<=n;i++)
	{
		if(i==n)i1=1;else i1=i+1;
		if(i==1)j=n;else j=i-1;
		if(Cross(p[j],p[i],p[i1])==0&&between(p[j],p[i],p[i1])<=0)return 0;
		if(i1==n)j=1;else j=i1+1;
		if(Cross(p[j],p[i],p[i1])==0&&between(p[j],p[i],p[i1])<=0)return 0;
		for(j=1;j<=n;j++)
		{
			if(j==n)j1=1;else j1=j+1;
			if(j==i1||j1==i||j==i)continue;
			if(Crossed(p[i],p[i1],p[j],p[j1]))return 0;
		}
	}
}
void Work()
{
	double ans=0;
	for(int i=1;i<n;i++)ans+=(p[i]%p[i+1]);
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
//		p[++n]=point(p[1].x,p[1].y);
		if(Check())Work();
		else printf("Impossible\n");
	}
	return 0;
}
