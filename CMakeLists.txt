cmake_minimum_required(VERSION 3.7)

project(rpg_test)


if(WIN32) # manual paths for windows
    set(SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/include")
    set(SDL2_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x64/SDL2.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x64/SDL2main.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x64/SDL2test.lib")
    # copy dll file
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/SDL2/lib/x64/SDL2.dll" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/src/Debug/")

elseif(UNIX) # auto paths for Linux
    find_package(SDL2 REQUIRED)

else()
    message("Only Windows and Linux are supported at this time")
endif()



include_directories(${SDL2_INCLUDE_DIRS})

message("SDL include set to: " ${SDL2_INCLUDE_DIRS})
message("SDL lib set to: " ${SDL2_LIBRARIES})

add_subdirectory(src)
