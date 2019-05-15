/*
  ==============================================================================

    Misc.h
    Created: 16 Mar 2019 12:24:46pm
    Author:  Edmund Blackaddr

  ==============================================================================
*/

#pragma once

#include <vector>

constexpr unsigned MAX_SEQUENCES = 10;
constexpr unsigned MAX_EVENTS = 11;

constexpr unsigned TRIG_ID = 0;
constexpr unsigned CH_ID = 0;
constexpr unsigned CC_ID = 1;
constexpr unsigned VAL_ID = 2;



struct MidiEvent {
    MidiEvent() : channel(0), cc(0), value(0) {}
    MidiEvent(int channel, int cc, int value) : channel(channel), cc(cc), value(value) {}
    int channel;
    int cc;
    int value;
};

using MidiSequence = std::vector<MidiEvent>;
using MidiSequenceList = std::vector<MidiSequence>;

int  getElement(int *arr, int seq, int ev, int word);
void setElement(int *arr, int seq, int ev, int word, int value);
//int  getElement(int (&arr)[MAX_SEQUENCES][MAX_EVENTS][3], int seq, int ev, int word);
//void setElement(int (&arr)[MAX_EVENTS][MAX_EVENTS][3], int seq, int ev, int word, int value);