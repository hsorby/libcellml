/*
Copyright libCellML Contributors

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#include <string>

#include "libcellml/exportdefinitions.h"
#include "libcellml/types.h"

namespace libcellml {

/**
 * @brief The Generator class.
 *
 * The Generator class is for representing a CellML Generator.
 */
class LIBCELLML_EXPORT Generator
{
    friend class Analyser;

public:
    ~Generator(); /**< Destructor, @private. */
    Generator(const Generator &rhs) = delete; /**< Copy constructor, @private. */
    Generator(Generator &&rhs) noexcept = delete; /**< Move constructor, @private. */
    Generator &operator=(Generator rhs) = delete; /**< Assignment operator, @private. */

    /**
     * @brief Create a @ref Generator object.
     *
     * Factory method to create a @ref Generator. Create a generator with::
     *
     * @code
     *   auto generator = libcellml::Generator::create();
     * @endcode
     *
     * @return A smart pointer to a @ref Generator object.
     */
    static GeneratorPtr create() noexcept;

    /**
     * @brief Get the @ref GeneratorProfile.
     *
     * Get the @ref GeneratorProfile used by this @ref Generator.
     *
     * @return The @ref GeneratorProfile used.
     */
    GeneratorProfilePtr profile();

    /**
     * @brief Set the @ref GeneratorProfile.
     *
     * Set the @ref GeneratorProfile to be used by this @ref Generator.
     *
     * @param profile The @ref GeneratorProfile to set.
     */
    void setProfile(const GeneratorProfilePtr &profile);

    /**
     * @brief Get the @ref AnalyserModel.
     *
     * Get the @ref AnalyserModel used by this @ref Generator.
     *
     * @return The @ref AnalyserModel used.
     */
    AnalyserModelPtr model();

    /**
     * @brief Set the @ref AnalyserModel.
     *
     * Set the @ref AnalyserModel to be used by this @ref Generator.
     *
     * @param model The @ref AnalyserModel to set.
     */
    void setModel(const AnalyserModelPtr &model);

    /**
     * @brief Get the interface code for the @ref AnalyserModel.
     *
     * Return the interface code for the @ref AnalyserModel, using the
     * @ref GeneratorProfile.
     *
     * @return The interface code as a @c std::string.
     */
    std::string interfaceCode() const;

    /**
     * @brief Get the implementation code for the @ref AnalyserModel.
     *
     * Return the implementation code for the @ref AnalyserModel, using the
     * @ref GeneratorProfile.
     *
     * @return The implementation code as a @c std::string.
     */
    std::string implementationCode() const;

private:
    Generator(); /**< Constructor, @private. */

    struct GeneratorImpl;
    GeneratorImpl *mPimpl; /**< Private member to implementation pointer, @private. */
};

} // namespace libcellml
