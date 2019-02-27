//
// Created by rgerst on 26.02.19.
//

#include "misaxx-analyzer/descriptions/misa_output_description.h"

void misaxx_analyzer::misa_output_description::from_json(const nlohmann::json &t_json) {
    misa_folder_description::from_json(t_json);
}

void misaxx_analyzer::misa_output_description::to_json(nlohmann::json &t_json) const {
    misa_folder_description::to_json(t_json);
}

void misaxx_analyzer::misa_output_description::to_json_schema(misaxx::misa_json_schema_property &t_schema) const {
    misa_folder_description::to_json_schema(t_schema);
}

void misaxx_analyzer::misa_output_description::build_serialization_id_hierarchy(
        std::vector<misaxx::misa_serialization_id> &result) const {
    misa_folder_description::build_serialization_id_hierarchy(result);
    result.emplace_back(misaxx::misa_serialization_id("misa-indexer", "descriptions/misa-output"));
}

std::string misaxx_analyzer::misa_output_description::get_documentation_name() const {
    return "MISA Output";
}

std::string misaxx_analyzer::misa_output_description::get_documentation_description() const {
    return "Output of a MISA++ run";
}
