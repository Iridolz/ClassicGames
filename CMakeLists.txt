CMAKE_MINIMUM_REQUIRED(VERSION 3.0.2)
PROJECT(ClassicGames)

# Set game sources
SET(GAME_DOOM_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Camera.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Camera.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Doom.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Doom.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Statusbar.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Statusbar.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Wad.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Wad.hpp
)
SET(GAME_DOOM_FLAT_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Flat/AbstractFlat.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Flat/AbstractFlat.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Flat/AnimatedFlat.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Flat/AnimatedFlat.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Flat/StaticFlat.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Flat/StaticFlat.hpp
)
SET(GAME_DOOM_LINEDEF_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/AbstractLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/AbstractLinedef.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/AbstractTriggerableLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/AbstractTriggerableLinedef.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/NullLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/NullLinedef.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/ScrollerLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/ScrollerLinedef.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/ActionTriggerableLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/ActionTriggerableLinedef.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/DonutTriggerableLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/DonutTriggerableLinedef.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/ExitLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/ExitLinedef.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/LightTriggerableLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/LightTriggerableLinedef.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/StairTriggerableLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/StairTriggerableLinedef.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/StopTriggerableLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/StopTriggerableLinedef.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/TeleporterTriggerableLinedef.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Linedef/TeleporterTriggerableLinedef.hpp
)
SET(GAME_DOOM_ACTION_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/AbstractAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/AbstractAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/AbstractStoppableAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/AbstractStoppableAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/AbstractTypeAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/AbstractTypeAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/BlinkLightingAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/BlinkLightingAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/CeilingLevelingAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/CeilingLevelingAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/CrusherLevelingAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/CrusherLevelingAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/DoorLevelingAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/DoorLevelingAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/FlickerLightingAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/FlickerLightingAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/FloorLevelingAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/FloorLevelingAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/LiftLevelingAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/LiftLevelingAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/OscillateLightingAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/OscillateLightingAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/PlatformLevelingAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/PlatformLevelingAction.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/RandomLightingAction.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Action/RandomLightingAction.hpp
)
SET(GAME_DOOM_THING_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Thing/AbstractThing.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Thing/AbstractThing.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Thing/PlayerThing.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/Thing/PlayerThing.hpp
)
SET(GAME_DOOM_STATES_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/DoomState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/DoomState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/GameDoomState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/GameDoomState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/MenuDoomState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/MenuDoomState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/SplashDoomState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/SplashDoomState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/StartDoomState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/StartDoomState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/TransitionDoomState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Doom/States/TransitionDoomState.hpp
)
SET(GAME_MATH_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Math/Math.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Math/Math.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Math/Vector.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Math/Vector.hpp
)
SET(GAME_STATES_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/StateMachine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/StateMachine.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/AbstractState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/AbstractState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/LoadingState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/LoadingState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/MessageState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/MessageState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/SplashState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/SplashState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/StartState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/StartState.hpp
)
SET(GAME_STATES_MENU_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/Menu/AbstractMenuState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/Menu/AbstractMenuState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/Menu/MainMenuState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/Menu/MainMenuState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/Menu/OptionsMenuState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/States/Menu/OptionsMenuState.hpp
)
SET(GAME_SYSTEM_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Config.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Config.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Sound.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Sound.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Window.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Window.hpp
)
SET(GAME_SYSTEM_LIBRARY_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Library/AbstractLibrary.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Library/AbstractLibrary.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Library/FontLibrary.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Library/FontLibrary.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Library/TextureLibrary.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/System/Library/TextureLibrary.hpp
)
SET(GAME_SRCS
	${GAME_DOOM_SRCS}
	${GAME_DOOM_FLAT_SRCS}
	${GAME_DOOM_LINEDEF_SRCS}
	${GAME_DOOM_ACTION_SRCS}
	${GAME_DOOM_THING_SRCS}
	${GAME_DOOM_STATES_SRCS}
	${GAME_MATH_SRCS}
	${GAME_STATES_SRCS}
	${GAME_STATES_MENU_SRCS}
	${GAME_SYSTEM_SRCS}
	${GAME_SYSTEM_LIBRARY_SRCS}
	${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
)

# Set game resources
SET(GAME_RSRC
	${CMAKE_CURRENT_SOURCE_DIR}/assets/icons/Icons.rc
	${CMAKE_CURRENT_SOURCE_DIR}/assets/levels/dmsp1666.txt
)

# Set game source groups
SOURCE_GROUP("\\" FILES ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp)
SOURCE_GROUP("\\Doom\\" FILES ${GAME_DOOM_SRCS})
SOURCE_GROUP("\\Doom\\Flat\\" FILES ${GAME_DOOM_FLAT_SRCS})
SOURCE_GROUP("\\Doom\\Linedef\\" FILES ${GAME_DOOM_LINEDEF_SRCS})
SOURCE_GROUP("\\Doom\\Action\\" FILES ${GAME_DOOM_ACTION_SRCS})
SOURCE_GROUP("\\Doom\\Thing\\" FILES ${GAME_DOOM_THING_SRCS})
SOURCE_GROUP("\\Doom\\States\\" FILES ${GAME_DOOM_STATES_SRCS})
SOURCE_GROUP("\\Math\\" FILES ${GAME_MATH_SRCS})
SOURCE_GROUP("\\States\\" FILES ${GAME_STATES_SRCS})
SOURCE_GROUP("\\States\\Menu\\" FILES ${GAME_STATES_MENU_SRCS})
SOURCE_GROUP("\\System\\" FILES ${GAME_SYSTEM_SRCS})
SOURCE_GROUP("\\System\\Library\\" FILES ${GAME_SYSTEM_LIBRARY_SRCS})
SOURCE_GROUP("\\Resources\\" FILES ${GAME_RSRC})

# Import SFML library
SET(SFML_STATIC_LIBRARIES TRUE)
FIND_PACKAGE(SFML 2.5 COMPONENTS system window network graphics audio REQUIRED)

# Set includes directories
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/sources/)

# Generate executables
ADD_EXECUTABLE(Game ${GAME_SRCS} ${GAME_RSRC})
TARGET_LINK_LIBRARIES(Game sfml-system sfml-window sfml-network sfml-graphics sfml-audio)

# Force C++17
SET_TARGET_PROPERTIES(Game PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)

# Copy assets to build directory
ADD_CUSTOM_COMMAND(TARGET Game POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets/ $<TARGET_FILE_DIR:Game>/assets/)
