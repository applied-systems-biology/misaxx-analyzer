//
// Created by rgerst on 26.02.19.
//

#include "misaxx-indexer/descriptions/misa_sqlite_description.h"

void misaxx_indexer::misa_sqlite_description::from_json(const nlohmann::json &t_json) {
    misa_file_description::from_json(t_json);
}

void misaxx_indexer::misa_sqlite_description::to_json(nlohmann::json &t_json) const {
    misa_file_description::to_json(t_json);
}

void misaxx_indexer::misa_sqlite_description::to_json_schema(misaxx::misa_json_schema_property &t_schema) const {
    misa_file_description::to_json_schema(t_schema);
}

std::string misaxx_indexer::misa_sqlite_description::get_documentation_name() const {
    return "SQLite database";
}

std::string misaxx_indexer::misa_sqlite_description::get_documentation_description() const {
    return "A SQLite database";
}

void misaxx_indexer::misa_sqlite_description::build_serialization_id_hierarchy(
        std::vector<misaxx::misa_serialization_id> &result) const {
    misa_file_description::build_serialization_id_hierarchy(result);
    result.emplace_back(misaxx::misa_serialization_id("misa-indexer", "descriptions/sqlite"));
}
