%module(package="libcellml") analyserequation

#define LIBCELLML_EXPORT

%include <std_shared_ptr.i>
%include <std_vector.i>

%import "types.i"

%feature("docstring") libcellml::AnalyserEquation
"Creates an :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::type
"Returns the :enum:`AnalyserEquation::Type` for this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::typeAsString
"Returns the :enum:`AnalyserEquation::Type` as a string for this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::ast
"Returns the :class:`AnalyserEquationAst` object for this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::dependencyCount
"Returns the number of dependencies for this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::dependencies
"Returns the dependencies for this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::dependency
"Returns the dependency, at the given index, for this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::nlaSystemIndex
"Returns the index of the NLA system for this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::nlaSiblingCount
"Returns the number of NLA siblings for this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::nlaSiblings
"Returns the NLA siblings for this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::nlaSibling
"Returns the NLA sibling, at the given index, for this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::isStateRateBased
"Tests if this :class:`AnalyserEquation` object relies on states and/or rates.";

%feature("docstring") libcellml::AnalyserEquation::variableCount
"Returns the number of variables computed by this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::variables
"Returns the variables computed by this :class:`AnalyserEquation` object.";

%feature("docstring") libcellml::AnalyserEquation::variable
"Returns the variable, at the given index, computed by this :class:`AnalyserEquation` object.";

%{
#include "libcellml/analyserequation.h"
%}

%template(AnalyserEquationVector) std::vector<libcellml::AnalyserEquationPtr>;

%pythoncode %{
# libCellML generated wrapper code starts here.
%}

%shared_ptr(libcellml::AnalyserEquation);

%include "libcellml/types.h"
%include "libcellml/analyserequation.h"
