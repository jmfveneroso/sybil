cmake_minimum_required (VERSION 3.0)
project (Renderer)
set (CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)

if (APPLE) 
  set(ALL_LIBS
    ${OPENGL_LIBRARY}
    glfw
    glew
    freetype
    boost_regex-mt
    boost_system 
    boost_filesystem
  )

  set(INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/include
    /usr/local/Cellar/glew/2.1.0/include
    /usr/local/Cellar/glfw/3.2.1/include
    /usr/local/Cellar/glm/0.9.9.4/include
    /usr/local/Cellar/boost/1.70.0/include
    /usr/local/Cellar/freetype/2.9.1/include/freetype2
  )

  set(LINK_DIRS
    /usr/local/Cellar/glew/2.1.0/lib
    /usr/local/Cellar/glfw/3.2.1/lib
    /usr/local/Cellar/glm/0.9.9.4/lib
    /usr/local/Cellar/boost/1.70.0/lib
    /usr/local/Cellar/freetype/2.9.1/lib
  )
  add_definitions(-DAPPLE)
else()
  set(INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/include
    /usr/include/freetype2/
  )

  link_directories(
    /usr/X11/lib 
    /usr/local/lib
    /usr/lib/x86_64-linux-gnu/
  )
  set(ALL_LIBS
    ${OPENGL_LIBRARY}
    glfw3
    GL 
    GLEW
    X11
    Xrandr 
    Xi 
    Xxf86vm 
    pthread
    freetype
    boost_regex 
    boost_system 
    boost_filesystem
  )
endif()

include_directories(${INCLUDE_DIRS})
link_directories(${LINK_DIRS})

set(
  SRC
  # src/main.cpp 
  src/game_state.cpp 
  src/shaders.cpp 
  src/sky_dome.cpp 
  src/texture.cpp 
  src/shaders.cpp
  src/clipmap.cpp
  src/terrain.cpp
  src/subregion.cpp
  src/building.cpp 
  src/renderer.cpp 
  src/engine.cpp 
  src/plotter.cpp 
  src/entity_manager.cpp 
  src/text_editor.cpp 
)

# Create sybil library.
add_library(sybil ${SRC})
target_link_libraries(sybil ${ALL_LIBS})

# Create main executable.
add_executable(main src/main.cpp)
target_link_libraries(main sybil)

# Create tools.
add_executable(plot_editor tools/plot_editor.cpp)
target_link_libraries(plot_editor sybil)

add_executable(text_editor tools/text_editor.cpp)
target_link_libraries(text_editor sybil)
