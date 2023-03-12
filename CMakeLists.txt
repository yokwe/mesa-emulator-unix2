cmake_minimum_required (VERSION 3.24.0)

project(mesa-emulator-unix2 VERSION 0.0.1 LANGUAGES CXX)

#
# common setting
#
# host name and system
cmake_host_system_information(RESULT HOST_NAME QUERY HOSTNAME)
set(HOST_SYSTEM ${CMAKE_HOST_SYSTEM_NAME})
message(STATUS "NAME       ${HOST_NAME}")
message(STATUS "SYSTEM     ${HOST_SYSTEM}")

# default c++ language level
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# default compiler options
set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -g -O2 -fPIC -flto")

# default linker options
set(CMAKE_EXE_LINKER_FLAGS "-g -rdynamic -flto -v")

# prepare data files
message(STATUS "Copy debug.properties")
configure_file(data/debug.properties.in run/debug.properties @ONLY)

#
# platform dependant setting
#
if(${HOST_SYSTEM} STREQUAL FreeBSD)
  #
  # FreeBSD
  #
  # require for backtrace
  link_libraries (execinfo)
  # default include directories
  include_directories(SYSTEM
    /usr/include
    /usr/include/c++/v1
    /usr/local/include
    )
  # default link directories
  link_directories(/usr/lib /usr/local/lib)
elseif (${HOST_SYSTEM} STREQUAL Darwin)
  #
  # MacOS
  #
  # Compile for arm64
  set(CMAKE_OSX_ARCHITECTURES arm64)
  #
  # default include directories
  #   clang++ -x c++ -E - -v -std=c++17  </dev/null
  set(COMMAND_LINE_TOOLS_PATH "/Library/Developer/CommandLineTools")
  include_directories(SYSTEM
    /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1
    /Library/Developer/CommandLineTools/usr/lib/clang/14.0.0/include
    /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
    /Library/Developer/CommandLineTools/usr/include
    /opt/local/include
    )
  # default link directories
  link_directories(/usr/lib /opt/local/lib)
else()
  message(FATAL_ERROR "Unknown system ${HOST_SYSTEM}")
endif()

# common library
link_libraries (log4cxx)

# add subdirectory
add_subdirectory (src/util          build/util)
add_subdirectory (src/main          build/main)
