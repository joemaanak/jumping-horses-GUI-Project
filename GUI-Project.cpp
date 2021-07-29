#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <string>
#include<iostream>
using namespace std;
string user_name;
string levelname;



float arrowx = 0;
int sounduser= 1;
int sounduser2 = 1;
int sounduser3 = 1;


int pointer = 0;
float click[8] = { 0,0,0,0,0,0,0,0};

bool timeclick =false;

int finaltime = 0;
string time;
int position[9] = { 0,1,2,3,-99,4,5,6,7 };

bool add1 = false;
bool add2 = false;
bool min1 = false;
bool min2 = false;
GLfloat angle = 0.0f;
int refreshmill = 1;
bool name_entered = false;
bool level_choice = false;
bool restart_game = false;
bool restart_program = false;

bool exit_button = false;
bool demo_button = false;
bool level_button = false;
bool restart_button = false;
bool reset_button = false;
bool user_won= false;
bool user_lost = false;

int demoadder=0;
void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refreshmill, timer, 0);
}

void game_timer(int value)
{
	
	timeclick = true;
	if (finaltime> 0 && timeclick == true && demo_button==false)
	{
	
		finaltime--;
		time = to_string(finaltime);
		glutPostRedisplay();
	}
	glutPostRedisplay();
	glutTimerFunc(1000, game_timer, 0);
}

/*
GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18*/


void insert(string output_text, int q, int w, int r, int g, int b)
{
	int o;
	char zz[80] = "";
	for (o = 0; o < output_text.length(); o++)
	{
		zz[o] += output_text[o];
	}
	int z;
	z = strlen(zz);
	glColor3f(r, g, b);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(q, w);
	for (int i = 0; i < z; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, zz[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void inserttwo(string output_text, int q, int w, int r, int g, int b)
{
	int o;
	char zz[80] = "";
	for (o = 0; o < output_text.length(); o++)
	{
		zz[o] += output_text[o];
	}
	int z;
	z = strlen(zz);
	glColor3f(r, g, b);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(q, w);
	for (int i = 0; i < z; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, zz[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
void insertthree(string output_text, int q, int w, int r, int g, int b)
{
	int o;
	char zz[80] = "";
	for (o = 0; o < output_text.length(); o++)
	{
		zz[o] += output_text[o];
	}
	int z;
	z = strlen(zz);
	glColor3f(r, g, b);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(q, w);
	for (int i = 0; i < z; ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, zz[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
void type_your_name(unsigned char key, int x, int y)
{
	string name2;


	if (key == 0x08)  //ascii in backspace: 0x08
	{
		for (int i = 0; i < user_name.length() - 1; i++)
		{
			name2 += user_name[i];
		}
		user_name = name2;
	}
	else {
		user_name += key;
	}
	glutPostRedisplay();




	if (key == 127) //Delete in ASCII: 127
	{
		user_name = "";
		glutPostRedisplay();
	}
	if (key == 13) //Enter in ASCII is: 13
	{
		if (user_name != "")
		{
		name_entered = true;
		}

	}

	glutPostRedisplay();



}


void checkhorse()
{
	for (int h = 0; h < 9; h++)
	{
		if (pointer == position[h])
		{
			if (pointer <= 3)  
	   /*checking to which side the clicked horse belong
		* if left side (red) ->moves forward
		* if right side (blue) -> moves backwards
		*/
			{
				if (position[h + 1] == -99)
					/*if the horse next to the horse clicked is empty, =99)*/
				{
					add1=true;
					
					position[h + 1] = position[h];
					position[h] = -99;
					
					
					glutPostRedisplay();
				}
				if (position[h + 2] == -99)
				{
					add2 = true;
			
					position[h + 2] = position[h];
					position[h] = -99;
					glutPostRedisplay();
				}
			}

		}

		if (pointer == position[h] && pointer > 3)
		{
		

			if (position[h - 1] == -99)
			{
			
				min1 = true;
				
				position[h - 1] = position[h];
				position[h] = -99;
				glutPostRedisplay();

			}
			if (position[h - 2] == -99)
			{
				
				min2 = true;
		
				position[h - 2] = position[h];
				position[h] = -99;
				glutPostRedisplay();
			}

		}
	}
	

	//cout << "POINTER= " << pointer << endl;
	//cout << endl;
	for (int j = 0; j < 9; j++)
	{
		cout << "position " << position[j]<<endl;
	}
	for (int j = 0; j < 9; j++)
	{
		cout << "click  of " << j << " = " <<click[j]<<endl;
	}

}

void redhorse(float x)
{

	glBegin(GL_LINES);

	//horse 1
	glColor3f(1, 0, 0);
	glVertex2f(-0.73+x, 0.2); //x1  =-0.73
	glVertex2f(-0.65 + x, 0.2); //x2=-0.65
	glVertex2f(-0.65 + x, 0.2);//x2
	glVertex2f(-0.65 + x, 0.15);//x2
	glVertex2f(-0.65 + x, 0.15);//x2
	glVertex2f(-0.73 + x, 0.15);//x1
	glVertex2f(-0.73 + x, 0.15);//x1
	glVertex2f(-0.73 + x, 0.2);//x1
	//head begin
	glVertex2f(-0.65 + x, 0.2);
	glVertex2f(-0.65 + x, 0.24);
	glVertex2f(-0.65 + x, 0.24);
	glVertex2f(-0.615 + x, 0.24);//x3=-0.615
	glVertex2f(-0.615 + x, 0.24);
	glVertex2f(-0.615 + x, 0.267);
	glVertex2f(-0.65 + x, 0.267);
	glVertex2f(-0.65 + x, 0.24);

	glVertex2f(-0.65 + x, 0.267);
	glVertex2f(-0.65 + x, 0.290);
	glVertex2f(-0.65 + x, 0.290);
	glVertex2f(-0.66 + x, 0.290); //x4=-0.66
	glVertex2f(-0.66 + x, 0.290);
	glVertex2f(-0.66 + x, 0.2);
	glVertex2f(-0.66 + x, 0.29);
	glVertex2f(-0.615 + x, 0.267);

	//head end
	//tail begin
	glVertex2f(-0.73 + x, 0.2);
	glVertex2f(-0.76 + x + 0.01, 0.18); //x5=-0.76
	//tail end
	//begin leg

	glVertex2f(-0.65 + x, 0.15);
	glVertex2f(-0.65 + x, 0.08);
	glVertex2f(-0.65 + x, 0.08);
	glVertex2f(-0.66 + x, 0.08);
	glVertex2f(-0.66 + x, 0.08);
	glVertex2f(-0.66 + x, 0.15);
	glVertex2f(-0.65 + x, 0.10);//
	glVertex2f(-0.66 + x, 0.10);

	glVertex2f(-0.669 + x, 0.15);//x6=-0.679
	glVertex2f(-0.679 + x, 0.15);
	glVertex2f(-0.679 + x, 0.15);
	glVertex2f(-0.679 + x, 0.10);
	glVertex2f(-0.679 + x, 0.10);
	glVertex2f(-0.669 + x, 0.10);
	glVertex2f(-0.669 + x, 0.10);
	glVertex2f(-0.669 + x, 0.15);

	//*/
//
	glVertex2f(-0.65 + x, 0.15);
	glVertex2f(-0.711 + x, 0.15);
	glVertex2f(-0.711 + x, 0.15);
	glVertex2f(-0.711 + x, 0.10);
	glVertex2f(-0.711 + x, 0.10);
	glVertex2f(-0.701 + x, 0.10);
	glVertex2f(-0.701 + x, 0.10);
	glVertex2f(-0.701 + x, 0.15);

	//

	//leg left
	glVertex2f(-0.73 + x, 0.15);
	glVertex2f(-0.72 + x, 0.15);
	glVertex2f(-0.72 + x, 0.15);
	glVertex2f(-0.72 + x, 0.08);
	glVertex2f(-0.72 + x, 0.08);
	glVertex2f(-0.73 + x, 0.08);
	glVertex2f(-0.73 + x, 0.08);
	glVertex2f(-0.73 + x, 0.15);
	glVertex2f(-0.73 + x, 0.10);
	glVertex2f(-0.73 + x, 0.10);
	//leg end tbc*/

	glEnd();
	//coloring foor
	glBegin(GL_POLYGON);
	glColor3f(2.0, 0.0, 0.0);
	glVertex2f(-0.72 + x, 0.1);
	glVertex2f(-0.73 + x, 0.1);
	glVertex2f(-0.73 + x, 0.1);
	glVertex2f(-0.73 + x, 0.08);
	glVertex2f(-0.73 + x, 0.08);
	glVertex2f(-0.72 + x, 0.08);
	glVertex2f(-0.72 + x, 0.08);
	glVertex2f(-0.72 + x, 0.1);
	//*/
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(2.0, 0.0, 0.0);
	glVertex2f(-0.65 + x, 0.10);//
	glVertex2f(-0.66 + x, 0.10);
	glVertex2f(-0.66 + x, 0.10);
	glVertex2f(-0.66 + x, 0.08);
	glVertex2f(-0.66 + x, 0.08);
	glVertex2f(-0.65 + x, 0.08);
	glVertex2f(-0.65 + x, 0.08);
	glVertex2f(-0.65 + x, 0.10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(2.0, 0.0, 0.0);
	glVertex2f(-0.701 + x, 0.115);
	glVertex2f(-0.711 + x, 0.115);
	glVertex2f(-0.711 + x, 0.115);
	glVertex2f(-0.711 + x, 0.10);
	glVertex2f(-0.711 + x, 0.10);
	glVertex2f(-0.701 + x, 0.10);
	glVertex2f(-0.701 + x, 0.10);
	glVertex2f(-0.701 + x, 0.115);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(2.0, 0.0, 0.0);
	glVertex2f(-0.669 + x, 0.115);
	glVertex2f(-0.679 + x, 0.115);
	glVertex2f(-0.679 + x, 0.115);
	glVertex2f(-0.679 + x, 0.10);
	glVertex2f(-0.679 + x, 0.10);
	glVertex2f(-0.669 + x, 0.10);
	glVertex2f(-0.669 + x, 0.10);
	glVertex2f(-0.669 + x, 0.115);
	glEnd();
	glutPostRedisplay();
	glBegin(GL_POLYGON);
	glColor3f(2.0, 0.0, 0.0);
	glVertex2f(-0.65 + x, 0.29);
	glVertex2f(-0.66 + x, 0.29);
	glVertex2f(-0.66 + x, 0.29);
	glVertex2f(-0.66 + x, 0.2);
	glVertex2f(-0.66 + x, 0.2);
	glVertex2f(-0.65 + x, 0.2);
	glVertex2f(-0.65 + x, 0.2);
	glVertex2f(-0.65 + x, 0.29);
	glutPostRedisplay();

	glEnd();


}

void bluehorse(float x)
{
	//drawhorse2(0.174 + click[5], 0.094 + click[5], 0.059 + click[5], 0.104 + click[5], 0.204 + click[5], 0.113 + click[5], 0.123 + click[5], 0.155 + click[5], 0.145 + click[5], 0.164 + click[5]);
	
	glutPostRedisplay();

	glBegin(GL_LINES);

	//horse 1
	glColor3f(0, 0, 1);
	glVertex2f(0.174+x, 0.2); //x1  =-0.73
	glVertex2f(0.094+x, 0.2); //x2=-0.65
	glVertex2f(0.094+x, 0.2);//x2
	glVertex2f(0.094+x, 0.15);//x2
	glVertex2f(0.094+x, 0.15);//x2
	glVertex2f(0.174+x, 0.15);//x1
	glVertex2f(0.174 + x, 0.15);//x1
	glVertex2f(0.174 + x, 0.2);//x1
	//head begin
	glVertex2f(0.094 + x, 0.2);
	glVertex2f(0.094 + x, 0.24);
	glVertex2f(0.094 + x, 0.24);
	glVertex2f(0.059 + x, 0.24);//x3=-0.615
	glVertex2f(0.059 + x, 0.24);
	glVertex2f(0.059 + x, 0.267);
	glVertex2f(0.094 + x, 0.267);
	glVertex2f(0.094 + x, 0.24);

	glVertex2f(0.094 + x, 0.267);
	glVertex2f(0.094 + x, 0.290);
	glVertex2f(0.094 + x, 0.290);
	glVertex2f(0.104 + x, 0.290); //x4=-0.66
	glVertex2f(0.104 + x, 0.290);
	glVertex2f(0.104 +x, 0.2);
	glVertex2f(0.104 + x, 0.29);
	glVertex2f(0.059 + x, 0.267);

	//head end
	//tail begin
	glVertex2f(0.174 + x, 0.2);
	glVertex2f(0.204 + x - 0.01, 0.18); //x5=-0.76
	//tail end
	//begin leg

	glVertex2f(0.094 + x, 0.15);
	glVertex2f(0.094 + x, 0.08);
	glVertex2f(0.094 + x, 0.08);
	glVertex2f(0.104 + x, 0.08);
	glVertex2f(0.104 + x, 0.08);
	glVertex2f(0.104 + x, 0.15);
	glVertex2f(0.094 + x, 0.10);//
	glVertex2f(0.104 + x, 0.10);


	glVertex2f(0.113 + x, 0.15);//x6=-0.679
	glVertex2f(0.123 + x, 0.15);
	glVertex2f(0.123 + x, 0.15);
	glVertex2f(0.123 + x, 0.10);
	glVertex2f(0.123 + x, 0.10);
	glVertex2f(0.113 + x, 0.10);
	glVertex2f(0.113 + x, 0.10);
	glVertex2f(0.113 + x, 0.15);

	//*/

//
	glVertex2f(0.094 + x, 0.15);
	glVertex2f(0.155 + x, 0.15);
	glVertex2f(0.155 + x, 0.15);
	glVertex2f(0.155 + x, 0.10);
	glVertex2f(0.155 + x, 0.10);
	glVertex2f(0.145 + x, 0.10);
	glVertex2f(0.145 + x, 0.10);
	glVertex2f(0.145 + x, 0.15);
	//
	//leg left
	glVertex2f(0.174 + x, 0.15);
	glVertex2f(0.164 + x, 0.15);
	glVertex2f(0.164 + x, 0.15);
	glVertex2f(0.164 + x, 0.08);
	glVertex2f(0.164 + x, 0.08);
	glVertex2f(0.174 + x, 0.08);
	glVertex2f(0.174 + x, 0.08);
	glVertex2f(0.174 + x, 0.15);
	glVertex2f(0.174 + x, 0.10);
	glVertex2f(0.164 + x, 0.10);
	//leg end tbc*/
	glEnd();
	//coloring foor
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(0.164 + x, 0.1);
	glVertex2f(0.174 + x, 0.1);
	glVertex2f(0.174 + x, 0.1);
	glVertex2f(0.174 + x, 0.08);
	glVertex2f(0.174 + x, 0.08);
	glVertex2f(0.164 + x, 0.08);
	glVertex2f(0.164 + x, 0.08);
	glVertex2f(0.164 + x, 0.1);
	//*/
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(0.094 + x, 0.10);//
	glVertex2f(0.104 + x, 0.10);
	glVertex2f(0.104 + x, 0.10);
	glVertex2f(0.104 + x, 0.08);
	glVertex2f(0.104 + x, 0.08);
	glVertex2f(0.094 + x, 0.08);
	glVertex2f(0.094 + x, 0.08);
	glVertex2f(0.094 + x, 0.10);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(0.145 + x, 0.115);
	glVertex2f(0.155 + x, 0.115);
	glVertex2f(0.155 + x, 0.115);
	glVertex2f(0.155 + x, 0.10);
	glVertex2f(0.155 + x, 0.10);
	glVertex2f(0.145 + x, 0.10);
	glVertex2f(0.145 + x, 0.10);
	glVertex2f(0.145 + x, 0.115);
	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0, 0, 1);
	glVertex2f(0.113 + x, 0.115);
	glVertex2f(0.123 + x, 0.115);
	glVertex2f(0.123 + x, 0.115);
	glVertex2f(0.123 + x, 0.10);
	glVertex2f(0.123 + x, 0.10);
	glVertex2f(0.113 + x, 0.10);
	glVertex2f(0.113 + x, 0.10);
	glVertex2f(0.113 + x, 0.115);
	glEnd();
	glutPostRedisplay();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(0.094 + x, 0.29);
	glVertex2f(0.104 + x, 0.29);
	glVertex2f(0.104 + x, 0.29);
	glVertex2f(0.104 + x, 0.2);
	glVertex2f(0.104 + x, 0.2);
	glVertex2f(0.094 + x, 0.2);
	glVertex2f(0.094 + x, 0.2);
	glVertex2f(0.094 + x, 0.29);
	glutPostRedisplay();

	glEnd();
	glutPostRedisplay();

}

void drawhorse()
{
	for (int i = 0; i < 9; i++)
	{
		if (position[i] <=3 && position[i] !=-99)
		{
		redhorse(((float)i/6.15));  // l espace ben kel horsde 0.162  = 1/6.15
		    glutPostRedisplay();
		}
		if (position[i] >3 && position[i] != -99)
		{
			bluehorse(((float)(i -6.15)/ 6.15)+0.2);
			glutPostRedisplay();
		}

	}
}

void drawstarleft()
{
		glFlush();
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glRotatef(angle, 0.0f, 1.0f, 0.0f);

	if (user_won == true)
	{
		glBegin(GL_TRIANGLES);

		glColor3f(1, 0, 0);
		glVertex2f(-0.60 + 0.62, 0.77 - 1.25);
		glColor3f(0, 1, 0);
		glVertex2f(-0.42 + 0.62, 0.77 - 1.25);
		glColor3f(0, 0, 1);
		glVertex2f(-0.58 + 0.62, 0.68 - 1.25);

		//second triangle top triangle

		glColor3f(1, 0, 0);
		glVertex2f(-0.64 + 0.62, 1 - 1.25);
		glColor3f(0, 1, 0);
		glVertex2f(-0.68 + 0.62, 0.77 - 1.25);
		glColor3f(0, 0, 1);
		glVertex2f(-0.60 + 0.62, 0.77 - 1.25);

		//3rd Triangle
		glColor3f(1, 0, 0);
		glVertex2f(-0.68 + 0.62, 0.77 - 1.25);
		glColor3f(0, 1, 0);
		glVertex2f(-0.7 + 0.62, 0.68 - 1.25);
		glColor3f(0, 0, 1);
		glVertex2f(-0.86 + 0.62, 0.77 - 1.25);

		//4th Triangle
		glColor3f(1, 0, 0);
		glVertex2f(-0.64 + 0.62, 0.63 - 1.25);
		glColor3f(0, 1, 0);
		glVertex2f(-0.7 + 0.62, 0.68 - 1.25);
		glColor3f(0, 0, 1);
		glVertex2f(-0.82 + 0.62, 0.43 - 1.25);

		//5th Triangle
		glColor3f(1, 0, 0);
		glVertex2f(-0.64 + 0.62, 0.63 - 1.25);
		glColor3f(0, 1, 0);
		glVertex2f(-0.58 + 0.62, 0.68 - 1.25);

		glColor3f(0, 0, 1);
		glVertex2f(-0.51 + 0.62, 0.43 - 1.25);
		glColor3f(1, 0, 0);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2f(-0.60 + 0.62, 0.77 - 1.25);
		glColor3f(0, 1, 0);
		glVertex2f(-0.68 + 0.62, 0.77 - 1.25);
		glColor3f(1, 0, 1);
		glVertex2f(-0.7 + 0.62, 0.68 - 1.25);
		glColor3f(1, 0, 0);
		glVertex2f(-0.64 + 0.62, 0.63 - 1.25);
		glColor3f(0, 1, 0);
		glVertex2f(-0.58 + 0.62, 0.68 - 1.25);
		glColor3f(0, 0, 1);

		glEnd();



		glPopMatrix();

	//	glutSwapBuffers();
		angle += 0.2;

	}

}



void display()
{

	
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	/*	glVertex2d(-1, 0);
		glVertex2d(1, 0);
		glVertex2d(0, 1);
		glVertex2d(0, -1);*/
		//begin player name
	if (name_entered == false)
	{

		glBegin(GL_LINES);

		glVertex2f(-0.3, -0.05);
		glVertex2f(0.3, -0.05);

		glVertex2f(0.3, -0.05);
		glVertex2f(0.3, 0.05);

		glVertex2f(0.3, 0.05);
		glVertex2f(-0.3, 0.05);

		glVertex2f(-0.3, 0.05);
		glVertex2f(-0.3, -0.05);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2f(0.3, 0.25);
		glColor3f(0, 1, 0);
		glVertex2f(-0.3, 0.25);
		glColor3f(0, 0, 1);
		glVertex2f(-0.3, 0.25);
		glVertex2f(-0.3, 0.4);
		glVertex2f(-0.3, 0.4);
		glVertex2f(0.3, 0.4);
		glVertex2f(0.3, 0.4);
		glVertex2f(0.3, 0.25);
		glEnd();

	}
	//end player name
	if (level_choice == true && demo_button == false)
	{
		//begin restart button
		glBegin(GL_POLYGON);
		glColor3f(220, 220, 220);
		glVertex2f(-0.84, -0.86); //a
		glVertex2f(-0.84, -0.94); //b

		glVertex2f(-0.84, -0.94); //b
		glVertex2f(-0.74, -0.94); //c

		glVertex2f(-0.74, -0.94); //c
		glVertex2f(-0.74, -0.86); //d

		glVertex2f(-0.74, -0.86); //d
		glVertex2f(-0.84, -0.86); //a
		glEnd();
		//end restart button

		glBegin(GL_POLYGON);
		//begin level button
		glColor3f(220, 220, 220);
		glVertex2f(-0.68, -0.86); //a
		glVertex2f(-0.68, -0.94); //b

		glVertex2f(-0.68, -0.94); //b
		glVertex2f(-0.58, -0.94); //c

		glVertex2f(-0.58, -0.94); //c
		glVertex2f(-0.58, -0.86); //d

		glVertex2f(-0.58, -0.86); //d
		glVertex2f(-0.68, -0.86); //a
		glEnd();
		//end level button
		//begin demo button
		glBegin(GL_POLYGON);
		glColor3f(220, 220, 220);
		glVertex2f(-0.52, -0.86); //a
		glVertex2f(-0.52, -0.94); //b

		glVertex2f(-0.52, -0.94); //b
		glVertex2f(-0.42, -0.94); //c

		glVertex2f(-0.42, -0.94); //c
		glVertex2f(-0.42, -0.86); //d

		glVertex2f(-0.42, -0.86); //d
		glVertex2f(-0.52, -0.86); //a
		//end demo button
		glEnd();

	

	}
	if (level_choice == true)
	{

		glBegin(GL_POLYGON);

		//exit button begin
		glColor3f(220, 220, 220);
		glVertex2f(-0.36, -0.86); //a
		glVertex2f(-0.36, -0.94); //b

		glVertex2f(-0.36, -0.94); //b
		glVertex2f(-0.26, -0.94); //c

		glVertex2f(-0.26, -0.94); //c
		glVertex2f(-0.26, -0.86); //d

		glVertex2f(-0.26, -0.86); //d
		glVertex2f(-0.36, -0.86); //a
		//exit button end
		glEnd();

		//begin reset button
		glBegin(GL_POLYGON);
		glColor3f(220, 220, 220);
		glVertex2f(-0.20, -0.86); //a
		glVertex2f(-0.20, -0.94); //b

		glVertex2f(-0.20, -0.94); //b
		glVertex2f(-0.10, -0.94); //c

		glVertex2f(-0.10, -0.94); //c
		glVertex2f(-0.10, -0.86); //d

		glVertex2f(-0.10, -0.86); //d
		glVertex2f(-0.20, -0.86); //a
		//end reset button
		glEnd();
	}


	if (name_entered == true && level_choice == false)
	{
		glBegin(GL_POLYGON);
		glColor3f(0.0, 128.0, 0.0);
		//easy surround button begin
		glVertex2f(-0.2, 0.1); //a
		glVertex2f(-0.2, 0.2); //b

		glVertex2f(-0.2, 0.2); //b
		glVertex2f(0.2, 0.2); //c

		glVertex2f(0.2, 0.2); //c
		glVertex2f(0.2, 0.1); //d

		glVertex2f(0.2, 0.1); //d
		glVertex2f(-0.2, 0.1); //a
	//easy surround end
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(255.0, 255.0, 0.0);
		//medium surround button begin
		glVertex2f(-0.2, -0.1); //a
		glVertex2f(-0.2, -0.2); //b

		glVertex2f(-0.2, -0.2); //b
		glVertex2f(0.2, -0.2); //c

		glVertex2f(0.2, -0.2); //c
		glVertex2f(0.2, -0.1); //d

		glVertex2f(0.2, -0.1); //d
		glVertex2f(-0.2, -0.1); //a
		//medium surround button end
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(2.0, 0.0, 0.0);
		//hard surround button begin
		glVertex2f(-0.2, -0.5); //a
		glVertex2f(-0.2, -0.4); //b

		glVertex2f(-0.2, -0.4); //b
		glVertex2f(0.2, -0.4); //c

		glVertex2f(0.2, -0.4); //c
		glVertex2f(0.2, -0.5); //d

		glVertex2f(0.2, -0.5); //d
		glVertex2f(-0.2, -0.5); //a
		//hard surround button end

		glEnd();

	}

	if (restart_button == true)
	{
		name_entered = false;
		level_choice = false;
		user_name = "";
		position[0] = 0;
		position[1] = 1;
		position[2] = 2;
		position[3] = 3;
		position[4] = -99;
		position[5] = 4;
		position[6] = 5;
		position[7] = 6;
		position[8] = 7;

		for (int i = 0; i < 8; i++)
		{

			click[i] = 0;

		}
		demo_button = false;
		demoadder = 0;
		user_won = false;
		user_lost = false;
		restart_button = false;
	}

	if (level_button == true)
	{
		level_choice = false;
		level_button = false;
		user_name = "";
		position[0] = 0;
		position[1] = 1;
		position[2] = 2;
		position[3] = 3;
		position[4] = -99;
		position[5] = 4;
		position[6] = 5;
		position[7] = 6;
		position[8] = 7;

		for (int i = 0; i < 8; i++)
		{

			click[i] = 0;

		}
	}

	glutPostRedisplay();

	if (name_entered == true && level_choice == true) //background box
	{
		drawhorse();
		glutPostRedisplay();

		glBegin(GL_LINES);
		//demo

		//demo end
		glColor3f(1, 1, 1);
		glVertex2f(-0.84, 0.50);
		glVertex2f(0.78, 0.50);
		glVertex2f(0.78, 0.50);
		glVertex2f(0.78, -0.18);
		glVertex2f(0.78, -0.18);
		glVertex2f(-0.84, -0.18);
		glVertex2f(-0.84, -0.18);
		glVertex2f(-0.84, 0.50);

		glEnd();
	}
	if (name_entered == true && demo_button == false && level_choice == true)
	{
		inserttwo("LEVEL: ", 500, 550, 1, 1, 1);
		glutPostRedisplay();
	}
	if (name_entered == true && level_choice == true && demo_button == false && levelname == " Easy")
	{
		inserttwo(levelname, 535, 550, 0, 1, 0);
		finaltime = 90;
		//timeclick = true;
		insert(time, 500, 530, 0, 1, 1);
		glutPostRedisplay();
	}
	glutPostRedisplay();
	if (name_entered == true && level_choice == true && demo_button == false && levelname == " Medium")
	{
		inserttwo(levelname, 535, 550, 1, 1, 0);
		finaltime = 60;
		insert(time, 500, 530, 0, 1, 1);
	//	timeclick = true;
		glutPostRedisplay();
	}
	if (demo_button == true)
	{
		insert("Click on each horse under the arrow.", 220, 150, 1, 1, 1);
	}
	if (name_entered == true && level_choice == true && demo_button == false && levelname == " Hard")
	{
		inserttwo(levelname, 535, 550, 1, 0, 0);
		finaltime = 20;
		insert(time, 500, 530, 0, 1, 1);
		timeclick = true;
		glutPostRedisplay();
	}

	if (name_entered == true && level_choice == false)
	{
		inserttwo("CHOOSE YOUR LEVEL:", 250, 400, 1, 1, 1);
		insert("(Left-click on your option)", 250, 380, 112, 128, 144);
		insertthree("EASY", 292, 340, 0, 0, 0);
		insertthree("MEDIUM", 289, 250, 0, 0, 0);
		insertthree("HARD", 292, 160, 0, 0, 0);
		glutPostRedisplay();
	}

	if (level_choice == true)
	{
		string button_restart = "Restart";
		string button_level = "Level";
		string button_demo = "Demo";
		string button_exit = "Exit";
		insertthree(button_restart, 50, 30, 0, 0, 0);
		insertthree(button_level, 102, 30, 0, 0, 0);
		insertthree(button_demo, 152, 30, 0, 0, 0);
		insertthree(button_exit, 200, 30, 0, 0, 0);
		insertthree("Reset", 246, 30, 0, 0, 0);
	}


	if (name_entered == false) {
		insert("WELCOME TO JUMPING HORSES", 220, 390, 15, 34, 0);
		inserttwo("ENTER PLAYER NAME: ", 210, 320, 1, 1, 1);
		insert(user_name, 215, 295, 1, 1, 1);
	}

	if (name_entered == true)
	{
		insert("Welcome, " + user_name, 50, 550, 1, 1, 1);
	}

	if (reset_button == true)
	{
		demoadder = 0;
		position[0] = 0;
		position[1] = 1;
		position[2] = 2;
		position[3] = 3;
		position[4] = -99;
		position[5] = 4;
		position[6] = 5;
		position[7] = 6;
		position[8] = 7;
		
		for (int i = 0; i < 8; i++)
		{

		click[i] = 0;
	
		}

		demo_button = false;
		user_won = false;
		user_lost = false;
		sounduser = 1;
		sounduser2 = 1;
		sounduser3 = 1;
		timeclick = false;
		reset_button = false;
	}
	
	////next demo button begin
	if (demo_button == true)
	{
	//	glBegin(GL_POLYGON);
	//	glColor3f(220, 220, 220);
	//	glVertex2f(0.52 + 0.25, -0.86); //a
	//	glVertex2f(0.52 + 0.25, -0.94); //b

	//	glVertex2f(0.52 + 0.25, -0.94); //b
	//	glVertex2f(0.42 + 0.25, -0.94); //c

	//	glVertex2f(0.42 + 0.25, -0.94); //c
	//	glVertex2f(0.42 + 0.25, -0.86); //d

	//	glVertex2f(0.42 + 0.25, -0.86); //d
	//	glVertex2f(0.52 + 0.25, -0.86); //a
	//	//end demo button
	//	glEnd();
	//	insertthree("Next", 508, 30, 0, 1, 1);


	//	//next demo button end

		if (reset_button == true)
		{
			demoadder = 0;
		}

		if (demoadder == 1)
		{
			arrowx = 0.162 * 2;
			glutPostRedisplay();
		}
		if (demoadder == 2)
		{
			arrowx = 0.162 * 3;
			glutPostRedisplay();
		}
		if (demoadder == 3)
		{
			arrowx = 0.162;
			glutPostRedisplay();
		}
		if (demoadder == 4)
		{
			arrowx = 0.162*-1;
			glutPostRedisplay();
		}
		if (demoadder == 5)
		{
			arrowx = 0.162*-2;
			glutPostRedisplay();
		}
		if (demoadder == 6)
		{
			arrowx = 0.162 * 0;
			glutPostRedisplay();
		}
		if (demoadder == 7)
		{
			arrowx = 0.162 * 2;
			glutPostRedisplay();
		}
		if (demoadder == 8)
		{
			arrowx = 0.162 * 4;
			glutPostRedisplay();
		}
		if (demoadder == 9)
		{
			arrowx = 0.162 * 5;
			glutPostRedisplay();
		}
		if (demoadder == 10)
		{
			arrowx = 0.162 * 3;
			glutPostRedisplay();
		}
		if (demoadder == 11)
		{
			arrowx = 0.162 * 1;
			glutPostRedisplay();
		}
		if (demoadder == 12)
		{
			arrowx = 0.162 * -1;
			glutPostRedisplay();
		}
		if (demoadder == 13)
		{
			arrowx = 0.162 * -3;
			glutPostRedisplay();
		}
		if (demoadder == 14)
		{
			arrowx = 0.162*-2;
			glutPostRedisplay();
		}
		if (demoadder == 15)
		{
			arrowx = 0;
			glutPostRedisplay();
		}
		if (demoadder == 16)
		{
			arrowx = 0.162 * 2;
			glutPostRedisplay();
		}
		if (demoadder == 17)
		{
			arrowx = 0.162 * 4;
			glutPostRedisplay();
		}
		if (demoadder == 18)
		{
			arrowx = 0.162 * 3;
			glutPostRedisplay();
		}
		if (demoadder == 19)
		{
			arrowx = 0.162 * 1;
			glutPostRedisplay();
		}
		if (demoadder == 20)
		{
			arrowx = 0.162 * -1;
			glutPostRedisplay();
		}
		if (demoadder == 21)
		{
			arrowx = 0.162 * 0;
			glutPostRedisplay();
		}
		if (demoadder == 22)
		{
			arrowx = 0.162 * 2;
			glutPostRedisplay();
		}
		if (demoadder == 23)
		{
			arrowx = 0.162 * 1;
			glutPostRedisplay();
			
		}
	}


	if (demo_button == true)
		{
	
		glBegin(GL_LINES);
		glVertex2d(-0.194+arrowx, 0.45);
		glVertex2d(-0.194+arrowx, 0.35);
		glVertex2d(-0.194 + arrowx, 0.35);
		glVertex2d(-0.2+arrowx,0.37);
		glVertex2d(-0.194 + arrowx, 0.35);
		glVertex2d(-0.188 + arrowx, 0.37);
		glutPostRedisplay();
		glEnd();
		}


	if (add1 == true)
	{
		click[pointer] = click[pointer] + 120;
		add1 = false;
	}
	if (add2 == true)
	{
		click[pointer] = click[pointer] + 240;
		add2 = false;
	}
	if (min1 == true)
	{
		click[pointer] = click[pointer]  -120;
		min1 = false;
	}
	if (min2 == true)
	{
		click[pointer] = click[pointer] - 240;
		min2 = false;
	}
	
	if (name_entered == true && level_choice == true)
	{
		if ((position[1] == 0 && position[2] == 1 )|| (position[6]==6&&position[7]==7)||position[2]==4&&position[3]==5 || position[3] == 4 && position[4] == 5||position[5]==5&&position[6]==7&&position[7]==6||position[1]==1&&position[2]==0&&position[3]==2||position[0]==0&&position[1]==1&&position[2]==4&&position[3]==-99||position[1]==0&&position[2]==1&&position[3]==4)
		{
			user_lost = true;
		}
	}

	if (name_entered == true && level_choice == true)
	{
		if (position[0] == 4 && position[1] == 5 && position[2] == 6 && position[3] == 7 && position[5] == 0 && position[6] == 1 && position[7] == 2 && position[8] == 3 )
		{
			user_won = true;
		}
	}
	if (name_entered == true && level_choice == true&&user_won==true&&demo_button==false)
	{
		inserttwo("! ! ! Y O U   W O N ! ! !",250,500,0,1,0);

	drawstarleft();
	}

	if (name_entered == true && level_choice == true && user_lost == true && demo_button == false)
	{
		inserttwo("! ! ! G A M E  O V E R ! ! !", 240, 500, 1, 0, 0);
	}
	
	

	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
	//glEnd();


	

//	glPushMatrix();

  



	if (sounduser ==1&&name_entered==false) {
	PlaySound(TEXT("welcome1.wav"), NULL, SND_ASYNC);
		sounduser ++;
		
	}
	if (sounduser2 == 1 && user_won == true&&demo_button==false) {
		PlaySound(TEXT("youwon.wav"), NULL, SND_ASYNC);
		sounduser2++;

	}
	if (sounduser3 == 1 && user_lost == true && demo_button == false) {
		PlaySound(TEXT("gameover.wav"), NULL, SND_ASYNC);
		sounduser3++;

	}
	
}

void onMouseButton(int button, int state, int  x, int y)
{    //detection

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		cout << "Left Button is clicked, x: " << x << " y: " << y << endl;
		glutPostRedisplay();
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) //glut down : 
	{
		cout << "Right Button is clicked, x: " << x << " y: " << y << endl;
		glutPostRedisplay();
	}
	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		cout << "Middle Button is clicked, x: " << x << " y: " << y << endl;

		glutPostRedisplay();
	}


	//easy button detection begin
	if (name_entered == true && level_choice == false && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x > 600 && x < 900) && (y > 309 && y < 345))
	{
		cout << "easy" << endl;
		level_choice = true;
		levelname = " Easy";
	}
	//easy button detection end

	//medium button detection begin
	if (name_entered == true && level_choice == false && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x > 600 && x < 900) && (y > 426 && y < 459))
	{
		cout << "med" << endl;
		level_choice = true;
		levelname = " Medium";
	}
	//medium button detection end

	//hard button detection begin
	if (name_entered == true && level_choice == false && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x > 600 && x < 900) && (y > 542 && y < 576))
	{
		cout << "hard" << endl;
		level_choice = true;
		levelname = " Hard";
	}
	//hard button detection end

	int i = 0;

	if (name_entered == true && level_choice == true && pointer == 1 || pointer == 2 || pointer == 3 || pointer == 4)
	{
	//	ti
	}

	//horse 0 detection
	if (name_entered == true && level_choice == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x > 190+click[0] && x < 286+ click[0]) && (y > 270 && y < 357))
	{
		pointer = 0;
		checkhorse();
	

		cout << "horse 0";
		glutPostRedisplay();
	}
	//horse 0 detection end

	//horse 1 detection
	if (name_entered == true && level_choice == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x > 310+ click[1] && x < 410+click[1]) && (y > 270 && y < 357))
	{
		
		cout << "horse 1" << endl;
		pointer = 1;
		checkhorse();
		
		glutPostRedisplay();
	}
	//horse 1 detection end

		//horse 2 detection
	if (name_entered == true && level_choice == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x >430 + click[2] && x<530+click[2]) && (y > 270 && y < 357))
	{
		timeclick = true;
		cout << "horse 2" << endl;
		pointer = 2;
		checkhorse();
	
		glutPostRedisplay();
	}

	//horse 2 detection end

		//horse 3 detection
	if (name_entered == true && level_choice == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x > 551 + click[3] && x < 651+click[3]) && (y > 270 && y < 357))
	{
		timeclick = true;
		cout << "horse 3" << endl;
		pointer = 3;
		checkhorse();
		
		glutPostRedisplay();
	}

	//horse 3 detection end
	//blank space detection begin



	//blank space detection end

	//horse 4 detection begin

	if (name_entered == true && level_choice == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x > 805 + click[4] && x < 905 + click[4]) && (y > 270 && y < 357))
	{
		timeclick = true;
		pointer = 4;
		checkhorse();
		cout << "horse 4" << endl;
		
		glutPostRedisplay();
	}
	//horse 4 detection end

	//horse 5 detection begin
	if (name_entered == true && level_choice == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x >925 + click[5] && x < 1026 + click[5]) && (y > 270 && y < 357))
	{
		timeclick = true;
		pointer = 5;
		checkhorse();
		cout << "horse 5" << endl;
	
		glutPostRedisplay();
	}
	//horse 5 detection end*/
	//horse 6 detection
	if (name_entered == true && level_choice == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x > 1047 + click[6] && x < 1147 + click[6]) && (y > 270 && y < 357))
	{
		pointer = 6;
		checkhorse();
		cout << "horse 6" << endl;
	
		glutPostRedisplay();
	}
	//horse 6 detection end


	//horse 7 detection
	if (name_entered == true && level_choice == true && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (x > 1170+click[7] && x < 1270 + click[7]) && (y > 270 && y < 357))
	{
		pointer = 7;
	checkhorse();
	
		cout << "horse 7" << endl;
		
		glutPostRedisplay();
	}
	//horse 7 detection end

	//horse detection end

	//end button begin
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && level_choice == true  && (x > 479 && x < 552) && (y > 717 && y < 748))
	{
		exit(0);
		glutPostRedisplay();
	}
	//end button end
	//restart button begin
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && level_choice == true && demo_button==false && (x > 121 && x < 195) && (y > 715 && y < 748))
	{
		restart_button = true;
	}
	//restart button end

	//begin level detection button
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && level_choice == true && demo_button == false && (x > 240 && x < 314) && (y > 715 && y < 748))
	{
		level_button = true;
	}
	//end level detection button

		//begin reset detection button
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && level_choice == true  && (x > 600 && x < 675) && (y > 715 && y < 748))
	{
		reset_button = true;
		
	}
	//end reset detection button

	//begin demo detection button
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && level_choice == true && (x > 359 && x < 434) && (y > 715 && y < 748))
	{
		demo_button = true;
	}
	//end demo detection button

	//beginnext demo adder
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && level_choice == true && (x > 1251 && x < 1326) && (y > 715 && y < 748))
	{
		//demoadder ++;
	}
	//end next demo adder

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && level_choice == true && demo_button == true && (x > 190 && x < 1270) && (y > 270 && y < 357))
	{
		demoadder++;
	}
}


int main(int argc, char** argv)
{
	glutTimerFunc(1000,game_timer,0);
	glutInit(&argc, argv);
	glutInitWindowSize(1500, 770);
	glutInitWindowPosition(250, 250);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Horses Jumping");
	glutDisplayFunc(display);
	glutMouseFunc(onMouseButton); //mouse detection
	//glutTimerFunc(textbar);
	//glutPassiveMotionFunc(glutPassiveMotionFunc);
	//glutTimerFunc(1000.0 / 60.0, timer, 0);
	glutKeyboardFunc(type_your_name);
	glutMainLoop();
	return (0);
}

