cmake_minimum_required(VERSION 3.24)
project(Chandler-vs-Janices)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(RESOURCE_FILES
        resources.qrc
        )

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

qt5_add_resources(RESOURCE_SOURCES ${RESOURCE_FILES})

add_executable(Chandler-vs-Janices main.cpp Headers/Player.h Sources/Player.cpp Sources/Bullet.cpp Headers/Bullet.h Sources/Enemy.cpp Headers/Enemy.h Sources/Game.cpp Headers/Game.h Headers/Score.h Sources/Score.cpp Headers/Health.h Sources/Health.cpp ${RESOURCE_SOURCES} Headers/GameMacros.h Sources/HighScore.cpp Headers/HighScore.h Sources/MyQObjectModel.cpp Headers/MyQObjectModel.h)

target_link_libraries(Chandler-vs-Janices
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        )
