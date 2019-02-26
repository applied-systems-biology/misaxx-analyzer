//
// Created by rgerst on 26.02.19.
//

#pragma once

#include <misaxx/core/misa_cache.h>
#include <misaxx-indexer/patterns/misa_sqlite_pattern.h>
#include <misaxx-indexer/descriptions/misa_sqlite_description.h>
#include <misaxx/core/misa_default_cache.h>
#include <misaxx-indexer/utils/sqlite_orm.h>

namespace misaxx_indexer {
    template<typename ...Ts>
    struct sqlite_orm_cache : public misaxx::misa_default_cache<misaxx::utils::cache<sqlite_orm::sto>,
            misa_sqlite_pattern, misa_sqlite_description> {

    };
}




