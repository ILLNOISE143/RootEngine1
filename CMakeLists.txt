cmake_minimum_required(VERSION 3.8)
project(rootengine)
add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(PROJECT_EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)
set(PROJECT_RESOURCES_DIR ${CMAKE_SOURCE_DIR}/res)

if(WIN32)
    set(ICON ${PROJECT_RESOURCES_DIR}/app.rc)
endif()

file(GLOB
     CS ${PROJECT_SOURCE_DIR}/*.c
)

file(GLOB
    CPPS ${PROJECT_SOURCE_DIR}/*.cpp
)

file(GLOB
     HS ${PROJECT_INCLUDE_DIR}/*.h
)

file(GLOB
     HPPS ${PROJECT_INCLUDE_DIR}/*.hpp
)

set(PROJECT_SOURCES
    ${CPPS}
    ${CS}
)

set(PROJECT_HEADERS
    ${HPPS}
    ${HS}
)

add_executable(${PROJECT_NAME}
    ${ICON}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS})

include_directories(${PROJECT_INCLUDE_DIR})

set(glfw3_DIR ${PROJECT_EXTERNAL_DIR}/GLFW/lib/cmake/glfw3)
find_package(glfw3)
target_link_libraries(${PROJECT_NAME} glfw)
