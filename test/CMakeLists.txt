include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(test_alloc_dealloc test_alloc_dealloc.c)
target_link_libraries(test_alloc_dealloc dvector)

add_executable(test_push_get test_push_get.c)
target_link_libraries(test_push_get dvector)

add_executable(test_ops test_ops.c)
target_link_libraries(test_ops dvector)

add_executable(test_max_min test_max_min.c)
target_link_libraries(test_max_min dvector)

add_executable(test_norm test_norm.c)
target_link_libraries(test_norm dvector)
