//
// Created by rgerst on 25.02.19.
//

#include "schema_traversion_task.h"
#include <stack>
#include <iostream>

void misaxx_indexer::schema_traversion_task::work() {

    nlohmann::json input_schemas;
    nlohmann::json output_schemas;

    {
        std::ifstream r;
        r.open("/home/rgerst/tmp/ome_glomeruli/output/attachments/serialization-schemas.json");
        r >> input_schemas;
    }

    std::stack<nlohmann::json> todo;
    for(auto it = input_schemas.begin(); it != input_schemas.end(); ++it) {
        todo.push(it.value());
    }

    while(!todo.empty()) {
        nlohmann::json json = todo.top();
        todo.pop();

        if (json.find("misa:serialization-id") != json.end()) {
            output_schemas[json["misa:serialization-id"].get<std::string>()] = json;
            std::cout << "[Schema Traversion] Added ID " << json["misa:serialization-id"].get<std::string>() << "\n";

            // Add properties if needed
            if(json.find("properties") != json.end()) {
                for(auto it = json["properties"].begin(); it != json["properties"].end(); ++it) {
                    todo.push(it.value());
                }
            }
        }
    }
}

void misaxx_indexer::schema_traversion_task::create_parameters(misaxx::misa_parameter_builder &t_parameters) {

}
