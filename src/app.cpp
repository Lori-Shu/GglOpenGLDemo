#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include"GglShader.h"
using namespace std;
int main(void) {
  GLFWwindow* window;

  /* Initialize the library */
  if (!glfwInit()) return -1;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  // init glew
  GLenum em= glewInit();
  if(em!=GLEW_OK) cout<<"initglew err"<<endl;
  
  cout<<glGetString(GL_VERSION)<<endl;
  
  double positions[8]={
    0.0,-0.5,
    0.5,0.0,
    0.0,0.5,
    -0.5,0.0
  };
  uint32_t indices[6]={
    0,1,3,
    1,2,3
  };
  uint32_t buffer;
  glGenBuffers(1,&buffer);
  glBindBuffer(GL_ARRAY_BUFFER,buffer);
  glBufferData(GL_ARRAY_BUFFER,8*sizeof(double),positions,GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0,2,GL_DOUBLE,GL_FALSE,2*sizeof(double),0);

  uint32_t indexBuffer;
  glGenBuffers(1, &indexBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(uint32_t), indices,
               GL_STATIC_DRAW);
  mystd::GglShader gglShader{};
  
  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    // draw
    // glDrawArrays(GL_TRIANGLES,0,3);
    // draw with indexBuffer
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,nullptr);
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}