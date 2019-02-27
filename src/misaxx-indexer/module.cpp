
#include <misaxx-indexer/module.h>
#include "schema_traversion_task.h"
#include "attachment_indexer_task.h"

using namespace misaxx_indexer;

void module::create_blueprints(blueprint_list &t_blueprints, parameter_list &t_parameters) {
    t_blueprints.add(create_blueprint<schema_traversion_task>("schema-traversion"));
    t_blueprints.add(create_blueprint<attachment_indexer_task>("attachment-indexer"));
}

void module::build(const misaxx::misa_dispatcher::blueprint_builder &t_builder) {
    if(!boost::filesystem::exists(data.get_location() / "attachments" / "serialization-schemas-full.json"))
        t_builder.build<schema_traversion_task>("schema-traversion");
    else
        std::cout << "Skipping serialization schema traversion ..." << "\n";

    if(!boost::filesystem::exists(data.get_location() / "attachment-index.sqlite")) {
        for(const auto &attachments : get_module_as<module_interface>()->data.get_attachments()) {
            auto &task = t_builder.build<attachment_indexer_task>("attachment-indexer");
            task.attachments = attachments;
        }
    }
    else {
        std::cout << "Skipping attachment indexing ..." << "\n";
    }
}

