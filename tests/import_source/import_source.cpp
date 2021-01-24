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

TEST(ImportSource, createImportSource)
{
    auto imp1 = libcellml::ImportSource::create();
    EXPECT_NE(nullptr, imp1);
}

TEST(ImportSource, addToModel)
{
    auto model = libcellml::Model::create("so_much_importing");

    // Add component to model, then import to component:
    auto imp1 = libcellml::ImportSource::create();
    std::string url1 = "http://www.example.com#hello";
    imp1->setUrl(url1);

    EXPECT_TRUE(model->addImportSource(imp1));
    EXPECT_EQ(size_t(1), model->importSourceCount());
    EXPECT_EQ(imp1, model->importSource(0));

    // Add the same one again:
    EXPECT_FALSE(model->addImportSource(imp1));
    EXPECT_EQ(size_t(1), model->importSourceCount());
    EXPECT_EQ(imp1, model->importSource(0));

    // Add another with the same URL:
    auto imp2 = libcellml::ImportSource::create();
    imp2->setUrl(url1);

    EXPECT_TRUE(model->addImportSource(imp2));
    EXPECT_EQ(size_t(2), model->importSourceCount());
    EXPECT_EQ(imp2, model->importSource(1));

    // Add another with a new URL:
    auto imp3 = libcellml::ImportSource::create();
    auto url3 = "http://www.example.com#bonjour";
    imp3->setUrl(url3);

    EXPECT_TRUE(model->addImportSource(imp3));
    EXPECT_EQ(size_t(3), model->importSourceCount());
    EXPECT_EQ(imp3, model->importSource(2));
}

TEST(ImportSource, importSourceMove)
{
    auto imp1 = libcellml::ImportSource::create();
    auto imp2 = libcellml::ImportSource::create();

    auto component = libcellml::Component::create("component");
    auto units = libcellml::Units::create("units");

    EXPECT_FALSE(component->isImport());
    EXPECT_FALSE(units->isImport());

    component->setSourceComponent(imp1, "other_component");
    units->setSourceUnits(imp1, "other_units");

    EXPECT_TRUE(component->isImport());
    EXPECT_TRUE(units->isImport());

    component->setImportSource(imp2);
    units->setImportSource(imp2);
    EXPECT_TRUE(component->isImport());
    EXPECT_TRUE(units->isImport());
}

TEST(ImportSource, importSourceSharedAcrossModels)
{
    auto m1 = libcellml::Model::create("m1");
    auto imp = libcellml::ImportSource::create();

    EXPECT_TRUE(m1->addImportSource(imp));

    // Add import source to another model.
    auto m2 = libcellml::Model::create("m2");
    EXPECT_TRUE(m2->addImportSource(imp));

    // Expect that first model has an import source
    EXPECT_EQ(size_t(1), m1->importSourceCount());
    EXPECT_EQ(imp, m1->importSource(0));
    EXPECT_TRUE(m1->removeImportSource(imp));

    // and that we can get it and remove it from the second.
    EXPECT_EQ(size_t(1), m2->importSourceCount());
    EXPECT_EQ(imp, m2->importSource(0));
    EXPECT_TRUE(m2->removeImportSource(imp));
}

TEST(ImportSource, addRemoveFromModel)
{
    auto imp = libcellml::ImportSource::create();
    auto model = libcellml::Model::create();

    model->addImportSource(imp);
    EXPECT_EQ(size_t(1), model->importSourceCount());
    EXPECT_EQ(imp, model->importSource(0));

    model->removeImportSource(imp);
    EXPECT_EQ(size_t(0), model->importSourceCount());
    EXPECT_EQ(nullptr, model->importSource(0));

    auto imp1 = libcellml::ImportSource::create();
    auto imp2 = libcellml::ImportSource::create();
    auto c1 = libcellml::Component::create("c1");
    auto c2 = libcellml::Component::create("c2");
    auto u1 = libcellml::Units::create("u1");
    auto u2 = libcellml::Units::create("u2");

    c1->setSourceComponent(imp1, "cc1");
    c2->setSourceComponent(imp1, "cc2");
    u1->setSourceUnits(imp2, "uu1");
    u2->setSourceUnits(imp2, "uu2");

    EXPECT_TRUE(c1->isImport());
    EXPECT_TRUE(c2->isImport());
    EXPECT_TRUE(u1->isImport());
    EXPECT_TRUE(u2->isImport());

    model->addImportSource(imp1);
    model->addImportSource(imp2);

    EXPECT_EQ(size_t(2), model->importSourceCount());

    model->removeAllImportSources();

    EXPECT_EQ(size_t(0), model->importSourceCount());

    EXPECT_TRUE(c1->isImport());
    EXPECT_TRUE(c2->isImport());
    EXPECT_TRUE(u1->isImport());
    EXPECT_TRUE(u2->isImport());
}

TEST(ImportSource, moveToAnotherModel)
{
    auto imp = libcellml::ImportSource::create();
    auto model1 = libcellml::Model::create();
    auto model2 = libcellml::Model::create();

    model1->addImportSource(imp);
    EXPECT_EQ(size_t(1), model1->importSourceCount());
    EXPECT_EQ(imp, model1->importSource(0));

    model2->addImportSource(imp);
    EXPECT_EQ(size_t(1), model2->importSourceCount());
    EXPECT_EQ(imp, model2->importSource(0));

    model1->removeImportSource(imp);
    EXPECT_EQ(size_t(0), model1->importSourceCount());
    EXPECT_EQ(nullptr, model1->importSource(0));
}

TEST(ImportSource, createLinkedMultiple)
{
    auto model = libcellml::Model::create();
    auto c1 = libcellml::Component::create("c1");
    auto c2 = libcellml::Component::create("c2");
    auto u1 = libcellml::Units::create("u1");
    auto u2 = libcellml::Units::create("u2");
    auto imp = libcellml::ImportSource::create();

    model->addComponent(c1);
    model->addComponent(c2);
    model->addUnits(u1);
    model->addUnits(u2);

    c1->setImportSource(imp);
    c2->setImportSource(imp);
    u1->setImportSource(imp);
    u2->setImportSource(imp);

    EXPECT_EQ(size_t(1), model->importSourceCount());

    // Change to another import source:
    auto imp2 = libcellml::ImportSource::create();
    c2->setImportSource(imp2);
    u2->setImportSource(imp2);

    EXPECT_EQ(size_t(2), model->importSourceCount());

    EXPECT_TRUE(c1->isImport());
    EXPECT_TRUE(u1->isImport());
    EXPECT_TRUE(c2->isImport());
    EXPECT_TRUE(u2->isImport());
}

TEST(ImportSource, addImportComponentBeforeAddingToModel)
{
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <import xmlns:xlink=\"http://www.w3.org/1999/xlink\" xlink:href=\"this_place.cellml\">\n"
        "    <component component_ref=\"c_other\" name=\"c2\"/>\n"
        "  </import>\n"
        "  <component name=\"c1\"/>\n"
        "  <encapsulation>\n"
        "    <component_ref component=\"c1\">\n"
        "      <component_ref component=\"c2\"/>\n"
        "    </component_ref>\n"
        "  </encapsulation>\n"
        "</model>\n";

    auto printer = libcellml::Printer::create();
    auto model = libcellml::Model::create();
    auto importSource = libcellml::ImportSource::create();

    importSource->setUrl("this_place.cellml");

    auto c1 = libcellml::Component::create("c1");
    auto c2 = libcellml::Component::create("c2");

    c2->setImportSource(importSource);
    c2->setImportReference("c_other");

    c1->addComponent(c2);
    model->addComponent(c1);

    EXPECT_EQ(e, printer->printModel(model));
}

TEST(ImportSource, addImportComponentAfterAddingToModel)
{
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <import xmlns:xlink=\"http://www.w3.org/1999/xlink\" xlink:href=\"this_place.cellml\">\n"
        "    <component component_ref=\"c_other\" name=\"c2\"/>\n"
        "  </import>\n"
        "  <component name=\"c1\"/>\n"
        "  <encapsulation>\n"
        "    <component_ref component=\"c1\">\n"
        "      <component_ref component=\"c2\"/>\n"
        "    </component_ref>\n"
        "  </encapsulation>\n"
        "</model>\n";

    auto printer = libcellml::Printer::create();
    auto model = libcellml::Model::create();
    auto importSource = libcellml::ImportSource::create();

    importSource->setUrl("this_place.cellml");

    auto c1 = libcellml::Component::create("c1");
    auto c2 = libcellml::Component::create("c2");

    c2->setImportSource(importSource);
    c2->setImportReference("c_other");

    model->addComponent(c1);
    c1->addComponent(c2);

    EXPECT_EQ(e, printer->printModel(model));
}
