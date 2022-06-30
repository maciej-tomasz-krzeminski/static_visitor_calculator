add_library(common INTERFACE)
target_include_directories(common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
install(TARGETS common DESTINATION lib)
install(FILES exceptions.hpp DESTINATION include)