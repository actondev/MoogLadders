#pragma once

#include "HuovilainenModel.h"
#include "ImprovedModel.h"
#include "KrajeskiModel.h"
#include "MicrotrackerModel.h"
#include "MusicDSPModel.h"
#include "OberheimVariationModel.h"
#include "RKSimulationModel.h"
#include "SimplifiedModel.h"
#include "StilsonModel.h"
#include "moogladders.h"

struct MoogLadders {
  StilsonMoog stilsonModel{44100};
  SimplifiedMoog simplifiedModel{44100};
  HuovilainenMoog huovilainenModel{44100};
  ImprovedMoog improvedModel{44100};
  MicrotrackerMoog microtrackerModel{44100};
  MusicDSPMoog musicdspModel{44100};
  KrajeskiMoog aaronModel{44100};
  RKSimulationMoog rkModel{44100};
  OberheimVariationMoog oberheimModel{44100};

  float process(float in, MoogLadderType type) {
    float buffer[1] = {in};
    switch (type) {
      case Stilson:
        stilsonModel.Process(buffer, 1);
        break;
      case Simplified:
        simplifiedModel.Process(buffer, 1);
        break;
      case Huovilainen:
        huovilainenModel.Process(buffer, 1);
        break;
      case Improved:
        improvedModel.Process(buffer, 1);
        break;
      case Microtracker:
        microtrackerModel.Process(buffer, 1);
        break;
      case MusicDSP:
        musicdspModel.Process(buffer, 1);
        break;
      case Krajeski:
        aaronModel.Process(buffer, 1);
        break;
      case RKSimulation:
        rkModel.Process(buffer, 1);
        break;
      case OberheimVariation:
        oberheimModel.Process(buffer, 1);
        break;
    }
    return buffer[0];
  }

  void setResonance(float Q) {
    stilsonModel.SetResonance(Q);
    simplifiedModel.SetResonance(Q);
    huovilainenModel.SetResonance(Q);
    improvedModel.SetResonance(Q);
    microtrackerModel.SetResonance(Q);
    musicdspModel.SetResonance(Q);
    aaronModel.SetResonance(Q);
    rkModel.SetResonance(Q);
    oberheimModel.SetResonance(Q);
  }

  void setCutoff(float f) {
    stilsonModel.SetCutoff(f);
    simplifiedModel.SetCutoff(f);
    huovilainenModel.SetCutoff(f);
    improvedModel.SetCutoff(f);
    microtrackerModel.SetCutoff(f);
    musicdspModel.SetCutoff(f);
    aaronModel.SetCutoff(f);
    rkModel.SetCutoff(f);
    oberheimModel.SetCutoff(f);
  }
};
