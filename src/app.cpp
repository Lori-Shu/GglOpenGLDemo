#include<GL/glew.h>
#include <GLFW/glfw3.h>
#include<iostream>
#include"GglShader.h"
#include"GglVertexBuffer.h"
#include"GglIndexBuffer.h"
#include"GglVertexArray.h"
#include"VertexBufferLayout.h"
#include"GglRenderer.h"
#include"GglTexture.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
using namespace std;
int main(void) {
  GLFWwindow* window;

  /* Initialize the library */
  if (!glfwInit()) return -1;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  // init glew
  GLenum em= glewInit();
  if(em!=GLEW_OK) cout<<"init glew err"<<endl;
  
  
  cout<<glGetString(GL_VERSION)<<endl;

  float positions[5 * 4] = {
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  // bottom left
      0.5f,  -0.5f, 0.0f, 1.0f, 0.0f,  // bottom right
      0.5f,  0.5f,  0.0f, 1.0f, 1.0f,  // top right
      -0.5f, 0.5f,  0.0f, 0.0f, 1.0f  // top left
  };
  uint32_t indices[6]={
    0,1,2,
    2,3,0
  };
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  // 使用vertex array 可以在切换绑定时自动绑定vertexbuffer

    mystd::GglVertexArray va{};
    mystd::GglVertexBuffer vb{positions,5*4*sizeof(float)};
    mystd::GglIndexBuffer ib{indices, 6};
    mystd::VertexBufferLayout layout;
    layout.push<float>(3);
    layout.push<float>(2);
    va.addVertexBuffer(vb,layout);
  

  mystd::GglShader gglShader{};
  glm::mat4 projection = glm::ortho(-0.5f, 0.5f, -0.5f, 0.5f, -1.0f, 1.0f);

  gglShader.useProgram();
  
  gglShader.setUniform4f("uColor", 0.5f, 0.0f, 0.2f, 0.75f);
  gglShader.setUniformMatrix4f("uProjection",projection);
  std::string programPath;
  gglShader.getProgramDir(programPath);
  mystd::GglTexture tx{programPath + string("image/image3.jpg")};
  tx.bind(0);
  gglShader.setUniform1i("uTexture", 0);
  // unbind 测试能否自动绑定vertexbuffer
    
    // vb.unBindVertexBuffer();
    // ib.unBindIndexBuffer();
    // gglShader.unUseProgram();
    mystd::GglRenderer rderer{va,ib,gglShader};
    for (;;) {
    GLenum em = glGetError();
    if (em == GL_NO_ERROR) {
      break;
    }
    const uint8_t* str = glewGetErrorString(em);
    cout << str << endl;
    }
  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    rderer.clear();
    // draw
    // glDrawArrays(GL_TRIANGLES,0,3);
    // draw with indexBuffer
    tx.bind(0);
    rderer.draw();
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}