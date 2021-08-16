#include<graphics.h>
#include<bits/stdc++.h>
#include <string> 
using namespace std;
typedef long long int ll;
#define PI 3.1415
int main()
{
	initwindow(500,500,"ANALOG CLOCK");
	{     
	      int page=0;
		 while(1){
		  
		 setactivepage(page);
		 setvisualpage(1-page);
		 cleardevice();
		 setcolor(WHITE);
		 circle(250,250,200);
		circle(250,250,5);
		for(int i=1;i<=12;i++){
			char p[5];
		    char first_digit=i%10+'0';
		     int g=i;
		     g/=10;
		     if(g>0)
		     {
		     	p[0]=g%10+'0';
		     	p[1]=first_digit;
		     	p[2]='\0';
			 }
			 else
			 p[0]=first_digit,p[1]='\0';
			 
		outtextxy(250+180*sin(i*PI/6)-5,250-180*cos(i*PI/6),p);
           	}
           	
           	time_t now=time(0);
           	tm *ltm=localtime(&now);
           	system("cls");
           	cout<<ltm->tm_hour<<" "<<ltm->tm_min;
           	
           	
           	setcolor(RED);
           	line(250,250,250+150*sin(ltm->tm_hour*PI/6),250-150*cos(ltm->tm_hour*PI/6));  //hour Line segment
           	
           	  	setcolor(GREEN);
           	line(250,250,250+170*sin(ltm->tm_min*PI/30),250-170*cos(ltm->tm_min*PI/30));    //minute Line segment
           	
           	
           		setcolor(WHITE);
           	line(250,250,250+190*sin(ltm->tm_sec*PI/30),250-190*cos(ltm->tm_sec*PI/30));    // second line segment
           	
           	if(GetAsyncKeyState(VK_RETURN))
           	break;
           	delay(10);
           	page=1-page;
           	
           }
	} 
	getch();
	closegraph();
	return 0;
}
