//
// Created by rgerst on 26.02.19.
//

#include <misaxx-indexer/patterns/misa_sqlite_pattern.h>

#include "misaxx-indexer/patterns/misa_sqlite_pattern.h"

std::string misaxx_indexer::misa_sqlite_pattern::get_documentation_name() const {
    return "SQLite database pattern";
}

std::string misaxx_indexer::misa_sqlite_pattern::get_documentation_description() const {
    return "Looks for a *.sqlite file";
}

void misaxx_indexer::misa_sqlite_pattern::build_serialization_id_hierarchy(
        std::vector<misaxx::misa_serialization_id> &result) const {
    misa_file_pattern::build_serialization_id_hierarchy(result);
}

misaxx_indexer::misa_sqlite_pattern::misa_sqlite_pattern() : misa_file_pattern({ ".sqlite" }) {

}
