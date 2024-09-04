cmake_minimum_required(VERSION 3.11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(FetchContent)

FetchContent_Declare(
	glad
	GIT_REPOSITORY https://github.com/Dav1dde/glad.git
	GIT_TAG v0.1.36
)

set(GLAD_PROFILE "core"	CACHE STRING "OpenGL profile")
set(GLAD_GENERATOR "c"	CACHE STRING "Language to generate the binding for")

FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL
    GIT_TAG release-2.30.7
)

FetchContent_MakeAvailable(glad SDL2)

project(
	opengl_template
	VERSION 1.0
	DESCRIPTION # ...
	HOMEPAGE_URL # ...
	LANGUAGES C CXX
)

set(
	SOURCES
	${CMAKE_SOURCE_DIR}/main.c
	# ...
)

set(
	INCLUDE_DIRECTORIES
	# ...
)

set(
	LINK_LIBRARIES
	glad
	SDL2
	# ...
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIRECTORIES})
target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES})

# ----------------------------------
# Section: Compiler & Linker options
# ----------------------------------

if (LINUX)

    # LINUX: Telling the linker to statically link the libgcc and libstdc++ to out project.
    # (Source: https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html)
    target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)

    # LINUX: Setting the target executable's suffix (for linux: *.out).
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".out")

endif()

if (WIN32)

    # WINDOWS: Telling the compiler to build a window application (If you want to make a console application, change this option to: `-mconsole`).
    # (Source: https://gcc.gnu.org/onlinedocs/gcc/Cygwin-and-MinGW-Options.html)
    target_compile_options(${PROJECT_NAME} PRIVATE -mwindows)

    # WINDOWS: Telling the linker to statically link our application.
    # (Source: https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html)
    target_link_options(${PROJECT_NAME} PRIVATE -static)

    # WINDOWS: Setting the target executable's suffix (for Win32: *.exe).
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".exe")

endif()

if (APPLE)

    # APPLE: Telling the linker to link to: IOKit - Access hardware devices and drivers from your apps and services.
    # (Source: https://developer.apple.com/documentation/iokit)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")

    # APPLE: Telling the linker to link to: Cocoa - native object-oriented application programming interface.
    # (Source: https://en.wikipedia.org/wiki/Cocoa_(API))
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")

    # APPLE: Telling the linker to link to: OpenGL - cross-language, cross-platform application programming interface for rendering 2D and 3D vector graphics.
    # (Source: https://en.wikipedia.org/wiki/OpenGL)
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")

    # APPLE: Setting the target executable's suffix (for MacOS: *.app).
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".app")

endif()
