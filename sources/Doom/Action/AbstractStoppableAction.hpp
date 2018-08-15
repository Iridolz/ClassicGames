#ifndef _ABSTRACT_STOPPABLE_ACTION_HPP_
#define _ABSTRACT_STOPPABLE_ACTION_HPP_

#include "Doom/Action/AbstractTypeAction.hpp"

namespace DOOM
{
  template<
    DOOM::Doom::Level::Sector::Action Type,
    DOOM::EnumAction::Change::Type ChangeType = DOOM::EnumAction::Change::Type::None
  >
  class AbstractStoppableAction : public DOOM::AbstractTypeAction<Type, ChangeType>
  {
  protected:
    bool	_run;	// Flag for stop

  public:
    AbstractStoppableAction(DOOM::Doom & doom, DOOM::Doom::Level::Sector & sector) :
      DOOM::AbstractTypeAction<Type, ChangeType>(doom, sector),
      _run(true)
    {}

    virtual ~AbstractStoppableAction() = default;

    void	stop(DOOM::Doom & doom, DOOM::AbstractThing & thing) override	// Request action to stop (for lift & crusher)
    {
      // TODO: add check of thing type ?

      // Set stop flag
      _run = false;
    }

    void	start(DOOM::Doom & doom, DOOM::AbstractThing & thing) override	// Request action to start (for lift & crusher)
    {
      // TODO: add check of thing type ?

      // Set run flag
      _run = true;
    }
  };
};

#endif