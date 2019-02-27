//
// Created by rgerst on 26.02.19.
//

#include <misaxx-indexer/patterns/attachment_index_pattern.h>

#include "misaxx-indexer/patterns/attachment_index_pattern.h"

std::string misaxx_indexer::attachment_index_pattern::get_documentation_name() const {
    return "SQLite database pattern";
}

std::string misaxx_indexer::attachment_index_pattern::get_documentation_description() const {
    return "Looks for a *.sqlite file";
}

void misaxx_indexer::attachment_index_pattern::build_serialization_id_hierarchy(
        std::vector<misaxx::misa_serialization_id> &result) const {
    misa_file_pattern::build_serialization_id_hierarchy(result);
}

misaxx_indexer::attachment_index_pattern::attachment_index_pattern() : misa_file_pattern({ ".sqlite" }) {

}
