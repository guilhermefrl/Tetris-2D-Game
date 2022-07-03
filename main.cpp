// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <thread>
#include <chrono>


// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;
#include <GL/freeglut.h>
// GLM header file
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

// shaders header file
//#include "common/shader.cpp"
#include "common/shader.cpp"

// Vertex array object (VAO)
GLuint VertexArrayID;
GLuint VertexArrayID3;
GLuint VertexArrayIDN;
GLuint VertexArrayIDN1;
GLuint VertexArrayIDN2;
GLuint VertexArrayIDN3;
GLuint VertexArrayIDN4;
GLuint VertexArrayIDN5;
GLuint VertexArrayIDN6;
GLuint VertexArrayIDN7;
GLuint VertexArrayIDN8;
GLuint VertexArrayIDN9;
GLuint VertexArrayIDPecaJ;
GLuint VertexArrayIDPecaVerde;
GLuint VertexArrayIDPecaAzul;
// Vertex buffer object (VBO)
GLuint vertexbuffer;
GLuint vertexbuffer3;
GLuint vertexbufferPecaJ;
GLuint vertexbufferPecaN;
GLuint vertexbufferPecaN1;
GLuint vertexbufferPecaN2;
GLuint vertexbufferPecaN3;
GLuint vertexbufferPecaN4;
GLuint vertexbufferPecaN5;
GLuint vertexbufferPecaN6;
GLuint vertexbufferPecaN7;
GLuint vertexbufferPecaN8;
GLuint vertexbufferPecaN9;
GLuint vertexbufferPecaVerde;
GLuint vertexbufferPecaAzul;

// color buffer object (CBO)
GLuint colorbuffer;
GLuint colorbuffer3;
GLuint colorbufferPecaJ;
GLuint colorbufferPecaN;
GLuint colorbufferPecaN1;
GLuint colorbufferPecaN2;
GLuint colorbufferPecaN3;
GLuint colorbufferPecaN4;
GLuint colorbufferPecaN5;
GLuint colorbufferPecaN6;
GLuint colorbufferPecaN7;
GLuint colorbufferPecaN8;
GLuint colorbufferPecaN9;
GLuint colorbufferPecaVerde;
GLuint colorbufferPecaAzul;

// GLSL program from the shaders
GLuint programID;


GLint WindowWidth = 780;
GLint WindowHeight = 780;

float delta = 0.0;
int tab[19][9];
int next1[6][6];
int rt;
int aux;
int tiponext = (rand() % 7) + 1;
int cores[100];
int win, val;
int pont = 0;
int dif = 0;

//--------------------------------------------------------------------------------
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void print(int nmr);
void transefereDataToGPUMemoryN(void) {
    glGenVertexArrays(1, &VertexArrayIDN);
    glBindVertexArray(VertexArrayIDN);

    programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

    static const GLfloat g_vertex_buffer_data_PecaN[] = {
        //Numero 0
        12.0f,0.0f,0.0f,
        12.0f,-5.0f,0.0f,
        13.0f,-5.0f,0.0f,
        12.0f,0.0f,0.0f,
        13.0f,-5.0f,0.0f,
        13.0f,0.0f,0.0f,

        12.0f,0.0f,0.0f,
        12.0f,-1.0f,0.0f,
        15.0f,0.0f,0.0f,
        12.0f,-1.0f,0.0f,
        15.0f,-1.0f,0.0f,
        15.0f,0.0f,0.0f,

        15.0f,0.0f,0.0f,
        14.0f,0.0f,0.0f,
        15.0f,-5.0f,0.0f,
        14.0f,0.0f,0.0f,
        14.0f,-5.0f,0.0f,
        15.0f,-5.0f,0.0f,

        12.0f,-5.0f,0.0f,
        13.0f,-4.0f,0.0f,
        15.0f,-5.0f,0.0f,
        12.0f,-4.0f,0.0f,
        15.0f,-4.0f,0.0f,
        15.0f,-5.0f,0.0f,


    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaN[] = {
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaN);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaN), g_vertex_buffer_data_PecaN, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaN);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaN), g_color_buffer_data_PecaN, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayIDN1);
    glBindVertexArray(VertexArrayIDN1);

    static const GLfloat g_vertex_buffer_data_PecaN1[] = {


        //Numero 1
        14.0f,0.0f,0.0f,
        15.0f,0.0f,0.0f,
        15.0f,-5.0f,0.0f,
        14.0f,0.0f,0.0f,
        14.0f,-5.0f,0.0f,
        15.0f,-5.0f,0.0f,

        13.0f,0.0f,0.0f,
        13.0f,-1.0f,0.0f,
        14.0f,0.0f,0.0f,
        13.0f,-1.0f,0.0f,
        14.0f,0.0f,0.0f,
        14.0f,-1.0f,0.0f,

    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaN1[] = {
        //Numero 1

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaN1);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaN1), g_vertex_buffer_data_PecaN1, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaN1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaN1), g_color_buffer_data_PecaN1, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayIDN2);
    glBindVertexArray(VertexArrayIDN2);

    static const GLfloat g_vertex_buffer_data_PecaN2[] = {



        //Numero 2

        12.0f,0.0f,0.0f,
        12.0f,-1.0f,0.0f,
        15.0f,0.0f,0.0f,
        12.0f,-1.0f,0.0f,
        15.0f,0.0f,0.0f,
        15.0f,-1.0f,0.0f,


        14.0f,-1.0f,0.0f,
        15.0f,-2.0f,0.0f,
        14.0f,-2.0f,0.0f,
        14.0f,-1.0f,0.0f,
        15.0f,-1.0f,0.0f,
        15.0f,-2.0f,0.0f,

        12.0f,-2.0f,0.0f,
        12.0f,-3.0f,0.0f,
        15.0f,-2.0f,0.0f,
        15.0f,-2.0f,0.0f,
        15.0f,-3.0f,0.0f,
        12.0f,-3.0f,0.0f,

        12.0f,-3.0f,0.0f,
        12.0f,-4.0f,0.0f,
        13.0f,-3.0f,0.0f,
        13.0f,-3.0f,0.0f,
        13.0f,-4.0f,0.0f,
        12.0f,-4.0f,0.0f,


        12.0f,-4.0f,0.0f,
        12.0f,-5.0f,0.0f,
        15.0f,-4.0f,0.0f,
        15.0f,-4.0f,0.0f,
        15.0f,-5.0f,0.0f,
        12.0f,-5.0f,0.0f,

    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaN2[] = {
        //Numero 1

       //Numero 2

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,

    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaN2);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaN2), g_vertex_buffer_data_PecaN2, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaN2);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaN2), g_color_buffer_data_PecaN2, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayIDN3);
    glBindVertexArray(VertexArrayIDN3);

    static const GLfloat g_vertex_buffer_data_PecaN3[] = {

        //Numero 3
        12.0f,0.0f,0.0f,
        12.0f,-1.0f,0.0f,
        15.0f,0.0f,0.0f,
        12.0f,-1.0f,0.0f,
        15.0f,0.0f,0.0f,
        15.0f,-1.0f,0.0f,


        14.0f,-1.0f,0.0f,
        15.0f,-2.0f,0.0f,
        14.0f,-2.0f,0.0f,
        14.0f,-1.0f,0.0f,
        15.0f,-1.0f,0.0f,
        15.0f,-2.0f,0.0f,

        12.0f,-2.0f,0.0f,
        12.0f,-3.0f,0.0f,
        15.0f,-2.0f,0.0f,
        15.0f,-2.0f,0.0f,
        15.0f,-3.0f,0.0f,
        12.0f,-3.0f,0.0f,

        14.0f,-3.0f,0.0f,
        14.0f,-4.0f,0.0f,
        15.0f,-3.0f,0.0f,
        15.0f,-3.0f,0.0f,
        15.0f,-4.0f,0.0f,
        14.0f,-4.0f,0.0f,


        12.0f,-4.0f,0.0f,
        12.0f,-5.0f,0.0f,
        15.0f,-4.0f,0.0f,
        15.0f,-4.0f,0.0f,
        15.0f,-5.0f,0.0f,
        12.0f,-5.0f,0.0f,
    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaN3[] = {
        //Numero 3

       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,

       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,

       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,

       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,

       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,
       1.0f,  0.0f,  0.0f,

    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaN3);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaN3), g_vertex_buffer_data_PecaN3, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaN3);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaN3), g_color_buffer_data_PecaN3, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayIDN4);
    glBindVertexArray(VertexArrayIDN4);

    static const GLfloat g_vertex_buffer_data_PecaN4[] = {
        //Numero 4

         12.0f,0.0f,0.0f,
         12.0f,-2.0f,0.0f,
         13.0f,0.0f,0.0f,
         13.0f,0.0f,0.0f,
         13.0f,-2.0f,0.0f,
         12.0f,-2.0f,0.0f,

         14.0f, 0.0f, 0.0f,
         14.0f, -5.0f, 0.0f,
         15.0f, 0.0f, 0.0f,
         15.0f, 0.0f, 0.0f,
         15.0f, -5.0f, 0.0f,
         14.0f, -5.0f, 0.0f,

         12.0f,-2.0f,0.0f,
         12.0f,-3.0f,0.0f,
         15.0f,-2.0f,0.0f,
         15.0f,-2.0f,0.0f,
         15.0f,-3.0f,0.0f,
         12.0f,-3.0f,0.0f,

    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaN4[] = {
        //Numero 4

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaN4);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN4);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaN4), g_vertex_buffer_data_PecaN4, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaN4);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN4);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaN4), g_color_buffer_data_PecaN4, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayIDN5);
    glBindVertexArray(VertexArrayIDN5);

    static const GLfloat g_vertex_buffer_data_PecaN5[] = {
        //Numero 5
         12.0f, 0.0f, 0.0f,
         15.0f, 0.0f, 0.0f,
         12.0f, -1.0f, 0.0f,

         12.0f, -1.0f, 0.0f,
         15.0f, 0.0f, 0.0f,
         15.0f, -1.0f, 0.0f,

         12.0f, -1.0f, 0.0f,
         12.0f, -2.0f, 0.0f,
         13.0f, -2.0f, 0.0f,

         12.0f, -1.0f, 0.0f,
         13.0f, -1.0f, 0.0f,
         13.0f, -2.0f, 0.0f,

         12.0f, -3.0f, 0.0f,
         12.0f, -2.0f, 0.0f,
         15.0f, -2.0f, 0.0f,

         12.0f, -3.0f, 0.0f,
         15.0f, -3.0f, 0.0f,
         15.0f, -2.0f, 0.0f,

         15.0f, -3.0f, 0.0f,
         15.0f, -5.0f, 0.0f,
         14.0f, -5.0f, 0.0f,

         14.0f, -3.0f, 0.0f,
         15.0f, -3.0f, 0.0f,
         14.0f, -5.0f, 0.0f,

         14.0f, -5.0f, 0.0f,
         12.0f, -4.0f, 0.0f,
         12.0f, -5.0f, 0.0f,

         14.0f, -5.0f, 0.0f,
         12.0f, -4.0f, 0.0f,
         14.0f, -4.0f, 0.0f,

    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaN5[] = {
        //Numero 5
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaN5);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN5);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaN5), g_vertex_buffer_data_PecaN5, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaN5);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN5);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaN5), g_color_buffer_data_PecaN5, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayIDN6);
    glBindVertexArray(VertexArrayIDN6);

    static const GLfloat g_vertex_buffer_data_PecaN6[] = {
        //Numero 6
           12.0f, 0.0f, 0.0f,
           15.0f, 0.0f, 0.0f,
           12.0f, -1.0f, 0.0f,

           12.0f, -1.0f, 0.0f,
           15.0f, 0.0f, 0.0f,
           15.0f, -1.0f, 0.0f,

           12.0f, -1.0f, 0.0f,
           12.0f, -2.0f, 0.0f,
           13.0f, -2.0f, 0.0f,

           12.0f, -1.0f, 0.0f,
           13.0f, -1.0f, 0.0f,
           13.0f, -2.0f, 0.0f,

           12.0f, -3.0f, 0.0f,
           12.0f, -2.0f, 0.0f,
           15.0f, -2.0f, 0.0f,

           12.0f, -3.0f, 0.0f,
           15.0f, -3.0f, 0.0f,
           15.0f, -2.0f, 0.0f,

           15.0f, -3.0f, 0.0f,
           15.0f, -5.0f, 0.0f,
           14.0f, -5.0f, 0.0f,

           14.0f, -3.0f, 0.0f,
           15.0f, -3.0f, 0.0f,
           14.0f, -5.0f, 0.0f,

           14.0f, -5.0f, 0.0f,
           12.0f, -4.0f, 0.0f,
           12.0f, -5.0f, 0.0f,

           14.0f, -5.0f, 0.0f,
           12.0f, -4.0f, 0.0f,
           14.0f, -4.0f, 0.0f,

           12.0f, -3.0f, 0.0f,
           12.0f, -4.0f, 0.0f,
           13.0f, -4.0f, 0.0f,

           12.0f, -3.0f, 0.0f,
           13.0f, -4.0f, 0.0f,
           13.0f, -3.0f, 0.0f,


    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaN6[] = {
        //Numero 6
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,



    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaN6);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN6);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaN6), g_vertex_buffer_data_PecaN6, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaN6);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN6);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaN6), g_color_buffer_data_PecaN6, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayIDN7);
    glBindVertexArray(VertexArrayIDN7);

    static const GLfloat g_vertex_buffer_data_PecaN7[] = {
        //Numero 7
       12.0f, 0.0f, 0.0f,
       15.0f, 0.0f, 0.0f,
       12.0f, -1.0f, 0.0f,

       12.0f, -1.0f, 0.0f,
       15.0f, 0.0f, 0.0f,
       15.0f, -1.0f, 0.0f,

       15.0f, -1.0f, 0.0f,
       12.0f, -5.0f, 0.0f,
       13.0f, -5.0f, 0.0f,

       15.0f, -1.0f, 0.0f,
       14.0f, -1.0f, 0.0f,
       12.0f, -5.0f, 0.0f,


    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaN7[] = {
        //Numero 7
          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,

          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,

          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,

          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,
          1.0f, 0.0f, 0.0f,


    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaN7);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN7);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaN7), g_vertex_buffer_data_PecaN7, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaN7);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN7);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaN7), g_color_buffer_data_PecaN7, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayIDN8);
    glBindVertexArray(VertexArrayIDN8);

    static const GLfloat g_vertex_buffer_data_PecaN8[] = {
        //Numero 8
         12.0f, 0.0f, 0.0f,
         15.0f, 0.0f, 0.0f,
         12.0f, -1.0f, 0.0f,

         12.0f, -1.0f, 0.0f,
         15.0f, 0.0f, 0.0f,
         15.0f, -1.0f, 0.0f,

         12.0f, -1.0f, 0.0f,
         12.0f, -2.0f, 0.0f,
         13.0f, -2.0f, 0.0f,

         12.0f, -1.0f, 0.0f,
         13.0f, -1.0f, 0.0f,
         13.0f, -2.0f, 0.0f,

         12.0f, -3.0f, 0.0f,
         12.0f, -2.0f, 0.0f,
         15.0f, -2.0f, 0.0f,

         12.0f, -3.0f, 0.0f,
         15.0f, -3.0f, 0.0f,
         15.0f, -2.0f, 0.0f,

         15.0f, -3.0f, 0.0f,
         15.0f, -5.0f, 0.0f,
         14.0f, -5.0f, 0.0f,

         14.0f, -3.0f, 0.0f,
         15.0f, -3.0f, 0.0f,
         14.0f, -5.0f, 0.0f,

         14.0f, -5.0f, 0.0f,
         12.0f, -4.0f, 0.0f,
         12.0f, -5.0f, 0.0f,

         14.0f, -5.0f, 0.0f,
         12.0f, -4.0f, 0.0f,
         14.0f, -4.0f, 0.0f,

         12.0f, -3.0f, 0.0f,
         12.0f, -4.0f, 0.0f,
         13.0f, -4.0f, 0.0f,

         12.0f, -3.0f, 0.0f,
         13.0f, -4.0f, 0.0f,
         13.0f, -3.0f, 0.0f,

         15.0f, -1.0f, 0.0f,
         14.0f, -1.0f, 0.0f,
         15.0f, -2.0f, 0.0f,

         14.0f, -2.0f, 0.0f,
         14.0f, -1.0f, 0.0f,
         15.0f, -2.0f, 0.0f,




    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaN8[] = {
        //Numero 8
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,

        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,


    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaN8);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN8);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaN8), g_vertex_buffer_data_PecaN8, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaN8);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN8);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaN8), g_color_buffer_data_PecaN8, GL_STATIC_DRAW);


    glGenVertexArrays(1, &VertexArrayIDN9);
    glBindVertexArray(VertexArrayIDN9);

    static const GLfloat g_vertex_buffer_data_PecaN9[] = {
        //Numero 9
        12.0f, 0.0f, 0.0f,
        15.0f, 0.0f, 0.0f,
        12.0f, -1.0f, 0.0f,

        12.0f, -1.0f, 0.0f,
        15.0f, 0.0f, 0.0f,
        15.0f, -1.0f, 0.0f,

        12.0f, -1.0f, 0.0f,
        12.0f, -2.0f, 0.0f,
        13.0f, -2.0f, 0.0f,

        12.0f, -1.0f, 0.0f,
        13.0f, -1.0f, 0.0f,
        13.0f, -2.0f, 0.0f,

        12.0f, -3.0f, 0.0f,
        12.0f, -2.0f, 0.0f,
        15.0f, -2.0f, 0.0f,

        12.0f, -3.0f, 0.0f,
        15.0f, -3.0f, 0.0f,
        15.0f, -2.0f, 0.0f,

        15.0f, -3.0f, 0.0f,
        15.0f, -5.0f, 0.0f,
        14.0f, -5.0f, 0.0f,

        14.0f, -3.0f, 0.0f,
        15.0f, -3.0f, 0.0f,
        14.0f, -5.0f, 0.0f,

        14.0f, -5.0f, 0.0f,
        12.0f, -4.0f, 0.0f,
        12.0f, -5.0f, 0.0f,

        14.0f, -5.0f, 0.0f,
        12.0f, -4.0f, 0.0f,
        14.0f, -4.0f, 0.0f,

        15.0f, -1.0f, 0.0f,
        14.0f, -1.0f, 0.0f,
        15.0f, -2.0f, 0.0f,

        14.0f, -2.0f, 0.0f,
        14.0f, -1.0f, 0.0f,
        15.0f, -2.0f, 0.0f,




    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaN9[] = {

        //Numero 9
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,

       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,
       1.0f, 0.0f, 0.0f,


    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaN9);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN9);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaN9), g_vertex_buffer_data_PecaN9, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaN9);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN9);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaN9), g_color_buffer_data_PecaN9, GL_STATIC_DRAW);
}
void transferDataToGPUMemoryTabuleiro(void)
{
    // VAO
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");


    static const GLfloat g_vertex_buffer_data[] = {
        5.0f,  -6.0f,  0.0f,
        6.0f, -6.0f,  0.0f,
        6.0f, 10.0f, 0.0f,
        5.0f,  -6.0f,  0.0f,
        6.0f, 10.0f, 0.0f,
        5.0f, 10.0f, 0.0f,

        -4.0f,-6.0f,0.0f,
        -4.0f,-5.0f,0.0f,
         5.0f,-5.0f,0.0f,
         5.0f,-6.0f,0.0f,
         5.0f,-5.0f,0.0f,
         -4.0f,-6.0f,0.0f,

        -5.0f, -6.0f,  0.0f,
        -4.0f, -6.0f,  0.0f,
        -4.0f, 10.0f, 0.0f,
        -5.0f,-6.0f,  0.0f,
        -5.0f, 10.0f, 0.0f,
        -4.0f, 10.0f, 0.0f,


        10.0f, 10.0f,0.0f,
        11.0f, 10.0f,0.0f,
        11.0f, 2.0f,0.0f,
        10.0f, 10.0f,0.0f,
        10.0f, 2.0f,0.0f,
        11.0f, 2.0f,0.0f,

        10.0f, 10.0f,0.0f,
        10.0f, 9.0f,0.0f,
        18.0f, 10.0f,0.0f,
        18.0f, 10.0f,0.0f,
        18.0f, 9.0f,0.0f,
        10.0f, 9.0f,0.0f,

        18.0f, 10.0f,0.0f,
        17.0f, 10.0f,0.0f,
        18.0f, 2.0f,0.0f,
        17.0f, 10.0f,0.0f,
        17.0f, 2.0f,0.0f,
        18.0f, 2.0f,0.0f,

        18.0f, 2.0f,0.0f,
        18.0f, 3.0f,0.0f,
        10.0f, 2.0f,0.0f,
        10.0f, 2.0f,0.0f,
        10.0f, 3.0f,0.0f,
        18.0f, 3.0f,0.0f,

    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data[] = {
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
         0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
         0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
        0.0f,  0.0f,  0.0f,
    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayID3);
    glBindVertexArray(VertexArrayID3);

    static const GLfloat g_vertex_buffer_data3[] = {
     10.0f,10.0f,0.0f,
     10.0f,-2.0f,0.0f,
     18.0f,10.0f,0.0f,

     18.0f,10.0f,0.0f,
     18.0,-2.0f,0.0f,
     10.0f,-2.0f,0.0f,

    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data3[] = {
     0.6f, 0.996f, 0.98431f, 0.0f,
     0.6f, 0.996f, 0.98431f, 0.0f,
     0.6f, 0.996f, 0.98431f, 0.0f,
     0.6f, 0.996f, 0.98431f, 0.0f,
     0.6f, 0.996f, 0.98431f, 0.0f,
     0.6f, 0.996f, 0.98431f, 0.0f,
    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbuffer3);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data3), g_vertex_buffer_data3, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbuffer3);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data3), g_color_buffer_data3, GL_STATIC_DRAW);

}
void transferDataToGPUMemoryBlock(void)
{
    glGenVertexArrays(1, &VertexArrayIDPecaJ);
    glBindVertexArray(VertexArrayIDPecaJ);



    static const GLfloat g_vertex_buffer_data_PecaJ[] = {
        0.0f, 2.0f,  0.0f,
        0.0f, 3.0f,  0.0f,
        1.0f, 3.0f, 0.0f,
        0.0f,  2.0f,  0.0f,
        1.0f, 2.0f, 0.0f,
        1.0f, 3.0f, 0.0f,
        0.0f,2.0f,0.0f,
        0.1f,2.0f,0.0f,
        0.0f,3.0f,0.0f,
        0.0f,3.0f,0.0f,
        0.1f,2.0f,0.0f,
        0.1f,3.0f,0.0f,

        0.0f,2.0f,0.0f,
        1.0f,2.0f,0.0f,
        1.0f,2.1f,0.0f,
        0.0f,2.0f,0.0f,
        0.0f,2.1f,0.0f,
        1.0f,2.1,0.0f,
    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_PecaJ[] = {
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
        1.0f,  0.0f,  0.0f,
         1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaJ);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaJ);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_PecaJ), g_vertex_buffer_data_PecaJ, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaJ);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaJ);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_PecaJ), g_color_buffer_data_PecaJ, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayIDPecaVerde);
    glBindVertexArray(VertexArrayIDPecaVerde);



    static const GLfloat g_vertex_buffer_data_Peca_Verde[] = {
        0.0f, 2.0f,  0.0f,
        0.0f, 3.0f,  0.0f,
        1.0f, 3.0f, 0.0f,
        0.0f,  2.0f,  0.0f,
        1.0f, 2.0f, 0.0f,
        1.0f, 3.0f, 0.0f,
        0.0f,2.0f,0.0f,
        0.1f,2.0f,0.0f,
        0.0f,3.0f,0.0f,
        0.0f,3.0f,0.0f,
        0.1f,2.0f,0.0f,
        0.1f,3.0f,0.0f,

        0.0f,2.0f,0.0f,
        1.0f,2.0f,0.0f,
        1.0f,2.1f,0.0f,
        0.0f,2.0f,0.0f,
        0.0f,2.1f,0.0f,
        1.0f,2.1,0.0f,
    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_Peca_Verde[] = {
        0.0f,  0.50f,  0.0f,
        0.0f, 0.5f,  0.0f,
        0.0f,  0.5f,  0.0f,
        0.0f, 0.5f,  0.0f,
        0.0f,  0.5f,  0.0f,
        0.0f,  0.5f,  0.0f,
         1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaVerde);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaVerde);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_Peca_Verde), g_vertex_buffer_data_Peca_Verde, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaVerde);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaVerde);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_Peca_Verde), g_color_buffer_data_Peca_Verde, GL_STATIC_DRAW);

    glGenVertexArrays(1, &VertexArrayIDPecaAzul);
    glBindVertexArray(VertexArrayIDPecaAzul);



    static const GLfloat g_vertex_buffer_data_Peca_Azul[] = {
        0.0f, 2.0f,  0.0f,
        0.0f, 3.0f,  0.0f,
        1.0f, 3.0f, 0.0f,
        0.0f,  2.0f,  0.0f,
        1.0f, 2.0f, 0.0f,
        1.0f, 3.0f, 0.0f,
        0.0f,2.0f,0.0f,
        0.1f,2.0f,0.0f,
        0.0f,3.0f,0.0f,
        0.0f,3.0f,0.0f,
        0.1f,2.0f,0.0f,
        0.1f,3.0f,0.0f,

        0.0f,2.0f,0.0f,
        1.0f,2.0f,0.0f,
        1.0f,2.1f,0.0f,
        0.0f,2.0f,0.0f,
        0.0f,2.1f,0.0f,
        1.0f,2.1,0.0f,
    };

    // One color for each vertex. They were generated randomly.
    static const GLfloat g_color_buffer_data_Peca_Azul[] = {
        0.0f,  0.0f,  1.0f,
        0.0f, 0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
    };

    // Move vertex data to video memory; specifically to VBO called vertexbuffer
    glGenBuffers(1, &vertexbufferPecaAzul);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaAzul);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data_Peca_Azul), g_vertex_buffer_data_Peca_Azul, GL_STATIC_DRAW);

    // Move color data to video memory; specifically to CBO called colorbuffer
    glGenBuffers(1, &colorbufferPecaAzul);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaAzul);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data_Peca_Azul), g_color_buffer_data_Peca_Azul, GL_STATIC_DRAW);
}

//--------------------------------------------------------------------------------
void cleanupDataFromGPU()
{
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &colorbuffer);
    glDeleteBuffers(1, &vertexbufferPecaJ);
    glDeleteBuffers(1, &colorbufferPecaJ);
    glDeleteBuffers(1, &vertexbufferPecaAzul);
    glDeleteBuffers(1, &colorbufferPecaAzul);
    glDeleteBuffers(1, &vertexbufferPecaVerde);
    glDeleteBuffers(1, &colorbufferPecaVerde);
    glDeleteBuffers(1, &vertexbufferPecaN);
    glDeleteBuffers(1, &colorbufferPecaN);
    glDeleteVertexArrays(1, &VertexArrayID);
    glDeleteProgram(programID);
}

//--------------------------------------------------------------------------------
void draw(void)
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    // Use our shader
    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    unsigned int matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


    glm::mat4 trans;
    trans = glm::translate(glm::mat4(1.0), glm::vec3(0.0f, 0.0f, 0.0f));
    unsigned int m = glGetUniformLocation(programID, "trans");
    glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);


    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10);
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 42); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);


}

void draw3(void)
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    // Use our shader
    glUseProgram(programID);

    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // retrieve the matrix uniform locations
    unsigned int matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

    glm::mat4 trans;
    trans = glm::translate(glm::mat4(1.0), glm::vec3(0.0f, 0.0f, 0.0f));
    unsigned int m = glGetUniformLocation(programID, "trans");
    glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);


    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer3);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer3);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10);
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 6); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);


}
//--------------------------------------------------------------------------------
void drawBlock(int i, int j)
{

    // Use our shader
    glUseProgram(programID);


    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations

    unsigned int matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

    glm::mat4 trans;
    trans = glm::translate(glm::mat4(1.0), glm::vec3(-4.0f + j, -7.0f + i, 0.0f));
    unsigned int m = glGetUniformLocation(programID, "trans");
    glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);


    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaJ);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaJ);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, 0, 18); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);


}

void drawN(int jko) {
    // Clear the screen
    //glClear(GL_COLOR_BUFFER_BIT);

    // Use our shader
    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    if (jko == 0) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(-3.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }
    if (jko == 1) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(2.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    //glEnable(GL_PROGRAM_POINT_SIZE);
    //glPointSize(10);
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, (0), (6 * 4)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}
void drawN1(int jko) {
    // Clear the screen
    //glClear(GL_COLOR_BUFFER_BIT);

    // Use our shader
    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    if (jko == 0) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(-3.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }
    if (jko == 1) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(2.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN1);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN1);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, (0), (6 * 2)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}
void drawN2(int jko) {

    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    if (jko == 0) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(-3.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }
    if (jko == 1) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(2.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN2);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN2);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, (0), (6 * 5)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}
void drawN3(int jko) {

    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    if (jko == 0) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(-3.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }
    if (jko == 1) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(2.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN3);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN3);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, (0), (6 * 5)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}
void drawN4(int jko) {

    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    if (jko == 0) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(-3.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }
    if (jko == 1) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(2.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN4);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN4);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, (0), (6 * 3)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}
void drawN5(int jko) {

    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    if (jko == 0) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(-3.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }
    if (jko == 1) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(2.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN5);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN5);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, (0), (6 * 5)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}
void drawN6(int jko) {

    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    if (jko == 0) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(-3.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }
    if (jko == 1) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(2.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN6);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN6);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, (0), (6 * 6)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}
void drawN7(int jko) {

    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    if (jko == 0) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(-3.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }
    if (jko == 1) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(2.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN7);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN7);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, (0), (6 * 2)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}
void drawN8(int jko) {

    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    if (jko == 0) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(-3.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }
    if (jko == 1) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(2.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN8);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN8);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, (0), (6 * 7)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}
void drawN9(int jko) {

    glUseProgram(programID);

    // create transformations
    //glm::mat4 model = glm::mat4(1.0f);
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations
    if (jko == 0) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(-3.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }
    if (jko == 1) {


        unsigned int matrix = glGetUniformLocation(programID, "mvp");
        glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);


        glm::mat4 trans;
        trans = glm::translate(glm::mat4(1.0), glm::vec3(2.0f, 0.0f, 0.0f));
        unsigned int m = glGetUniformLocation(programID, "trans");
        glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);
    }

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaN9);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaN9);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, (0), (6 * 6)); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}
void drawBlockAzul(int i, int j)
{

    // Use our shader
    glUseProgram(programID);


    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations

    unsigned int matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

    glm::mat4 trans;
    trans = glm::translate(glm::mat4(1.0), glm::vec3(-4.0f + j, -7.0f + i, 0.0f));
    unsigned int m = glGetUniformLocation(programID, "trans");
    glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);


    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaAzul);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaAzul);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, 0, 18); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);


}
void drawBlockVerde(int i, int j)
{

    // Use our shader
    glUseProgram(programID);


    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations

    unsigned int matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

    glm::mat4 trans;
    trans = glm::translate(glm::mat4(1.0), glm::vec3(-4.0f + j, -7.0f + i, 0.0f));
    unsigned int m = glGetUniformLocation(programID, "trans");
    glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);


    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaVerde);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaVerde);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, 0, 18); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);


}
void drawNextBlock(int i, int j)
{

    // Use our shader
    glUseProgram(programID);


    glm::mat4 mvp = glm::ortho(-10.0f, 20.0f, -10.0f, 20.0f);

    // Our ModelViewProjection : multiplication of our 3 matrices
    //glm::mat4 mvp = projection * view * model;
    // Remember, matrix multiplication is the other way around

    // retrieve the matrix uniform locations

    unsigned int matrix = glGetUniformLocation(programID, "mvp");
    glUniformMatrix4fv(matrix, 1, GL_FALSE, &mvp[0][0]);

    glm::mat4 trans;
    trans = glm::translate(glm::mat4(1.0), glm::vec3(-4.0f + 15.0f + j, -7.0f + 8.0f + i, 0.0f));
    unsigned int m = glGetUniformLocation(programID, "trans");
    glUniformMatrix4fv(m, 1, GL_FALSE, &trans[0][0]);


    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbufferPecaJ);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbufferPecaJ);
    glVertexAttribPointer(
        1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
        3,                                // size
        GL_FLOAT,                         // type
        GL_FALSE,                         // normalized?
        0,                                // stride
        (void*)0                          // array buffer offset
    );


    glDrawArrays(GL_TRIANGLES, 0, 6); // 3 indices starting at 0 -> 1 triangle
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);


}
void atualizaTabuleiro() {
    draw();
    print(pont);
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 9; j++) {
            if (tab[i][j] != 0) {
                int t = tab[i][j];
                int c = cores[t];
                if (c == 1) {
                    drawBlock(i, j);
                }
                if (c == 2) {
                    drawBlockAzul(i, j);
                }
                if (c == 3 || c == 0) {
                    drawBlockVerde(i, j);
                }
            }
        }
    }
    if (dif != 3) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (next1[i][j] != 0) {
                    drawNextBlock(i, j);
                }
            }
        }

    }
}
void inicarTabuleiro() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 9; j++) {
            tab[i][j] = 0;

        }
    }
}
void imprimeTabuleiro() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%i ", tab[i][j]);
        }
        printf("\n");
    }
}

bool ColideEsquerda(int tipo, int id, int rot, int l, int c) {
    bool a = true;
    if (tipo == 7 && rot == 1) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;
    }
    if (tipo == 6 && rot == 2) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;
    }
    if (tipo == 6 && rot == 1) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;
        if (tab[l - 2][c - 1] != 0)
            a = false;
        if (tab[l - 3][c - 1] != 0)
            a = false;
    }
    if (tipo == 5 && rot == 2) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;
    }
    if (tipo == 5 && rot == 1) {
        if (c - 2 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;

        if (tab[l - 1][c - 2] != 0)
            a = false;
        if (tab[l - 2][c - 2] != 0)
            a = false;
    }

    if (tipo == 4 && rot == 2) {
        if (c - 2 < 0) {
            a = false;
        }
        if (tab[l][c - 2] != 0)
            a = false;
        if (tab[l - 1][c - 2] != 0)
            a = false;
        if (tab[l][c - 1] != 0)
            a = false;
    }
    if (tipo == 4 && rot == 1) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;
        if (tab[l - 2][c] != 0)
            a = false;
    }

    if (tipo == 3 && rot == 2) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c] != 0)
            a = false;
    }
    if (tipo == 3 && rot == 4) {
        if (c - 2 < 0) {
            a = false;
        }
        if (tab[l - 1][c - 2] != 0)
            a = false;
        if (tab[l][c - 1] != 0)
            a = false;

    }
    if (tipo == 3 && rot == 3) {
        if (c - 2 < 0) {
            a = false;
        }
        if (tab[l - 1][c - 2] != 0)
            a = false;
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 2][c - 1] != 0)
            a = false;
    }
    if (tipo == 3 && rot == 1) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;
        if (tab[l - 2][c - 1] != 0)
            a = false;
    }

    if (tipo == 2 && rot == 4) {
        if (c - 3 < 0) {
            a = false;
        }
        if (tab[l - 1][c - 3] != 0)
            a = false;
        if (tab[l][c - 1] != 0)
            a = false;
    }
    if (tipo == 2 && rot == 3) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l - 1][c] != 0)
            a = false;
        if (tab[l - 2][c] != 0)
            a = false;
    }
    if (tipo == 2 && rot == 2) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;
        if (tab[l - 2][c - 1] != 0)
            a = false;
    }
    if (tipo == 2 && rot == 1) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;
        if (tab[l - 2][c - 1] != 0)
            a = false;
    }

    if (tipo == 1 && rot == 1) {
        if (c - 2 < 0) {
            a = false;
        }
        if (tab[l][c - 2] != 0)
            a = false;
        if (tab[l - 1][c - 2] != 0)
            a = false;
        if (tab[l - 2][c - 2] != 0)
            a = false;
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;

    }
    if (tipo == 1 && rot == 2) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;
    }
    if (tipo == 1 && rot == 3) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c - 1] != 0)
            a = false;
        if (tab[l - 2][c - 1] != 0)
            a = false;
    }
    if (tipo == 1 && rot == 4) {
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l][c - 1] != 0)
            a = false;
        if (tab[l - 1][c + 1] != 0)
            a = false;
    }
    return a;

}
void moveLeft(int tipo, int id, int rot) {
    bool a = true;
    int  l = 0, c = 0;

    //Peca 7
    if (tipo == 7 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
         //  tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l][c - 1] = id;
            tab[l - 1][c - 1] = id;

        }
    }
    //Peca 6

    if (tipo == 6 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c + 3] = 0;
            tab[l][c - 1] = id;

        }
    }
    if (tipo == 6 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l - 1][c] = 0;
            tab[l - 2][c] = 0;
            tab[l - 3][c] = 0;
            tab[l][c] = 0;
            tab[l - 3][c - 1] = id;
            tab[l][c - 1] = id;
            tab[l - 1][c - 1] = id;
            tab[l - 2][c - 1] = id;

        }
    }
    //Peca 
    //Pea 5

    if (tipo == 5 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
         //  tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l - 1][c + 2] = 0;
            tab[l][c - 1] = id;
            tab[l - 1][c] = id;
        }
    }
    if (tipo == 5 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c - 1] = 0;
            tab[l][c - 1] = id;
            tab[l - 1][c - 2] = id;
            tab[l - 2][c - 2] = id;
        }
    }
    //Pea 4

    if (tipo == 4 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
         //  tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l - 1][c - 2] = id;
            tab[l][c - 1] = id;
            tab[l - 1][c] = 0;
        }
    }
    if (tipo == 4 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l - 2][c + 1] = 0;
            tab[l][c - 1] = id;
            tab[l - 1][c - 1] = id;
            tab[l - 2][c] = id;
        }
    }

    //Pea 3

    if (tipo == 3 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
           //tab[l][c] = 5;
            tab[l][c + 2] = 0;
            tab[l - 1][c] = id;
            tab[l][c - 1] = id;
            tab[l - 1][c + 1] = 0;
        }
    }
    if (tipo == 3 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 2][c] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l - 1][c] = id;
            tab[l][c - 1] = id;
            tab[l - 1][c + 1] = 0;
            tab[l - 1][c - 1] = id;
            tab[l - 2][c - 1] = id;
        }
    }
    if (tipo == 3 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c] = 0;

            tab[l][c - 1] = id;
            tab[l - 2][c - 1] = id;
            tab[l - 1][c - 2] = id;

        }
    }
    if (tipo == 3 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l][c - 1] = id;
            tab[l - 1][c - 2] = id;


        }
    }
    //Pea 2

    if (tipo == 2 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
           //tab[l][c] = 5;
            tab[l][c + 2] = 0;
            tab[l - 1][c] = 0;
            tab[l][c - 1] = id;
            tab[l - 1][c - 1] = id;
        }
    }
    if (tipo == 2 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c + 1] = 0;
            tab[l - 1][c] = 0;
            tab[l][c - 1] = id;
            tab[l - 1][c - 1] = id;
            tab[l - 2][c - 1] = id;
        }
    }
    if (tipo == 2 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c + 1] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l - 2][c + 1] = 0;
            tab[l - 1][c] = id;
            tab[l - 2][c] = id;
            tab[l][c - 1] = id;
        }
    }
    if (tipo == 2 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c] = 0;

            tab[l][c - 1] = id;
            tab[l - 1][c - 3] = id;

        }
    }
    //Pea 1
    if (tipo == 1 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c] = 0;
            tab[l][c - 1] = id;
            tab[l - 1][c - 1] = id;
            tab[l - 2][c - 2] = id;


        }
    }
    if (tipo == 1 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c - 1] = id;
            tab[l][c - 1] = id;
            tab[l - 1][c + 2] = 0;
        }
    }
    if (tipo == 1 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c + 1] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c] = 0;
            tab[l][c - 1] = id;
            tab[l - 1][c - 1] = id;
            tab[l - 2][c - 1] = id;


        }
    }
    if (tipo == 1 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideEsquerda(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l - 1][c + 2] = 0;
            tab[l][c + 2] = 0;
            tab[l - 1][c + 1] = id;
            tab[l][c - 1] = id;

        }
    }
    atualizaTabuleiro();


}

bool ColideBase(int tipo, int id, int rot, int l, int c) {
    bool a = true;

    if (tipo == 1 && rot == 1) {
        if (l - 3 < 0) {
            a = false;
        }
        if (tab[l - 3][c] != 0) {
            a = false;
        }
        if (tab[l - 3][c - 1] != 0) {
            a = false;
        }
    }

    if (tipo == 1 && rot == 2) {
        if (l - 2 < 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 1] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 2] != 0) {
            a = false;
        }
    }

    if (tipo == 1 && rot == 3) {
        if (l - 3 < 0) {
            a = false;
        }
        if (tab[l - 1][c + 1] != 0) {
            a = false;
        }
        if (tab[l - 3][c] != 0) {
            a = false;
        }
    }

    if (tipo == 1 && rot == 4) {
        if (l - 2 < 0) {
            a = false;
        }
        if (tab[l - 1][c] != 0) {
            a = false;
        }
        if (tab[l - 1][c + 1] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 2] != 0) {
            a = false;
        }
    }

    if (tipo == 2 && rot == 1) {
        if (l - 3 < 0) {
            a = false;
        }
        if (tab[l - 3][c] != 0) {
            a = false;
        }
        if (tab[l - 3][c + 1] != 0) {
            a = false;
        }
    }

    if (tipo == 2 && rot == 2) {
        if (l - 2 < 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 1][c + 1] != 0) {
            a = false;
        }
        if (tab[l - 1][c + 2] != 0) {
            a = false;
        }
    }

    if (tipo == 2 && rot == 3) {
        if (l - 3 < 0) {
            a = false;
        }
        if (tab[l - 1][c] != 0) {
            a = false;
        }
        if (tab[l - 3][c + 1] != 0) {
            a = false;
        }
    }

    if (tipo == 2 && rot == 4) {
        if (l - 2 < 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 2][c - 1] != 0) {
            a = false;
        }
        if (tab[l - 2][c - 2] != 0) {
            a = false;
        }
    }

    if (tipo == 3 && rot == 1) {
        if (l - 3 < 0) {
            a = false;
        }
        if (tab[l - 2][c + 1] != 0) {
            a = false;
        }
        if (tab[l - 3][c] != 0) {
            a = false;
        }
    }

    if (tipo == 3 && rot == 2) {
        if (l - 2 < 0) {
            a = false;
        }
        if (tab[l - 1][c] != 0) {
            a = false;
        }
        if (tab[l - 1][c + 2] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 1] != 0) {
            a = false;
        }
    }

    if (tipo == 3 && rot == 3) {
        if (l - 3 < 0) {
            a = false;
        }
        if (tab[l - 2][c - 1] != 0) {
            a = false;
        }
        if (tab[l - 3][c] != 0) {
            a = false;
        }
    }

    if (tipo == 3 && rot == 4) {
        if (l - 2 < 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 2][c - 1] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 1] != 0) {
            a = false;
        }
    }

    if (tipo == 4 && rot == 1) {
        if (l - 3 < 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 3][c + 1] != 0) {
            a = false;
        }
    }

    if (tipo == 4 && rot == 2) {
        if (l - 2 < 0) {
            a = false;
        }
        if (tab[l - 1][c + 1] != 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 2][c - 1] != 0) {
            a = false;
        }
    }

    if (tipo == 5 && rot == 1) {
        if (l - 3 < 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 3][c - 1] != 0) {
            a = false;
        }
    }

    if (tipo == 5 && rot == 2) {
        if (l - 2 < 0) {
            a = false;
        }
        if (tab[l - 1][c] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 1] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 2] != 0) {
            a = false;
        }
    }

    if (tipo == 6 && rot == 1) {
        if (l - 4 < 0) {
            a = false;
        }
        if (tab[l - 4][c] != 0) {
            a = false;
        }
    }

    if (tipo == 6 && rot == 2) {
        if (l - 1 < 0) {
            a = false;
        }
        if (tab[l - 1][c] != 0) {
            a = false;
        }
        if (tab[l - 1][c + 1] != 0) {
            a = false;
        }
        if (tab[l - 1][c + 2] != 0) {
            a = false;
        }
        if (tab[l - 1][c + 3] != 0) {
            a = false;
        }
    }

    if (tipo == 7 && rot == 1) {
        if (l - 2 < 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 1] != 0) {
            a = false;
        }
    }

    return a;
}
bool moveDown(int tipo, int id, int rot) {
    bool a = true;
    int  l = 0, c = 0;

    //P 1, Rot 1
    if (tipo == 1 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 2][c - 1] = 0;
            tab[l - 3][c] = id;
            tab[l - 3][c - 1] = id;
        }
    }


    if (tipo == 1 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l - 1][c + 2] = 0;
            tab[l - 2][c] = id;
            tab[l - 2][c + 1] = id;
            tab[l - 2][c + 2] = id;
        }
    }

    if (tipo == 1 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l - 1][c + 1] = id;
            tab[l - 3][c] = id;
        }
    }

    if (tipo == 1 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l][c + 2] = 0;
            tab[l - 1][c] = id;
            tab[l - 1][c + 1] = id;
            tab[l - 2][c + 2] = id;
        }
    }

    if (tipo == 2 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 2][c + 1] = 0;
            tab[l - 3][c] = id;
            tab[l - 3][c + 1] = id;
        }
    }

    if (tipo == 2 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l][c + 2] = 0;
            tab[l - 1][c + 1] = id;
            tab[l - 1][c + 2] = id;
            tab[l - 2][c] = id;
        }
    }

    if (tipo == 2 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l - 1][c] = id;
            tab[l - 3][c + 1] = id;
        }
    }

    if (tipo == 2 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c - 1] = 0;
            tab[l - 1][c - 2] = 0;
            tab[l - 2][c] = id;
            tab[l - 2][c - 1] = id;
            tab[l - 2][c - 2] = id;
        }
    }


    if (tipo == 3 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l - 2][c + 1] = id;
            tab[l - 3][c] = id;
        }
    }

    if (tipo == 3 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l][c + 2] = 0;
            tab[l - 1][c] = id;
            tab[l - 1][c + 2] = id;
            tab[l - 2][c + 1] = id;
        }
    }

    if (tipo == 3 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c - 1] = 0;
            tab[l - 2][c - 1] = id;
            tab[l - 3][c] = id;
        }
    }


    if (tipo == 3 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c - 1] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l - 2][c] = id;
            tab[l - 2][c - 1] = id;
            tab[l - 2][c + 1] = id;
        }
    }

    if (tipo == 4 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l - 2][c] = id;
            tab[l - 3][c + 1] = id;
        }
    }


    if (tipo == 4 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l - 1][c - 1] = 0;
            tab[l - 1][c + 1] = id;
            tab[l - 2][c] = id;
            tab[l - 2][c - 1] = id;
        }
    }

    if (tipo == 5 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c - 1] = 0;
            tab[l - 2][c] = id;
            tab[l - 3][c - 1] = id;
        }
    }

    if (tipo == 5 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l - 1][c + 2] = 0;
            tab[l - 1][c] = id;
            tab[l - 2][c + 1] = id;
            tab[l - 2][c + 2] = id;
        }
    }

    if (tipo == 6 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 4][c] = id;
        }
    }


    if (tipo == 6 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l][c + 2] = 0;
            tab[l][c + 3] = 0;
            tab[l - 1][c] = id;
            tab[l - 1][c + 1] = id;
            tab[l - 1][c + 2] = id;
            tab[l - 1][c + 3] = id;
        }
    }

    if (tipo == 7 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideBase(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l - 2][c] = id;
            tab[l - 2][c + 1] = id;
        }
    }

    atualizaTabuleiro();
    return a;
}

bool ColideDireita(int tipo, int id, int rot, int l, int c) {
    bool a = true;
    if (tipo == 7 && rot == 1) {
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c + 2] != 0)
            a = false;
        if (tab[l - 1][c + 2] != 0)
            a = false;
    }
    if (tipo == 6 && rot == 2) {
        if (c + 4 > 8) {
            a = false;
        }
        if (tab[l][c + 4] != 0)
            a = false;
        //if (tab[l - 1][c - 1] != 0)
            //a = false;
    }
    if (tipo == 6 && rot == 1) {
        if (c + 1 > 8) {
            a = false;
        }
        if (tab[l][c + 1] != 0)
            a = false;
        if (tab[l - 1][c + 1] != 0)
            a = false;
        if (tab[l - 2][c + 1] != 0)
            a = false;
        if (tab[l - 3][c + 1] != 0)
            a = false;
    }
    if (tipo == 5 && rot == 2) {
        if (c + 3 > 8) {
            a = false;
        }
        if (tab[l][c + 2] != 0)
            a = false;
        if (tab[l - 1][c + 3] != 0)
            a = false;
    }
    if (tipo == 5 && rot == 1) {
        if (c + 1 > 8) {
            a = false;
        }
        if (tab[l][c + 1] != 0)
            a = false;

        if (tab[l - 1][c + 1] != 0)
            a = false;
        if (tab[l - 2][c] != 0)
            a = false;
    }
    if (tipo == 4 && rot == 2) {
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c + 2] != 0)
            a = false;
        if (tab[l - 1][c + 1] != 0)
            a = false;

    }
    if (tipo == 4 && rot == 1) {
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c + 1] != 0)
            a = false;
        if (tab[l - 1][c + 2] != 0)
            a = false;
        if (tab[l - 2][c + 2] != 0)
            a = false;
    }
    if (tipo == 3 && rot == 2) {
        if (c + 3 > 8) {
            a = false;
        }
        if (tab[l][c + 3] != 0)
            a = false;
        if (tab[l - 1][c + 2] != 0)
            a = false;
    }
    if (tipo == 3 && rot == 4) {
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l - 1][c + 2] != 0)
            a = false;
        if (tab[l][c + 1] != 0)
            a = false;

    }
    if (tipo == 3 && rot == 3) {
        if (c + 1 > 8) {
            a = false;
        }
        if (tab[l - 1][c + 1] != 0)
            a = false;
        if (tab[l][c + 1] != 0)
            a = false;
        if (tab[l - 2][c + 1] != 0)
            a = false;
    }
    if (tipo == 3 && rot == 1) {
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c + 1] != 0)
            a = false;
        if (tab[l - 1][c + 2] != 0)
            a = false;
        if (tab[l - 2][c + 1] != 0)
            a = false;
    }
    if (tipo == 2 && rot == 4) {
        if (c + 1 > 8) {
            a = false;
        }
        if (tab[l - 1][c + 1] != 0)
            a = false;
        if (tab[l][c + 1] != 0)
            a = false;
    }
    if (tipo == 2 && rot == 3) {
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l - 1][c + 2] != 0)
            a = false;
        if (tab[l - 2][c + 2] != 0)
            a = false;
        if (tab[l][c + 2] != 0)
            a = false;
    }
    if (tipo == 2 && rot == 2) {
        if (c + 3 > 8) {
            a = false;
        }
        if (tab[l][c + 3] != 0)
            a = false;
        if (tab[l - 1][c + 1] != 0)
            a = false;
    }
    if (tipo == 2 && rot == 1) {
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c + 1] != 0)
            a = false;
        if (tab[l - 1][c + 1] != 0)
            a = false;
        if (tab[l - 2][c + 2] != 0)
            a = false;
    }
    if (tipo == 1 && rot == 1) {
        if (c + 1 > 8) {
            a = false;
        }
        if (tab[l][c + 1] != 0)
            a = false;
        if (tab[l - 1][c + 1] != 0)
            a = false;
        if (tab[l - 2][c + 1] != 0)
            a = false;

    }
    if (tipo == 1 && rot == 2) {
        if (c + 3 > 8) {
            a = false;
        }
        if (tab[l][c + 1] != 0)
            a = false;
        if (tab[l - 1][c + 3] != 0)
            a = false;
    }
    if (tipo == 1 && rot == 3) {
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c + 2] != 0)
            a = false;
        if (tab[l - 1][c + 1] != 0)
            a = false;
        if (tab[l - 2][c + 1] != 0)
            a = false;
    }
    if (tipo == 1 && rot == 4) {
        if (c + 3 > 8) {
            a = false;
        }
        if (tab[l][c + 3] != 0)
            a = false;
        if (tab[l - 1][c + 3] != 0)
            a = false;
    }
    return a;
}
void moveRight(int tipo, int id, int rot) {
    bool a = true;
    int  l = 0, c = 0;

    //Peca 7
    if (tipo == 7 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
          //tab[l][c] = 5;
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l][c + 2] = id;
            tab[l - 1][c + 2] = id;
        }
    }
    //Peca 6

    if (tipo == 6 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l][c + 4] = id;

        }
    }
    if (tipo == 6 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l - 1][c] = 0;
            tab[l - 2][c] = 0;
            tab[l - 3][c] = 0;
            tab[l][c] = 0;
            tab[l - 3][c + 1] = id;
            tab[l][c + 1] = id;
            tab[l - 1][c + 1] = id;
            tab[l - 2][c + 1] = id;

        }
    }
    //Peca 
    //Pea 5

    if (tipo == 5 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
           //tab[l][c] = 5;
            tab[l][c] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l][c + 2] = id;
            tab[l - 1][c + 3] = id;
        }
    }
    if (tipo == 5 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c - 1] = 0;
            tab[l - 2][c - 1] = 0;
            tab[l][c + 1] = id;
            tab[l - 1][c + 1] = id;
            tab[l - 2][c] = id;
        }
    }
    //Pea 4

    if (tipo == 4 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);

        if (a) { //Movimenta para a esquerda
         //  tab[l][c] = 0;
            tab[l][c] = 0;
            tab[l - 1][c + 1] = id;
            tab[l][c + 2] = id;
            tab[l - 1][c - 1] = 0;

        }
    }
    if (tipo == 4 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c + 1] = 0;
            tab[l][c + 1] = id;
            tab[l - 1][c + 2] = id;
            tab[l - 2][c + 2] = id;
        }
    }

    //Pea 3

    if (tipo == 3 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
           //tab[l][c] = 5;
            tab[l][c] = 0;
            tab[l - 1][c + 2] = id;
            tab[l][c + 3] = id;
            tab[l - 1][c + 1] = 0;
        }
    }
    if (tipo == 3 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 2][c] = 0;
            tab[l - 1][c + 2] = id;
            tab[l - 1][c] = 0;
            tab[l][c + 1] = id;
            tab[l - 2][c + 1] = id;
        }
    }
    if (tipo == 3 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c - 1] = 0;
            tab[l - 2][c] = 0;

            tab[l][c + 1] = id;
            tab[l - 2][c + 1] = id;
            tab[l - 1][c + 1] = id;

        }
    }
    if (tipo == 3 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c - 1] = 0;
            tab[l][c + 1] = id;
            tab[l - 1][c + 2] = id;


        }
    }
    //Pea 2

    if (tipo == 2 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
           //tab[l][c] = 5;
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l][c + 3] = id;
            tab[l - 1][c + 1] = id;
        }
    }
    if (tipo == 2 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c] = 0;
            tab[l][c + 1] = id;
            tab[l - 1][c + 1] = id;
            tab[l - 2][c + 2] = id;
        }
    }
    if (tipo == 2 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l - 2][c + 1] = 0;
            tab[l - 1][c + 2] = id;
            tab[l - 2][c + 2] = id;
            tab[l][c + 2] = id;
        }
    }
    if (tipo == 2 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c - 2] = 0;

            tab[l][c + 1] = id;
            tab[l - 1][c + 1] = id;

        }
    }
    //Pea 1
    if (tipo == 1 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c - 1] = 0;
            tab[l][c + 1] = id;
            tab[l - 1][c + 1] = id;
            tab[l - 2][c + 1] = id;


        }
    }
    if (tipo == 1 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c + 3] = id;
            tab[l][c + 1] = id;
            tab[l - 1][c] = 0;
        }
    }
    if (tipo == 1 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }

        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c] = 0;
            tab[l][c + 2] = id;
            tab[l - 1][c + 1] = id;
            tab[l - 2][c + 1] = id;


        }
    }
    if (tipo == 1 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }


        a = ColideDireita(tipo, id, rot, l, c);
        if (a) { //Movimenta para a esquerda
            tab[l - 1][c + 2] = 0;
            tab[l][c] = 0;
            tab[l - 1][c + 3] = id;
            tab[l][c + 3] = id;

        }
    }
    atualizaTabuleiro();
}

void makePeca(int tipo, int id, int rot) {
    if (tipo == 7) { //Verificamos se   o quadrado
        // printf("%i", id);
        tab[18][5] = id;
        tab[18][4] = id;
        tab[17][5] = id;
        tab[17][4] = id;
    }
    if (tipo == 6 && rot == 2) { //Verificamos se   o quadrado
        tab[18][3] = id;
        tab[18][4] = id;
        tab[18][5] = id;
        tab[18][6] = id;
    }
    if (tipo == 6 && rot == 1) { //Verificamos se   o quadrado
        tab[18][4] = id;
        tab[17][4] = id;
        tab[16][4] = id;
        tab[15][4] = id;
    }

    if (tipo == 5 && rot == 2) { //Verificamos se   o quadrado
        tab[18][4] = id;
        tab[18][5] = id;
        tab[17][5] = id;
        tab[17][6] = id;
    }
    if (tipo == 5 && rot == 1) { //Verificamos se   o quadrado
        tab[16][4] = id;
        tab[17][4] = id;
        tab[17][5] = id;
        tab[18][5] = id;
    }
    if (tipo == 4 && rot == 2) { //Verificamos se   o quadrado
        tab[17][4] = id;
        tab[17][5] = id;
        tab[18][5] = id;
        tab[18][6] = id;
    }
    if (tipo == 4 && rot == 1) { //Verificamos se   o quadrado
        tab[16][5] = id;
        tab[17][5] = id;
        tab[17][4] = id;
        tab[18][4] = id;
    }
    if (tipo == 3 && rot == 2) { //Verificamos se   o quadrado
        tab[18][4] = id;
        tab[18][5] = id;
        tab[18][6] = id;
        tab[17][5] = id;
    }
    if (tipo == 3 && rot == 1) { //Verificamos se   o quadrado
        tab[18][5] = id;
        tab[17][5] = id;
        tab[16][5] = id;
        tab[17][6] = id;
    }
    if (tipo == 2 && rot == 1) { //Verificamos se   o quadrado
        tab[16][4] = id;
        tab[16][5] = id;
        tab[17][4] = id;
        tab[18][4] = id;
    }
    if (tipo == 1 && rot == 1) { //Verificamos se   o quadrado
        tab[16][4] = id;
        tab[16][5] = id;
        tab[17][5] = id;
        tab[18][5] = id;
    }
    if (tipo == 1 && rot == 2) { //Verificamos se   o quadrado
        tab[17][4] = id;
        tab[17][5] = id;
        tab[17][6] = id;
        tab[18][4] = id;
    }
    if (tipo == 1 && rot == 3) { //Verificamos se   o quadrado
        tab[18][4] = id;
        tab[18][5] = id;
        tab[17][4] = id;
        tab[16][4] = id;
    }
    if (tipo == 1 && rot == 4) { //Verificamos se   o quadrado
        tab[18][4] = id;
        tab[18][5] = id;
        tab[18][6] = id;
        tab[17][6] = id;
    }
    if (tipo == 2 && rot == 2) { //Verificamos se   o quadrado
        tab[18][4] = id;
        tab[18][5] = id;
        tab[18][6] = id;
        tab[17][4] = id;
    }
    if (tipo == 2 && rot == 3) { //Verificamos se   o quadrado
        tab[18][4] = id;
        tab[18][5] = id;
        tab[17][5] = id;
        tab[16][5] = id;
    }
    if (tipo == 2 && rot == 4) { //Verificamos se   o quadrado
        tab[17][4] = id;
        tab[17][5] = id;
        tab[17][6] = id;
        tab[18][6] = id;
    }
    if (tipo == 3 && rot == 3) { //Verificamos se   o quadrado
        tab[17][4] = id;
        tab[18][5] = id;
        tab[17][5] = id;
        tab[16][5] = id;
    }
    if (tipo == 3 && rot == 4) { //Verificamos se   o quadrado
        tab[17][4] = id;
        tab[17][5] = id;
        tab[17][6] = id;
        tab[18][5] = id;
    }

}

void makeNext(int tipo) {
    if (tipo == 7) { //Verificamos se   o quadrado
        // printf("%i", id);
        next1[2][2] = tipo;
        next1[3][2] = tipo;
        next1[2][3] = tipo;
        next1[3][3] = tipo;
    }
    if (tipo == 6) { //Verificamos se   o quadrado
        next1[1][3] = tipo;
        next1[2][3] = tipo;
        next1[3][3] = tipo;
        next1[4][3] = tipo;
    }

    if (tipo == 5) { //Verificamos se   o quadrado
        next1[1][2] = tipo;
        next1[2][2] = tipo;
        next1[2][3] = tipo;
        next1[3][3] = tipo;
    }

    if (tipo == 4) { //Verificamos se   o quadrado
        next1[1][3] = tipo;
        next1[2][3] = tipo;
        next1[2][2] = tipo;
        next1[3][2] = tipo;
    }

    if (tipo == 3) { //Verificamos se   o quadrado
        next1[1][2] = tipo;
        next1[2][2] = tipo;
        next1[3][2] = tipo;
        next1[2][3] = tipo;
    }

    if (tipo == 2) { //Verificamos se   o quadrado
        next1[1][2] = tipo;
        next1[1][3] = tipo;
        next1[2][2] = tipo;
        next1[3][2] = tipo;
    }

    if (tipo == 1) { //Verificamos se   o quadrado
        next1[1][2] = tipo;
        next1[1][3] = tipo;
        next1[2][3] = tipo;
        next1[3][3] = tipo;
    }

}
void clearNext() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            next1[i][j] = 0;
        }
    }
}

bool GameOver() {
    bool a = false;
    for (int j = 0; j < 9; j++) {
        if (tab[14][j] != 0)
            a = true;
    }
    return a;
}
bool ColideRotacao(int tipo, int id, int rot, int l, int c) {
    bool a = true;

    if (tipo == 6 && rot == 1) {
        if (c + 2 > 8) {
            a = false;
        }
        if (c - 1 < 0) {
            a = false;
        }
        if (tab[l - 1][c - 1] != 0) {
            a = false;
        }
        if (tab[l - 1][c + 1] != 0) {
            a = false;
        }
        if (tab[l - 1][c + 2] != 0) {
            a = false;
        }
    }

    if (tipo == 6 && rot == 2) {
        if (c < 0) {
            a = false;
        }
        if (c > 8) {
            a = false;
        }
        if (tab[l - 1][c] != 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 3][c] != 0) {
            a = false;
        }
    }

    if (tipo == 5 && rot == 1) {
        if (c < 0) {
            a = false;
        }
        if (c + 1 > 8) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 1] != 0) {
            a = false;
        }
    }

    if (tipo == 5 && rot == 2) {
        if (c < 0) {
            a = false;
        }
        if (c > 8) {
            a = false;
        }
        if (tab[l - 1][c] != 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
    }

    if (tipo == 4 && rot == 1) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c + 1] != 0) {
            a = false;
        }
        if (tab[l][c + 2] != 0) {
            a = false;
        }
    }

    if (tipo == 4 && rot == 2) {
        if (c - 1 < 0) {
            a = false;
        }
        if (c > 8) {
            a = false;
        }
        if (tab[l][c - 1] != 0) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
    }

    if (tipo == 3 && rot == 1) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c + 2] != 0) {
            a = false;
        }
        if (tab[l][c + 1] != 0) {
            a = false;
        }
    }
    if (tipo == 3 && rot == 2) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l - 1][c + 2] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 2] != 0) {
            a = false;
        }
    }
    if (tipo == 3 && rot == 3) {
        if (c - 2 < 0) {
            a = false;
        }
        if (c > 8) {
            a = false;
        }
        if (tab[l - 2][c - 1] != 0) {
            a = false;
        }
        if (tab[l - 2][c - 2] != 0) {
            a = false;
        }
    }
    if (tipo == 3 && rot == 4) {
        if (c - 1 < 0) {
            a = false;
        }
        if (c > 8) {
            a = false;
        }
        if (tab[l][c - 1] != 0) {
            a = false;
        }
        if (tab[l - 2][c - 1] != 0) {
            a = false;
        }
    }

    if (tipo == 2 && rot == 1) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l - 2][c + 2] != 0) {
            a = false;
        }
        if (tab[l - 3][c] != 0) {
            a = false;
        }
    }
    if (tipo == 2 && rot == 2) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l - 1][c + 2] != 0) {
            a = false;
        }
        if (tab[l - 2][c + 2] != 0) {
            a = false;
        }
    }
    if (tipo == 2 && rot == 3) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c + 2] != 0) {
            a = false;
        }
        if (tab[l + 1][c + 2] != 0) {
            a = false;
        }
    }
    if (tipo == 2 && rot == 4) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c - 2] != 0) {
            a = false;
        }
        if (tab[l + 1][c - 2] != 0) {
            a = false;
        }
    }
    if (tipo == 1 && rot == 1) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l - 2][c - 2] != 0) {
            a = false;
        }
        if (tab[l - 1][c - 2] != 0) {
            a = false;
        }
    }
    if (tipo == 1 && rot == 2) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l - 2][c] != 0) {
            a = false;
        }
        if (tab[l - 3][c] != 0) {
            a = false;
        }
    }
    if (tipo == 1 && rot == 3) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l][c + 2] != 0) {
            a = false;
        }
        if (tab[l - 1][c + 2] != 0) {
            a = false;
        }
    }
    if (tipo == 1 && rot == 4) {
        if (c < 0) {
            a = false;
        }
        if (c + 2 > 8) {
            a = false;
        }
        if (tab[l + 1][c + 1] != 0) {
            a = false;
        }
        if (tab[l + 2][c + 1] != 0) {
            a = false;
        }
    }
    return a;
}

bool RodarPeca(int tipo, int id, int rot) {
    bool a = true;
    int  l = 0, c = 0;

    if (tipo == 6 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 2][c] = 0;
            tab[l - 3][c] = 0;
            tab[l - 1][c - 1] = id;
            tab[l - 1][c + 1] = id;
            tab[l - 1][c + 2] = id;
            rt = 2;
            return true;
        }
        return false;
    }

    if (tipo == 6 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c + 1] = 0;
            tab[l][c + 2] = 0;
            tab[l][c + 3] = 0;
            tab[l - 1][c] = id;
            tab[l - 2][c] = id;
            tab[l - 3][c] = id;
            rt = 1;
            return true;
        }
        return false;
    }

    if (tipo == 5 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 2][c - 1] = 0;
            tab[l - 2][c] = id;
            tab[l - 2][c + 1] = id;
            rt = 2;
            return true;
        }
        return false;
    }

    if (tipo == 5 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c + 2] = 0;
            tab[l - 1][c] = id;
            tab[l - 2][c] = id;
            rt = 1;
            return true;
        }
        return false;
    }

    if (tipo == 4 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 2][c + 1] = 0;
            tab[l][c + 1] = id;
            tab[l][c + 2] = id;
            rt = 2;
            return true;
        }
        return false;
    }

    if (tipo == 4 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l][c - 1] = id;
            tab[l - 2][c] = id;
            rt = 1;
            return true;
        }
        return false;
    }

    if (tipo == 3 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l - 1][c] = 0;
            tab[l - 2][c] = 0;
            tab[l][c + 1] = id;
            tab[l][c + 2] = id;
            rt = 2;
            return true;
        }
        return false;
    }
    if (tipo == 3 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l][c + 1] = 0;
            tab[l - 1][c + 2] = id;
            tab[l - 2][c + 2] = id;
            rt = 3;
            return true;
        }
        return false;
    }
    if (tipo == 3 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c - 1] = id;
            tab[l - 2][c - 2] = id;
            rt = 4;
            return true;
        }
        return false;
    }
    if (tipo == 3 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c + 1] = 0;
            tab[l][c - 1] = id;
            tab[l - 2][c - 1] = id;
            rt = 1;
            return true;
        }
        return false;
    }

    if (tipo == 2 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 3][c] = id;
            tab[l - 2][c + 2] = id;
            rt = 2;
            return true;
        }
        return false;
    }
    if (tipo == 2 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 1][c + 2] = id;
            tab[l - 2][c + 2] = id;
            rt = 3;
            return true;
        }
        return false;
    }
    if (tipo == 2 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l - 1][c + 1] = 0;
            tab[l - 2][c + 1] = 0;
            tab[l][c + 2] = id;
            tab[l + 1][c + 2] = id;
            rt = 4;
            return true;
        }
        return false;
    }
    if (tipo == 2 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l][c - 2] = id;
            tab[l + 1][c - 2] = id;
            rt = 1;
            return true;
        }
        return false;
    }
    //Peca 1
    if (tipo == 1 && rot == 1) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c] = 0;
            tab[l - 2][c + 1] = id;
            tab[l - 1][c - 1] = id;
            rt = 2;
            return true;
        }
        return false;
    }
    if (tipo == 1 && rot == 2) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c] = 0;
            tab[l - 1][c + 2] = 0;
            tab[l - 2][c] = id;
            tab[l - 3][c] = id;
            rt = 3;
            return true;
        }
        return false;
    }
    if (tipo == 1 && rot == 3) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l - 1][c] = 0;
            tab[l - 2][c] = 0;
            tab[l][c + 2] = id;
            tab[l - 1][c + 2] = id;
            rt = 4;
            return true;
        }
        return false;
    }
    if (tipo == 1 && rot == 4) {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 9; j++) {
                if (tab[i][j] == id) {
                    l = i;
                    c = j;
                    break;
                }
            }
        }
        a = ColideRotacao(tipo, id, rot, l, c);
        if (a) {
            tab[l][c + 2] = 0;
            tab[l - 1][c + 2] = 0;
            tab[l + 2][c + 1] = id;
            tab[l + 1][c + 1] = id;
            rt = 1;
            return true;
        }
        return false;
    }
    return false;
}

int verificaLinha() {


    for (int i = 0; i < 19; i++) {
        if (tab[i][0] != 0 && tab[i][1] != 0 && tab[i][2] != 0 && tab[i][3] != 0 && tab[i][4] != 0 && tab[i][5] != 0 && tab[i][6] != 0 && tab[i][7] != 0 && tab[i][8] != 0) {
            printf("%d\n", i);
            return i;
        }
    }

    return 30; //valor alto para restrio
}

void removerLinha(int l) {

    int aux[9];

    for (int i = l; i < 18; i++) {
        for (int j = 0; j < 9; j++) {
            tab[i][j] = tab[i + 1][j];
        }
    }

    for (int k = 0; k < 9; k++) {
        tab[19][k] = 0;
    }

}
void displayText(float x, float y, int r, int g, int b, const char* string) {
    int j = strlen(string);

    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (int i = 0; i < j; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }


}
void print(int nmr) {
    if (nmr == 0) {
        drawN(0);
        return;
    }
    if (nmr == 1) {
        drawN1(0);
        return;
    }
    if (nmr == 2) {
        drawN2(0);
        return;
    }
    if (nmr == 3) {
        drawN3(0);
        return;
    }
    if (nmr == 4) {
        drawN4(0);
        return;
    }
    if (nmr == 5) {
        drawN5(0);
        return;
    }
    if (nmr == 6) {
        drawN6(0);
        return;
    }
    if (nmr == 7) {
        drawN7(0);
        return;
    }
    if (nmr == 8) {
        drawN8(0);
        return;
    }
    if (nmr == 9) {
        drawN9(0);
        return;
    }
    if (nmr == 10) {
        drawN1(0);
        drawN(1);
        return;
    }
    if (nmr == 11) {
        drawN1(0);
        drawN(1);
        return;
    }
    if (nmr == 12) {
        drawN1(0);
        drawN2(1);
        return;
    }
    if (nmr == 13) {
        drawN1(0);
        drawN3(1);
        return;
    }
    if (nmr == 14) {
        drawN1(0);
        drawN4(1);
        return;
    }
    if (nmr == 15) {
        drawN1(0);
        drawN5(1);
        return;
    }
    if (nmr == 16) {
        drawN1(0);
        drawN6(1);
        return;
    }
    if (nmr == 17) {
        drawN1(0);
        drawN7(1);
        return;
    }
    if (nmr == 18) {
        drawN1(0);
        drawN8(1);
        return;
    }
    if (nmr == 19) {
        drawN1(0);
        drawN9(1);
        return;
    }
    if (nmr == 20) {
        drawN2(0);
        drawN(1);
        return;
    }
    if (nmr == 21) {
        drawN2(0);
        drawN1(1);
        return;
    }
    if (nmr == 22) {
        drawN2(0);
        drawN2(1);
        return;
    }
    if (nmr == 23) {
        drawN2(0);
        drawN3(1);
        return;
    }
    if (nmr == 24) {
        drawN2(0);
        drawN4(1);
        return;
    }
    if (nmr == 25) {
        drawN2(0);
        drawN5(1);
        return;
    }
    if (nmr == 26) {
        drawN2(0);
        drawN6(1);
        return;
    }
    if (nmr == 27) {
        drawN2(0);
        drawN7(1);
        return;
    }
    if (nmr == 28) {
        drawN2(0);
        drawN8(1);
        return;
    }
    if (nmr == 29) {
        drawN2(0);
        drawN9(1);
        return;
    }
    if (nmr == 30) {
        drawN3(0);
        drawN(1);
        return;
    }
    if (nmr == 31) {
        drawN3(0);
        drawN1(1);
        return;
    }
    if (nmr == 32) {
        drawN3(0);
        drawN2(1);
        return;
    }
    if (nmr == 33) {
        drawN3(0);
        drawN3(1);
        return;
    }
    if (nmr == 34) {
        drawN3(0);
        drawN4(1);
        return;
    }
    if (nmr == 35) {
        drawN3(0);
        drawN5(1);
        return;
    }
    if (nmr == 36) {
        drawN3(0);
        drawN6(1);
        return;
    }
    if (nmr == 37) {
        drawN3(0);
        drawN7(1);
        return;
    }
    if (nmr == 38) {
        drawN3(0);
        drawN8(1);
        return;
    }
    if (nmr == 39) {
        drawN3(0);
        drawN9(1);
        return;
    }
    if (nmr == 40) {
        drawN4(0);
        drawN(1);
        return;
    }
    if (nmr == 41) {
        drawN4(0);
        drawN1(1);
        return;
    }
    if (nmr == 42) {
        drawN4(0);
        drawN2(1);
        return;
    }
    if (nmr == 43) {
        drawN4(0);
        drawN3(1);
        return;
    }
    if (nmr == 44) {
        drawN4(0);
        drawN4(1);
        return;
    }
    if (nmr == 45) {
        drawN4(0);
        drawN5(1);
        return;
    }
    if (nmr == 46) {
        drawN4(0);
        drawN6(1);
        return;
    }
    if (nmr == 47) {
        drawN4(0);
        drawN7(1);
        return;
    }
    if (nmr == 48) {
        drawN4(0);
        drawN8(1);
        return;
    }
    if (nmr == 49) {
        drawN4(0);
        drawN9(1);
        return;
    }
    if (nmr == 50) {
        drawN5(0);
        drawN(1);
        return;
    }
    if (nmr == 51) {
        drawN5(0);
        drawN1(1);
        return;
    }
    if (nmr == 52) {
        drawN5(0);
        drawN2(1);
        return;
    }
    if (nmr == 53) {
        drawN5(0);
        drawN3(1);
        return;
    }
    if (nmr == 54) {
        drawN5(0);
        drawN4(1);
        return;
    }
    if (nmr == 55) {
        drawN5(0);
        drawN5(1);
        return;
    }
    if (nmr == 56) {
        drawN5(0);
        drawN6(1);
        return;
    }
    if (nmr == 57) {
        drawN5(0);
        drawN7(1);
        return;
    }
    if (nmr == 58) {
        drawN5(0);
        drawN8(1);
        return;
    }
    if (nmr == 59) {
        drawN5(0);
        drawN9(1);
        return;
    }
    if (nmr == 60) {
        drawN6(0);
        drawN(1);
        return;
    }
    if (nmr == 61) {
        drawN6(0);
        drawN1(1);
        return;
    }
    if (nmr == 62) {
        drawN6(0);
        drawN2(1);
        return;
    }
    if (nmr == 63) {
        drawN6(0);
        drawN3(1);
        return;
    }
    if (nmr == 64) {
        drawN6(0);
        drawN4(1);
        return;
    }
    if (nmr == 65) {
        drawN6(0);
        drawN5(1);
        return;
    }
    if (nmr == 66) {
        drawN6(0);
        drawN6(1);
        return;
    }
    if (nmr == 67) {
        drawN6(0);
        drawN7(1);
        return;
    }
    if (nmr == 68) {
        drawN6(0);
        drawN8(1);
        return;
    }
    if (nmr == 69) {
        drawN6(0);
        drawN9(1);
        return;
    }
    if (nmr == 70) {
        drawN7(0);
        drawN(1);
        return;
    }
    if (nmr == 71) {
        drawN7(0);
        drawN1(1);
        return;
    }
    if (nmr == 72) {
        drawN7(0);
        drawN2(1);
        return;
    }
    if (nmr == 73) {
        drawN7(0);
        drawN3(1);
        return;
    }
    if (nmr == 74) {
        drawN7(0);
        drawN4(1);
        return;
    }
    if (nmr == 75) {
        drawN7(0);
        drawN5(1);
        return;
    }
    if (nmr == 76) {
        drawN7(0);
        drawN6(1);
        return;
    }
    if (nmr == 77) {
        drawN7(0);
        drawN7(1);
        return;
    }
    if (nmr == 78) {
        drawN7(0);
        drawN8(1);
        return;
    }
    if (nmr == 79) {
        drawN7(0);
        drawN9(1);
        return;
    }
    if (nmr == 80) {
        drawN8(0);
        drawN(1);
        return;
    }
    if (nmr == 81) {
        drawN8(0);
        drawN1(1);
        return;
    }
    if (nmr == 82) {
        drawN8(0);
        drawN2(1);
        return;
    }
    if (nmr == 83) {
        drawN8(0);
        drawN3(1);
        return;
    }
    if (nmr == 84) {
        drawN8(0);
        drawN4(1);
        return;
    }
    if (nmr == 85) {
        drawN8(0);
        drawN5(1);
        return;
    }
    if (nmr == 86) {
        drawN8(0);
        drawN6(1);
        return;
    }
    if (nmr == 87) {
        drawN8(0);
        drawN7(1);
        return;
    }
    if (nmr == 88) {
        drawN8(0);
        drawN8(1);
        return;
    }
    if (nmr == 89) {
        drawN8(0);
        drawN9(1);
        return;
    }
    if (nmr == 90) {
        drawN9(0);
        drawN(1);
        return;
    }
    if (nmr == 91) {
        drawN9(0);
        drawN1(1);
        return;
    }
    if (nmr == 92) {
        drawN9(0);
        drawN2(1);
        return;
    }
    if (nmr == 93) {
        drawN9(0);
        drawN3(1);
        return;
    }
    if (nmr == 94) {
        drawN9(0);
        drawN4(1);
        return;
    }
    if (nmr == 95) {
        drawN9(0);
        drawN5(1);
        return;
    }
    if (nmr == 96) {
        drawN9(0);
        drawN6(1);
        return;
    }
    if (nmr == 97) {
        drawN9(0);
        drawN7(1);
        return;
    }
    if (nmr == 98) {
        drawN9(0);
        drawN8(1);
        return;
    }
    if (nmr == 99) {
        drawN9(0);
        drawN9(1);
        return;
    }
}

void Jogo(int id, int dif) {
    int f = 0;
    int x = 1;
    while (x != 30) {
        x = verificaLinha();
        if (x != 30) {
            removerLinha(x);
            pont = pont + 1;
        }
    }

    // id++;
    cores[id] = (rand() % 3) + 1;
    int aux = tiponext;
    int tipo = aux;
    tiponext = (rand() % 7) + 1;


    if (tipo == 1 || tipo == 2 || tipo == 3) {
        rt = (rand() % 4) + 1;
    }
    if (tipo == 4 || tipo == 5 || tipo == 6) {
        rt = (rand() % 2) + 1;
    }
    if (tipo == 7) {
        rt = 1;
    }
    makePeca(tipo, id, rt);
    clearNext();
    makeNext(tiponext);
    atualizaTabuleiro();
    while (f == 0) {
        auto t0 = std::chrono::system_clock::now();
        while ((std::chrono::system_clock::now() - t0) < std::chrono::milliseconds(dif))
        {

            if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
                if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE) {
                    moveLeft(tipo, id, rt);
                }
            }
            if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
                if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE) {
                    while (moveDown(tipo, id, rt)) {
                        atualizaTabuleiro();
                    }

                }
            }
            if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
                if (glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE) {
                    moveRight(tipo, id, rt);
                }
            }
            if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
                if (glfwGetKey(window, GLFW_KEY_R) == GLFW_RELEASE) {
                    RodarPeca(tipo, id, rt);
                    atualizaTabuleiro();
                }
            }
            if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
                if (glfwGetKey(window, GLFW_KEY_L) == GLFW_RELEASE) {
                    verificaLinha();
                }
            }
            //  if (d == 1) {
                 // std::this_thread::sleep_for(std::chrono::milliseconds(100));
               //   glfwSwapBuffers(window);


            glfwPollEvents();
            //  }

        }
        if (!moveDown(tipo, id, rt))
            f = 1;


        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main(void)
{

    int irt = 0;
    glutInit(&irt, NULL);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    win = glutCreateWindow("Menu Inicial");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glOrtho(0, 256, 0, 256, -1, 1);

}

void display(void) {
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    displayText(10.0, 230, 0.0, 0.0, 0.0, "Escolha uma dificuldade para iniciar o jogo");
    displayText(50.0, 200, 1.0, 0.0, 0.0, "1 - Facil");
    displayText(50.0, 150, 1.0, 0.0, 0.0, "2 - Medio");
    displayText(50.0, 100, 1.0, 0.0, 0.0, "3 - Dificil");
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    int id = 0;
    switch (key) {
    case '1':
        glutLeaveMainLoop();
        glutDestroyWindow(win);
        glfwInit();

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Open a window
        window = glfwCreateWindow(WindowWidth, WindowHeight, "Tetris Game", NULL, NULL);
        // Create window context
        glfwMakeContextCurrent(window);

        // Initialize GLEW
        glewExperimental = true; // Needed for core profile
        glewInit();
        // Ensure we can capture the escape key being pressed below
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

        // White background
        glClearColor(0.6f, 0.996f, 0.98431f, 0.0f);
        // transfer my data (vertices, colors, and shaders) to GPU side
        transferDataToGPUMemoryTabuleiro();
        transferDataToGPUMemoryBlock();
        transefereDataToGPUMemoryN();
        inicarTabuleiro();
        imprimeTabuleiro();
        // render scene for each frame

        do {
            id++;
            // drawing callback
            atualizaTabuleiro();
            if (!GameOver()) {
                Jogo(id, 650);

            }
        } // Check if the ESC key was pressed or the window was closed
        while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);


        // Cleanup VAO, VBOs, and shaders from GPU
        cleanupDataFromGPU();

        // Close OpenGL window and terminate GLFW
        glfwTerminate();

        break;
    case '2':
        glutDestroyWindow(win);
        glfwInit();

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Open a window
        window = glfwCreateWindow(WindowWidth, WindowHeight, "Tetris Game", NULL, NULL);
        // Create window context
        glfwMakeContextCurrent(window);

        // Initialize GLEW
        glewExperimental = true; // Needed for core profile
        glewInit();
        // Ensure we can capture the escape key being pressed below
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

        // White background
        glClearColor(0.6f, 0.996f, 0.98431f, 0.0f);
        // transfer my data (vertices, colors, and shaders) to GPU side
        transferDataToGPUMemoryTabuleiro();
        transferDataToGPUMemoryBlock();
        inicarTabuleiro();
        imprimeTabuleiro();
        transefereDataToGPUMemoryN();

        // render scene for each frame

        do {
            id++;
            // drawing callback
            atualizaTabuleiro();
            if (!GameOver()) {
                Jogo(id, 500);

            }
        } // Check if the ESC key was pressed or the window was closed
        while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);


        // Cleanup VAO, VBOs, and shaders from GPU
        cleanupDataFromGPU();

        // Close OpenGL window and terminate GLFW
        glfwTerminate();

        break;
    case '3':
        glutDestroyWindow(win);
        glfwInit();

        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        // Open a window
        window = glfwCreateWindow(WindowWidth, WindowHeight, "Tetris Game", NULL, NULL);
        // Create window context
        glfwMakeContextCurrent(window);

        // Initialize GLEW
        glewExperimental = true; // Needed for core profile
        glewInit();
        // Ensure we can capture the escape key being pressed below
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

        // White background
        glClearColor(0.6f, 0.996f, 0.98431f, 0.0f);
        // transfer my data (vertices, colors, and shaders) to GPU side
        transferDataToGPUMemoryTabuleiro();
        transferDataToGPUMemoryBlock();
        transefereDataToGPUMemoryN();
        inicarTabuleiro();
        imprimeTabuleiro();


        dif = 3;
        // render scene for each frame
        do {
            id++;
            // drawing callback
            atualizaTabuleiro();
            if (!GameOver()) {
                Jogo(id, 400);

            }
        } // Check if the ESC key was pressed or the window was closed
        while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);


        // Cleanup VAO, VBOs, and shaders from GPU
        cleanupDataFromGPU();

        // Close OpenGL window and terminate GLFW
        glfwTerminate();

        break;
    }
}



