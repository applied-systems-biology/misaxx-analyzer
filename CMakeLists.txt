cmake_minimum_required(VERSION 3.11) # Or higher if required
project(misaxx-analyzer VERSION 0.1.0 DESCRIPTION "MISA++ Analysis Helper")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(misaxx-core REQUIRED)
find_package(SQLite3 REQUIRED)
# Add additional packages if necessary

add_library(misaxx-analyzer include/misaxx-analyzer/module_interface.h
        include/misaxx-analyzer/module.h
        src/misaxx-analyzer/module_interface.cpp
        src/misaxx-analyzer/module.cpp
        src/misaxx-analyzer/utils/sqlite_orm.h
        src/misaxx-analyzer/schema_traversion_task.cpp
        src/misaxx-analyzer/schema_traversion_task.h
        src/misaxx-analyzer/patterns/misa_output_pattern.cpp
        include/misaxx-analyzer/patterns/misa_output_pattern.h
        src/misaxx-analyzer/descriptions/misa_output_description.cpp
        include/misaxx-analyzer/descriptions/misa_output_description.h
        src/misaxx-analyzer/descriptions/misa_output_description.cpp
        include/misaxx-analyzer/descriptions/misa_output_description.h
        src/misaxx-analyzer/patterns/misa_output_pattern.cpp
        include/misaxx-analyzer/patterns/misa_output_pattern.h
        src/misaxx-analyzer/accessors/misa_output.cpp
        include/misaxx-analyzer/accessors/misa_output.h
        src/misaxx-analyzer/caches/misa_output_cache.cpp
        include/misaxx-analyzer/caches/misa_output_cache.h
        src/misaxx-analyzer/attachment_indexer_task.cpp
        src/misaxx-analyzer/attachment_indexer_task.h
        src/misaxx-analyzer/caches/attachment_index_cache.cpp
        include/misaxx-analyzer/caches/attachment_index_cache.h
        src/misaxx-analyzer/descriptions/attachment_index_description.cpp
        include/misaxx-analyzer/descriptions/attachment_index_description.h
        src/misaxx-analyzer/patterns/attachment_index_pattern.cpp
        include/misaxx-analyzer/patterns/attachment_index_pattern.h
        src/misaxx-analyzer/accessors/attachment_index.cpp
        include/misaxx-analyzer/accessors/attachment_index.h)

# Add additional link targets if necessary
target_link_libraries(misaxx-analyzer PUBLIC misaxx::misaxx-core PRIVATE SQLite::SQLite3)

# MISA++ helper script (automatically included by Core Library)
set(MISAXX_LIBRARY misaxx-analyzer)
set(MISAXX_LIBRARY_NAMESPACE misaxx::)
set(MISAXX_API_NAME misaxx_analyzer)
set(MISAXX_API_INCLUDE_PATH misaxx-analyzer)
set(MISAXX_API_NAMESPACE misaxx_analyzer)
misaxx_with_default_module_info()
misaxx_with_default_api()

# Only if it's a worker module:
misaxx_with_default_executable()
