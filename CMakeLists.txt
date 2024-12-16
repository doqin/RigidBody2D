cmake_minimum_required(VERSION 3.30)
project(RigidBody2D)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER /opt/homebrew/opt/llvm/bin/clang)
set(CMAKE_CXX_COMPILER /opt/homebrew/opt/llvm/bin/clang++)
set(INCLUDE ./source)
include_directories(${INCLUDE})
add_executable(${PROJECT_NAME} source/main.cpp
        source/component/GameEngine.cpp
        source/component/GameEngine.h
        source/component/GameScreen.h
        source/component/GameStage.h
        source/component/GameObject.h
        source/screen/GameplayScreen.cpp
        source/screen/GameplayScreen.h
        source/screen/stage/TestStage.cpp
        source/screen/stage/TestStage.h
        source/component/Sprite.cpp
        source/component/Sprite.h
        source/component/Text.cpp
        source/component/Text.h
        source/component/ScreenRepresentation.h
        source/component/PlayerController.cpp
        source/component/PlayerController.h
        source/component/DeltaTime.cpp
        source/component/DeltaTime.h
        source/component/Timer.cpp
        source/component/Timer.h
        source/component/RigidBody2D.cpp
        source/component/RigidBody2D.h
        source/component/BoxCollider2D.cpp
        source/component/BoxCollider2D.h
        source/component/BoundaryCollider2D.h
        source/component/Vector2D.h
        source/component/Point2D.h
        source/component/BoundaryCollider2D.cpp
        source/component/CircleCollider2D.cpp
        source/component/CircleCollider2D.h)

# target_compile_options(${PROJECT_NAME} PRIVATE -target x86_64-w64-mingw32)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "RigidBody2D.exe")


find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
        PRIVATE
        $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
        PRIVATE
        $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
)
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_NAME "RigidBody2D")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "business.doqin@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION "RigidBody2D is a 2D physics engine for game development.")
set(CPACK_GENERATOR "ZIP")

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/assets/ DESTINATION bin/assets)

include(CPack)
