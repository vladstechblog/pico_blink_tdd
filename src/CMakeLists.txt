add_library(App STATIC App.c Util.c)
target_include_directories(App PUBLIC include)
target_link_libraries(App PUBLIC pico_stdlib)

add_executable(blink main.c)
target_include_directories(blink PUBLIC include)
target_link_libraries(blink PUBLIC App pico_stdlib)

pico_add_extra_outputs(blink)
