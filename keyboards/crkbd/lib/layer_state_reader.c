#include <stdio.h>
#include "action_layer.h"

#define L_BASE 0
#define L_LEFT_FN (1 << 1)
#define L_RIGHT_FN (1 << 2)
#define L_LEFT_MOD (1 << 3)
#define L_RIGHT_MOD (1 << 4)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: base");
    break;
  case L_LEFT_FN:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: left");
    break;
  case L_RIGHT_FN:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: right");
    break;
  case L_LEFT_MOD:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: left-mod");
    break;
  case L_RIGHT_MOD:
    snprintf(layer_state_str, sizeof(layer_state_str), "layer: right-mod");
    break;
  default:
#if defined (LAYER_STATE_32BIT)
    snprintf(layer_state_str, sizeof(layer_state_str), "$ unknown: %ld", layer_state);
#else
    snprintf(layer_state_str, sizeof(layer_state_str), "$ unknown: %d", layer_state);
#endif
  }

  return layer_state_str;
}
