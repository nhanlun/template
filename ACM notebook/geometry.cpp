struct line
{
	double a,b,c;
	line() {}
	line(double A,double B,double C):a(A),b(B),c(C){}
	line(Point A,Point B)
	{
  	a=A.y-B.y; b=B.x-A.x; c=-a*A.x-b*A.y;
	}
};
 
Point intersect(line AB,line CD)
{
	AB.c=-AB.c; CD.c=-CD.c;
	double D=CROSS(AB.a,AB.b,CD.a,CD.b);
	double Dx=CROSS(AB.c,AB.b,CD.c,CD.b);
	double Dy=CROSS(AB.a,AB.c,CD.a,CD.c);
	if (D==0.0) return Point(1e9,1e9);
	else return Point(Dx/D,Dy/D);
}