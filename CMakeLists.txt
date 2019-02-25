cmake_minimum_required(VERSION 3.11) # Or higher if required
project(misaxx-indexer VERSION 0.1.0 DESCRIPTION "MISA++ Indexer")

find_package(misaxx-core REQUIRED)
# Add additional packages if necessary

add_library(misaxx-indexer include/misaxx-indexer/module_interface.h
        include/misaxx-indexer/module.h
        src/misaxx-indexer/module_interface.cpp
        src/misaxx-indexer/module.cpp
        src/misaxx-indexer/util/sqlite_orm.h)

# Add additional link targets if necessary
target_link_libraries(misaxx-indexer misaxx::misaxx-core)

# MISA++ helper script (automatically included by Core Library)
set(MISAXX_LIBRARY misaxx-indexer)
set(MISAXX_LIBRARY_NAMESPACE misaxx::)
set(MISAXX_API_NAME misaxx_indexer)
set(MISAXX_API_INCLUDE_PATH misaxx-indexer)
set(MISAXX_API_NAMESPACE misaxx_indexer)
misaxx_with_default_module_info()
misaxx_with_default_api()

# Only if it's a worker module:
misaxx_with_default_executable()
