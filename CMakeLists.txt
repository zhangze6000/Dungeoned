cmake_minimum_required (VERSION 2.6)
project (Dungeoned)

# The version number.
set (Remote_System_VERSION_MAJOR 1)
set (Remote_System_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/Dungeoned.h.in"
  "${PROJECT_BINARY_DIR}/Dungeoned.h"
  )

if (WIN32) 
LINK_DIRECTORIES("${PROJECT_SOURCE_DIR}/lib")
#kb2876217
endif(WIN32)

# add the binary tree to the search path for include files
# so that we will find Dungeoned.h
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("include/cocos2dx")
include_directories("include/cocos2dx/include")
include_directories("include/cocos2dx/platform/win32")
include_directories("include/cocos2dx/platform/third_party/win32/OGLES")
include_directories("include/cocos2dx/kazmath/include")
include_directories("include/extensions")
add_subdirectory(src)


