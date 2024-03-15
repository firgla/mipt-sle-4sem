set(SOURCES fixed_point_it.h gauss_seidel.h jacobi.h ../../Dense_CSRMatrix/src/CSRMatrix.h ../../Dense_CSRMatrix/src/vector.h)

add_library(${PROJECT_NAME} INTERFACE ${SOURCES})

target_include_directories(Solvers INTERFACE include)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)