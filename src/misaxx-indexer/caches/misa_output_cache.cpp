//
// Created by rgerst on 26.02.19.
//

#include "misaxx-indexer/caches/misa_output_cache.h"

void misaxx_indexer::misa_output_cache::postprocess() {
    misa_cache::postprocess();
}

void misaxx_indexer::misa_output_cache::do_link(const misaxx_indexer::misa_output_description &t_description) {
    set(t_description.folder);
}

misaxx_indexer::misa_output_description
misaxx_indexer::misa_output_cache::produce_description(const boost::filesystem::path &t_location,
                                                       const misaxx_indexer::misa_output_pattern &t_pattern) {
    misa_output_description result;
    t_pattern.apply(result, t_location);
    return result;
}
