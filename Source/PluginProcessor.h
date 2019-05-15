/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Misc.h"


//==============================================================================
/**
*/
class ScripterAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    ScripterAudioProcessor();
    ~ScripterAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect () const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    void setElement(int seq, int ev, int word, int value);
    int  getElement(int seq, int ev, int word);
    void clearElements();

    unsigned getSequenceSize() { return m_midiSequenceList->size(); }
    void addSequence();
    void removeSequence();
    void setSelectedSequence(unsigned index) { m_selectedSequence = index; }
    unsigned getSelectedSequence() { return m_selectedSequence; }
    void loadFromStorage();
    void saveToStorage();
    MidiEvent getEvent(int seq, int ev) { return m_midiSequenceList->at(seq).at(ev); }

private:
    //==============================================================================
    //ScripterProcessorEditor *editor = nullptr;
    AudioParameterInt *paramArray[MAX_EVENTS][MAX_EVENTS][3];
    MidiSequenceList *m_midiSequenceList;
    unsigned m_selectedSequence = 0;
    void setElementLocal(int seq, int ev, int word, int value);
    AudioProcessorEditor* m_editor = nullptr;
    bool m_printAllCCEvents = true;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ScripterAudioProcessor)
    
};
