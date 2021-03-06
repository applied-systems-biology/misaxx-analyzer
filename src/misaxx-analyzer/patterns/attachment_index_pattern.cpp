/**
 * Copyright by Ruman Gerst
 * Research Group Applied Systems Biology - Head: Prof. Dr. Marc Thilo Figge
 * https://www.leibniz-hki.de/en/applied-systems-biology.html
 * HKI-Center for Systems Biology of Infection
 * Leibniz Institute for Natural Product Research and Infection Biology - Hans Knöll Insitute (HKI)
 * Adolf-Reichwein-Straße 23, 07745 Jena, Germany
 *
 * This code is licensed under BSD 2-Clause
 * See the LICENSE file provided with this code for the full license.
 */

#include <misaxx-analyzer/patterns/attachment_index_pattern.h>

#include "misaxx-analyzer/patterns/attachment_index_pattern.h"

std::string misaxx_analyzer::attachment_index_pattern::get_documentation_name() const {
    return "SQLite database pattern";
}

std::string misaxx_analyzer::attachment_index_pattern::get_documentation_description() const {
    return "Looks for a *.sqlite file";
}

void misaxx_analyzer::attachment_index_pattern::build_serialization_id_hierarchy(
        std::vector<misaxx::misa_serialization_id> &result) const {
    misa_file_pattern::build_serialization_id_hierarchy(result);
}

misaxx_analyzer::attachment_index_pattern::attachment_index_pattern() : misa_file_pattern({ ".sqlite" }) {

}
