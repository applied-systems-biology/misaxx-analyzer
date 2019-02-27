#include <misaxx/core/misa_module.h>
#include <misaxx-analyzer/module_interface.h>

namespace misaxx_analyzer {
    struct module : public misaxx::misa_module<module_interface> {

        misaxx::misa_parameter<bool> m_enable_schema_traversion;
        misaxx::misa_parameter<bool> m_enable_attachment_indexing;

        using misaxx::misa_module<module_interface>::misa_module;

        void create_blueprints(blueprint_list &t_blueprints, parameter_list &t_parameters) override;
        void build(const blueprint_builder &t_builder) override;
    };
}
