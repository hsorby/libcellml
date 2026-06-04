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

#include "test_utils.h"

#include "gtest/gtest.h"

#include <libcellml>

TEST(Analyser, unlinkedUnitsInModel)
{
    std::cerr << "11111111111111111" << std::endl;
    // auto parser = libcellml::Parser::create();
    std::cerr << "22222222222222222" << std::endl;
}


TEST(Version, versionMatch)
{
    unsigned int version = libcellml::version();
    EXPECT_EQ(0x000603U, version);

    std::string versionString = libcellml::versionString();
    EXPECT_EQ("0.6.3", versionString);
}
