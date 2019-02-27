#include <misaxx-analyzer/module.h>
#include <misaxx-analyzer/module_info.h>
#include <misaxx/core/runtime/misa_cli.h>

using namespace misaxx;
using namespace misaxx_analyzer;

int main(int argc, const char** argv) {
    misa_cli<misaxx_analyzer::module> cli(misaxx_analyzer::module_info());
    return cli.prepare_and_run(argc, argv);
}
