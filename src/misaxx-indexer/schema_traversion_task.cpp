//
// Created by rgerst on 25.02.19.
//

#include "schema_traversion_task.h"

void misaxx_indexer::schema_traversion_task::work() {

    nlohmann::json input_schemas;
    {
        std::ifstream r;
        r.open("/home/rgerst/tmp/ome_glomeruli/output/attachments/serialization-schemas.json");
        r >> input_schemas;
    }



}

void misaxx_indexer::schema_traversion_task::create_parameters(misaxx::misa_parameter_builder &t_parameters) {

}
