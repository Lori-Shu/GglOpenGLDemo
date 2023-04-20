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
#include<imgui.h>
#include<imgui_impl_glfw.h>
#include<imgui_impl_opengl3.h>
using namespace std;

static void glfw_error_callback(int error, const char* description) {
  fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}
int main(void) {
  glfwSetErrorCallback(glfw_error_callback);
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
  glfwSwapInterval(1);

  // init glew
  GLenum em= glewInit();
  if(em!=GLEW_OK) cout<<"init glew err"<<endl;
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
  ImGui::StyleColorsLight();
  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

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
  glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    glm::mat4 view=glm::translate(glm::mat4(1.0f),glm::vec3(0.3f,0.0f,0.0f));
    glm::mat4 model =
        glm::translate(glm::mat4{1.0f}, glm::vec3{0.0f, -0.3f, 0.0f});
    glm::mat4 mvp=projection*view*model;
    gglShader.useProgram();

    gglShader.setUniform4f("uColor", 0.5f, 0.0f, 0.2f, 0.75f);
    
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
    float imageTranslateXY[2]={0.0f};
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
    /* Render here */
    rderer.clear();
    model =
        glm::translate(glm::mat4{1.0f}, glm::vec3{imageTranslateXY[0], imageTranslateXY[1], 0.0f});
    mvp = projection * view * model;
    
    // draw
    // glDrawArrays(GL_TRIANGLES,0,3);
    // draw with indexBuffer
    
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    gglShader.useProgram();
    gglShader.setUniformMatrix4f("uMVP", mvp);
    tx.bind(0);
    rderer.draw();
    glm::mat4 secondView =
        glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    mvp=projection*secondView;
    gglShader.useProgram();
    gglShader.setUniformMatrix4f("uMVP", mvp);
    tx.bind(0);
    rderer.draw();
    // imgui demo window
    ImGui::Begin("hello world");
    ImGui::SliderFloat2("imagexy:",imageTranslateXY,-0.5f,0.5f);

    ImGui::End();
    // Rendering
    ImGui::Render();
    // int display_w, display_h;
    // glfwGetFramebufferSize(window, &display_w, &display_h);
    // glViewport(0, 0, display_w, display_h);
    // // glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w,
    // //              clear_color.z * clear_color.w, clear_color.w);
    // glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }
  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);

  glfwTerminate();
  return 0;
}