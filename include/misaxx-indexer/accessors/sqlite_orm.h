//
// Created by rgerst on 26.02.19.
//

#pragma once

#include <misaxx/core/misa_cached_data.h>
#include <misaxx-indexer/caches/sqlite_orm_cache.h>

namespace misaxx_indexer {
    struct sqlite_orm : public misaxx::misa_cached_data<sqlite_orm_cache> {
    };
}



