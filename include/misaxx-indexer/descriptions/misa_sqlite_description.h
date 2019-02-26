//
// Created by rgerst on 26.02.19.
//

#pragma once

#include <misaxx/core/descriptions/misa_file_description.h>

namespace misaxx_indexer {
    struct misa_sqlite_description : public misaxx::misa_file_description {
        using misaxx::misa_file_description::misa_file_description;

        void from_json(const nlohmann::json &t_json) override;

        void to_json(nlohmann::json &t_json) const override;

        void to_json_schema(misaxx::misa_json_schema_property &t_schema) const override;

        std::string get_documentation_name() const override;

        std::string get_documentation_description() const override;

    protected:
        void build_serialization_id_hierarchy(std::vector<misaxx::misa_serialization_id> &result) const override;
    };
}




