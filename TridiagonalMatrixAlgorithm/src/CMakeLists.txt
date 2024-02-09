set(SOURCES algorithm/algorithm.cpp algorithm/algorithm.h)

add_library(Algorithm ${SOURCES})

target_include_directories(Algorithm PUBLIC include)
