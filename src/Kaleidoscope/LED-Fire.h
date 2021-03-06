/* -*- mode: c++ -*-
 * Kaleidoscope-LED-Fire
 * Copyright (C) 2018 Kevin Riggle
 * Copyright (C) 2017 Selene Scriven
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <Kaleidoscope.h>
#include <Kaleidoscope-LEDControl.h>

#define WP_WID 14
#define WP_HGT 5

namespace kaleidoscope { namespace plugin {
class FireEffect : public LEDMode {
 public:
  FireEffect(void) {};

  EventHandlerResult onKeyswitchEvent(Key &mapped_key, byte row, byte col, uint8_t key_state);

  // make the WASD keys (in standard QWERTY layout) brighter
  static bool highlight_wasd;

 protected:
  void update(void) final;

 private:
  static uint8_t frames_since_event;
  static uint8_t surface[2][WP_WID*WP_HGT];
  static uint8_t page;
  static PROGMEM const uint8_t rc2pos[ROWS*COLS];

  static void raindrop(uint8_t x, uint8_t y, int8_t *page);
  static uint8_t wp_rand();
};

} }

extern kaleidoscope::plugin::FireEffect FireEffect;
