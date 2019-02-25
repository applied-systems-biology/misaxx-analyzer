#include <misaxx-indexer/module.h>
#include <misaxx-indexer/module_info.h>
#include <misaxx/core/runtime/misa_cli.h>

using namespace misaxx;
using namespace misaxx_indexer;

int main(int argc, const char** argv) {
    misa_cli<misaxx_indexer::module> cli(misaxx_indexer::module_info());
    return cli.prepare_and_run(argc, argv);
}