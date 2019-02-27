cmake_minimum_required(VERSION 3.11) # Or higher if required
project(misaxx-indexer VERSION 0.1.0 DESCRIPTION "MISA++ Indexer")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(misaxx-core REQUIRED)
find_package(SQLite3 REQUIRED)
# Add additional packages if necessary

add_library(misaxx-indexer include/misaxx-indexer/module_interface.h
        include/misaxx-indexer/module.h
        src/misaxx-indexer/module_interface.cpp
        src/misaxx-indexer/module.cpp
        src/misaxx-indexer/utils/sqlite_orm.h
        src/misaxx-indexer/schema_traversion_task.cpp
        src/misaxx-indexer/schema_traversion_task.h
        src/misaxx-indexer/patterns/misa_output_pattern.cpp
        include/misaxx-indexer/patterns/misa_output_pattern.h
        src/misaxx-indexer/descriptions/misa_output_description.cpp
        include/misaxx-indexer/descriptions/misa_output_description.h
        src/misaxx-indexer/descriptions/misa_output_description.cpp
        include/misaxx-indexer/descriptions/misa_output_description.h
        src/misaxx-indexer/patterns/misa_output_pattern.cpp
        include/misaxx-indexer/patterns/misa_output_pattern.h
        src/misaxx-indexer/accessors/misa_output.cpp
        include/misaxx-indexer/accessors/misa_output.h
        src/misaxx-indexer/caches/misa_output_cache.cpp
        include/misaxx-indexer/caches/misa_output_cache.h
        src/misaxx-indexer/attachment_indexer_task.cpp
        src/misaxx-indexer/attachment_indexer_task.h
        src/misaxx-indexer/caches/attachment_index_cache.cpp
        include/misaxx-indexer/caches/attachment_index_cache.h
        src/misaxx-indexer/descriptions/attachment_index_description.cpp
        include/misaxx-indexer/descriptions/attachment_index_description.h
        src/misaxx-indexer/patterns/attachment_index_pattern.cpp
        include/misaxx-indexer/patterns/attachment_index_pattern.h
        src/misaxx-indexer/accessors/attachment_index.cpp
        include/misaxx-indexer/accessors/attachment_index.h)

# Add additional link targets if necessary
target_link_libraries(misaxx-indexer PUBLIC misaxx::misaxx-core PRIVATE SQLite::SQLite3)

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
