# add utils library
add_library(utils utils.c)

# screen_server library
add_subdirectory(screen_server)

# add images library
add_subdirectory(images)

# paint functions lib
add_library(paint_functions paint_functions.c)
target_link_libraries(paint_functions screen_servers utils images)

# add tilemap lib
add_subdirectory(tilemap)

# main exe
add_executable(main main.c)

target_link_directories(main PRIVATE ${SDL2_LIBRARIES})

target_link_libraries(main PRIVATE screen_servers paint_functions)
target_link_libraries(main PRIVATE tilemap images)
target_link_libraries(main PRIVATE ${SDL2_LIBRARIES})

