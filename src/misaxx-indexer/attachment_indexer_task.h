//
// Created by rgerst on 26.02.19.
//

#pragma once

#include <misaxx/core/misa_task.h>
#include <misaxx/core/accessors/misa_json.h>

namespace misaxx_indexer {
    struct attachment_indexer_task : public misaxx::misa_task {

        misaxx::misa_json attachments;

        using misaxx::misa_task::misa_task;

        void work() override;

        void create_parameters(misaxx::misa_parameter_builder &t_parameters) override;

        void discover(const nlohmann::json &json, const std::vector<std::string> &path, misaxx::readwrite_access<attachment_index_database> &db);

    private:

        std::string sample;
        std::string cache;

    };
}




