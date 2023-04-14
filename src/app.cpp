#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include"GglShader.h"
#include"GglVertexBuffer.h"
#include"GglIndexBuffer.h"
#include"GglVertexArray.h"
#include"VertexBufferLayout.h"
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
  // 使用vertex array 可以在切换绑定时自动绑定vertexbuffer

    mystd::GglVertexArray va{};
    mystd::GglVertexBuffer vb{positions,8};
    mystd::VertexBufferLayout layout;
layout.push<double>(2);
va.addVertexBuffer(vb,layout);
  mystd::GglIndexBuffer ib{indices,6};

  mystd::GglShader gglShader{};
  // unbind 测试能否自动绑定vertexbuffer
    gglShader.unUseProgram();
    vb.unBindVertexBuffer();
    ib.unBindIndexBuffer();
  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    // draw
    // glDrawArrays(GL_TRIANGLES,0,3);
    // draw with indexBuffer
    gglShader.useProgram();
    gglShader.setUniform("uColor",0.5f,0.0f,0.2f,0.75f);
    va.bindVertexArray();
    ib.bindIndexBuffer();
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}