#include <stdio.h>
#include <stdlib.h> //for taking absolute value between angles
int calculate_angle(double ,double ,double , double); //declaring the function to compute the angles b/w the hands of a clock
int main()
{
	int h,m,s;
	double tol;
	printf("Please enter the time in hh:mm:ss format:\n");
	scanf("%d:%d:%d",&h,&m,&s); //taking input from stdin
	if(h<0 || h>23 || m<0 || m >59 || s<0 || s>59 ) //checking the wrong input
	{
		printf("wrong input\n");
		return 0;
	}
	if(h>=12 && h<=23)
	    h=h-12;	// converting 24 hour clock time to 12 hour clock time
	printf("Enter the tolerance level of angle(in radian):");
	scanf("%lf",&tol);
	tol=tol*57.296;	
	calculate_angle(h,m,s,tol);
	return 0;
}
int calculate_angle(double h,double m,double s,double tol)
{
	double x,y,z,angle_hour,angle_min,angle_sec;
	angle_hour=(float)(30*h + 30*(m/60.0) + 30*(s/(60.0*60.0))); //calculating the angle of hour hand wrt position at 12
    angle_min=(float)(6*m + 6*(s/60.0)); //calculating the angle of min hand wrt position at 12
    angle_sec=(float)6*s; ////calculating the angle of second hand wrt position at 12
    //printf("%lf,%lf,%lf ",angle_hour,angle_min,angle_sec);
	if(angle_hour>=angle_min)
		x=angle_hour-angle_min;
	else
		x=angle_min-angle_hour;
    if(angle_min>=angle_sec)
		y=angle_min-angle_sec;
	else
		y=angle_sec-angle_min;
	if(angle_hour>=angle_sec)
		z=angle_hour-angle_sec;
	else
		z=angle_sec-angle_hour;
    //printf("%lf,%lf,%lf ",x,y,z);
	if(x>180)
		x=(float)360-x; //making the angle less than 180
	printf("\nangle(in degree) between hour hand and minute hand is:%lf\n",x);
	if(y>180)
		y=(float)360-y; //making the angle less than 180
	printf("angle(in degree) between minute hand and second hand is:%lf\n",y);
	if(z>180)
        z=(float)360-z; //making the angle less than 180
	printf("angle(in degree) between hour hand and second hand is:%lf\n",z);
	if((abs(x-y)<=tol) && (abs(y-z)<=tol) && (abs(x-z)<=tol))
		printf("EQUIANGULAR\n");
	else if((abs(x-y)>tol) && (abs(y-z)>tol) && (abs(x-z)>tol))
		printf("NONE\n");
	else
		printf("SEMI-EQUIANGULAR\n");
}
