#
# Tests the Issue class bindings
#
import unittest


class IssueTestCase(unittest.TestCase):

    def test_item_type_enum(self):
        from libcellml import CellmlElementType

        self.assertIsInstance(CellmlElementType.COMPONENT, int)
        self.assertIsInstance(CellmlElementType.COMPONENT_REF, int)
        self.assertIsInstance(CellmlElementType.CONNECTION, int)
        self.assertIsInstance(CellmlElementType.ENCAPSULATION, int)
        self.assertIsInstance(CellmlElementType.IMPORT, int)
        self.assertIsInstance(CellmlElementType.MAP_VARIABLES, int)
        self.assertIsInstance(CellmlElementType.MATH, int)
        self.assertIsInstance(CellmlElementType.MODEL, int)
        self.assertIsInstance(CellmlElementType.UNDEFINED, int)
        self.assertIsInstance(CellmlElementType.UNITS, int)
        self.assertIsInstance(CellmlElementType.UNIT, int)
        self.assertIsInstance(CellmlElementType.VARIABLE, int)

    def test_reference_rule_enum(self):
        from libcellml import Issue

        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_EQUATION_NOT_EQUALITY_STATEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_EXTERNAL_VARIABLE_DIFFERENT_MODEL, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_EXTERNAL_VARIABLE_USE_PRIMARY_VARIABLE, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_EXTERNAL_VARIABLE_VOI, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_ODE_NOT_FIRST_ORDER, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_STATE_NOT_INITIALISED, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_STATE_RATE_AS_ALGEBRAIC, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_UNITS, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_UNLINKED_UNITS, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_VARIABLE_COMPUTED_MORE_THAN_ONCE, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_VARIABLE_INITIALISED_MORE_THAN_ONCE, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_VARIABLE_NON_CONSTANT_INITIALISATION, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_VARIABLE_UNUSED, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_VOI_INITIALISED, int)
        self.assertIsInstance(Issue.ReferenceRule.ANALYSER_VOI_SEVERAL, int)
        self.assertIsInstance(Issue.ReferenceRule.ANNOTATOR_ID_NOT_FOUND, int)
        self.assertIsInstance(Issue.ReferenceRule.ANNOTATOR_ID_NOT_UNIQUE, int)
        self.assertIsInstance(Issue.ReferenceRule.ANNOTATOR_INCONSISTENT_TYPE, int)
        self.assertIsInstance(Issue.ReferenceRule.ANNOTATOR_NO_MODEL, int)
        self.assertIsInstance(Issue.ReferenceRule.ANNOTATOR_NULL_MODEL, int)
        self.assertIsInstance(Issue.ReferenceRule.COMPONENT_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.COMPONENT_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.COMPONENT_NAME, int)
        self.assertIsInstance(Issue.ReferenceRule.COMPONENT_NAME_UNIQUE, int)
        self.assertIsInstance(Issue.ReferenceRule.COMPONENT_NAME_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.COMPONENT_REF_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.COMPONENT_REF_COMPONENT_ATTRIBUTE, int)
        self.assertIsInstance(Issue.ReferenceRule.COMPONENT_REF_COMPONENT_ATTRIBUTE_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.COMPONENT_REF_COMPONENT_ATTRIBUTE_UNIQUE, int)
        self.assertIsInstance(Issue.ReferenceRule.COMPONENT_REF_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.CONNECTION_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.CONNECTION_COMPONENT1_ATTRIBUTE, int)
        self.assertIsInstance(Issue.ReferenceRule.CONNECTION_COMPONENT1_ATTRIBUTE_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.CONNECTION_COMPONENT2_ATTRIBUTE, int)
        self.assertIsInstance(Issue.ReferenceRule.CONNECTION_COMPONENT2_ATTRIBUTE_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.CONNECTION_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.CONNECTION_EXCLUDE_SELF, int)
        self.assertIsInstance(Issue.ReferenceRule.CONNECTION_UNIQUE, int)
        self.assertIsInstance(Issue.ReferenceRule.DATA_REPR_IDENTIFIER_AT_LEAST_ONE_ALPHANUM, int)
        self.assertIsInstance(Issue.ReferenceRule.DATA_REPR_IDENTIFIER_BEGIN_EURO_NUM, int)
        self.assertIsInstance(Issue.ReferenceRule.DATA_REPR_IDENTIFIER_LATIN_ALPHANUM, int)
        self.assertIsInstance(Issue.ReferenceRule.ENCAPSULATION_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.ENCAPSULATION_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORTER_ERROR_IMPORTING_UNITS, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORTER_MISSING_COMPONENT, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORTER_MISSING_FILE, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORTER_MISSING_UNITS, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORTER_NULL_MODEL, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORTER_UNDEFINED_MODEL, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORTER_UNRESOLVED_IMPORTS, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_COMPONENT_COMPONENT_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_COMPONENT_COMPONENT_REFERENCE_TARGET, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_COMPONENT_COMPONENT_REFERENCE_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_COMPONENT_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_COMPONENT_NAME, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_COMPONENT_NAME_UNIQUE, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_COMPONENT_NAME_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_EQUIVALENT_INFOSET, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_HREF, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_HREF_LOCATOR, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_UNITS_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_UNITS_NAME, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_UNITS_NAME_UNIQUE, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_UNITS_NAME_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_UNITS_UNITS_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_UNITS_UNITS_REFERENCE_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.IMPORT_UNITS_UNITS_REFERENCE_VALUE_TARGET, int)
        self.assertIsInstance(Issue.ReferenceRule.INVALID_ARGUMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.MAP_VARIABLES_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.MAP_VARIABLES_UNIQUE, int)
        self.assertIsInstance(Issue.ReferenceRule.MAP_VARIABLES_VARIABLE1_ATTRIBUTE, int)
        self.assertIsInstance(Issue.ReferenceRule.MAP_VARIABLES_VARIABLE1_ATTRIBUTE_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.MAP_VARIABLES_VARIABLE2_ATTRIBUTE, int)
        self.assertIsInstance(Issue.ReferenceRule.MAP_VARIABLES_VARIABLE2_ATTRIBUTE_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.MATH_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.MATH_CI_VARIABLE_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.MATH_CN_BASE10, int)
        self.assertIsInstance(Issue.ReferenceRule.MATH_CN_FORMAT, int)
        self.assertIsInstance(Issue.ReferenceRule.MATH_CN_UNITS_ATTRIBUTE, int)
        self.assertIsInstance(Issue.ReferenceRule.MATH_CN_UNITS_ATTRIBUTE_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.MATH_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.MATH_MATHML, int)
        self.assertIsInstance(Issue.ReferenceRule.MODEL_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.MODEL_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.MODEL_MORE_THAN_ONE_ENCAPSULATION, int)
        self.assertIsInstance(Issue.ReferenceRule.MODEL_NAME, int)
        self.assertIsInstance(Issue.ReferenceRule.MODEL_NAME_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_ATTRIBUTE_REQUIRED, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_ORDER_UNIQUE, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_ORDER_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_RESET_VALUE_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_TEST_VALUE_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_TEST_VARIABLE_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_VALUE_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_VALUE_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.RESET_VARIABLE_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.TEST_VALUE_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.TEST_VALUE_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.UNDEFINED, int)
        self.assertIsInstance(Issue.ReferenceRule.UNITS_CHILD, int)
        self.assertIsInstance(Issue.ReferenceRule.UNITS_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.UNITS_NAME, int)
        self.assertIsInstance(Issue.ReferenceRule.UNITS_NAME_UNIQUE, int)
        self.assertIsInstance(Issue.ReferenceRule.UNITS_NAME_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.UNITS_STANDARD, int)
        self.assertIsInstance(Issue.ReferenceRule.UNIT_ATTRIBUTE_EXPONENT_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.UNIT_ATTRIBUTE_MULTIPLIER_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.UNIT_ATTRIBUTE_OPTIONAL, int)
        self.assertIsInstance(Issue.ReferenceRule.UNIT_ATTRIBUTE_PREFIX_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.UNIT_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.UNIT_UNITS, int)
        self.assertIsInstance(Issue.ReferenceRule.UNIT_UNITS_CIRCULAR_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.UNIT_UNITS_REFERENCE, int)
        self.assertIsInstance(Issue.ReferenceRule.UNSPECIFIED, int)
        self.assertIsInstance(Issue.ReferenceRule.VARIABLE_ATTRIBUTE_OPTIONAL, int)
        self.assertIsInstance(Issue.ReferenceRule.VARIABLE_ATTRIBUTE_REQUIRED, int)
        self.assertIsInstance(Issue.ReferenceRule.VARIABLE_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.VARIABLE_INITIAL_VALUE_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.VARIABLE_INTERFACE_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.VARIABLE_NAME_UNIQUE, int)
        self.assertIsInstance(Issue.ReferenceRule.VARIABLE_NAME_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.VARIABLE_UNITS_VALUE, int)
        self.assertIsInstance(Issue.ReferenceRule.XML_ID_ATTRIBUTE, int)
        self.assertIsInstance(Issue.ReferenceRule.XML_UNEXPECTED_CHARACTER, int)
        self.assertIsInstance(Issue.ReferenceRule.XML_UNEXPECTED_ELEMENT, int)
        self.assertIsInstance(Issue.ReferenceRule.XML_UNEXPECTED_NAMESPACE, int)
        self.assertIsInstance(Issue.ReferenceRule.XML_UNEXPECTED_NAMESPACE_PREFIX, int)

    def test_coverage(self):
        from libcellml import Issue
        from libcellml import Parser
        from test_resources import file_contents

        self.assertRaises(AttributeError, Issue)

        p = Parser()
        p.parseModel(file_contents('invalid_cellml_2.0.xml'))

        self.assertEqual(2, p.issueCount())

        i = p.issue(0)

        self.assertEqual(Issue.Level.ERROR, i.level())
        self.assertNotEqual(None, i.item())
        self.assertEqual("1.2.1.1", i.referenceHeading())
        self.assertEqual(1, i.referenceRule())
        self.assertEqual(
            "https://cellml-specification.readthedocs.io/en/latest/reference/formal_and_informative/specA02.html?issue=XML",
            i.url())

        self.assertEqual(2, p.errorCount())
        self.assertEqual(None, p.error(4))
        self.assertEqual(0, p.warningCount())
        self.assertEqual(None, p.warning(0))
        self.assertEqual(0, p.messageCount())
        self.assertEqual(None, p.message(0))


if __name__ == '__main__':
    unittest.main()
