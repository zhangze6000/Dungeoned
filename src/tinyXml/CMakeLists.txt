AUX_SOURCE_DIRECTORY(. DIR_SRCS)
file(GLOB dungeoned_source_files "*.cpp")
file(GLOB dungeoned_head_files "*.h")
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

add_library(tinyXml STATIC ${dungeoned_source_files} ${dungeoned_head_files})