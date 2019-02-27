//
// Created by rgerst on 26.02.19.
//

#include <misaxx-indexer/accessors/misa_output.h>

#include "misaxx-indexer/accessors/misa_output.h"

const misaxx::misa_json misaxx_indexer::misa_output::get_attachment_schemas() const {
    return data->m_attachment_schemas;
}

misaxx::misa_json misaxx_indexer::misa_output::get_full_attachment_schemas() {
    return data->m_full_attachment_schemas;
}

std::vector<misaxx::misa_json> misaxx_indexer::misa_output::get_attachments() const {
   return data->m_attachments;
}

misaxx_indexer::attachment_index misaxx_indexer::misa_output::get_attachment_index() {
    return data->m_attachment_index;
}
