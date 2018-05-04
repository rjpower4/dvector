include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(test_alloc_dealloc test_alloc_dealloc.c)
target_link_libraries(test_alloc_dealloc dvector)

add_executable(test_push_get test_push_get.c)
target_link_libraries(test_push_get dvector)
