#include <stdexcept>
#include <iostream>

#include "States/SplashState.hpp"
#include "States/StateMachine.hpp"
#include "System/Config.hpp"
#include "System/Window.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#endif

namespace Game
{
  void	initialize(int argc, char ** argv)
  {
    Game::Config::initialize(argc, argv);
  }

  void	help()
  {}
};

int	main(int argc, char ** argv)
{
#ifdef __linux__
  // Initializes Xlib support for concurrent threads
  if (XInitThreads() == 0)
  {
    std::cerr << "XInitThreads() failed." << std::endl;
    return EXIT_FAILURE;
  }
#endif

  try
  {
    Game::initialize(argc, argv);
    Game::help();

    // Push initial state in state machine here
    Game::StateMachine::Instance().push(new Game::SplashState());
    Game::StateMachine::Instance().run();
  }
  catch (std::exception e)
  {
    std::cerr << "[Runtime Error]: " << e.what() << std::endl;

#ifdef _WIN32
    MessageBox(Game::Window::Instance().window().getSystemHandle(), e.what(), "Runtime error", MB_OK | MB_ICONSTOP);
#endif

    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
  