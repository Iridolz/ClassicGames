#ifndef _MESSAGE_STATE_HPP_
#define _MESSAGE_STATE_HPP_

#include <string>

#include <SFML/Graphics/Text.hpp>

#include "States/AbstractState.hpp"

namespace Game
{
  class MessageState : public Game::AbstractState
  {
  private:
    sf::Text	_message;	// Message to display
    sf::Text	_return;	// Return button
    int		_selected;	// Index of selected menu (-1 for no selection)

  public:
    MessageState(std::string const &);
    ~MessageState();

    bool	update(sf::Time) override;	// Update state
    void	draw() override;		// Draw state
  };
};

#endif