#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define limit 1e-7
class point
{
	public:
		double x,y;
		point(){};
		point(double x1,double y1) {x=x1,y=y1;}
		double operator & (const point &a) {return (x*a.y-y*a.x);}//叉积 
		double operator % (const point &a) {return (x*a.x+y*a.y);}//点积
		point operator * (const double h) {return point(x*h,y*h);}
		point operator / (const double h) {return point(x/h,y/h);}
		point operator + (const point &a) {return point(x+a.y,y+a.y);}
		point operator - (const point &a) {return point(x-a.x,y-a.y);}
		bool operator == (const point &a) {return (x==a.x&&y==a.y);}
}dot[1005];
int n;
void Init()
{
	double a,b;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a,&b);
		dot[i]=point(a,b);
	}
}
int Cross(point &a,point &b,point &c)
{
	double p=(a-c)&(b-c);
	if(fabs(p)<limit) return 0;
	if(p>0) return 1; else return -1;
}
bool On_segment(point &a,point &b,point &c)//判断点a是否在线段b->c上 在就返回true 
{
	if(fabs((a-c)&(b-c))>limit) return false;
	if(min(b.x,c.x)<=a.x&&max(b.x,c.x)>=a.x&&min(b.y,c.y)<=a.y&&max(b.y,c.y)>=a.y) return true;
	return false;
}
bool NOcross(point &a,point &b,point &c,point &d)//相交或点在线段上返回true 
{
	bool t1,t2;
	t1=(Cross(a,c,d)^Cross(b,c,d))==-2&&(Cross(c,a,b)^Cross(d,a,b))==-2;
	t2=On_segment(a,c,d)||On_segment(b,c,d)||On_segment(c,a,b)||On_segment(d,a,b);
	return t1||t2;
}
void Solve()
{
	if(n<3) {printf("Impossible\n");return ;} 
	double ans=0;
	int i1,j,j1;
	for(int i=1;i<=n;i++) 
	{
		if(i==n) i1=1;else i1=i+1;
		if(i==1) j=n;else j=i-1;
		if(On_segment(dot[j],dot[i],dot[i1])) {printf("Impossible\n");return ;}
		if(i1==n) j=1;else j=i1+1;
		if(On_segment(dot[j],dot[i],dot[i1])) {printf("Impossible\n");return ;}	
		for(j=1;j<=n;j++)
		{
			if(j==n) j1=1;else j1=j+1;
			if(j==i1||j1==i||j==i) continue;
			if(NOcross(dot[i],dot[i1],dot[j],dot[j1])) {printf("Impossible\n");return ;}
		}
	}
	for(int i=1;i<n;i++) ans+=(dot[i]&dot[i+1]);
	ans=fabs((ans+(dot[n]&dot[1])))/2.0;
	printf("%.2f\n",ans);
}
int main()
{
	freopen("1010.in","r",stdin);
	freopen("1010.out","w",stdout);
	int t=0;
	while(scanf("%d",&n))
	{
		if(!n) break;
		printf("Figure %d: ",++t);
		Init();
		Solve();
	}
//	system("pause");
	return 0;
} 
