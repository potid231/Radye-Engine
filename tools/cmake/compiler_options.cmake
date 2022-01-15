
# Options
option (EXPORT_COMPILE_COMMANDS "Export compile commands" OFF)
option(GENERATE_DEPENDENCY_DATA "Generate dependency data." OFF)
option(GENERATE_EXTERNAL_DATA "Generate external data." OFF)


# EXPORT_COMPILE_COMMANDS
if(EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
    message(STATUS "Export compile commands.")
else(EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS 0)
    message(STATUS "Don't export compile commands.")
endif(EXPORT_COMPILE_COMMANDS)

# GENERATE_EXTERNAL_DATA
if(GENERATE_EXTERNAL_DATA)
    message(STATUS "Generate external data.")
else(GENERATE_EXTERNAL_DATA)
    message(STATUS "Don't generate external data.")
endif(GENERATE_EXTERNAL_DATA)

# GENERATE_DEPENDENCY_DATA
if(GENERATE_DEPENDENCY_DATA)
  if(CMAKE_C_COMPILER_ID MATCHES "GNU"
     OR CMAKE_CXX_COMPILER_ID MATCHES "GNU"
     OR CMAKE_C_COMPILER_ID MATCHES "(Apple)?[Cc]lang"
     OR CMAKE_CXX_COMPILER_ID MATCHES "(Apple)?[Cc]lang")
    add_compile_options(-MD)
  else()
    message(
      WARNING "Cannot generate header dependency on non GCC/Clang compilers.")
  endif()
endif()

