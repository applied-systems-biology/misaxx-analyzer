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

    // Link attachment schemas
    m_attachment_schemas.force_link(get_location() / "attachments",
                                    misaxx::misa_description_storage::with(misaxx::misa_json_description(
                                            get_location() / "attachments" / "serialization-schemas.json")));
    if (!m_attachment_schemas.exists())
        throw std::runtime_error("Serialization schemata for attachments do not exist!");

    // Link full attachment schemas
    m_full_attachment_schemas.force_link(get_location() / "attachments",
                                         misaxx::misa_description_storage::with(misaxx::misa_json_description(
                                                 get_location() / "attachments" / "serialization-schemas-full.json")));

    // Link attachments
    if(boost::filesystem::exists(get_location() / "attachments" / "exported")) {
        for(const boost::filesystem::path& entry : boost::make_iterator_range(
                boost::filesystem::recursive_directory_iterator(get_location() / "attachments" / "exported"))) {
            if(entry.extension() == ".json") {
                misaxx::misa_json cache;
                cache.force_link(entry.parent_path(), std::make_shared<misaxx::misa_json_description>(entry));
                m_attachments.emplace_back(std::move(cache));
            }
        }
    }

    if(boost::filesystem::exists(get_location() / "attachments" / "imported")) {
        for(const boost::filesystem::path& entry : boost::make_iterator_range(
                boost::filesystem::recursive_directory_iterator(get_location() / "attachments" / "imported"))) {
            if(entry.extension() == ".json") {
                misaxx::misa_json cache;
                cache.force_link(entry.parent_path(), std::make_shared<misaxx::misa_json_description>(entry));
                m_attachments.emplace_back(std::move(cache));
            }
        }
    }

    // Link attachment index database
    m_attachment_index.force_link(get_location(), std::make_shared<attachment_index_description>("attachment-index.sqlite"));
}

misaxx_indexer::misa_output_description
misaxx_indexer::misa_output_cache::produce_description(const boost::filesystem::path &t_location,
                                                       const misaxx_indexer::misa_output_pattern &t_pattern) {
    misa_output_description result;
    t_pattern.apply(result, t_location);
    return result;
}
