
#include <misaxx-analyzer/module_interface.h>

using namespace misaxx_analyzer;

void module_interface::setup() {
    data.suggest_import_location(filesystem, "");
}

