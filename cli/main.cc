//==========================================================================
// Maidez AI code assistant: main.cc
//
// Main file
//
// Copyright (c) 2023 Paul Clark
//==========================================================================

#include "common.h"

namespace
{
}

//--------------------------------------------------------------------------
// Main
int main(int argc, char **argv)
{
  if (argc < 2)
  {
    cout << "Maidez AI code assistant version " << VERSION << endl;

    cout << "\nUsage:\n  " << argv[0] << " [gen options] command [command options]\n";

    cout << "\nGeneral Options:\n";
    cout << "  -q  --quiet            Quiet - issue only data explicitly requested\n";
    cout << "  -v  --verbose          More verbose (can be repeated)\n";
    cout << "  -l  --llm <type>       Select LLM: 'mock' | 'openai' (mock)\n";
    cout << "  -k  --api-key <key>    Set API key for LLM (none)\n";

    cout << "\nCommands:\n";
    cout << "  transform     Transform a code base\n";

    transform_options();

    return 1;
  }

  auto log_level = Log::Level::summary;
  bool quiet = false;
  string api_key;
  string llm_type{"mock"};

  int i;
  for (i=1; i<argc-1; i++)
  {
    string opt = argv[i];

    if (opt=="-q" || opt=="--quiet")
    {
      log_level = Log::Level::none;
      quiet = true;
    }
    else if (opt=="-v" || opt=="--verbose")
      log_level = static_cast<Log::Level>(static_cast<int>(log_level)+1);
    else if ((opt=="-l" || opt=="--llm") && i<argc-1)
      llm_type = argv[++i];
    else if ((opt=="-k" || opt=="--api-key") && i<argc-1)
      api_key = argv[++i];
    else if (opt[0] == '-')
    {
      cerr << "Unknown general option: " << opt << endl;
      return 2;
    }
    else break;
  }

  string command = argv[i];

  // Shift args forward and count backward
  argv+=i;
  argc-=i;

  // Set up logging
  auto chan_out = new Log::StreamChannel{&cerr};
  auto level_out = new Log::LevelFilter{chan_out, log_level};
  Log::logger.connect(level_out);

  if (!quiet)
  {
    cout << "Maidez AI code assistant version " << VERSION << endl;
  }

  // Set up LLM
  unique_ptr<LLM::Interface> llm;
  if (llm_type == "mock")
    llm.reset(new LLM::MockInterface);
  else if (llm_type == "openai")
    llm.reset(new LLM::OpenAIInterface(api_key));
  else
  {
    cerr << "Unknown LLM type '" << llm_type << "'\n";
    return 2;
  }

  // Do command
  if (command == "transform")
    return transform_command(argc, argv, *llm);
  else
  {
    cerr << "Unknown command: " << command << endl;
    return 2;
  }
}


