"""
Python bindings for libCellML

The purpose of libCellML is to create, manipulate, serialise, deserialise,
 validate and instantiate CellML models. In the first instance, all serialising
 and deserialising will be to and from standard strings and using the CellML
 XML format.
"""

import libcellml
from libcellml.analyser import Analyser
from libcellml.analyserequation import AnalyserEquation
from libcellml.analyserequationast import AnalyserEquationAst
from libcellml.analyserexternalvariable import AnalyserExternalVariable
from libcellml.analysermodel import AnalyserModel
from libcellml.analyservariable import AnalyserVariable
from libcellml.component import Component
from libcellml.generator import Generator
from libcellml.generatorprofile import GeneratorProfile
from libcellml.importsource import ImportSource
from libcellml.issue import Issue
from libcellml.model import Model
from libcellml.parser import Parser
from libcellml.printer import Printer
from libcellml.reset import Reset
from libcellml.units import Units
from libcellml.validator import Validator
from libcellml.variable import Variable
from libcellml.version import version, versionString


# Convert enumerations generated by SWIG


def convert(base, enum, variables, new_base=None):
    converting = False

    class Object:
        pass

    obj = Object()
    for var in variables:
        if hasattr(base, enum + '_' + var):
            # Swig 3.0.3 and higher
            setattr(obj, var, getattr(base, enum + '_' + var))
            delattr(base, enum + '_' + var)
            converting = True
        elif hasattr(base, var):
            # Swig 3.0.0, 3.0.1, 3.0.2
            setattr(obj, var, getattr(base, var))
            delattr(base, var)
            converting = True
    if converting:
        setattr(base if new_base is None else new_base, enum, obj)


convert(AnalyserEquation, 'Type', [
    'TRUE_CONSTANT',
    'VARIABLE_BASED_CONSTANT',
    'RATE',
    'ALGEBRAIC',
])
convert(AnalyserEquationAst, 'Type', [
    'ASSIGNMENT',

    # Relational and logical operators.

    'EQ',
    'NEQ',
    'LT',
    'LEQ',
    'GT',
    'GEQ',
    'AND',
    'OR',
    'XOR',
    'NOT',

    # Arithmetic operators.

    'PLUS',
    'MINUS',
    'TIMES',
    'DIVIDE',
    'POWER',
    'ROOT',
    'ABS',
    'EXP',
    'LN',
    'LOG',
    'CEILING',
    'FLOOR',
    'MIN',
    'MAX',
    'REM',

    # Calculus elements.

    'DIFF',

    # Trigonometric operators.

    'SIN',
    'COS',
    'TAN',
    'SEC',
    'CSC',
    'COT',
    'SINH',
    'COSH',
    'TANH',
    'SECH',
    'CSCH',
    'COTH',
    'ASIN',
    'ACOS',
    'ATAN',
    'ASEC',
    'ACSC',
    'ACOT',
    'ASINH',
    'ACOSH',
    'ATANH',
    'ASECH',
    'ACSCH',
    'ACOTH',

    # Piecewise statement.

    'PIECEWISE',
    'PIECE',
    'OTHERWISE',

    # Token elements.

    'CI',
    'CN',

    # Qualifier elements.

    'DEGREE',
    'LOGBASE',
    'BVAR',

    # Constants.

    'TRUE',
    'FALSE',
    'E',
    'PI',
    'INF',
    'NAN',
])
convert(AnalyserModel, 'Type', [
    'UNKNOWN',
    'ALGEBRAIC',
    'ODE',
    'INVALID',
    'UNDERCONSTRAINED',
    'OVERCONSTRAINED',
    'UNSUITABLY_CONSTRAINED',
])
convert(AnalyserVariable, 'Type', [
    'VARIABLE_OF_INTEGRATION',
    'STATE',
    'CONSTANT',
    'COMPUTED_CONSTANT',
    'ALGEBRAIC',
])
convert(GeneratorProfile, 'Profile', [
    'C',
    'PYTHON',
])
convert(Issue, 'Cause', [
    'COMPONENT',
    'CONNECTION',
    'ENCAPSULATION',
    'IMPORT',
    'MATHML',
    'MODEL',
    'RESET',
    'UNDEFINED',
    'UNITS',
    'VARIABLE',
    'XML',
])
convert(Issue, 'Level', [
    'ERROR',
    'WARNING',
    'HINT',
    'INFORMATION',
])
convert(Issue, 'ReferenceRule', [
    'UNDEFINED',
    'DATA_REPR_IDENTIFIER_UNICODE',
    'DATA_REPR_IDENTIFIER_LATIN_ALPHANUM',
    'DATA_REPR_IDENTIFIER_AT_LEAST_ONE_ALPHANUM',
    'DATA_REPR_IDENTIFIER_BEGIN_EURO_NUM',
    'DATA_REPR_IDENTIFIER_IDENTICAL',
    'DATA_REPR_NNEG_INT_BASE10',
    'DATA_REPR_NNEG_INT_EURO_NUM',
    'MODEL_ELEMENT',
    'MODEL_NAME',
    'MODEL_CHILD',
    'MODEL_MORE_THAN_ONE_ENCAPSULATION',
    'IMPORT_HREF',
    'IMPORT_CHILD',
    'IMPORT_CIRCULAR',
    'IMPORT_UNITS_NAME',
    'IMPORT_UNITS_REF',
    'IMPORT_COMPONENT_NAME',
    'IMPORT_COMPONENT_REF',
    'UNITS_NAME',
    'UNITS_NAME_UNIQUE',
    'UNITS_STANDARD',
    'UNITS_CHILD',
    'UNIT_UNITS_REF',
    'UNIT_DIGRAPH',
    'UNIT_CIRCULAR_REF',
    'UNIT_OPTIONAL_ATTRIBUTE',
    'UNIT_PREFIX',
    'UNIT_MULTIPLIER',
    'UNIT_EXPONENT',
    'COMPONENT_NAME',
    'COMPONENT_CHILD',
    'VARIABLE_NAME',
    'VARIABLE_UNITS',
    'VARIABLE_INTERFACE',
    'VARIABLE_INITIAL_VALUE',
    'RESET_CHILD',
    'RESET_ORDER',
    'RESET_VARIABLE_REFERENCE',
    'RESET_TEST_VARIABLE_REFERENCE',
    'RESET_TEST_VALUE',
    'RESET_RESET_VALUE',
    'MATH_MATHML',
    'MATH_CHILD',
    'MATH_CI_VARIABLE_REFERENCE',
    'MATH_CN_UNITS_ATTRIBUTE',
    'ENCAPSULATION_COMPONENT_REF',
    'COMPONENT_REF_COMPONENT_ATTRIBUTE',
    'COMPONENT_REF_CHILD',
    'COMPONENT_REF_ENCAPSULATION',
    'CONNECTION_COMPONENT1',
    'CONNECTION_COMPONENT2',
    'CONNECTION_UNIQUE_TRANSITIVE',
    'CONNECTION_MAP_VARIABLES',
    'MAP_VARIABLES_VARIABLE1',
    'MAP_VARIABLES_VARIABLE2',
    'MAP_VARIABLES_UNIQUE',
    'MAP_VARIABLES_IDENTICAL_UNIT_REDUCTION',
])
convert(Units, 'Prefix', [
    'YOTTA',
    'ZETTA',
    'EXA',
    'PETA',
    'TERA',
    'GIGA',
    'MEGA',
    'KILO',
    'HECTO',
    'DECA',
    'DECI',
    'CENTI',
    'MILLI',
    'MICRO',
    'NANO',
    'PICO',
    'FEMTO',
    'ATTO',
    'ZEPTO',
    'YOCTO',
], new_base=Units)
convert(Units, 'StandardUnit', [
    'AMPERE',
    'BECQUEREL',
    'CANDELA',
    'COULOMB',
    'DIMENSIONLESS',
    'FARAD',
    'GRAM',
    'GRAY',
    'HENRY',
    'HERTZ',
    'JOULE',
    'KATAL',
    'KELVIN',
    'KILOGRAM',
    'LITRE',
    'LUMEN',
    'LUX',
    'METRE',
    'MOLE',
    'NEWTON',
    'OHM',
    'PASCAL',
    'RADIAN',
    'SECOND',
    'SIEMENS',
    'SIEVERT',
    'STERADIAN',
    'TESLA',
    'VOLT',
    'WATT',
    'WEBER',
])
convert(Variable, 'InterfaceType', [
    'NONE',
    'PRIVATE',
    'PUBLIC',
    'PUBLIC_AND_PRIVATE',
])
del (convert, libcellml)
