#include <misaxx/core/misa_module_interface.h>
#include <misaxx-analyzer/accessors/misa_output.h>
#include <misaxx-analyzer/accessors/attachment_index.h>

namespace misaxx_analyzer {
    struct module_interface : public misaxx::misa_module_interface {

        misa_output data;

        void setup() override;
    };
}
