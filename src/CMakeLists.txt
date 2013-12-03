add_subdirectory (tinyXml)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
file(GLOB dungeoned_source_files "*.cxx")
file(GLOB dungeoned_head_files "*.h")

#add_executable(Dungeoned WIN32 main.cxx;AppDelegate.cxx;LayerMenu.cpp;SceneMenu.cpp;HelloWorldScene.cxx;main.h;SceneMenu.h;LayerMenu.h;AppDelegate.h;AppMacros.h;HelloWorldScene.h)
ADD_EXECUTABLE(Dungeoned WIN32 ${dungeoned_source_files} ${dungeoned_head_files} )
add_definitions(-DUNICODE -D_UNICODE)
target_link_libraries (Dungeoned  tinyXml)
if (WIN32) 
target_link_libraries (Dungeoned  opengl32.lib;glew32.lib;libcocos2d.lib;libExtensions.lib;pthreadVCE2.lib;libCocosDenshion.lib;libBox2d.lib;libchipmunk.lib;libcurl_imp.lib;websockets.lib)
endif(WIN32)
file(COPY "${PROJECT_SOURCE_DIR}/language" DESTINATION  "${CMAKE_CURRENT_BINARY_DIR}")

