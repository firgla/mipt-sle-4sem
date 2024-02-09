set(SOURCES algorithm/algorithm.cpp algorithm/include/rr/algorithm.h)

add_library(Algorithm ${SOURCES})

target_include_directories(Algorithm PUBLIC include)
