add_library(tmatrix INTERFACE)

target_include_directories(tmatrix INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

get_property ( LIB_LIST GLOBAL PROPERTY LIBS_P)
list(APPEND LIB_LIST tmatrix)
set_property ( GLOBAL PROPERTY LIBS_P ${LIB_LIST})