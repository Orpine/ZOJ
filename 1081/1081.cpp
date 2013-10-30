#include<cstdio>
#include<cmath>
class point
{
	public:
		double x,y;
		point(){};
		point(double x1,double y1){x=x1;y=y1;}
		double operator %(const point &b){return x*b.y-y*b.x;}
		double operator *(const point &b){return x*b.x+y*b.y;}
		point operator +(const point &b){return point(x+b.x,y+b.y);}
		point operator -(const point &b){return point(x-b.x,y-b.y);}
		point operator *(double &k){return point(x*k,y*k);}
		point operator /(double &k){return point(x/k,y/k);}
}p[2000],l,r;
int n,m;
double x1,y2,eps=1e-6,oo=1e8;
void Init()
{
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x1,&y2);
		p[i]=point(x1,y2);
	}
}
int Judge(double p){if(fabs(p)<eps)return 0;return p>0?1:-1;}
int Cross(point &a,point &b,point &c){return Judge((b-a)%(c-a));}
int Between(point &a,point &b,point &c){return Judge((b-a)*(c-a));}
int Crossed(point &a,point &b,point &c,point &d)
{
	if((Cross(a,b,c)^Cross(a,b,d))==-2&&(Cross(c,d,a)^Cross(c,d,b))==-2)return 1;
	return 0;
}
bool Work()
{
	scanf("%lf%lf",&x1,&y2);l=point(x1,y2);r=point(oo,y2);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int j=(i==n?1:i+1);
		if(Cross(l,p[i],p[j])==0&&Between(l,p[i],p[j])<=0)return true;
		if(p[i].y!=p[j].y)
		{
			if(Cross(p[i],l,r)==0&&Between(p[i],l,r)==0)
				{if(p[i].y>p[j].y)cnt++;}
			else if(Cross(p[j],l,r)==0&&Between(p[j],l,r)==0)
				{if(p[j].y>p[i].y)cnt++;}
			else if(Crossed(p[i],p[j],l,r))cnt++;			
		}
	}
	if(cnt%2)return true;
	else return false;
}
int main()
{
	freopen("1081.in","r",stdin);
	freopen("1081.out","w",stdout);
	int t=0;
	while(scanf("%d",&n))
	{
		if(n==0)break;
		if(t)printf("\n");
		printf("Problem %d:\n",++t);
		Init();
		for(int i=1;i<=m;i++)if(Work())printf("Within\n");else printf("Outside\n");
	}
	return 0;
}
