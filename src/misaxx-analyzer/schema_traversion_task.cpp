//
// Created by rgerst on 25.02.19.
//

#include "schema_traversion_task.h"
#include <stack>
#include <iostream>
#include <misaxx-analyzer/module_interface.h>

void misaxx_analyzer::schema_traversion_task::work() {

    auto input_access = get_module_as<module_interface>()->data.get_attachment_schemas().access_readonly();
    auto output_access = get_module_as<module_interface>()->data.get_full_attachment_schemas().access_write();
    const nlohmann::json &input_schemas = input_access.get();
    nlohmann::json output_schemas;

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
        }


        // Add properties if needed
        if(json.find("properties") != json.end()) {
            for(auto it = json["properties"].begin(); it != json["properties"].end(); ++it) {
                todo.push(it.value());
            }
        }
        if(json.find("additionalProperties") != json.end()) {
            todo.push(json["additionalProperties"]);
        }
        if(json.find("items") != json.end()) {
            todo.push(json["items"]);
        }
    }

    output_access.set(std::move(output_schemas));
}

void misaxx_analyzer::schema_traversion_task::create_parameters(misaxx::misa_parameter_builder &t_parameters) {

}
