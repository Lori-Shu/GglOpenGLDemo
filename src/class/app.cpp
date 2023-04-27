
#include"App.h"


using namespace std;
static void glfw_error_callback(int error, const char* description) {
  fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}
namespace mystd {
App::App(){
    if(initEnvironment()!=0){
        cout<<"environment err"<<endl;
    }
}
App::~App(){
  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(windowPtr);

  glfwTerminate();
}
void App::runMainLoop() {
  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(windowPtr)) {
    /* Render here */
    rdererPtr->clear();
    model = glm::translate(
        glm::mat4{1.0f},
        glm::vec3{imageTranslateXYZ[0], imageTranslateXYZ[1],
                  imageTranslateXYZ[2]});
    // view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f,
    // -imageTranslateZ));
    mvp = projectionPerspective * view * model;
    gglShaderPtr->useProgram();
    gglShaderPtr->setUniformMatrix4f("uMVP", mvp);
    loadVertexBufferDynamicly();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // imgui demo window
    ImGui::Begin("hello world");
    ImGui::SliderFloat("==imageX", imageTranslateXYZ, -0.5f, 0.5f);
    ImGui::SliderFloat("==imageY", imageTranslateXYZ+1, -0.5f, 0.5f);

    ImGui::End();
    ImGui::Begin("test window");
    // bool
    // createTableRes=ImGui::BeginTable("tests",1,ImGuiTableFlags_Borders|ImGuiTableFlags_RowBg|ImGuiTableFlags_ScrollY);
    // if(!createTableRes){
    //     cout<<"创建table失败"<<endl;
    // }
    // ImGui::TableSetupColumn("testcolmn", ImGuiTableColumnFlags_WidthStretch,
    //                         100.0f);
    ImGui::BeginChild("TestColumns");
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
    for (int32_t index = 0; index < testVt.size();) {
      ImGui::Columns(1);
      currentTestPtr = testVt[index];
      //   ImGui::TableNextRow(0,20.0f);
      //   ImGui::TableSetColumnIndex(0);
      if (ImGui::Button(
              (currentTestPtr->testName + to_string(index)).c_str())) {
        currentTestPtr->showTestWindow = !currentTestPtr->showTestWindow;
      }
      currentTestPtr->onImGuiRender();
      ++index;
    }
    ImGui::PopStyleVar();
    ImGui::EndChild();
    // ImGui::EndTable();
    ImGui::End();
    // Rendering
    ImGui::Render();
    // int display_w, display_h;
    // glfwGetFramebufferSize(window, &display_w, &display_h);
    // glViewport(0, 0, 100, 100);
    // // glClearColor(clear_color.x * clear_color.w, clear_color.y *
    // clear_color.w,
    // //              clear_color.z * clear_color.w, clear_color.w);
    // glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    rdererPtr->draw();
    /* Swap front and back buffers */
    glfwSwapBuffers(windowPtr);

    /* Poll for and process events */
    glfwPollEvents();
  }
    }

    void App::loadVertexBufferDynamicly(){
        dynamicVbPtr->bindVertexBuffer();
        std::array<GglVertex, 4> r1=createVertexVec4(-1.0f, 0.0f, 0.0f);
        std::array<GglVertex, 4> r2 = createVertexVec4(0.0f,-1.0f, 1.0f);
        float ptr[sizeof(GglVertex)*4*2];
        memcpy(ptr, &r1, sizeof(GglVertex) * 4);
        memcpy(ptr + sizeof(GglVertex) * 4, &r2, sizeof(GglVertex) * 4);
        glBufferSubData(dynamicVbPtr->id, 0,sizeof(ptr) ,static_cast<const void*>(ptr));
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                              sizeof(GglVertex),
                              reinterpret_cast<const void*>(offsetof(GglVertex,position)));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(
            1, 4, GL_FLOAT, GL_FALSE, sizeof(GglVertex),
            reinterpret_cast<const void*>(offsetof(GglVertex, color)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(
            2, 2, GL_FLOAT, GL_FALSE, sizeof(GglVertex),
            reinterpret_cast<const void*>(offsetof(GglVertex, texCoord)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(
            3, 1, GL_FLOAT, GL_FALSE, sizeof(GglVertex),
            reinterpret_cast<const void*>(offsetof(GglVertex, vertexId)));
        glEnableVertexAttribArray(3);
    }
    // create rectangle Vertex by bottom left point
    std::array<GglVertex, 4> App::createVertexVec4(float botlx,float botly,float id){
        // widandheight
        float wAndh=0.5f;
        // botleft
        GglVertex v1{botlx,botly,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,id};
        // botright
        GglVertex v2{botlx+wAndh, botly, 0.0f, 0.0f, 0.0f,
                     0.0f,  0.0f,  1.0f, 0.0f, id};
        // topleft
        GglVertex v3{botlx, botly + wAndh, 0.0f, 0.0f, 0.0f,
                     0.0f,  0.0f,          0.0f, 1.0f, id};
        // topright
        GglVertex v4{botlx + wAndh, botly + wAndh, 0.0f, 0.0f, 0.0f,
                     0.0f,          0.0f,          1.0f, 1.0f, id};
        return std::array<GglVertex, 4>{v1,v2,v3,v4};
    }
    int32_t App::initEnvironment(){
  glfwSetErrorCallback(glfw_error_callback);

  /* Initialize the library */
  if (!glfwInit()) return -1;

  /* Create a windowed mode window and its OpenGL context */
  windowPtr = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
  if (!windowPtr) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(windowPtr);
  glfwSwapInterval(1);

  // init glew
  GLenum em = glewInit();
  if (em != GLEW_OK) cout << "init glew err" << endl;
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
  ImGui::StyleColorsLight();
  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(windowPtr, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  cout << glGetString(GL_VERSION) << endl;

  float positions[] = {
      // two textures
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f,  // bottom left
      0.0f,  -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
      0.0f,  0.0f,  0.0f, 1.0f, 1.0f, 0.0f,  // top right
      -0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 0.0f,  // top left

      0.5f,  -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,  // bottom left
      1.0f,  -0.5f, 0.0f, 1.0f, 0.0f, 1.0f,  // bottom right
      1.0f,  0.0f,  0.0f, 1.0f, 1.0f, 1.0f,  // top right
      0.5f,  0.0f,  0.0f, 0.0f, 1.0f, 1.0f   // top left
  };
  uint32_t indices[] = {0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4};
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  // 使用vertex array 可以在切换绑定时自动绑定vertexbuffer

  vaPtr = make_unique<mystd::GglVertexArray>();
  vbPtr =make_unique <mystd::GglVertexBuffer>(positions, 6 * 8 * sizeof(float));
  ibPtr=make_unique<mystd::GglIndexBuffer>(indices, 12);
  mystd::VertexBufferLayout layout;
  layout.push<float>(3);
  layout.push<float>(2);
  layout.push<float>(1);
  vaPtr->addVertexBuffer(*vbPtr, layout);

  gglShaderPtr = make_unique<mystd::GglShader>();
  dynamicVbPtr=make_unique<GglDynamicVertexBuffer>();
  projectionPerspective =
      glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
  //   projectionOrth = glm::ortho(0.0f, 100.0f, 0.0f, 100.0f, 0.0f, 100.0f);
  view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
  model =
      glm::translate(glm::mat4{1.0f}, glm::vec3{0.0f, 0.0f, 0.0f});
  mvp = projectionPerspective * view * model;
  gglShaderPtr->useProgram();

  gglShaderPtr->setUniform4f("uColor", 0.5f, 0.0f, 0.2f, 1.0f);
  getProgramDir(programPath);
  textureVector.push_back(
      make_unique<mystd::GglTexture>(programPath + string("image/image3.jpg")));
  textureVector.push_back(
      make_unique<mystd::GglTexture>(programPath + string("image/image1.png")));
  // tx.bind(0);
  // gglShader.setUniform1i("uTexture", 0);
  // tx1.bind(1);
  // gglShader.setUniform1i("uTexture", 1);
  gglShaderPtr->bindUniformTextureUnit(
      vector<uint32_t>{textureVector[0]->getTextureId(), textureVector[1]->getTextureId()});
  gglShaderPtr->setUniformSamplerArray("uTexture", 2);
  rdererPtr = make_unique<  mystd::GglRenderer>(*vaPtr, *ibPtr, *gglShaderPtr);
  for (;;) {
    GLenum em = glGetError();
    if (em == GL_NO_ERROR) {
      break;
    }
    const uint8_t* str = glewGetErrorString(em);
    cout << str << endl;
  }
  bkPtr = make_unique<mystd::GglBackground>(windowPtr);
//   cout<<"xyz z=="<<*(imageTranslateXYZ+2)<<endl;
  bkPtr->setMouseControlBkImageZ(imageTranslateXYZ+2);
  // mystd::TextureTest txt3{programPath + string("image/image3.jpg")};
  // testVt.push_back(&txt3);
  // mystd::TextureTest txt2{programPath + string("image/image2.jpg")};
  // testVt.push_back(&txt2);
  // mystd::TextureTest txt1{programPath + string("image/image1.png")};
  // testVt.push_back(&txt1);
  // mystd::TextureTest txt0{programPath + string("image/image0.jpg")};
  // testVt.push_back(&txt0);
//   mystd::GglBKColorTest bkCTest{gglShaderPtr.get()};
//   testVt.push_back(&bkCTest);
  gglShaderPtr->bindUniformTextureUnit(vector<uint32_t>{
      textureVector[0]->getTextureId(), textureVector[1]->getTextureId()});
  return 0;
    }
}


int main(void) {
    mystd::App app{};
    app.runMainLoop();
  return 0;
}
