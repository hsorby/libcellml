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

#include "gtest/gtest.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <libcellml>
#include <sstream>
#include <vector>

// generated with test resource locations
#include "test_resources.h"

TEST(ResolveImports, resolveSineModelFromFile) {
    std::ifstream t(TestResources::getLocation(
                    TestResources::CELLML_SINE_MODEL_RESOURCE));

    std::stringstream buffer;
    buffer << t.rdbuf();

    libcellml::Parser p;
    libcellml::ModelPtr model = p.parseModel(buffer.str());

    EXPECT_EQ(0u, p.errorCount());
    EXPECT_FALSE(model->hasUnresolvedImports());
}

TEST(ResolveImports, resolveSineImportsModelFromFile) {
    std::string sineModelLocation = TestResources::getLocation(
                TestResources::CELLML_SINE_IMPORTS_MODEL_RESOURCE);
    std::ifstream t(sineModelLocation);
    std::stringstream buffer;
    buffer << t.rdbuf();

    libcellml::Parser p;
    libcellml::ModelPtr model = p.parseModel(buffer.str());
    EXPECT_EQ(0u, p.errorCount());

    EXPECT_TRUE(model->hasUnresolvedImports());
    model->resolveImports(sineModelLocation);
    EXPECT_FALSE(model->hasUnresolvedImports());
}

TEST(ResolveImports, resolveComplexImportsModelFromFile) {
    std::string modelLocation = TestResources::getLocation(
                TestResources::CELLML_COMPLEX_IMPORTS_MODEL_RESOURCE);
    std::ifstream t(modelLocation);
    std::stringstream buffer;
    buffer << t.rdbuf();

    libcellml::Parser p;
    libcellml::ModelPtr model = p.parseModel(buffer.str());
    EXPECT_EQ(0u, p.errorCount());

    EXPECT_TRUE(model->hasUnresolvedImports());
    model->resolveImports(modelLocation);
    EXPECT_FALSE(model->hasUnresolvedImports());
}

TEST(ResolveImports, resolveUnitsImportFromFile) {
    std::string modelLocation = TestResources::getLocation(
        TestResources::CELLML_UNITS_IMPORT_MODEL_RESOURCE);
    std::ifstream t(modelLocation);
    std::stringstream buffer;
    buffer << t.rdbuf();

    libcellml::Parser p;
    libcellml::ModelPtr model = p.parseModel(buffer.str());

    EXPECT_EQ(0u, p.errorCount());

    EXPECT_TRUE(model->hasUnresolvedImports());
    model->resolveImports(modelLocation);
    EXPECT_FALSE(model->hasUnresolvedImports());
}

TEST(ResolveImports, resolveImportsFromFileLevel0) {
    std::string modelLocation = TestResources::getLocation(
        TestResources::CELLML_IMPORT_LEVEL0_MODEL_RESOURCE);
    std::ifstream t(modelLocation);
    std::stringstream buffer;
    buffer << t.rdbuf();

    libcellml::Parser p;
    libcellml::ModelPtr model = p.parseModel(buffer.str());

    printErrors(p);
    EXPECT_EQ(0u, p.errorCount());
    EXPECT_EQ(1u, libcellml::unresolvedImportedComponentsCount(model));

    libcellml::resolveImportedComponents(model, modelLocation);
    EXPECT_EQ(0u, libcellml::unresolvedImportedComponentsCount(model));

}
