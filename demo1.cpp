#include<glut.h>
#include<stdio.h>
#include<string.h>
#include<math.h>


int k=0,submenu,c;
int a[10];
int n,i,s=0,swap=0;
char r[3]="";

void int_str(int p,char r[]);
void display();
void keyboard();
void keyboard1();
void keyboard2();
void option(int id);
void mouse(int btn, int state, int x, int y);
void bitmap_output(int x, int y, char *string, void *font);
void about();
void sort();
void front_page();
void draw_square();
void delay();
void draw_outline();
void draw1();
void drawBold();

void timer(int)
{
/* update animation */
//glutPostRedisplay();
glutTimerFunc(100000.0/60.0, timer, 0);
}

void draw_square(int x,int y,int x1,int y1){
	glBegin(GL_QUADS);
	glColor3f(1.0,0.0,1.0);
	glVertex2i(x,y);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(x1,y);
	glColor3f(0.0,0.5,1.4);
	glVertex2i(x1,y1);
	glColor3f(1.0,1.0,0.0);
	glVertex2i(x,y1);
	glEnd();
	glFlush();
}

void draw1(int i,int pos){
	int x=10,y=200,x1=30,y1=210;
	int j=i*10,k;
		pos=pos*40;
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_QUADS);
		glVertex2i(x+pos,y);
		glVertex2i(x1+pos,y);
		glVertex2i(x1+pos,y1+(i*10));
		glVertex2i(x+pos,y1+(i*10));
		glEnd();
		glRasterPos2f((x+pos+x1+pos)/2,y-15);
		/*for(k=0;k<n;k++)
		{
		char srt[]="input string is-->";
    glRasterPos3f(200.0, 75.0, 1.0);
    for (int i =0 ;srt[i] != '\0';i++)
    {
        //glutBitmapCharacter(GLUT_BITMAP_9_BY_15,i+'0');
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,srt[i]);
    }
		}*/
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,i+'0');
		glFlush();
		
}

void keyboard(unsigned char key,int x,int y){

	if(key==13) //13 is the ascii value for Enter
	{
		glutDisplayFunc(front_page);
		glFlush();
	}

	if(key=='x'){
		exit(0);
	}
		glutPostRedisplay();
}

void keyboard1(unsigned char key,int x,int y){

	if(key=='s'||key=='S'){
		glClearColor(0.0,0.0,0.0,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glutDisplayFunc(sort);
		swap++;
		glFlush();
		glutPostRedisplay();
	}
	if(key=='a'){

		glutDisplayFunc(about);
			glFlush();
			glutPostRedisplay();
	}
	if(key=='x'){
		exit(0);
	}
	glutPostRedisplay();
	glutSwapBuffers();
}

void int_str(int p,char r[]){
	switch(p){
	case 0:strcpy(r,"0");break;
	case 1:strcpy(r,"1");break;
	case 2:strcpy(r,"2");break;
	case 3:strcpy(r,"3");break;
	case 4:strcpy(r,"4");break;
	case 5:strcpy(r,"5");break;
	case 6:strcpy(r,"6");break;
	case 7:strcpy(r,"7");break;
	case 8:strcpy(r,"8");break; 
	case 9:strcpy(r,"9");break;
	}
}

void draw_outline(int x,int y,int x1,int y1)
{	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_QUADS);
	glVertex2i(x+5,y+5);
	glVertex2i(x1+5,y+5);
	glVertex2i(x1+5,y1+5);
	glVertex2i(x+5,y1+5);
	glEnd();	
	glFlush();
}

void sort(){
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


	glColor3f(1.9f, 0.2f, 1.9f);
	char text1[]="B U B B L E   S O R T   A L G O R I T H M";
    glRasterPos3f(140.0, 370.0, 1.0);
    for (int i =0 ;text1[i] != '\0';i++)
    {    
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text1[i]);
    }

	int temp,pos;
	if(swap==1){
		for(int i=0;i<n;i++){//Drawing The bar Graph for the required input
			draw1(a[i],i);	
			//delay();
		}
	}
	else
	{
		printf("Array elements :\n");
		for(int i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-1;j++)
			{
				if(a[j]>a[j+1])
				{	
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
					glClear(GL_COLOR_BUFFER_BIT);
					glClearColor(0.0,0.0,0.0,1.0);
					for(int i=0;i<n;i++)
					{
						draw1(a[i],i);
						delay();					
					}		
			}
		}
	}
	glutKeyboardFunc(keyboard1);
	glFlush();
	glutSwapBuffers();
}

void keyboard2(unsigned char key,int x,int y){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0,0.0,0.0,1.0);
	if(key=='m'){
		glutDisplayFunc(front_page);
			glFlush();
			glutPostRedisplay();	
	}
}

void bitmap_output(int x, int y, char *string, void *font)
{
  int len, i;
  glRasterPos2f(x, y);
  //len = (int) strlen(string);
  for (i = 0; string[i] !='\0'; i++) {
	  glutBitmapCharacter(font, string[i]);
  }
}

void display(){
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(0.5,0.9,1.0);
	glVertex2f(0,0);
	glColor3f(1.5,0.2,1.2);
	glVertex2f(0,750);
	glColor3f(1.0,1.2,0.0);
	glVertex2f(1800,750);
	glColor3f(0.5,1.2,0.9);
	glVertex2f(1800,0);
	glEnd();
	
	glColor3f(0.5,0.0,1.0);
	bitmap_output(147.0,310.0,"COMPUTER GRAPHICS MINI PROJECT",GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1.0f,0.0f,0.0f);
	bitmap_output(140.0,270.0,"A visual representation of",GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(0.0,0.5,1.0);
	bitmap_output(208.0,270.0,"Bubble Sort Algorithm",GLUT_BITMAP_TIMES_ROMAN_24);

	char text4[]="Mr.Suchith P - 4SU19CS102";
	glColor3f(1.0f,0.0f,0.0f);
	glRasterPos3f(100.0,225.0,1.0);
	for(int i=0;text4[i]!='\0';i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text4[i]);
	}

	char text5[]="Mr.Swaroop K - 4SU19CS105";
	glColor3f(1.0f,0.0f,0.0f);
	glRasterPos2f(240.0,225.0);
	for(int i=0;text5[i]!='\0';i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text5[i]);
	}

	char text6[]="Ms.Vaishnavi Y - 4SU19CS108";
	glColor3f(1.0f,0.0f,0.0f);
	glRasterPos3f(100.0,190.0,1.0);
	for(int i=0;text6[i]!='\0';i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text6[i]);
	}

	char text7[]="Mr.Vinil Shibu - 4SU19CS112";
	glColor3f(1.0f,0.0f,0.0f);
	glRasterPos3f(240.0,190.0,1.0);
	for(int i=0;text7[i]!='\0';i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text7[i]);
	}

	char text8[]="Under The Guidance of";
	glColor3f(1.0f,1.0f,1.0f);
	glRasterPos3f(180.0,150.0,1.0);
	for(int i=0;text8[i]!='\0';i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text8[i]);
	}

	char text9[]="Mr . Arjun K";
	glColor3f(1.0f,1.0f,1.0f);
	glRasterPos3f(190.0,125.0,1.0);
	for(int i=0;text9[i]!='\0';i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text9[i]);
	}

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);
	glVertex2i(173,43);
	glVertex2i(173,63);
	glVertex2i(234,63);
	glVertex2i(234,43);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2i(207,263);
	glVertex2i(267,263);
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);
	char text3[]="Click Enter Button";
    glRasterPos3f(180.0, 50.0, 1.0);
    for (int i =0 ;text3[i] != '\0';i++)
    {
        glColor3f(0.0, 0.0, 0.0);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text3[i]);
    }

	

	glutKeyboardFunc(keyboard);
	glPushMatrix();
	glLineWidth(5);
	glColor3f(1.0,1.0,1.0);
	glTranslatef(100,370,0);
	glScaled(0.07,0.1,0.0);
	char str[]="SDM INSTITUTE OF TECHNOLOGY,UJIRE";
	for(int i=0;str[i] != '\0';i++)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str[i]);
	glPopMatrix();
	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void delay(){int time=390000000;while(time--);}

void front_page()
{ 
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.5,0.0,1.2);
	glVertex2f(0,0);
	glColor3f(0.0,0.1,0.);
	glVertex2f(0,750);
	glColor3f(1.0,1.2,1.0);
	glVertex2f(1800,750);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(1800,0);
	glEnd();

	glColor3f(1.9f, 0.2f, 1.9f);
	char text1[]="B U B B L E   S O R T   A L G O R I T H M";
    glRasterPos3f(140.0, 370.0, 1.0);
    for (int i =0 ;text1[i] != '\0';i++)
    {    
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,text1[i]);
    }

	draw_outline(167,150,231,180);
	draw_square(167,150,233,180);
	glColor3f(0.0,0.0,0.0);
	bitmap_output(175,160,"S i m u l a t i o n --> s",GLUT_BITMAP_HELVETICA_18);

	glColor3f(1.0f, 1.0f, 1.0f);
	char about[]="About-->Press ( a )";
    glRasterPos3f(20.0, 55.0, 1.0);
    for (int i =0 ;about[i] != '\0';i++)
    {  
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,about[i]);
    }

	glColor3f(1.0f, 1.0f, 1.0f);
	char srt[]="Or Use Right Mouse Button to use the same Options";
    glRasterPos3f(20.0, 15.0, 1.0);
    for (int i =0 ;srt[i] != '\0';i++)
    {
        
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,srt[i]);
    }
	glColor3f(1.0f, 1.0f, 1.0f);
	char more[]="Start Simulation -->press ( s )";
    glRasterPos3f(20.0, 75.0, 1.0);
    for (int i =0 ;more[i] != '\0';i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,more[i]);
    }
	glColor3f(1.0f, 1.0f, 1.0f); 
	char ext[]="To EXIT-->press ( x )";
    glRasterPos3f(20.0, 35.0, 1.0);
    for (int i =0 ;ext[i] != '\0';i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,ext[i]);
    }

	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard1);

	glFlush();
}

void about(){
	
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glColor3f(0.0,0.7,1.0);    
    bitmap_output(130,370,"B U B B L E   S O R T   A L G O R I T H M",GLUT_BITMAP_TIMES_ROMAN_24);


	glColor3f(1.0,1.0,1.0);
	bitmap_output(20,320,"Bubble sort, sometimes referred to as sinking sort,",GLUT_BITMAP_HELVETICA_18);
	
	bitmap_output(20,300,"is a simple sorting algorithm, that repeatedly ",GLUT_BITMAP_HELVETICA_18);

	bitmap_output(20,280,"steps through the list, compares adjacent elements",GLUT_BITMAP_HELVETICA_18);
	
	bitmap_output(20,260,"and swaps them if they are in the wrong order.",GLUT_BITMAP_HELVETICA_18);

	bitmap_output(20,240,"The pass through the list is repeated until the list is sorted.",GLUT_BITMAP_HELVETICA_18);


	glutKeyboardFunc(keyboard2);
	glFlush();
}

void mouse(int btn, int state, int x, int y){
		submenu=glutCreateMenu(option);
		glutAddMenuEntry("About",1);
		glutAddMenuEntry("EXIT",2);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void option(int id){
	switch(id){
		case 1:
			glutDisplayFunc(about);
			glFlush();
			glutPostRedisplay();
			break;
		case 2: exit(0);
	}
}

int main(int argc,char **argv){

	printf("Enter the Number of Elements\n");
	scanf("%d",&n);
	a[n];
	printf("Enter the Numbers Between (0-9)\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1800,750);
	glutCreateWindow("Bubble Sorting Algorithm ");
	glutDisplayFunc(display);
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,400.0,0.0,400.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0;

}