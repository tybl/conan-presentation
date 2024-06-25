from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.scm import Git

class logRecipe(ConanFile):
    name = "swp-log"
    version = "1.3.1"
    package_type = "library"

    # Optional metadata
    author = "Brandon Lyons tlyons@srcinc.com"
    url = "https://engbb.srcinc.com/projects/SWP/repos/log/browse"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = { "fPIC": [True, False], "shared": [True, False], }
    default_options = { "fPIC": True, "shared": False, }

    exports_sources = "CMakeLists.txt", "log/include/*.hpp", "log/lib/*.cpp"

    def requirements(self):
        self.requires("gtest/[>=1.8.1 <=1.14.0]")

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["log_srcinc"]
        self.cpp_info.includedirs = ["include", "include/log"]
