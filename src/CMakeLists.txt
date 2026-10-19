add_library(App STATIC App.c)
target_include_directories(App PUBLIC include)
target_link_libraries(App PUBLIC pico_stdlib)
