//==========================================================================
// Maidez AI code assistant: transform.cc
//
// Transform a code based through function-calling AI
//
// Copyright (c) 2023 Paul Clark
//==========================================================================

#include "common.h"

using namespace std;
using namespace ObTools;

//--------------------------------------------------------------------------
// Show options for 'transform'
void transform_options()
{
  cout << "\nTransform Options:\n";
  cout << "  -i --instructions <file>   Set AI instructions (repeatable)\n";
}

//--------------------------------------------------------------------------
// Transform command
int transform_command(int argc, char **argv, LLM::Interface& /*llm*/)
{
  // Create LLM context
  LLM::Context context;

  for (int i=1; i<argc; i++)
  {
    string opt = argv[i];

    if ((opt=="-i" || opt=="--instructions") && i<argc-1)
    {
      File::Path ifile(argv[++i]);
      string instructions;
      if (ifile.read_all(instructions))
        context.add({ LLM::Context::Element::Role::instruction, instructions });
      else
        cerr << "Can't read file " << ifile << " - ignored\n";
    }
    else if (opt[0] == '-')
    {
      cerr << "Unknown chat option: " << opt << endl;
      return 2;
    }

    // !!! Use non - option?
  }

  // !!! Do something!

  return 0;
}
