#include "engine.hpp"

namespace Sibyl {

Engine::Engine(
  std::shared_ptr<Window> window,
  std::shared_ptr<Renderer> renderer,
  std::shared_ptr<Input> input,
  std::shared_ptr<Physics> physics
) : window_(window), 
    renderer_(renderer), 
    input_(input), 
    physics_(physics) {
}

void Engine::Run() {
  double last_time = glfwGetTime();
  int nb_frames = 0;
  do {
    // Measure speed.
    double current_time = glfwGetTime();
    nb_frames++;

    // If last printf() was more than 1 second ago.
    if (current_time - last_time >= 1.0) { 
      std::printf("%f ms/frame\n", 1000.0 / double(nb_frames));
      nb_frames = 0;
      last_time += 1.0;
    }

    Water::UpdateMoveFactor(1.0f / 60.0f);
    renderer_->Render();

    input_->ProcessInput();
    physics_->UpdateForces();

    window_->SwapBuffers();
  } while (!window_->ShouldClose());

  // Cleanup VBO and shader.
  renderer_->Clean();

  // Close OpenGL window and terminate GLFW.
  window_->Close();
}

} // End of namespace.