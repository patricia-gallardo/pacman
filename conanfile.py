from conans import ConanFile, CMake

class ConanDependencies(ConanFile):

    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_find_package"

    def requirements(self):
        self.requires("sdl2/2.0.8@bincrafters/stable")
        self.requires("sdl2_image/2.0.3@bincrafters/stable")

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='lib', src='lib')
        self.copy("license*", dst="licenses", folder=True, ignore_case=True)
