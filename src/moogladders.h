#pragma once

typedef enum MoogLadderType {
  Stilson = 0,
  Simplified,
  Huovilainen,
  Improved,
  Microtracker,
  MusicDSP,
  Krajeski,
  RKSimulation,
  OberheimVariation,
  DAngelo,
} MoogLadderType;

typedef struct moogladders_t {
  void* impl;
} moogladders_t;

#ifdef __cplusplus
extern "C" {
#endif
moogladders_t moogladders_init();

void moogladders_deinit(moogladders_t);

float moogladders_process(moogladders_t, MoogLadderType, float);
void moogladders_set_cutoff(moogladders_t, float);
void moogladders_set_resonance(moogladders_t, float);

#ifdef __cplusplus
}
#endif
