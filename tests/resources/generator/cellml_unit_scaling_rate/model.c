/* The content of this file was generated using the C profile of libCellML 0.6.1. */

#include "model.h"

#include <math.h>
#include <stdlib.h>

const char VERSION[] = "0.5.0";
const char LIBCELLML_VERSION[] = "0.6.1";

const size_t STATE_COUNT = 1;
const size_t VARIABLE_COUNT = 2;

const VariableInfo VOI_INFO = {"t", "ms", "environment", VARIABLE_OF_INTEGRATION};

const VariableInfo STATE_INFO[] = {
    {"k", "mM", "states", STATE}
};

const VariableInfo VARIABLE_INFO[] = {
    {"x", "mM", "main", ALGEBRAIC},
    {"y", "M", "main", ALGEBRAIC}
};

double * createStatesArray()
{
    double *res = (double *) malloc(STATE_COUNT*sizeof(double));

    for (size_t i = 0; i < STATE_COUNT; ++i) {
        res[i] = NAN;
    }

    return res;
}

double * createVariablesArray()
{
    double *res = (double *) malloc(VARIABLE_COUNT*sizeof(double));

    for (size_t i = 0; i < VARIABLE_COUNT; ++i) {
        res[i] = NAN;
    }

    return res;
}

void deleteArray(double *array)
{
    free(array);
}

void initialiseVariables(double *states, double *rates, double *variables)
{
    states[0] = 123.0;
}

void computeComputedConstants(double *variables)
{
}

void computeRates(double voi, double *states, double *rates, double *variables)
{
    rates[0] = 1.23;
}

void computeVariables(double voi, double *states, double *rates, double *variables)
{
    variables[0] = 1000.0*rates[0]+1000.0*rates[0];
    variables[1] = 1000.0*0.001*rates[0]+1000.0*0.001*rates[0];
}
