
add_library(screen_servers screen_server_sdl.c screen_server_vga.c screen_server.c)

# target_link_directories(screen_servers PRIVATE "../../SDL2-2.0.20/lib")
# target_link_directories(screen_servers PRIVATE "../../SDL2-2.0.20/lib/x64")

target_link_libraries(screen_servers ${SDL2_LIBRARIES})
