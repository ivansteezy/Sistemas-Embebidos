
#include "U8glib.h"

//The following line will need changing depending on your board type!
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_FAST); // Dev 0, Fast I2C / TWI

float tx, nx, p;
float ty, ny, py;
float rot, rotx, roty, rotz, rotxx, rotyy, rotzz, rotxxx, rotyyy, rotzzz;
int i; //0 to 360
int fl, scale; //focal length
int wireframe[12][2];

int originx = 64;
int originy = 32; //32

int front_depth = 20;
int back_depth = -20;

//Store cube vertices
int cube_vertex[8][3] = {
 { -20, -20, front_depth},
 {20, -20, front_depth},
 {20, 20, front_depth},
 { -20, 20, front_depth},
 { -20, -20, back_depth},
 {20, -20, back_depth},
 {20, 20, back_depth},
 { -20, 20, back_depth}
};

int fd = 0; //0=orthographic

void setup(void)
{
 u8g.begin();

//Clear Screen
 u8g.firstPage();
 do {
// empty screen
 } while ( u8g.nextPage() );
}

void draw_vertices(void)
{
 u8g.drawPixel (rotxxx, rotyyy);
}

void draw_wireframe(void)
{
 u8g.drawLine(wireframe[0][0], wireframe[0][1], wireframe[1][0], wireframe[1][1]);
 u8g.drawLine(wireframe[1][0], wireframe[1][1], wireframe[2][0], wireframe[2][1]);
 u8g.drawLine(wireframe[2][0], wireframe[2][1], wireframe[3][0], wireframe[3][1]);
 u8g.drawLine(wireframe[3][0], wireframe[3][1], wireframe[0][0], wireframe[0][1]);

//cross face above
 u8g.drawLine(wireframe[1][0], wireframe[1][1], wireframe[3][0], wireframe[3][1]);
 u8g.drawLine(wireframe[0][0], wireframe[0][1], wireframe[2][0], wireframe[2][1]);

  u8g.drawLine(wireframe[4][0], wireframe[4][1], wireframe[5][0], wireframe[5][1]);
 u8g.drawLine(wireframe[5][0], wireframe[5][1], wireframe[6][0], wireframe[6][1]);
 u8g.drawLine(wireframe[6][0], wireframe[6][1], wireframe[7][0], wireframe[7][1]);
 u8g.drawLine(wireframe[7][0], wireframe[7][1], wireframe[4][0], wireframe[4][1]);

  u8g.drawLine(wireframe[0][0], wireframe[0][1], wireframe[4][0], wireframe[4][1]);
 u8g.drawLine(wireframe[1][0], wireframe[1][1], wireframe[5][0], wireframe[5][1]);
 u8g.drawLine(wireframe[2][0], wireframe[2][1], wireframe[6][0], wireframe[6][1]);
 u8g.drawLine(wireframe[3][0], wireframe[3][1], wireframe[7][0], wireframe[7][1]);
}

void loop(void)
{
//picture loop
 for (int angle = 0; angle <= 360; angle = angle + 3) {
  u8g.firstPage();
  do {
   for (int i = 0; i < 8; i++) {

     rot = angle * 0.0174532; //0.0174532 = one degree
//rotateY
    rotz = cube_vertex[i][2] * cos(rot) - cube_vertex[i][0] * sin(rot);
    rotx = cube_vertex[i][2] * sin(rot) + cube_vertex[i][0] * cos(rot);
    roty = cube_vertex[i][1];
//rotateX
    rotyy = roty * cos(rot) - rotz * sin(rot);
    rotzz = roty * sin(rot) + rotz * cos(rot);
    rotxx = rotx;
//rotateZ
    rotxxx = rotxx * cos(rot) - rotyy * sin(rot);
    rotyyy = rotxx * sin(rot) + rotyy * cos(rot);
    rotzzz = rotzz;

//orthographic projection
    rotxxx = rotxxx + originx;
    rotyyy = rotyyy + originy;

//store new vertices values for wireframe drawing
    wireframe[i][0] = rotxxx;
    wireframe[i][1] = rotyyy;
    wireframe[i][2] = rotzzz;

     draw_vertices();
   }

    draw_wireframe();

   } while (u8g.nextPage());
 }
}
