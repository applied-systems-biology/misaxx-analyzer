#include <misaxx/core/misa_module_interface.h>
#include <misaxx-indexer/accessors/misa_output.h>
#include <misaxx-indexer/accessors/attachment_index.h>

namespace misaxx_indexer {
    struct module_interface : public misaxx::misa_module_interface {

        misa_output data;

        void setup() override;
    };
}
