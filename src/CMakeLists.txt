add_subdirectory(cii)
add_library(sizedistribution STATIC sizedistribution.c)
target_link_libraries(sizedistribution PRIVATE assert except mem)
