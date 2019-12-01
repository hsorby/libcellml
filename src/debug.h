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

#include <iostream>
#include <sstream>

#include "internaltypes.h"

namespace libcellml {

struct Debug
{
    explicit Debug(bool newLine = true)
        : mNewLine(newLine)
    {
    }

    ~Debug()
    {
        std::cout << mSS.str();
        if (mNewLine) {
            std::cout << std::endl;
        }
    }

    Debug &operator<<(const void *p)
    {
        std::ostringstream ss;
        ss << static_cast<const void *>(p);
        mSS << ss.str();
        return *this;
    }

    // Accept just about anything.
    template<class T>
    Debug &operator<<(const T &x)
    {
        mSS << x;
        return *this;
    }

private:
    std::ostringstream mSS;
    bool mNewLine;
};

void printStack(const IndexStack &stack);
void printEquivalenceMap(const EquivalenceMap &map);

} // namespace libcellml
