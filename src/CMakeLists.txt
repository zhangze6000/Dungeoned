add_executable(Dungeoned WIN32 main.cxx;AppDelegate.cxx;HelloWorldScene.cxx;main.h;AppDelegate.h;AppMacros.h;HelloWorldScene.h)
add_definitions(-DUNICODE -D_UNICODE)
if (WIN32) 
target_link_libraries (Dungeoned  opengl32.lib;glew32.lib;libcocos2d.lib;libExtensions.lib;pthreadVCE2.lib;libCocosDenshion.lib;libBox2d.lib;libchipmunk.lib;libcurl_imp.lib;websockets.lib)
endif(WIN32)

