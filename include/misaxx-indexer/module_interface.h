#include <misaxx/core/misa_module_interface.h>

namespace misaxx_indexer {
    struct module_interface : public misaxx::misa_module_interface {
        void setup() override;
    };
}
