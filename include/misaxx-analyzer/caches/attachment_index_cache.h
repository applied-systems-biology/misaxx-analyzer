//
// Created by rgerst on 26.02.19.
//

#pragma once

#include <misaxx/core/misa_cache.h>
#include <misaxx-analyzer/patterns/attachment_index_pattern.h>
#include <misaxx-analyzer/descriptions/attachment_index_description.h>
#include <misaxx/core/misa_default_cache.h>

namespace misaxx_analyzer {

    struct attachment_index_row {
        int id;
        std::string sample;
        std::string cache;
        std::string property;
        std::string serialization_id;
    };

    struct attachment_index_database {
        virtual void insert(const attachment_index_row &row) { };
    };

    struct attachment_index_cache
            : public misaxx::misa_default_cache<misaxx::utils::cache<attachment_index_database>,
                    attachment_index_pattern, attachment_index_description> {
        void do_link(const attachment_index_description &t_description) override;

        attachment_index_database &get() override;

        const attachment_index_database &get() const override;

        void set(attachment_index_database value) override;

        bool has() const override;

        bool can_pull() const override;

        void pull() override;

        void stash() override;

        void push() override;

    protected:
        attachment_index_description produce_description(const boost::filesystem::path &t_location,
                                                         const attachment_index_pattern &t_pattern) override;

    private:
        std::shared_ptr<attachment_index_database> m_database;
    };
}




