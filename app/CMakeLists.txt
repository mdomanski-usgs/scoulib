add_executable(app app.c)
target_include_directories(app PRIVATE "../src")
target_link_libraries(app mem sizedistribution)
