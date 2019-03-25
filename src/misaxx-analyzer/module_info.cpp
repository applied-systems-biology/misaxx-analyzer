#include <misaxx/core/misa_mutable_module_info.h>
#include <misaxx/core/module_info.h>
#include <misaxx-analyzer/module_info.h>

misaxx::misa_module_info misaxx_analyzer::module_info() {
    misaxx::misa_mutable_module_info info;
    info.set_id("misaxx-analyzer");
    info.set_version("1.0.0");
    info.set_name("MISA++ Result Analyzer");
    info.set_description("Companion module for MISA-ImageJ that applies performance-critical tasks");

    // External dependency: OME Files
    misaxx::misa_mutable_module_info sqlite_info;
    sqlite_info.set_id("sqlite3");
    sqlite_info.set_name("SQLite");
    sqlite_info.set_version("3");
    sqlite_info.set_url("https://www.sqlite.org/");
    sqlite_info.set_organization("SQLite Consortium");
    sqlite_info.set_license("Public Domain");
    sqlite_info.set_is_external(true);

    info.add_dependency(misaxx::module_info());
    info.add_dependency(std::move(sqlite_info));

    return info;
}