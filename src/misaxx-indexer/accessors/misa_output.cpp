//
// Created by rgerst on 26.02.19.
//

#include <misaxx-indexer/accessors/misa_output.h>

#include "misaxx-indexer/accessors/misa_output.h"

misaxx::misa_json misaxx_indexer::misa_output::get_attachment_schemas() {
    return data->m_attachment_schemas;
}
