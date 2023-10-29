//==========================================================================
// Maidez AI-driven code assistant
//
// Common header file
//
// Copyright (c) 2023 Paul Clark
//==========================================================================

#include "ot-log.h"
#include "ot-llm.h"

using namespace std;
using namespace ObTools;

//==========================================================================
// Transform (transform.cc)

//--------------------------------------------------------------------------
// Show options for transform
void transform_options();

//--------------------------------------------------------------------------
// Do a transform
int transform_command(int argc, char **argv, LLM::Interface& llm);

