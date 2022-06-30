cmake_minimum_required(VERSION 3.19)




set( CMAKE_CXX_STANDARD 17 )

add_executable( cal tokenizer.cpp parser.cpp main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling cal with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( HIVE_STATIC_BUILD )
   target_link_libraries( cal PRIVATE
                          "-static-libstdc++ -static-libgcc"
                          graphene_net hive_chain hive_protocol hive_utilities hive_wallet condenser_api_plugin fc fc_implementation common ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
else( HIVE_STATIC_BUILD )
   target_link_libraries( cal PRIVATE
                          graphene_net hive_chain hive_protocol hive_utilities hive_wallet condenser_api_plugin fc fc_implementation common ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
endif( HIVE_STATIC_BUILD )

if( CLANG_TIDY_EXE )
   set_target_properties(
      cal PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

if(MSVC)
  set_source_files_properties( main.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

add_executable(cal_std  tokenizer.cpp parser.cpp main.cpp)
target_link_libraries( cal_std PRIVATE std_implementation common)

add_executable(cal_dynamic tokenizer.cpp parser.cpp main.cpp)
target_link_libraries(cal_dynamic PRIVATE dynamic_implementation common)

add_subdirectory(libraries)
list(APPEND EXTRA_LIBS fc_implementation std_implementation)



install( TARGETS
   cal

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)


project(cal)