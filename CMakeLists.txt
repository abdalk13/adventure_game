cmake_minimum_required(VERSION 3.25.1)
project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(NCURSES REQUIRED ncursesw)

include_directories(${NCURSES_INCLUDE_DIRS})
include_directories(src)

set(SOURCE_FILES
    main.cpp
    src/enemy.cpp
    src/game.cpp
    src/item.cpp
    src/player.cpp
    src/room.cpp
    src/world.cpp
)

set(HEADER_FILES
    src/enemy.h
    src/game.h
    src/item.h
    src/player.h
    src/room.h
    src/world.h
	src/inventory.h
)

add_executable(Game ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(Game ${NCURSES_LIBRARIES})
