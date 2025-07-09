cmake_minimum_required(VERSION 3.29.6)
project(pack_man_project C)

set(CMAKE_C_STANDARD 23)

include(FetchContent)

function(include_dependency libName gitURL gitTag)
    FetchContent_Declare(${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG        ${gitTag}
            GIT_SHALLOW    TRUE
            GIT_PROGRESS   TRUE
    )
    FetchContent_MakeAvailable(${libName})
endfunction()

set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    message(STATUS "Getting ${LIB1} from Github")
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git 5.5)
else()
    message(STATUS "Using local ${LIB1}")
endif()

add_executable(pack_man_project src/main.c
        include/menu.h
        src/menu.c
        include/game.h
        src/game.c
        include/records.h
        src/records.c
        include/gameOver.h
        src/gameOver.c
        include/degreeOfDifficulty.h
        src/degreeOfDifficulty.c)

target_include_directories(pack_man_project PRIVATE ${raylib_INCLUDE_DIRS})

target_link_libraries(pack_man_project PRIVATE ${LIB1})
include_directories(C:/Users/alite/raylib/src)
link_directories(C:/Users/alite/raylib/lib)
