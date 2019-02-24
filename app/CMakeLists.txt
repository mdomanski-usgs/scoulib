add_executable(app app.c)
target_include_directories(app PRIVATE "../src/cii")
target_link_libraries(app mem sizedistribution)
