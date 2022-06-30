cmake_minimum_required(VERSION 3.19)




set( CMAKE_CXX_STANDARD 17 )

add_executable( calc_fc tokenizer.cpp parser.cpp main.cpp )


# target_link_libraries( calc_fc PRIVATE
   # graphene_net hive_chain hive_protocol hive_utilities hive_wallet condenser_api_plugin fc fc_implementation common ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
target_link_libraries( calc_fc PRIVATE
   fc fc_implementation common ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )




add_executable(calc_std  tokenizer.cpp parser.cpp main.cpp)
target_link_libraries( calc_std PRIVATE std_implementation common)

add_executable(calc_dynamic tokenizer.cpp parser.cpp main.cpp)
target_link_libraries(calc_dynamic PRIVATE dynamic_implementation common)

add_subdirectory(libraries)
list(APPEND EXTRA_LIBS fc_implementation std_implementation)



install( TARGETS
   calc_fc

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)


project(cal)