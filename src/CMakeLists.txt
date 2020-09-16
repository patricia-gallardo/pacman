include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_add_remote(NAME bincrafters INDEX 1 URL https://api.bintray.com/conan/bincrafters/public-conan)

conan_cmake_run(CONANFILE ../conanfile.py BASIC_SETUP CMAKE_TARGETS BUILD missing)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.cpp")
add_executable(pacman ${sources})
