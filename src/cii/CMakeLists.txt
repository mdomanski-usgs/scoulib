add_library(assert PRIVATE assert.c assert.h except.h)
add_library(except PRIVATE except.c assert.h except.h)
add_library(mem PRIVATE mem.c assert.h except.h mem.h)

target_link_libraries(assert PUBLIC except)
target_link_libraries(except PUBLIC assert)
target_link_libraries(mem PUBLIC assert except)
