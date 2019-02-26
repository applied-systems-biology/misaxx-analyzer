//
// Created by rgerst on 26.02.19.
//

#pragma once

#include <misaxx/core/misa_data_pattern.h>
#include <misaxx/core/patterns/misa_file_pattern.h>

namespace misaxx_indexer {
    struct misa_sqlite_pattern : public misaxx::misa_file_pattern {
        misa_sqlite_pattern();

        std::string get_documentation_name() const override;

        std::string get_documentation_description() const override;

    protected:
        void build_serialization_id_hierarchy(std::vector<misaxx::misa_serialization_id> &result) const override;
    };
}



