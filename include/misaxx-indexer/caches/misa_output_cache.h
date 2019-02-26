//
// Created by rgerst on 26.02.19.
//

#pragma once

#include <misaxx/core/misa_default_cache.h>
#include <misaxx-indexer/patterns/misa_output_pattern.h>

namespace misaxx_indexer {
    struct misa_output_cache : public misaxx::misa_default_cache<misaxx::utils::memory_cache<boost::filesystem::path>,
        misa_output_pattern, misa_output_description> {
        void postprocess() override;

        void do_link(const misa_output_description &t_description) override;

    protected:
        misa_output_description
        produce_description(const boost::filesystem::path &t_location, const misa_output_pattern &t_pattern) override;
    };
}




