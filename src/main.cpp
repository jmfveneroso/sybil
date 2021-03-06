#include "ioc_container.hpp"
#include "game_state.hpp"
#include "renderer.hpp"
#include "engine.hpp"

using namespace Sibyl;

int main() {
  static IoC::Container& container = IoC::Container::Get();
  container.RegisterInstance<GameState, GameState>();
  container.RegisterInstance<Renderer, Renderer>();
  container.RegisterInstance<TextEditor, TextEditor, GameState, Renderer>();
  container.RegisterInstance<Building, Building, Renderer>();
  container.RegisterInstance<Plotter, Plotter, GameState, Renderer, TextEditor>();
  container.RegisterInstance<EntityManager, EntityManager, GameState, Renderer, TextEditor, Building, Plotter>();
  container.RegisterInstance<Engine, Engine, GameState, Renderer, EntityManager, TextEditor>();

  container.Resolve<Engine>()->Run();
  return 0;
}
