# The content of this file was generated using the Python profile of libCellML 0.6.1.

from enum import Enum
from math import *


__version__ = "0.4.0"
LIBCELLML_VERSION = "0.6.1"

VARIABLE_COUNT = 3


class VariableType(Enum):
    CONSTANT = 0
    COMPUTED_CONSTANT = 1
    ALGEBRAIC = 2


VARIABLE_INFO = [
    {"name": "k", "units": "mM", "component": "constants", "type": VariableType.CONSTANT},
    {"name": "x", "units": "mM", "component": "main", "type": VariableType.COMPUTED_CONSTANT},
    {"name": "y", "units": "M", "component": "main", "type": VariableType.COMPUTED_CONSTANT}
]


def create_variables_array():
    return [nan]*VARIABLE_COUNT


def initialise_variables(variables):
    variables[0] = 123.0


def compute_computed_constants(variables):
    variables[1] = variables[0]+variables[0]
    variables[2] = 0.001*variables[0]+0.001*variables[0]


def compute_variables(variables):
    pass
