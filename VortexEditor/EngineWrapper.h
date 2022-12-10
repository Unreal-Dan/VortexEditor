#pragma once

#include "VortexEngine.h"
#include "Patterns/Patterns.h"
#include "Leds/LedTypes.h"

#include <inttypes.h>

#include <string>

class ByteStream;
class Colorset;

// Vortex Engine wrapper class, use this to interface with
// the vortex engine as much as possible
class VEngine
{
  VEngine();
public:

  static void init();
  static void cleanup();

  static bool getModes(ByteStream &outStream);
  static bool setModes(ByteStream &stream);

  // functions to operate on the current mode selection
  static uint32_t curMode();
  static uint32_t numModes();
  static bool addNewMode();
  static bool setCurMode(uint32_t index);
  static bool nextMode();
  static bool delCurMode();

  // functions to operate on the current Mode
  static bool setPattern(PatternID id);
  static PatternID getPatternID(LedPos pos = LED_FIRST);
  static std::string getPatternName(LedPos pos = LED_FIRST);
  static bool setSinglePat(LedPos pos, PatternID id);
  static bool getColorset(LedPos pos, Colorset &set);
  static bool setColorset(LedPos pos, const Colorset &set);

  // Helpers for converting pattern id and led id to string
  static std::string patternToString(PatternID id = PATTERN_NONE);
  static std::string ledToString(LedPos pos);

private:

};