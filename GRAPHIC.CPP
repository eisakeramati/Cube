#include<iostream.h>
#include<conio.h>
#include"graphics.h"
#include<math.h>
#include<dos.h>


int x=320;
int y=240;
int isfunc;
double zoom=1;
float xdeg=0,ydeg=0,zdeg=0;
double rx2[8][3],ry2[8][3],rz2[8][3],wait[8][3];
double pi=(3.14159)/180;
double points[8][3]={{-50,-50,-50},{-50,50,-50},{50,50,-50},{50,-50,-50},{-50,-50,50},{-50,50,50},{50,50,50},{50,-50,50}};
int l[12][2]={{0,1},{1,2},{2,3},{3,0},{4,5},{5,6},{6,7},{7,4},{0,4},{1,5},{3,7},{2,6}};

char funckey( int &T)
{
	char c=getch();

	if(c==0)
	{
		T=1;
		c=getch();
	}
	else
		T=0;

	return c ;
}
//setbkcolor(1);


 void draw(){
	for(int i=0;i<12;i++){
	line((points[l[i][0]][0]*zoom)+x,(points[l[i][0]][1]*zoom)+y,(points[l[i][1]][0]*zoom)+x,(points[l[i][1]][1]*zoom)+y);
}
}
void rot(float xdeg,float ydeg,float zdeg){
float p[8][3];
for(int i=0;i<8;i++){
	for(int j=0;j<3;j++){
		p[i][j]=points[i][j];
		wait[i][j]=points[i][j];
		}}

double rx[3][3]={{1,0,0},{0,cos(xdeg*pi),-sin(xdeg*pi)},{0,sin(xdeg*pi),cos(xdeg*pi)}};
double ry[3][3]={{cos(ydeg*pi),0,sin(ydeg*pi)},{0,1,0},{-sin(ydeg*pi),0,cos(ydeg*pi)}};
double rz[3][3]={{cos(zdeg*pi),-sin(zdeg*pi),0},{sin(zdeg*pi),cos(zdeg*pi),0},{0,0,1}};

for(int a=0;a<8;a++){
	for(int b=0;b<3;b++){
		int t=0;
		for(int k=0;k<3;k++){
				t+=p[a][k]*rx[k][b];
				rx2[a][b]=t;
				}
				}}
for(int c=0;c<8;c++)
	for(int v=0;v<3;v++)
		p[c][v]=rx2[c][v];

for(int d=0;d<8;d++){
	for(int f=0;f<3;f++){
		int t=0;
		for(int A=0;A<3;A++){
				t+=p[d][A]*ry[A][f];
				ry2[d][f]=t;
				}
				}}
for(int w=0;w<8;w++)
	for(int q=0;q<3;q++)
		p[w][q]=ry2[w][q];

for(int o=0;o<8;o++){
	for(int l=0;l<3;l++){
		int t=0;
		for(int K=0;K<3;K++){
				t+=p[o][K]*rz[K][l];
				rz2[o][l]=t;
				}
				}}
for(int W=0;W<8;W++)
	for(int Q=0;Q<3;Q++)
		p[W][Q]=rz2[W][Q];

for(int u=0 ; u<12 ; u++)
	line((p[l[u][0]][0]*zoom)+x,(p[l[u][0]][1]*zoom)+y,(p[l[u][1]][0]*zoom)+x,(p[l[u][1]][1]*zoom)+y);





		}
void something(char d){


switch(d){
case'H':
y-=5;
break;
case'P':
y+=5;
break;
case'M':
x+=5;
break;
case'K':
x-=5;
break;

case'S':
zoom=zoom+0.1;
break;

case's':
zoom=zoom-0.1;
	if(zoom<=0.001)
	zoom=0.001;
break;
case'x':
	xdeg++;
	//rotx(xdeg);

	if(xdeg==360)
	xdeg=0;
	break;
case'X':
	xdeg--;
	//rotx(xdeg);

	if(xdeg==0)
	xdeg=360;
	break;
case'y':
	ydeg++;
	//roty(ydeg);

	if(ydeg==360)
	ydeg=0;
	break;
case'Y':
	ydeg--;
	//roty(ydeg);

	if(y==0)
	y=360;
	break;
case'z':
	zdeg++;
	//rotz(zdeg);

	if(zdeg==360)
	zdeg=0;
	break;
case'Z':
	zdeg--;
	//rotz(zdeg);

	if(zdeg==0)
	zdeg=360;
	break;

}

rot(xdeg,ydeg,zdeg);
}




void main(){
int gd=DETECT,gm;
initgraph(&gd ,&gm,"c://turboc3//bgi");

//cleardevice();
draw();
char d;//=funckey(isfunc);
while(d!=27){
//something(d);
//draw();
d=funckey(isfunc);

cleardevice();
something(d);

}
//closegraph();
}
