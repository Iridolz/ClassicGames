#pragma once

#include <list>

#include "Doom/Action/AbstractStoppableAction.hpp"

namespace DOOM
{
  template<
    DOOM::EnumAction::Speed Speed,
    bool Repeat = false,
    unsigned int TickWait = 105
  >
    class LiftLevelingAction : public DOOM::AbstractStoppableAction<DOOM::Doom::Level::Sector::Action::Leveling>
  {
  private:
    enum State
    {
      Raise,  // Raise the lift
      Lower,  // Lower the lift
      Wait,   // Wait for the specified time
      Stop    // Stop and remove lift
    };

    const float _low, _high;  // Low and high height of lift
    State       _state;       // Lift current state
    sf::Time    _elapsed;     // Elapsed time since beginning of state

    sf::Time  updateRaise(DOOM::Doom& doom, DOOM::Doom::Level::Sector& sector, sf::Time elapsed)
    {
      float obstacle = std::numeric_limits<float>::max();

      // Get lowest obstacle
      // TODO: is Shootable enough to identify a monster ?
      for (const std::reference_wrapper<DOOM::AbstractThing>& thing : doom.level.getThings(sector, DOOM::Enum::ThingProperty::ThingProperty_Shootable))
        for (int16_t sector_index : doom.level.getSectors(thing.get().position.convert<2>(), thing.get().attributs.radius / 2.f))
          obstacle = std::min(obstacle, doom.level.sectors[sector_index].ceiling_current - thing.get().height);

      // Handle collision with obstacle
      if (sector.floor_current + elapsed.asSeconds() * Speed / DOOM::Doom::Tic.asSeconds() > obstacle) {
        if (sector.floor_current > obstacle) {
          _state = State::Lower;
          return elapsed;
        }
        else {
          sf::Time  exceding = std::min(sf::seconds((obstacle - sector.floor_current) / Speed * DOOM::Doom::Tic.asSeconds()), elapsed);

          sector.floor_current = obstacle;
          _state = State::Lower;
          return exceding;
        }
      }

      // Raise floor
      sector.floor_current += elapsed.asSeconds() * Speed / DOOM::Doom::Tic.asSeconds();

      // Compute exceding time
      if (sector.floor_current > _high) {
        sf::Time  exceding = std::min(sf::seconds((sector.floor_current - _high) / Speed * DOOM::Doom::Tic.asSeconds()), elapsed);

        sector.floor_current = _high;
        _state = (Repeat == true ? State::Wait : State::Stop);
        return exceding;
      }
      else {
        return sf::Time::Zero;
      }
    }

    sf::Time  updateLower(DOOM::Doom& doom, DOOM::Doom::Level::Sector& sector, sf::Time elapsed)
    {
      sf::Time  remaining = sf::Time::Zero;

      // Lower floor
      float     floor_new = sector.floor_current - elapsed.asSeconds() * Speed / DOOM::Doom::Tic.asSeconds();

      // Compute exceding time
      if (floor_new < _low) {
        remaining = std::min(sf::seconds((_low - floor_new) / Speed * DOOM::Doom::Tic.asSeconds()), elapsed);
        floor_new = _low;
        _state = State::Wait;
      }

      // Lower things that stand on the ground of the sector
      for (const std::reference_wrapper<DOOM::AbstractThing>& thing : doom.level.getThings(sector, DOOM::Enum::ThingProperty::ThingProperty_Shootable))
        if ((thing.get().attributs.properties & DOOM::Enum::ThingProperty::ThingProperty_SpawnCeiling) == 0 && thing.get().position.z() == sector.floor_current) {
          float floor_next = std::numeric_limits<float>::lowest();

          // Find next lower floor
          for (int16_t sector_index : doom.level.getSectors(thing.get().position.convert<2>(), thing.get().attributs.radius / 2.f)) {
            const DOOM::Doom::Level::Sector& sector_current = doom.level.sectors[sector_index];

            if (&sector_current != &sector)
              floor_next = std::max(floor_next, sector_current.floor_current);
          }

          // Move thing to new floor position
          thing.get().position.z() = std::max(floor_next, floor_new);
        }

      sector.floor_current = floor_new;
      return remaining;
    }

    sf::Time  updateWait(DOOM::Doom& doom, DOOM::Doom::Level::Sector& sector, sf::Time elapsed)
    {
      // Add elapsed time to counter
      _elapsed += elapsed;

      // Compute remaining time if any
      sf::Time  exceding = std::max(_elapsed - (DOOM::Doom::Tic * (float)TickWait), sf::Time::Zero);

      // Switch to next state if wait finished
      if (exceding != sf::Time::Zero) {
        _state = (sector.floor_current == _low ?
          State::Raise :
          State::Lower);
      }

      return exceding;
    }

    sf::Time  updateStop(DOOM::Doom& doom, DOOM::Doom::Level::Sector& sector, sf::Time elapsed)
    {
      // Set new floor base value
      sector.floor_base = sector.floor_current;

      // Remove sector action
      remove(doom, sector);

      return sf::Time::Zero;
    }

  public:
    LiftLevelingAction(DOOM::Doom& doom, DOOM::Doom::Level::Sector& sector, float low, float high) :
      DOOM::AbstractStoppableAction<DOOM::Doom::Level::Sector::Action::Leveling>(doom, sector),
      _low(low),
      _high(high),
      _state(State::Lower),
      _elapsed(sf::Time::Zero)
    {}

    ~LiftLevelingAction() override = default;

    void  update(DOOM::Doom& doom, DOOM::Doom::Level::Sector& sector, sf::Time elapsed) override  // Update door action
    {
      if (Repeat == true && _run == false)
        return;

      // Update action states
      while (elapsed != sf::Time::Zero) {
        switch (_state)
        {
        case State::Raise:
          elapsed = updateRaise(doom, sector, elapsed);
          break;
        case State::Lower:
          elapsed = updateLower(doom, sector, elapsed);
          break;
        case State::Wait:
          elapsed = updateWait(doom, sector, elapsed);
          break;
        case State::Stop:
          elapsed = updateStop(doom, sector, elapsed);
          break;

        default:  // Handle error (should not happen)
          throw std::runtime_error((std::string(__FILE__) + ": l." + std::to_string(__LINE__)).c_str());
        }

        // Reset internal elapsed time between states
        if (elapsed != sf::Time::Zero)
          _elapsed = sf::Time::Zero;
      }
    }
  };
}