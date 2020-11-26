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

#include "libcellml/importedentity.h"

#include "libcellml/importsource.h"

namespace libcellml {

/**
 * @brief The ImportedEntity::ImportedEntityImpl struct.
 *
 * The private implementation for the ImportedEntity class.
 */
struct ImportedEntity::ImportedEntityImpl
{
    ImportSourcePtr mImportSource;
    std::string mImportReference;
    bool mIsResolved = false;
};

ImportedEntity::ImportedEntity()
    : mPimpl(new ImportedEntityImpl())
{
}

ImportedEntity::~ImportedEntity()
{
    delete mPimpl;
}

bool ImportedEntity::importEqual(const ImportedEntityPtr &other) const
{
    if (other) {
        bool importMatches = this->isImport() == other->isImport();
        if (this->isImport() &&
                importMatches &&
                this->importReference() == other->importReference()) {
            auto importSource = this->importSource();
            if (mPimpl->mImportSource) {
                return mPimpl->mImportSource->equal(other->importSource());
            } else if (other->importSource()) {
                return false;
            }
            return true;
        }
        return importMatches;
    }
    return false;
}

bool ImportedEntity::isImport() const
{
    return mPimpl->mImportSource != nullptr;
}

ImportSourcePtr ImportedEntity::importSource() const
{
    return mPimpl->mImportSource;
}

void ImportedEntity::setImportSource(const ImportSourcePtr &importSource)
{
    doSetImportSource(importSource);
}

void ImportedEntity::doSetImportSource(const ImportSourcePtr &importSource)
{
    mPimpl->mImportSource = importSource;
}

std::string ImportedEntity::importReference() const
{
    return mPimpl->mImportReference;
}

void ImportedEntity::setImportReference(const std::string &reference)
{
    mPimpl->mImportReference = reference;
}

bool ImportedEntity::isResolved() const
{
    return mPimpl->mIsResolved;
}

void ImportedEntity::setResolved(bool status)
{
    mPimpl->mIsResolved = status;
}

} // namespace libcellml
