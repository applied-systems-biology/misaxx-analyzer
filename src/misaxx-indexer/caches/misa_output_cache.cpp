//
// Created by rgerst on 26.02.19.
//

#include "misaxx-indexer/caches/misa_output_cache.h"

void misaxx_indexer::misa_output_cache::postprocess() {
    misa_cache::postprocess();
}

void misaxx_indexer::misa_output_cache::do_link(const misaxx_indexer::misa_output_description &t_description) {
    set(t_description.folder);
    set_unique_location(t_description.folder);
    m_attachment_schemas.force_link(get_location() / "attachments",
            misaxx::misa_description_storage::with(misaxx::misa_json_description(get_location() / "attachments" / "serialization-schemas.json")));
    std::cout << m_attachment_schemas.data->get_filename() << std::endl;
    if(!m_attachment_schemas.exists())
        throw std::runtime_error("Serialization schemata for attachments do not exist!");
}

misaxx_indexer::misa_output_description
misaxx_indexer::misa_output_cache::produce_description(const boost::filesystem::path &t_location,
                                                       const misaxx_indexer::misa_output_pattern &t_pattern) {
    misa_output_description result;
    t_pattern.apply(result, t_location);
    return result;
}
