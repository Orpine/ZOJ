#include<cstdio>
#include<cmath>
class point
{
	public:
		double x,y;
		point(){};
		point(double x1,double y2){x=x1;y=y2;}
		double operator %(const point &b){return x*b.y-y*b.x;}
		double operator *(const point &b){return x*b.x+y*b.y;}
		point operator +(const point &b){return point(x+b.x,y+b.y);}
		point operator -(const point &b){return point(x-b.x,y-b.y);}
		point operator *(const double k){return point(x*k,y*k);}
		point operator /(const double k){return point(x*k,y*k);}
}p[2000];
double xx,yy,xx1,xx2,yy1,yy2,rr1,rr2,x1,y2;
int n;
double Distance(double a,double b,double c,double d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
void Work()
{
	scanf("%lf%lf%lf",&xx1,&yy1,&rr1);
	scanf("%lf%lf%lf",&xx2,&yy2,&rr2);
	if(rr1==rr2){printf("Impossible.\n");return;}
	double dis=Distance(xx1,yy1,xx2,yy2);
	if(dis<=fabs(rr1-rr2)){printf("Impossible.\n");return;}
	if(rr1<rr2)
	{
		double tmp=xx1;xx1=xx2;xx2=tmp;
		tmp=yy1;yy1=yy2;yy2=tmp;
		tmp=rr1;rr1=rr2;rr2=tmp;
	}

	xx=(-rr2*xx1+rr1*xx2)/(rr1-rr2);
	yy=(-rr2*yy1+rr1*yy2)/(rr1-rr2);
	printf("%.2lf %.2lf\n",xx,yy);
}
int main()
{
	freopen("1199.in","r",stdin);
	freopen("1199.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		Work();
	return 0;
}
