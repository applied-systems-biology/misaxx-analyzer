#include <misaxx/core/misa_mutable_module_info.h>
#include <misaxx/core/module_info.h>
#include <misaxx-analyzer/module_info.h>

misaxx::misa_module_info misaxx_analyzer::module_info() {
    misaxx::misa_mutable_module_info info;
    info.set_id("misaxx-analyzer");
    info.set_version("0.1.0");
    info.set_name("MISA++ Analysis Helper");
    info.set_description("A MISA++ module");
    
    info.add_dependency(misaxx::module_info());
    // TODO: Add dependencies via info.add_dependency()
    return info;
}