#ifndef _FLOOR_LEVELING_ACTION_HPP_
#define _FLOOR_LEVELING_ACTION_HPP_

#include "Doom/Action/AbstractTypeAction.hpp"

namespace DOOM
{
  template<
    DOOM::EnumAction::Direction Direction,
    DOOM::EnumAction::Speed Speed,
    DOOM::EnumAction::Change Change = DOOM::EnumAction::Change::ChangeNone,
    bool Crush = false
  >
  class FloorLevelingAction : public DOOM::AbstractTypeAction<DOOM::Doom::Level::Sector::Action::Leveling, Change>
  {
  private:
    const float	_target;	// Floor target height

  public:
    FloorLevelingAction(DOOM::Doom & doom, float target, int16_t model = -1) :
      DOOM::AbstractTypeAction<DOOM::Doom::Level::Sector::Action::Leveling, Change>(doom, model),
      _target(target)
    {}

    ~FloorLevelingAction() override = default;

    void	update(DOOM::Doom & doom, DOOM::Doom::Level::Sector & sector, sf::Time elapsed) override	// Update door action
    {
      // Update floor height
      sector.floor_current = (Direction == DOOM::EnumAction::Direction::DirectionUp) ?
	std::min(sector.floor_current + Speed / DOOM::Doom::Tic.asSeconds() * elapsed.asSeconds(), _target) :
	std::max(sector.floor_current - Speed / DOOM::Doom::Tic.asSeconds() * elapsed.asSeconds(), _target);

      // TODO: apply crushing

      // Detect end of action
      if (sector.floor_current == _target) {
	sector.floor_base = sector.floor_current;
	remove(doom, sector);
      }
    }
  };
};

#endif