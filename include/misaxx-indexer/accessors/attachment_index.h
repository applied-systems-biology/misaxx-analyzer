//
// Created by rgerst on 26.02.19.
//

#pragma once

#include <misaxx/core/misa_cached_data.h>
#include <misaxx-indexer/caches/attachment_index_cache.h>

namespace misaxx_indexer {
    struct attachment_index : public misaxx::misa_cached_data<attachment_index_cache> {
    };
}



