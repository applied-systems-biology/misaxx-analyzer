//
// Created by rgerst on 26.02.19.
//

#include "attachment_indexer_task.h"

using namespace misaxx_indexer;
using namespace misaxx;

void attachment_indexer_task::discover(const nlohmann::json &json, const boost::filesystem::path &path) {
    if(json.is_object()) {
        auto serialization_id = json.find("misa:serialization-id");
        if(serialization_id != json.end()) {
            // Add to database
        }
        for(auto it = json.begin(); it != json.end(); ++it) {
            discover(it.value(), path / it.key());
        }
    }
    else if(json.is_array()) {
        for(size_t i = 0; i < json.size(); ++i) {
            discover(json[i], path / ("[" + std::to_string(i) + "]"));
        }
    }
}

void attachment_indexer_task::work() {
    auto json_access = attachments.access_readonly();
    discover(json_access.get(), "");
}

void attachment_indexer_task::create_parameters(misaxx::misa_parameter_builder &t_parameters) {

}


