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

#include <libcellml>

#include "test_utils.h"

TEST(Model, setGetId)
{
    const std::string id = "modelID";
    libcellml::ModelPtr m = libcellml::Model::create();
    m->setId(id);
    EXPECT_EQ(id, m->id());
}

TEST(Model, name)
{
    const std::string n = "name";
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"name\"/>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    m->setName(n);

    EXPECT_EQ(n, m->name());

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    const std::string a = printer->printModel(m);
    EXPECT_EQ(e, a);

    auto m2 = libcellml::Model::create(n);
    const std::string a2 = printer->printModel(m2);
    EXPECT_EQ(e, a2);
}

TEST(Model, unsetName)
{
    const std::string n = "name";
    const std::string eName =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"name\"/>\n";
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\"/>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    m->setName(n);
    EXPECT_EQ(n, m->name());

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    std::string a = printer->printModel(m);
    EXPECT_EQ(eName, a);

    m->setName("");
    EXPECT_EQ("", m->name());
    a = printer->printModel(m);
    EXPECT_EQ(e, a);
}

TEST(Model, invalidName)
{
    const std::string n = "invalid name";
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"invalid name\"/>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    m->setName(n);

    EXPECT_EQ(n, m->name());

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    const std::string a = printer->printModel(m);
    EXPECT_EQ(e, a);
}

TEST(Model, addComponent)
{
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <component/>\n"
        "</model>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ComponentPtr c = libcellml::Component::create();
    m->addComponent(c);

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    const std::string a = printer->printModel(m);
    EXPECT_EQ(e, a);
}

TEST(Model, addValidNamedComponent)
{
    const std::string in = "valid_name";
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <component name=\"valid_name\"/>\n"
        "</model>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ComponentPtr c = libcellml::Component::create();
    c->setName(in);
    m->addComponent(c);

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    const std::string a = printer->printModel(m);
    EXPECT_EQ(e, a);
}

TEST(Model, addInvalidNamedComponent)
{
    const std::string in = "invalid name";
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <component name=\"invalid name\"/>\n"
        "</model>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ComponentPtr c = libcellml::Component::create();
    c->setName(in);
    m->addComponent(c);

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    const std::string a = printer->printModel(m);
    EXPECT_EQ(e, a);
}

TEST(Model, addTwoNamedComponents)
{
    const std::string name1 = "component_1";
    const std::string name2 = "component_2";
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <component name=\"component_1\"/>\n"
        "  <component name=\"component_2\"/>\n"
        "</model>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ComponentPtr c1 = libcellml::Component::create();
    c1->setName(name1);
    m->addComponent(c1);
    libcellml::ComponentPtr c2 = libcellml::Component::create();
    m->addComponent(c2);
    // once the component is added, we should be able to change the handle to the component and have those changes
    // reflected in the model? Yes we are using shared pointers.
    c2->setName(name2); // so should this give an error? Nope

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    const std::string a = printer->printModel(m);
    EXPECT_EQ(e, a);
}

TEST(Model, countComponents)
{
    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ComponentPtr c1 = libcellml::Component::create();
    libcellml::ComponentPtr c2 = libcellml::Component::create();
    c1->setName("child1");
    c2->setName("child2");

    EXPECT_EQ(size_t(0), m->componentCount());

    m->addComponent(c1);
    m->addComponent(c2);
    EXPECT_EQ(size_t(2), m->componentCount());
}

TEST(Model, containsComponent)
{
    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ComponentPtr c1 = libcellml::Component::create();
    libcellml::ComponentPtr c2 = libcellml::Component::create();
    c1->setName("child1");
    c2->setName("child2");

    EXPECT_FALSE(m->containsComponent("child1"));

    m->addComponent(c1);
    m->addComponent(c2);
    EXPECT_TRUE(m->containsComponent("child2"));
}

TEST(Model, removeComponent)
{
    const std::string e1 =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <component name=\"child2\"/>\n"
        "</model>\n";
    const std::string e2 =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <component name=\"child2\"/>\n"
        "</model>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ComponentPtr c1 = libcellml::Component::create();
    libcellml::ComponentPtr c2 = libcellml::Component::create();
    c1->setName("child1");
    c2->setName("child2");
    m->addComponent(c1);
    m->addComponent(c2);

    EXPECT_EQ(size_t(2), m->componentCount());
    EXPECT_TRUE(m->removeComponent(0));
    EXPECT_EQ(size_t(1), m->componentCount());

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    std::string a = printer->printModel(m);
    EXPECT_EQ(e1, a);
    EXPECT_FALSE(m->removeComponent(1));

    m->addComponent(c1);

    // Remove the first occurence of "child1".
    EXPECT_TRUE(m->removeComponent("child1"));
    EXPECT_EQ(size_t(1), m->componentCount());
    a = printer->printModel(m);
    EXPECT_EQ(e2, a);

    // Expect no change to model.
    EXPECT_FALSE(m->removeComponent("child3"));
    EXPECT_EQ(size_t(1), m->componentCount());
}

TEST(Model, componentMethods)
{
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <component name=\"childA\"/>\n"
        "</model>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ComponentPtr c1 = libcellml::Component::create();
    c1->setName("child1");
    m->addComponent(c1);

    libcellml::ComponentPtr cA = m->component(0);
    cA->setName("childA");

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    const std::string a = printer->printModel(m);
    EXPECT_EQ(e, a);

    // Using const version of overloaded method
    const libcellml::ComponentPtr cB = m->component(0);
    // Can do this as we just have a const pointer
    cB->setName("gus");
    EXPECT_EQ("gus", cB->name());

    EXPECT_EQ(nullptr, m->component(4));
}

TEST(Model, takeComponentMethods)
{
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\"/>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ComponentPtr c1 = libcellml::Component::create();
    libcellml::ComponentPtr c2 = libcellml::Component::create();
    c1->setName("child1");
    c2->setName("child2");
    m->addComponent(c1);
    m->addComponent(c2);

    libcellml::ComponentPtr c02 = m->takeComponent(1);
    EXPECT_EQ(size_t(1), m->componentCount());

    EXPECT_EQ(m->takeComponent(4), nullptr);

    EXPECT_EQ("child2", c02->name());
    EXPECT_EQ(nullptr, c02->parent());

    libcellml::ComponentPtr c01 = m->takeComponent("child1");
    EXPECT_NE(nullptr, c01);
    EXPECT_EQ(size_t(0), m->componentCount());

    EXPECT_EQ("child1", c01->name());
    EXPECT_EQ(nullptr, c01->parent());

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    const std::string a = printer->printModel(m);
    EXPECT_EQ(e, a);

    // Expect no change.
    EXPECT_EQ(size_t(0), m->componentCount());
    EXPECT_EQ(nullptr, m->takeComponent("child4"));
    EXPECT_EQ(size_t(0), m->componentCount());
}

static int count = 0;
class big_and_complicated
{
    // lots of complicated code
public:
    int id;
    big_and_complicated()
        : id(count + 101)
    {
        ++count;
    }

    ~big_and_complicated()
    {
        --count;
    }
};

struct structure
{
    structure()
        : m_data {new big_and_complicated {}}
    {
        std::cout << "structure constructor: " << m_data->id << std::endl;
    }

    structure(const structure &rhs)
        : m_data {new big_and_complicated {}}
    {
        std::cout << "structure copy constructor: " << rhs.m_data->id << std::endl;
        m_data->id = rhs.m_data->id;
    }

    structure(structure &&rhs) noexcept
        : m_data(rhs.m_data)
    {
        std::cout << "structure move constructor: " << m_data->id << std::endl;
        rhs.m_data = nullptr;
    }

    structure &operator=(structure rhs)
    {
        rhs.swap(*this);
        return *this;
    }

    void swap(structure &rhs) noexcept
    {
        std::swap(m_data, rhs.m_data);
    }

    ~structure()
    {
        std::cout << "structure destructor: ";
        if (m_data != nullptr) {
            std::cout << m_data->id << std::endl;
        } else {
            std::cout << std::endl;
        }
        delete m_data;
    }

private:
    big_and_complicated *m_data;
};

TEST(Model, replaceComponent)
{
    const std::string e_orig =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <component name=\"child1\"/>\n"
        "  <component name=\"child2\"/>\n"
        "</model>\n";
    const std::string e_after =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <component name=\"child1\"/>\n"
        "  <component name=\"child3\"/>\n"
        "</model>\n";
    const std::string e_post =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\">\n"
        "  <component name=\"child5\"/>\n"
        "  <component name=\"child3\"/>\n"
        "</model>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ComponentPtr c1 = libcellml::Component::create();
    libcellml::ComponentPtr c2 = libcellml::Component::create();
    libcellml::ComponentPtr c3 = libcellml::Component::create();
    libcellml::ComponentPtr c4 = libcellml::Component::create();
    libcellml::ComponentPtr c5 = libcellml::Component::create();
    c1->setName("child1");
    c2->setName("child2");
    c3->setName("child3");
    c4->setName("child4");
    c5->setName("child5");
    m->addComponent(c1);
    m->addComponent(c2);

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    std::string a = printer->printModel(m);
    EXPECT_EQ(e_orig, a);

    // Attempt to replace non-existent component.
    EXPECT_FALSE(m->replaceComponent(5, c3));

    // Replace existing component.
    EXPECT_TRUE(m->replaceComponent(1, c3));
    EXPECT_EQ(m, c3->parent());

    a = printer->printModel(m);
    EXPECT_EQ(e_after, a);

    // Nothing happens when trying to replace a component that doesn't match
    // the given name.
    EXPECT_FALSE(m->replaceComponent("child5", c4));
    EXPECT_EQ(nullptr, c4->parent());

    EXPECT_TRUE(m->replaceComponent("child1", c4));
    EXPECT_EQ(m, c4->parent());

    EXPECT_TRUE(m->replaceComponent(c4, c5));
    EXPECT_EQ(m, c5->parent());

    a = printer->printModel(m);
    EXPECT_EQ(e_post, a);
}

TEST(Model, constructors)
{
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"my_name\">\n"
        "  <component/>\n"
        "</model>\n";
    const std::string n = "my_name";

    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ModelPtr m1;
    libcellml::ModelPtr m2;
    m->setName(n);
    m->addComponent(libcellml::Component::create());

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    const std::string a = printer->printModel(m);

    EXPECT_EQ(e, a);

    //Testing copy constructor
    libcellml::ModelPtr &m3(m);
    EXPECT_EQ("my_name", m3->name());

    // Testing model assignment
    m1 = m;
    EXPECT_EQ("my_name", m->name());

    // Testing move assignment for model
    m2 = std::move(m1);
    EXPECT_EQ("my_name", m2->name());

    // Testing move constructor for component
    libcellml::ModelPtr m4 = std::move(m2);
    EXPECT_EQ("my_name", m4->name());
}

TEST(Model, setAndCheckIdsAllEntities)
{
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"mname\" id=\"mid\">\n"
        "  <import xmlns:xlink=\"http://www.w3.org/1999/xlink\" xlink:href=\"some-other-model.xml\" id=\"i1id\">\n"
        "    <component component_ref=\"a_component_in_that_model\" name=\"c1name\" id=\"c1id\"/>\n"
        "  </import>\n"
        "  <import xmlns:xlink=\"http://www.w3.org/1999/xlink\" xlink:href=\"some-other-model.xml\" id=\"i2id\">\n"
        "    <units units_ref=\"a_units_in_that_model\" name=\"u1name\" id=\"u1id\"/>\n"
        "  </import>\n"
        "  <units name=\"u2name\" id=\"u2id\"/>\n"
        "  <units name=\"u3name\" id=\"u3id\"/>\n"
        "  <component name=\"c2name\" id=\"c2id\">\n"
        "    <variable name=\"vname\" units=\"u1name\" id=\"vid\"/>\n"
        "    <reset id=\"r1id\">\n"
        "      <test_value id=\"tvid\"/>\n"
        "      <reset_value id=\"rvid\"/>\n"
        "    </reset>\n"
        "  </component>\n"
        "</model>\n";

    libcellml::ModelPtr m = libcellml::Model::create();
    libcellml::ImportSourcePtr i1 = libcellml::ImportSource::create();
    libcellml::ImportSourcePtr i2 = libcellml::ImportSource::create();
    libcellml::ComponentPtr c1 = libcellml::Component::create();
    libcellml::ComponentPtr c2 = libcellml::Component::create();
    libcellml::VariablePtr v = libcellml::Variable::create();
    libcellml::UnitsPtr u1 = libcellml::Units::create();
    libcellml::UnitsPtr u2 = libcellml::Units::create();
    libcellml::UnitsPtr u3 = libcellml::Units::create();
    libcellml::ResetPtr r1 = libcellml::Reset::create();

    i1->setUrl("some-other-model.xml");
    c1->setSourceComponent(i1, "a_component_in_that_model");

    i2->setUrl("some-other-model.xml");
    u1->setSourceUnits(i2, "a_units_in_that_model");

    m->setName("mname");
    c1->setName("c1name");
    c2->setName("c2name");
    v->setName("vname");
    u1->setName("u1name");
    u2->setName("u2name");
    u3->setName("u3name");

    m->setId("mid");
    i1->setId("i1id");
    i2->setId("i2id");
    c1->setId("c1id");
    c2->setId("c2id");
    v->setId("vid");
    u1->setId("u1id");
    u2->setId("u2id");
    u3->setId("u3id");
    r1->setId("r1id");

    r1->setTestValueId("tvid");
    r1->setResetValueId("rvid");

    v->setUnits(u1);
    c2->addReset(r1);
    c2->addVariable(v);

    m->addUnits(u1);
    m->addUnits(u2);
    m->addUnits(u3);
    m->addComponent(c1);
    m->addComponent(c2);

    libcellml::PrinterPtr printer = libcellml::Printer::create();
    const std::string a = printer->printModel(m);
    EXPECT_EQ(a, e);
}

TEST(Model, missingUnitsFromImportOfCnTerms)
{
    // This test is intended to show that parsing a model and importing
    // it have the same end result.  Previously (see #519) any units
    // defined in the model but not used by a variable (ie: only used by <cn> tags)
    // were not imported.
    auto validator = libcellml::Validator::create();
    auto model = libcellml::Model::create("model_from_imports");
    auto c = libcellml::Component::create("c");

    auto imp = libcellml::ImportSource::create();
    imp->setUrl("units_in_cn.cellml");

    c->setImportReference("myComponent");
    c->setImportSource(imp);
    model->addComponent(c);

    EXPECT_TRUE(model->hasUnresolvedImports());
    model->resolveImports(resourcePath());
    EXPECT_FALSE(model->hasUnresolvedImports());
    model->flatten();

    // Confirm that the bug reported in #519 wherein units used solely by <cn> items
    // in imported components were not being imported is now fixed.
    validator->validateModel(model);
    EXPECT_EQ(size_t(0), validator->errorCount());
}

TEST(Model, missingUnitsFromImportOfCnTermsNotDefinedInImportedModel)
{
    const std::string in =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"myModel\">\n"
        "   <component name=\"myComponent\">\n"
        "       <variable name=\"a\" units=\"second\"/>\n"
        "       <math xmlns=\"http://www.w3.org/1998/Math/MathML\" xmlns:cellml=\"http://www.cellml.org/cellml/2.0#\">\n"
        "           <apply><eq/>\n"
        "               <ci>a</ci>\n"
        "               <cn cellml:units=\"myUnitsThatIUse\">1</cn>\n"
        "           </apply>\n"
        "       </math>\n"
        "   </component>\n"
        "</model>";
    const std::vector<std::string> e = {"Math has a cn element with a cellml:units attribute 'myUnitsThatIUse' that is not a valid reference to units in the model 'model' or a standard unit."};

    // Create the model by parsing the string above.
    auto parser = libcellml::Parser::create();
    auto importedModel = parser->parseModel(in);

    auto validator = libcellml::Validator::create();
    // The importedModel has one validation error because the units
    // myUnitsThatIUse are not defined in the imported model.
    validator->validateModel(importedModel);
    EXPECT_EQ(size_t(1), validator->errorCount());

    auto model = libcellml::Model::create("model");
    auto c = libcellml::Component::create("c");

    auto importSource = libcellml::ImportSource::create();
    importSource->setUrl("not_required_resolving_import_manually");
    importSource->setModel(importedModel);

    c->setImportReference("myComponent");
    c->setImportSource(importSource);
    model->addComponent(c);

    EXPECT_FALSE(model->hasUnresolvedImports());
    model->flatten();

    // But now by importing the component I have miraculously
    // found the units myUnitsThatIUse!

    // KRM: This is not the behaviour I see? I get the expected error message about the missing units.
    validator->validateModel(model);
    EXPECT_EQ(size_t(1), validator->errorCount());
    EXPECT_EQ_ERRORS(e, validator);
}

TEST(Model, importingComponentWithCnUnitNamesThatAreAlreadyDefinedInImportingModel)
{
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"myModel\">\n"
        "  <units name=\"myUnitsThatIUse\">\n"
        "    <unit units=\"metre\"/>\n"
        "  </units>\n"
        "  <units name=\"myUnitsThatIUse_1\">\n"
        "    <unit units=\"second\"/>\n"
        "  </units>\n"
        "  <component name=\"c\">\n"
        "    <variable name=\"a\" units=\"second\"/>\n"
        "    <math xmlns=\"http://www.w3.org/1998/Math/MathML\" xmlns:cellml=\"http://www.cellml.org/cellml/2.0#\">\n"
        "      <apply>\n"
        "        <eq/>\n"
        "        <ci>a</ci>\n"
        "        <cn cellml:units=\"myUnitsThatIUse_1\">1</cn>\n"
        "      </apply>\n"
        "    </math>\n"
        "  </component>\n"
        "</model>\n";

    const std::string in =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"myModel\">\n"
        "  <units name=\"myUnitsThatIUse\">\n"
        "    <unit units=\"second\"/>\n"
        "  </units>\n"
        "   <component name=\"myComponent\">\n"
        "       <variable name=\"a\" units=\"second\"/>\n"
        "       <math xmlns=\"http://www.w3.org/1998/Math/MathML\" xmlns:cellml=\"http://www.cellml.org/cellml/2.0#\">\n"
        "           <apply>"
        "             <eq/>\n"
        "             <ci>a</ci>\n"
        "             <cn cellml:units=\"myUnitsThatIUse\">1</cn>\n"
        "           </apply>\n"
        "       </math>\n"
        "   </component>\n"
        "</model>";

    // Create the model by parsing the string above.
    auto parser = libcellml::Parser::create();
    auto importedModel = parser->parseModel(in);

    auto validator = libcellml::Validator::create();

    // No problems with the imported model.
    validator->validateModel(importedModel);
    EXPECT_EQ(size_t(0), validator->errorCount());

    // The model myModel already has myUnitsThatIUse defined.
    auto model = libcellml::Model::create("myModel");
    auto u = libcellml::Units::create("myUnitsThatIUse");
    u->addUnit("metre");
    model->addUnits(u);

    auto c = libcellml::Component::create("c");

    auto importSource = libcellml::ImportSource::create();
    importSource->setUrl("not_required_resolving_import_manually");
    importSource->setModel(importedModel);

    c->setImportReference("myComponent");
    c->setImportSource(importSource);
    model->addComponent(c);

    EXPECT_FALSE(model->hasUnresolvedImports());
    model->flatten();

    validator->validateModel(model);
    EXPECT_EQ(size_t(0), validator->errorCount());

    // I would expect that the name of the cn elements units would need
    // to change as the importing model already has units of that name.
    auto printer = libcellml::Printer::create();
    EXPECT_EQ(e, printer->printModel(model));
}

TEST(Model, importingComponentWithIdenticallyDefinedUnitsAsImportingModel)
{
    const std::string e =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"myModel\">\n"
        "  <units name=\"myUnitsThatIUse\">\n"
        "    <unit units=\"second\"/>\n"
        "  </units>\n"
        "  <units name=\"myOtherUnits\">\n"
        "    <unit units=\"metre\"/>\n"
        "  </units>\n"
        "  <component name=\"c\">\n"
        "    <variable name=\"a\" units=\"second\"/>\n"
        "    <variable name=\"b\" units=\"myOtherUnits\"/>\n"
        "    <math xmlns=\"http://www.w3.org/1998/Math/MathML\" xmlns:cellml=\"http://www.cellml.org/cellml/2.0#\">\n"
        "      <apply>\n"
        "        <eq/>\n"
        "        <ci>a</ci>\n"
        "        <cn cellml:units=\"myUnitsThatIUse\">1</cn>\n"
        "      </apply>\n"
        "    </math>\n"
        "  </component>\n"
        "</model>\n";

    const std::string in =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"myModel\">\n"
        "  <units name=\"myUnitsThatIUse\">\n"
        "    <unit units=\"second\"/>\n"
        "  </units>\n"
        "  <units name=\"myOtherUnits\">\n"
        "    <unit units=\"metre\"/>\n"
        "  </units>\n"
        "   <component name=\"myComponent\">\n"
        "       <variable name=\"a\" units=\"second\"/>\n"
        "       <variable name=\"b\" units=\"myOtherUnits\"/>\n"
        "       <math xmlns=\"http://www.w3.org/1998/Math/MathML\" xmlns:cellml=\"http://www.cellml.org/cellml/2.0#\">\n"
        "           <apply>"
        "             <eq/>\n"
        "             <ci>a</ci>\n"
        "             <cn cellml:units=\"myUnitsThatIUse\">1</cn>\n"
        "           </apply>\n"
        "       </math>\n"
        "   </component>\n"
        "</model>";

    // Create the model by parsing the string above.
    auto parser = libcellml::Parser::create();
    auto importedModel = parser->parseModel(in);

    auto validator = libcellml::Validator::create();

    // No problems with the imported model.
    validator->validateModel(importedModel);
    EXPECT_EQ(size_t(0), validator->errorCount());

    // The model myModel already has myUnitsThatIUse defined.
    auto model = libcellml::Model::create("myModel");
    auto u1 = libcellml::Units::create("myUnitsThatIUse");
    u1->addUnit("second");
    model->addUnits(u1);
    auto u2 = libcellml::Units::create("myOtherUnits");
    u2->addUnit("metre");
    model->addUnits(u2);

    auto c = libcellml::Component::create("c");

    auto importSource = libcellml::ImportSource::create();
    importSource->setUrl("not_required_resolving_import_manually");
    importSource->setModel(importedModel);

    c->setImportReference("myComponent");
    c->setImportSource(importSource);
    model->addComponent(c);

    EXPECT_FALSE(model->hasUnresolvedImports());
    model->flatten();

    validator->validateModel(model);
    EXPECT_EQ(size_t(0), validator->errorCount());

    // I would expect that the name of the cn elements units would not need
    // to change as the importing model already has units of that name and definition.
    auto printer = libcellml::Printer::create();
    EXPECT_EQ(e, printer->printModel(model));
}

TEST(Model, importingComponentWithTwoMathMLDocuments)
{
    const std::string in =
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<model xmlns=\"http://www.cellml.org/cellml/2.0#\" name=\"myModel\">\n"
        "  <component name=\"myComponent\">\n"
        "    <variable name=\"a\" units=\"second\"/>\n"
        "    <variable name=\"b\" units=\"dimensionless\"/>\n"
        "       <math xmlns=\"http://www.w3.org/1998/Math/MathML\" xmlns:cellml=\"http://www.cellml.org/cellml/2.0#\">\n"
        "           <apply><eq/>\n"
        "               <ci>a</ci>\n"
        "               <cn cellml:units=\"myUnitsThatAUses\">1</cn>\n"
        "           </apply>\n"
        "       </math>\n"
        "       <math xmlns=\"http://www.w3.org/1998/Math/MathML\" xmlns:cellml=\"http://www.cellml.org/cellml/2.0#\">\n"
        "           <apply><eq/>\n"
        "               <ci>b</ci>\n"
        "               <cn cellml:units=\"myUnitsThatBUses\">1</cn>\n"
        "           </apply>\n"
        "       </math>\n"
        "   </component>\n"
        "</model>";

    const std::vector<std::string> e1 = {"LibXml2 error: Extra content at the end of the document.",
                                         "Could not get a valid XML root node from the math on component 'myComponent'."};
    const std::vector<std::string> e2 = {"LibXml2 error: Extra content at the end of the document.",
                                         "Could not get a valid XML root node from the math on component 'c'."};

    // Create the model by parsing the string above.
    auto parser = libcellml::Parser::create();
    auto importedModel = parser->parseModel(in);

    auto validator = libcellml::Validator::create();
    // The importedModel has one validation error because the units
    // myUnitsThatIUse are not defined in the imported model.

    // KRM: The validator returns two errors because it cannot find the root mathml from the two strings.
    //   - If we don't permit more than one mathml block, then it becomes a validation prob, not an import one.
    //   - If we do, then I would have expected errors from both myUnitsThatAUses and myUnitsThatBUses? two errors, not one?
    validator->validateModel(importedModel);
    EXPECT_EQ(size_t(2), validator->errorCount());
    EXPECT_EQ_ERRORS(e1, validator);

    auto model = libcellml::Model::create("model");
    auto c = libcellml::Component::create("c");

    auto importSource = libcellml::ImportSource::create();
    importSource->setUrl("not_required_resolving_import_manually");
    importSource->setModel(importedModel);

    c->setImportReference("myComponent");
    c->setImportSource(importSource);
    model->addComponent(c);

    EXPECT_FALSE(model->hasUnresolvedImports());
    model->flatten();

    validator->validateModel(model);

    // KRM: I'd expect exactly the same errors here as in the parsed model validation, which is what I get, so
    //  I'm confused about what this test is trying to show?
    EXPECT_EQ(size_t(2), validator->errorCount());
    EXPECT_EQ_ERRORS(e2, validator);
}
