//
// Created by rgerst on 26.02.19.
//

#include <misaxx-analyzer/module_interface.h>
#include "attachment_indexer_task.h"

using namespace misaxx_analyzer;
using namespace misaxx;

void attachment_indexer_task::discover(const nlohmann::json &json, const std::vector<std::string> &path, misaxx::readwrite_access<attachment_index_database> &db) {
    if(json.is_object()) {
        auto serialization_id = json.find("misa:serialization-id");
        if(serialization_id != json.end()) {
            // Add to database
            attachment_index_row row {};
            row.id = -1;
            row.sample = sample;
            row.cache = cache;
            row.property = boost::algorithm::join(path, "/");
            row.serialization_id = serialization_id->get<std::string>();
            db.get().insert(row);
        }
        for(auto it = json.begin(); it != json.end(); ++it) {
            auto p = path;
            p.emplace_back(it.key());
            discover(it.value(), p, db);
        }
    }
    else if(json.is_array()) {
        for(size_t i = 0; i < json.size(); ++i) {
            auto p = path;
            p.emplace_back("[" + std::to_string(i) + "]");
            discover(json[i], p, db);
        }
    }
}

void attachment_indexer_task::work() {
    std::cout << "Indexing attachment " << attachments.get_unique_location() << "\n";

    // Extract the sample and cache from the attachment
    boost::filesystem::path attachment_root_path = get_module_as<module_interface>()->data.get_location() / "attachments";
    boost::filesystem::path attachment_relative_path = boost::filesystem::relative(attachments.get_unique_location(), attachment_root_path);
    std::vector<std::string> segments;
    for(const boost::filesystem::path &segment: attachment_relative_path) {
        segments.emplace_back(segment.filename().string());
    }
    sample = segments[1];
    cache = segments[0];
    for(size_t i = 2; i < segments.size(); ++i) {
        cache += "/" + segments[i];
    }
    auto json_access = attachments.access_readonly();
    auto db_access = get_module_as<module_interface>()->data.get_attachment_index().access_readwrite();
    discover(json_access.get(), {}, db_access);
}

void attachment_indexer_task::create_parameters(misaxx::misa_parameter_builder &t_parameters) {

}


