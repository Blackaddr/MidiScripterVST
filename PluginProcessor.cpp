/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Misc.h"


//==============================================================================
ScripterAudioProcessor::ScripterAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    m_midiStorage = (int *)malloc(MAX_SEQUENCES*MAX_EVENTS * 3 * sizeof(int));

    unsigned count = 0;
    for (int seq = 0; seq < MAX_SEQUENCES; seq++) {
        for (int ev = 0; ev < MAX_EVENTS; ev++) {
            for (int i = 0; i < 3; i++) {
                setElement(m_midiStorage, seq, ev, i, 0);

                // Register the audio parameter
                addParameter(paramArray[seq][ev][i] = new AudioParameterInt(String(count), "", 0, 127, 0));
                count++;
            }
        }
    }
}

ScripterAudioProcessor::~ScripterAudioProcessor()
{
    if (m_midiStorage) { 
        free(m_midiStorage); 
        m_midiStorage = nullptr;
    }
}

//==============================================================================
const String ScripterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ScripterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool ScripterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool ScripterAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double ScripterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ScripterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int ScripterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ScripterAudioProcessor::setCurrentProgram (int index)
{
}

const String ScripterAudioProcessor::getProgramName (int index)
{
    return {};
}

void ScripterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void ScripterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void ScripterAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool ScripterAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif



void ScripterAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    buffer.clear();
    int time;
    MidiMessage msg;
    MidiBuffer processedMidi;

    for (MidiBuffer::Iterator it(midiMessages); it.getNextEvent(msg, time);)
    {
        //editor->setTextToWindow(String(String("RECV: Ch:") + String(msg.getChannel()) +
        //    String(" CC:") + String(msg.getControllerNumber()) +
        //    String(" Val:") + String(msg.getControllerValue())));


        //{
        //    MidiEvent eventOut (msg.getChannel(), msg.getControllerNumber(), msg.getControllerValue() );
        //    MidiMessage msgOut = MidiMessage::controllerEvent(eventOut.channel, eventOut.cc + 10, eventOut.value);
        //    processedMidi.addEvent(msgOut, time);
        //}

        //{
        //    MidiEvent eventOut(msg.getChannel(), msg.getControllerNumber(), msg.getControllerValue());
        //    MidiMessage msgOut = MidiMessage::controllerEvent(eventOut.channel, eventOut.cc + 11, eventOut.value);
        //    processedMidi.addEvent(msgOut, time);
        //}
    }
    midiMessages.clear();
    midiMessages.swapWith(processedMidi);
}

//==============================================================================
bool ScripterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* ScripterAudioProcessor::createEditor()
{
    editor =  new ScripterProcessorEditor (*this, m_midiStorage);
    return static_cast<AudioProcessorEditor*>(editor);
}

//==============================================================================
void ScripterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    MemoryOutputStream stream(destData, true);

    for (int seq = 0; seq < MAX_SEQUENCES; seq++) {
        for (int ev = 0; ev < MAX_EVENTS; ev++) {
            for (int i = 0; i < 3; i++) {
                int value = getElement(m_midiStorage, seq, ev, i);
                stream.writeInt(value);
                // It's necessary to mirror the AudioParameter array sync with the int array that stores
                // the data due to he manner in which parameters are handled in VST.
                *(paramArray[seq][ev][i]) = value;
            }
        }
    }

}

void ScripterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

    MemoryInputStream stream(data, static_cast<size_t> (sizeInBytes), false);

    for (int seq = 0; seq < MAX_SEQUENCES; seq++) {
        for (int ev = 0; ev < MAX_EVENTS; ev++) {
            for (int i = 0; i < 3; i++) {
                int value = stream.readInt();
                setElement(m_midiStorage, seq, ev, i, value);
                // It's necessary to mirror the AudioParameter array sync with the int array that stores
                // the data due to he manner in which parameters are handled in VST.
                *(paramArray[seq][ev][i]) = value;
            }
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ScripterAudioProcessor();
}
