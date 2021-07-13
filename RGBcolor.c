#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
#define DEGREES_TO_RADIANS 3.14159/180.0
GLfloat  r=75, flag=0,flag1=0, angle, xt, yt,x,y,rx=250,ry=400,gx=100,gy=100,bx=400,by=100,spin;
GLfloat sub_menu,sub_menu1,s,rx1,ry1,gx1,gy1,bx1,by1;
GLint flag2=0,flag3=0,flag4=0,flag5=0,flag6=0;
void mov();

void spinDisplay (void);
 void init(void)
{	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,500.0); 
	glMatrixMode(GL_MODELVIEW);
}
void drawstring(float x,float y,float z,char *string)
{
 char *c;
 glRasterPos3f(x,y,z);
 for(c=string;*c!='\0';c++)
 {
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
 }
}
void screen()
{
	glColor3f(0.0,0.0,1.0);
	drawstring(120.0,460.0,0.0," CGV Lab. Mini Project");
	drawstring(120.0,435.0,0.0,"on ''RGB COLORS''");
	glColor3f(1.0,0.0,0.0);
	drawstring(120,375,0.0,"6th sem CSE,SVIT");
	drawstring(50,350,0.0,"Name:TEJAS MANU S        USN:1VA18CS052 ");
	drawstring(50,325,0.0,"Name:SUHAS M             USN:1VA18CS048 ");
	drawstring(50,325,0.0,"Name:AISHWARYA           USN:1VA19CS400 ");
	drawstring(50,325,0.0,"Name:SHARATH GOWDA P     USN:1VA18CS042 ");
	glColor3f(1.0,1.0,1.0);
	drawstring(120,260,0.0,"   Under The Guidance of:");
	drawstring(155,230,0.0,"Prof:SYED MATHEEN PASHA");
	glColor3f(0.0,1.0,1.0);
	drawstring(50,100,0.0,"Department of Computer Science And");
	drawstring(50,75,0.0,"      Engineering      ");
	glColor3f(rand()%2,rand()%2,0.0);
	drawstring(250,20,0.0,"Press 'e' to start");
glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
   switch (key) 
   {
		case 'r':
		case 'R': 
				rx=250;
				ry=400;
				gx=100;
				gy=100;
				bx=400;
				by=100;
				flag4=0;
				flag1=0;
				flag6=0;
				flag=0;
				s=0;//reset
				glutPostRedisplay();
				break;	
		case 'm':flag=1;
				flag6=0;
				glutPostRedisplay();	
				break;
		case 'M':flag=0;          //move
				if(rx==100&&ry==100||gx==100&&gy==100||bx==100&&by==100)
			 flag6=0;
			 	else flag6=1;
				glutPostRedisplay();	
				break;
		case 's':
		case 'S':                 //s=3;
				flag1=1;
				if (s==0.0) 	
				{
				s=0.1;		 
				}
				else if(s>0.0) 
				{
				s *= 1.5;
				}
				 if(s>=50)
				{
			    s/= 25.0;
				}				//spinDisplay with increment
				glutPostRedisplay();
				break;
		case 'e':
		case 'E': flag3=1;                              //Enter the project Screen
					break;
		case 'a':
		case 'A':s=0;
				flag1=0;//stop the spin or rotation
				break;
				
		case 'q':		
		case 27:  /*  Escape key  */
				exit(0);
				break;
				default:
		break;
}
}

void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN) 
	{
	if(rx==100&&ry==100||gx==100&&gy==100||bx==100&&by==100)
			 flag6=0;
			flag=1; //MOve 
    	glutPostRedisplay();
    if(rx>=210&&ry>=210||gx>=210&&gy>+210||bx>210&&by>210)
			flag6=1;
		glutPostRedisplay();
	}
	
}
void top_menu(int id)
{
	switch(id)
	{
		case 1: rx=250;
				ry=400;
				gx=100;
				gy=100;
				bx=400;
				by=100;
				flag4=0;flag6=0;
				flag1=0;  //order RGB
				glutPostRedisplay();
			break;
		case 2:	bx=250;
				by=400;
				rx=100;
				ry=100;
				gx=400;
				gy=100;
				flag4=0;flag6=0;
				flag1=0;//Order BRG
				glutPostRedisplay();
			break;
		case 3: gx=250;
				gy=400;
				bx=100;
				by=100;
				rx=400;
				ry=100;
				flag4=0;
				flag6=0;
				flag1=0;//Order GBR
				glutPostRedisplay();
			break;
		case 4: rx=250;
				ry=400;
				gx=100;
				gy=100;
				bx=400;
				by=100;
				flag4=0;
				flag1=0;
				flag6=0;
				s=0;//Reset circles in Original position
				glutPostRedisplay();
			break;
		case 5: flag1=0;
				flag=1; //Move to Centre
			break;
		case 8:exit(0);
			break;		
				
	}
}
void rotate_menu(int id)
{
	switch(id)
	{
	case 6: s=1;
			flag1=1; //Slow spin
		break;
	case 7: s=10;
			flag1=1; //Fast Spin
		break;	
	}
}
void mov(void)
{
	
		if(flag==1)//Move circles in center position
		{
			if(gx<=210&&gy<=210)
				{
				gx+=0.4;
				gy+=0.4;
				//rx+=0.2;
				ry-=0.4;
				bx-=0.4;
				by+=0.4;
				if(gx>=210) flag=0;//Move when Order is RGB
				}
			else if(bx<=210&&by<=210)
				{
				//gx+=0.2;
				gy-=0.4;
				rx-=0.4;
				ry+=0.4;
				bx+=0.4;
				by+=0.4;
				if(bx>=210) flag=0;//Move when Order is GBR
				}
			else if(rx<=210&&ry<=210)
				{
				gx-=0.4;
				gy+=0.4;
				rx+=0.4;
				ry+=0.4;
				//bx-=0.2;
				by-=0.4; //Move When order is BRG
				if(rx>=210) flag=0;
				}
		}
		
			if(flag1==1)//Spin or Rotation
    	{
    		spin = spin +s;
    		if (spin >360.0) 
			spin = 0;
			rx= 250+50*cos(DEGREES_TO_RADIANS * spin);
    		ry= 250+50*sin(DEGREES_TO_RADIANS * spin);
			gx= 250+45*sin(DEGREES_TO_RADIANS * spin);
    		gy= 250-45*cos(DEGREES_TO_RADIANS * spin);
    		bx= 250-45*sin(DEGREES_TO_RADIANS * spin);
    		by= 250+45*cos(DEGREES_TO_RADIANS * spin);
		
		}
		if(flag6==1)//for moving away from each other 
		{
			if(gx<=250&&gy<=250)
				{
				gx-=0.4;
				gy-=0.4;
				bx+=0.4;
				by-=0.4;
				//rx+=0.2;
				ry+=0.4;
				if(rx==100&&ry==100||gx==100&&gy==100||bx==100&&by==100)
			 flag6=0;
				//if(gx==100) flag6=0;
				}
			
			 else if(rx<=250&&ry<=250)
				{
				rx-=0.4;
				ry-=0.4;
				gx+=0.4;
				gy-=0.4;
				
				//bx-=0.2;
				by+=0.4; 
				if(rx==100&&ry==100||gx==100&&gy==100||bx==100&&by==100)
			 flag6=0;
				}
				else if(bx<=250&&by<=250)
				{
				bx-=0.4;
				by-=0.4;
				rx+=0.4;
				ry-=0.4;
				//gx+=0.2;
				gy+=0.4;
				if(rx==100&&ry==100||gx==100&&gy==100||bx==100&&by==100)
			 flag6=0;
				}
			 
		}
		glutPostRedisplay();
	
	
}
void display(void)
{
	
	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	if(flag2==0)
	{
		screen();
	}
	if(flag3==1)
	{
		flag2=1;
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_TRIANGLE_FAN);//Display a Green Circle
	for(angle=0;angle<360.0;angle+=.1)
	{
    		yt =gy+(sin(angle*3.142/180)*r);
    		xt =gx+(cos(angle*3.142/180)*r);
    		glVertex2f(xt, yt);
	}
 	glEnd();
 	glColor3f(0.0,0.0,1.0);
	glBegin(GL_TRIANGLE_FAN);//Display a Blue Circle
	for(angle=0;angle<360.0;angle+=.1)
	{
    		yt =by+(sin(angle*3.142/180)*r);
    		xt =bx+(cos(angle*3.142/180)*r);
    		glVertex2f(xt, yt);
	}
 	glEnd();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_TRIANGLE_FAN);
	for(angle=0; angle<360.0; angle+=.1)//Draw a Red Circle
	{
    		yt =ry+(sin(angle*3.142/180)*r);
    		xt =rx+(cos(angle*3.142/180)*r);
    		glVertex2f(xt, yt);
	}
 
	glEnd();
	glFlush();
	}
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutCreateWindow("Additive Color Model");
	init();
	glutDisplayFunc (display);
	glutMouseFunc(mouse);
	 sub_menu=glutCreateMenu(rotate_menu);
	 glutAddMenuEntry("Rotate slow",6);
	 glutAddMenuEntry("Rotate fast",7);
	glutCreateMenu(top_menu);
	 glutAddSubMenu("Rotate",sub_menu);
	 glutAddMenuEntry("RGB",1);
	 glutAddMenuEntry("BRG",2);
	 glutAddMenuEntry("GBR",3);
	 glutAddMenuEntry("Reset",4);
	 glutAddMenuEntry("Move",5);
	 glutAddMenuEntry("Exit",8);
	 glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutIdleFunc (mov);
	glutKeyboardFunc (keyboard);
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE,GL_ONE);//Additive Blend
	glutMainLoop();
	return 0;
}
