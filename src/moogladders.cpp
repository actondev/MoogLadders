#include "moogladders.hpp"

extern "C" {
moogladders_t moogladders_init() {
  return moogladders_t{new MoogLadders{}};
}

void moogladders_deinit(moogladders_t m) {
  MoogLadders* impl = reinterpret_cast<MoogLadders*>(m.impl);
  delete impl;
}

float moogladders_process(moogladders_t m, MoogLadderType t, float in) {
  MoogLadders* impl = reinterpret_cast<MoogLadders*>(m.impl);
  return impl->process(in, t);
}

float moogladders_processx(moogladders_t m,
                           MoogLadderType t,
                           float in,
                           unsigned int x) {
  MoogLadders* impl = reinterpret_cast<MoogLadders*>(m.impl);
  return impl->processx(in, t, x);
}

void moogladders_set_cutoff(moogladders_t m, float cutoff) {
  MoogLadders* impl = reinterpret_cast<MoogLadders*>(m.impl);
  impl->setCutoff(cutoff);
}

void moogladders_set_resonance(moogladders_t m, float res) {
  MoogLadders* impl = reinterpret_cast<MoogLadders*>(m.impl);
  impl->setResonance(res);
}
}
