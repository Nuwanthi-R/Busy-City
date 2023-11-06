#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 10.0                  //speed of traffic
float i=0.0;                        //movement of car
float c=0.0;                        //movement of clouds
float n=0.0;                        //movement of plane along x-axis
float o=0.0;                        //  and y-axis
int light=1;                        //1 for green-light, 0 for red-light
int day=1;                          //1 for day ,0 for night
int plane=0;                        //1 for plane

void draw_point(GLint p, GLint q)
{
	glBegin(GL_POINTS);
		glVertex2i(p,q);
	glEnd();
}
void render_points(GLint b,GLint a, GLint x,GLint y)
{
	draw_point(x+b,y+a);
	draw_point(-x+b,y+a);
	draw_point(x+b,-y+a);
	draw_point(-x+b,-y+a);
	draw_point(y+b,x+a);
	draw_point(-y+b,x+a);
	draw_point(y+b,-x+a);
	draw_point(-y+b,-x+a);
}
void draw_circle(GLint b, GLint a, GLint r)
{
	GLint p=1-r, x=0, y=r;
	while(y>x)
	{
		render_points(b,a,x,y);
		if(p<0) p+=2*x+3;
		else
		{
			p+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	render_points(b,a,x,y);
}
void draw_element()
{
int j;
if(day==1)
{
                                    //sky
glColor3f(0.5,0.8,0.9);
glBegin(GL_POLYGON);
    glVertex2f(0,400);
    glVertex2f(0,700);
    glVertex2f(1100,700);
    glVertex2f(1100,400);
glEnd();
                                    //sun
	for(j=0;j<=40;j++)
{
		glColor3f(1.0,0.4,0.1);
		draw_circle(100,625,j);
}
                                    //plane
if(plane==1)
{
glColor3f(0.8,0.6,0.0);
glBegin(GL_POLYGON);
	glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
	glVertex2f(1015+n,640+o);
	glVertex2f(1030+n,650+o);
	glVertex2f(1050+n,650+o);
	glVertex2f(1010+n,625+o);
glEnd();

}                                    //cloud1
	for(j=0;j<=15;j++)
	{
        glColor3f(0.9,0.9,0.9);
		draw_circle(170+c,660,j);
		draw_circle(275+c,660,j);
	}
	for(j=0;j<=30;j++)
	{
        glColor3f(0.9,0.9,0.9);
		draw_circle(210+c,660,j);
		draw_circle(235+c,660,j);
	}
	                             //cloud2
	for(j=0;j<=20;j++)
	{
        glColor3f(0.9,0.9,0.9);
		draw_circle(390+c,625,j);
		draw_circle(520+c,625,j);
}
	for(j=0;j<=35;j++)
	{

        glColor3f(0.9,0.9,0.9);
		draw_circle(430+c,625,j);
		draw_circle(455+c,625,j);
		draw_circle(490+c,625,j);
	}


                            //cloud 03
for(j=0;j<=15;j++)
	{
        glColor3f(0.9,0.9,0.9);
		draw_circle(700+c,660,j);
		draw_circle(805+c,660,j);
	}
	for(j=0;j<=30;j++)
	{
        glColor3f(0.9,0.9,0.9);
		draw_circle(740+c,660,j);
		draw_circle(765+c,660,j);
	}
                                    //grass
glColor3f(0.4,0.6,0.1);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,400);
glVertex2f(1100,400);
glVertex2f(1100,160);
glEnd();


}
else
{                                    // night sky
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,400);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,400);
glEnd();
    //moon
int j;
	for(j=0;j<=40;j++)
	{
		glColor3f(1.0,1.0,0.0);
		draw_circle(100,625,j);
	}

//star2
glColor3f(1.0,1.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2f(977,645);
glVertex2f(972,637);
glVertex2f(982,637);
glVertex2f(977,634);
glVertex2f(972,642);
glVertex2f(982,642);
glEnd();
                                    //star3
glColor3f(1.0,1.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2f(870,543);
glVertex2f(865,535);
glVertex2f(875,535);
glVertex2f(870,532);
glVertex2f(865,540);
glVertex2f(875,540);
glEnd();
                                    //star4
glColor3f(1.0,1.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2f(375,598);
glVertex2f(370,590);
glVertex2f(380,590);
glVertex2f(375,587);
glVertex2f(370,595);
glVertex2f(380,595);
glEnd();
                                    //star5
glColor3f(1.0,1.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2f(750,628);
glVertex2f(745,620);
glVertex2f(755,620);
glVertex2f(750,618);
glVertex2f(745,625);
glVertex2f(755,625);
glEnd();

                                    //star7
glColor3f(1.0,1.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2f(490,543);
glVertex2f(485,535);
glVertex2f(495,535);
glVertex2f(490,532);
glVertex2f(485,540);
glVertex2f(495,540);
glEnd();
                                //Plane
if(plane==1)
{
glColor3f(0.8,0.2,0.0);
glBegin(GL_POLYGON);
	glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
	glVertex2f(1015+n,640+o);
	glVertex2f(1030+n,650+o);
	glVertex2f(1050+n,650+o);
	glVertex2f(1010+n,625+o);
glEnd();
}


                                  //grass
glColor3f(0.0,0.3,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,400);
glVertex2f(1100,400);
glVertex2f(1100,160);
glEnd();
}
}


void draw_road(){                                    //road
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();

//Road boundry
 int X1=0,X2=40;
    for(int i=0;i<30;i++){
        glBegin(GL_POLYGON);
        if(i%2==1){
            glColor3f(0,0,0);  //black color
        }else{
            glColor3f(1, 1, 1);  //white color
        }
        glVertex2f(X1,150);
        glVertex2f(X2,150);
        glVertex2f(X2,170);
        glVertex2f(X1,170);
        X1=X2;
        X2=X2+40;
        glEnd();
    }}
void draw_trees(){
//Tree 1
glColor3f(0.4f, 0.2f, 0.0f); // Brown color

// Tree trunk (rectangle)
glBegin(GL_POLYGON);
glVertex2f(50.0f, 260.0f);
glVertex2f(50.0f, 350.0f);
glVertex2f(70.0f, 350.0f);
glVertex2f(70.0f, 260.0f);
glEnd();

glColor3f(0.0, 0.4f, 0.0f); // Green color

// Tree foliage (triangle-based)
glBegin(GL_TRIANGLES);
glVertex2f(30.0f, 320.0f);
glVertex2f(100.0f, 320.0f);
glVertex2f(60.0f, 420.0f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(60.0f, 450.0f);
glVertex2f(30.0f, 370.0f);
glVertex2f(100.0f, 370.0f);
glEnd();

//Tree 2
glColor3f(0.4f, 0.2f, 0.0f); // Brown color

// Tree trunk (rectangle)
glBegin(GL_POLYGON);
glVertex2f(350.0f, 250.0f);
glVertex2f(350.0f, 350.0f);
glVertex2f(370.0f, 350.0f);
glVertex2f(370.0f, 250.0f);
glEnd();

glColor3f(0.0, 0.4f, 0.0f); // Green color

// Tree foliage (triangle-based)
glBegin(GL_TRIANGLES);
glVertex2f(330.0f, 300.0f);
glVertex2f(400.0f, 300.0f);
glVertex2f(360.0f, 400.0f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(360.0f, 430.0f);
glVertex2f(330.0f, 350.0f);
glVertex2f(400.0f, 350.0f);
glEnd();

//Tree 3
glColor3f(0.4f, 0.2f, 0.0f); // Brown color

// Tree trunk (rectangle)
glBegin(GL_POLYGON);
glVertex2f(950.0f, 210.0f);
glVertex2f(950.0f, 280.0f);
glVertex2f(970.0f, 280.0f);
glVertex2f(970.0f, 210.0f);
glEnd();

glColor3f(0.0, 0.4f, 0.0f); // Green color

// Tree foliage (triangle-based)
glBegin(GL_TRIANGLES);
glVertex2f(930.0f, 280.0f);
glVertex2f(1000.0f, 280.0f);
glVertex2f(960.0f, 370.0f);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2f(960.0f, 410.0f);
glVertex2f(930.0f, 320.0f);
glVertex2f(1000.0f, 320.0f);
glEnd();
}
void draw_buildings() {

// Draw the building


  // building 0
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.4, 0.2);  //  orange color
    glVertex2f(0, 400 );
    glVertex2f(0,550);
    glVertex2f(28,550);
    glVertex2f(28,400);
    glEnd();

// window 1
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(5, 420 );
    glVertex2f(5,470);
    glVertex2f(23,470);
    glVertex2f(23,420);
    glEnd();


// window 2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(5, 475 );
    glVertex2f(5,530);
    glVertex2f(23,530);
    glVertex2f(23,475);
    glEnd();

  // building 1
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.0, 0.0);  // Maroon color
    glVertex2f(150, 490 );
    glVertex2f(150,220);
    glVertex2f(280,220);
    glVertex2f(280,490);
    glEnd();

     // window 1
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(170, 240 );
    glVertex2f(170,290);
    glVertex2f(205,290);
    glVertex2f(205,240);
    glEnd();

      // window 2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(170, 300 );
    glVertex2f(170,350);
    glVertex2f(205,350);
    glVertex2f(205,300);
    glEnd();

        // window 3
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(170, 360 );
    glVertex2f(170,410);
    glVertex2f(205,410);
    glVertex2f(205,360);
    glEnd();

          // window 4
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(170, 420 );
    glVertex2f(170,470);
    glVertex2f(205,470);
    glVertex2f(205,420);
    glEnd();

             // window 5
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(225, 420 );
    glVertex2f(225,470);
    glVertex2f(260,470);
    glVertex2f(260,420);
    glEnd();

           // window 6
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(225, 360 );
    glVertex2f(225,410);
    glVertex2f(260,410);
    glVertex2f(260,360);
    glEnd();

       // window 7
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(225, 300 );
    glVertex2f(225,350);
    glVertex2f(260,350);
    glVertex2f(260,300);
    glEnd();

        // window 8
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(225, 240 );
    glVertex2f(225,290);
    glVertex2f(260,290);
    glVertex2f(260,240);
    glEnd();


  // building 2
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.0, 0.5);  // purple color
    glVertex2f(495, 500 );
    glVertex2f(495,380);
    glVertex2f(400,380);
    glVertex2f(400,500);
    glEnd();

    //windows 1
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(410,460);
    glVertex2f(410,480);
    glVertex2f(485,480);
    glVertex2f(485,460);
    glEnd();


    //windows 2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(410,420);
    glVertex2f(410,450);
    glVertex2f(485,450);
    glVertex2f(485,420);
    glEnd();


    //windows 3
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(410, 390 );
    glVertex2f(410,410);
    glVertex2f(485,410);
    glVertex2f(485,390);
    glEnd();

     // building 3
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.0, 0.5);  // purple color
    glVertex2f(500, 550 );
    glVertex2f(500,300);
    glVertex2f(700,300);
    glVertex2f(700,550);
    glEnd();

       // windows 1
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(520, 330 );
    glVertex2f(520,360);
    glVertex2f(590,360);
    glVertex2f(590,330);
    glEnd();

        // windows 2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(520, 380 );
    glVertex2f(520,410);
    glVertex2f(590,410);
    glVertex2f(590,380);
    glEnd();

        // windows 3
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(520, 430 );
    glVertex2f(520,460);
    glVertex2f(590,460);
    glVertex2f(590,430);
    glEnd();

        // windows 4
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(520, 480 );
    glVertex2f(520,510);
    glVertex2f(590,510);
    glVertex2f(590,480);
    glEnd();


      // windows 5
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(610, 480 );
    glVertex2f(610,510);
    glVertex2f(680,510);
    glVertex2f(680,480);
    glEnd();

        // windows 6
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(610, 430 );
    glVertex2f(610,460);
    glVertex2f(680,460);
    glVertex2f(680,430);
    glEnd();

        // windows 7
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(610, 380 );
    glVertex2f(610,410);
    glVertex2f(680,410);
    glVertex2f(680,380);
    glEnd();

        // windows 8
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);  // black color
    glVertex2f(610, 330 );
    glVertex2f(610,360);
    glVertex2f(680,360);
    glVertex2f(680,330);
    glEnd();

     // building 4
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.2, 0.4);  // pink color
    glVertex2f(900,450 );
    glVertex2f(900,220);
    glVertex2f(800,220);
    glVertex2f(800,450);
    glEnd();

     //window 1
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(820,250 );
    glVertex2f(820,290);
    glVertex2f(880,290);
    glVertex2f(880,250);
    glEnd();

      //window 2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(820,300 );
    glVertex2f(820,360);
    glVertex2f(880,360);
    glVertex2f(880,300);
    glEnd();

      //window 3
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(820,370 );
    glVertex2f(820,420);
    glVertex2f(880,420);
    glVertex2f(880,370);
    glEnd();

 // building 5
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.6);  // dark blue color
    glVertex2f(1000,590 );
    glVertex2f(1000,340);
    glVertex2f(1100,340);
    glVertex2f(1100,590);
    glEnd();

    //window 1
    glColor3f(0.0, 0.0, 0.0);  // black color
    glBegin(GL_QUADS);
    glVertex2f(1020,360 );
    glVertex2f(1020,410);
    glVertex2f(1080,410);
    glVertex2f(1080,360);
    glEnd();

        //window 2
    glColor3f(0.0, 0.0, 0.0);  // black color
    glBegin(GL_QUADS);
    glVertex2f(1020,420 );
    glVertex2f(1020,470);
    glVertex2f(1080,470);
    glVertex2f(1080,420);
    glEnd();

        //window 3
    glColor3f(0.0, 0.0, 0.0);  // black color
    glBegin(GL_QUADS);
    glVertex2f(1020,480 );
    glVertex2f(1020,530);
    glVertex2f(1080,530);
    glVertex2f(1080,480);
    glEnd();

        //window 4
    glColor3f(0.0, 0.0, 0.0);  // black color
    glBegin(GL_QUADS);
    glVertex2f(1020,540 );
    glVertex2f(1020,570);
    glVertex2f(1080,570);
    glVertex2f(1080,540);
    glEnd();
}

    //signal
     void draw_signal(){
      int l;
	glColor3f(0.4,0.2,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,170);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,170);
	glEnd();
	glColor3f(0.4,0.2,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();
	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
	}}

	void draw_vechicles(){
    int l;

// car 2

glColor3f(0.0f, 0.2f, 0.4f);
glBegin(GL_POLYGON);
glVertex2f(30.0f + i, 60.0f);
glVertex2f(30.0f + i, 180.0f);
glVertex2f(200.0f + i, 180.0f);
glVertex2f(250.0f + i, 130.0f);
glVertex2f(270.0f + i, 130.0f);
glVertex2f(270.0f + i, 60.0f);
glEnd();


// windows
glColor3f(0.1f, 0.1f, 0.1f);
glBegin(GL_POLYGON);
glVertex2f(50.0f + i, 130.0f);
glVertex2f(50.0f + i, 165.0f);
glVertex2f(130.0f + i, 165.0f);
glVertex2f(130.0f + i, 130.0f);
glEnd();

glColor3f(0.1f, 0.1f, 0.1f);
glBegin(GL_POLYGON);
glVertex2f(140.0f + i, 130.0f);
glVertex2f(140.0f + i, 165.0f);
glVertex2f(200.0f + i, 165.0f);
glVertex2f(230.0f + i, 130.0f);
glEnd();

for (l = 0; l < 20; l++) {
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle(70.0f + i, 60.0f,l);
    draw_circle(200.0f + i, 60.0f, l);
}
                                    //car3
glColor3f(0.4f, 0.0f, 0.2f);
glBegin(GL_POLYGON);
glVertex2f(-480.0f + i, 60.0f);
glVertex2f(-480.0f + i, 120.0f);
glVertex2f(-430.0f + i, 120.0f);
glVertex2f(-405.0f + i, 190.0f);
glVertex2f(-195.0f + i, 190.0f);
glVertex2f(-170.0f + i, 120.0f);
glVertex2f(-125.0f + i, 120.0f);
glVertex2f(-125.0f + i, 60.0f);
glEnd();

// Car windows
glColor3f(0.1f, 0.1f, 0.1f);
glBegin(GL_POLYGON);
glVertex2f(-410.0f + i, 120.0f);
glVertex2f(-390.0f + i, 170.0f);
glVertex2f(-310.0f + i, 170.0f);
glVertex2f(-310.0f + i, 120.0f);
glEnd();

glColor3f(0.1f, 0.1f, 0.1f);
glBegin(GL_POLYGON);
glVertex2f(-300.0f + i, 120.0f);
glVertex2f(-300.0f + i, 170.0f);
glVertex2f(-220.0f + i, 170.0f);
glVertex2f(-200.0f + i, 120.0f);
glEnd();

for (l = 0; l < 30; l++) {
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle(-375.0f + i, 60.0f, l);
    draw_circle(-220.0f + i, 60.0f, l);
}

   //car 1
glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_POLYGON);
glVertex2f(320.0f + i, 50.0f);
glVertex2f(320.0f + i, 220.0f);
glVertex2f(700.0f + i, 220.0f);
glVertex2f(700.0f + i, 50.0f);
glEnd();

// Car windows
glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(600.0f + i, 120.0f);
glVertex2f(600.0f + i, 190.0f);
glVertex2f(690.0f + i, 190.0f);
glVertex2f(690.0f + i, 120.0f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(500.0f + i, 120.0f);
glVertex2f(500.0f + i, 190.0f);
glVertex2f(575.0f + i, 190.0f);
glVertex2f(575.0f + i, 120.0f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(400.0f + i, 120.0f);
glVertex2f(400.0f + i, 190.0f);
glVertex2f(475.0f + i, 190.0f);
glVertex2f(475.0f + i, 120.0f);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_POLYGON);
glVertex2f(325.0f + i, 120.0f);
glVertex2f(325.0f + i, 190.0f);
glVertex2f(375.0f + i, 190.0f);
glVertex2f(375.0f + i, 120.0f);
glEnd();
//car wheels
for (l = 0; l < 30; l++) {
    glColor3f(0.0f, 0.0f, 0.0f);
    draw_circle(400.0f + i, 50.0f, l);
    draw_circle(585.0f + i, 50.0f, l);
}
glFlush();

}


//traffic light
void traffic_light()
{
	int l;
    if(light==1){
        for(l=0;l<=20;l++)
		{
            glColor3f(0.0,0.0,0.0);
            draw_circle(1065,475,l);
            glColor3f(0.0,0.7,0.0);
            draw_circle(1065,375,l);
		}
    }
	else{
        for(l=0;l<=20;l++)
		{
            glColor3f(1.0,0.0,0.0);
            draw_circle(1065,475,l);
            glColor3f(0.0,0.0,0.0);
            draw_circle(1065,375,l);
		}
    }
}
void idle()
{
glClearColor(1.0,1.0,1.0,1.0);
if(light==0 && (i>=330 && i<=750))  //value of i when first vehicle is near the traffic-signal
 {
	 i+=SPEED/10;
      c+=0.2;
	n-=2;
	 o+=0.2;

 }
if(light==0 && (i>=830 && i<=1100)) //value of i when second vehicle is near the traffic-signal
 {
	 i+=SPEED/10;
     c+=0.2;
	n-=2;
	 o+=0.2;

 }
if(light==0 && (i>=1200 && i<=1620))// value of i when third vehicle is near the traffic signal
 {
	 i+=SPEED/10;
     c+=0.2;
	n-=2;
	 o+=0.2;

 }
if(light==0)
 {
	 i=i;
	  c+=0.2;
	n-=2;
	 o+=0.2;

 }
else
 {
     i+=SPEED/10;
  c+=0.2;
	n-=2;
	 o+=0.2;

 }
if(i>1630)
	 i=0.0;
if(c>1100)
	 c=0.0;
if( o>75)
 {
	plane=0;
 }

glutPostRedisplay();
}
void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'g':
case 'G':
light=1;
break;
	case 'r':
	case 'R':
		light=0;
		break;
case 'd':
	case 'D':
		day=1;
		break;
	case 'n':
case 'N':
		day=0;
		break;
    };
}
void main_menu(int index)
{
	switch(index)
	{
	case 1:
	if(index==1)
	 {
	plane=1;
		 o=n=0.0;
	 }
	break;

	case 2:
        if(index==2)
        {
            exit(0);
        }
    break;
	}
}

void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_element();

draw_road();
draw_trees();
draw_buildings();
draw_signal();
draw_vechicles();
traffic_light();
glFlush();
}
int main(int argc,char*argv[])
{
int c_menu;
    printf("\n");
    printf(" |=========================================================================|\n");
    printf(" |                       Busy City with Traffic Lights                     |\n");
    printf(" |=========================================================================|\n");
    printf(" |                                                                         |\n");
    printf(" |                                                                         |\n");
    printf(" |                             How to Operate                              |\n");
    printf(" |                                                                         |\n");
    printf(" |                                                                         |\n");
    printf(" |            |> Press RIGHT MOUSE BUTTON to display menu                  |\n");
	printf(" |            |> Select  'Aeroplane' to add moving Aeroplane               |\n");
	printf(" |            |> Select  'Quit' to Exit the application                    |\n");
	printf(" |                                                                         |\n");
	printf(" |                                                                         |\n");
	printf(" |            |> Press 'r' or 'R' to change the signal light to Red        |\n");
	printf(" |            |> Press 'g' or 'G' to change the signal light to Green      |\n");
	printf(" |            |> Press 'd' or 'D' to make it Day Time                      |\n");
	printf(" |            |> Press 'n' or 'N' to make it Night Time                    |\n");
	printf(" |                                                                         |\n");
    printf(" |-------------------------------------------------------------------------|\n");

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(250,0);
	glutCreateWindow("Busy City with Traffic Lights");
	myinit();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	c_menu=glutCreateMenu(main_menu);
	glutAddMenuEntry("Aeroplane",1);
	glutAddMenuEntry("Quit",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
