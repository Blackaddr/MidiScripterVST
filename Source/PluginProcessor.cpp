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
    : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput("Input", AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", AudioChannelSet::stereo(), true)
#endif
    )
#endif
{
    //m_midiStorage = (int *)malloc(MAX_SEQUENCES*MAX_EVENTS * 3 * sizeof(int));
    m_midiSequenceList = new MidiSequenceList();
    if (!m_midiSequenceList) {
        throw std::exception("Failed to allocate m_midiSequenceList");
    }

    unsigned count = 0;
    for (int seq = 0; seq < MAX_SEQUENCES; seq++) {
        for (int ev = 0; ev < MAX_EVENTS; ev++) {
            for (int i = 0; i < 3; i++) {
                // Register the audio parameter
                addParameter(paramArray[seq][ev][i] = new AudioParameterInt(String(count), String(String("param") + String(count)), 0, 127, 0));
                if (!paramArray[seq][ev][i]) {
                    throw std::exception("Failed to allocate paramArray");
                }
                count++;
            }
        }
    }
    loadFromStorage();
}

ScripterAudioProcessor::~ScripterAudioProcessor()
{
    if (m_midiSequenceList) {
        delete m_midiSequenceList;
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
    ScripterProcessorEditor* editor = reinterpret_cast<ScripterProcessorEditor*>(m_editor);

    for (MidiBuffer::Iterator it(midiMessages); it.getNextEvent(msg, time);)
    {
        // If enabled, print all CC messages to the text window
        if ( m_printAllCCEvents && msg.isController() && editor) {
            editor->setWindowText(String(String("RECV:: Ch:") + String(msg.getChannel()) + String(" CC:") + String(msg.getControllerNumber()) + String(" Val:") + String(msg.getControllerValue()) + String("\n")));
        }

        for (auto seq = m_midiSequenceList->begin(); seq != m_midiSequenceList->end(); ++seq) {

            MidiEvent trigger = (*seq).at(TRIG_ID); // get the sequence trigger event

            // Check if the MIDI message matches the trigger
            if ((trigger.channel == msg.getChannel()) && (trigger.cc == msg.getControllerNumber()) && (trigger.value == msg.getControllerValue()) ) {
                
                if (editor) {
                    editor->setWindowText(String(String("TRIG:: Ch:") + String(trigger.channel) + String(" CC:") + String(trigger.cc) + String(" Val:") + String(trigger.value) + String("\n")));
                }

                // Send each event starting after the trigger
                for (auto ev = (*seq).begin() + 1; ev != (*seq).end(); ++ev) {
                    if ((*ev).cc != 0) {
                        if (editor) {
                            editor->setWindowText(String(String("SEND:: Ch:") + String((*ev).channel) + String(" CC:") + String((*ev).cc) + String(" Val:") + String((*ev).value) + String("\n")));
                        }
                        MidiMessage msgOut = MidiMessage::controllerEvent((*ev).channel, (*ev).cc, (*ev).value);
                        processedMidi.addEvent(msgOut, time);
                    }
                }
            }
        }

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
    m_editor =  new ScripterProcessorEditor (*this);
    return m_editor;
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
                int value = getElement(seq, ev, i);
                stream.writeInt(value);
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
                setElementLocal(seq, ev, i, value);
            }
        }
    }
    loadFromStorage();
    m_selectedSequence = 0;
}

void ScripterAudioProcessor::setElement(int seq, int ev, int word, int value)
{
    AudioParameterInt *param = paramArray[seq][ev][word];
    if (param) {
        *param = value;
        loadFromStorage();
    }
}
int  ScripterAudioProcessor::getElement(int seq, int ev, int word)
{
    AudioParameterInt *param = paramArray[seq][ev][word];
    if (param) {
        int value = *param;
        return value;
    }
    else {
        return 0;
    }
}

void ScripterAudioProcessor::setElementLocal(int seq, int ev, int word, int value)
{
    AudioParameterInt *param = paramArray[seq][ev][word];
    if (param) {
        *param = value;
    }
}

void ScripterAudioProcessor::clearElements()
{
    for (int seq = 0; seq < MAX_SEQUENCES; seq++) {
        for (int ev = 0; ev < MAX_EVENTS; ev++) {
            for (int i = 0; i < 3; i++) {
                setElementLocal(seq, ev, i, 0);
            }
        }
    }

}

void ScripterAudioProcessor::addSequence()
{
    unsigned sequenceSize = getSequenceSize();
    if (sequenceSize < MAX_SEQUENCES) {
        // there is room to add another sequence
        // To validate sequence set the CC_ID for it's TRIG_ID to non-zero.
        for (int ev = 0; ev < MAX_EVENTS; ev++) {
            for (int i = 0; i < 3; i++) {
                setElementLocal(sequenceSize, ev, i, 0); // clear the sequence
            }
        }
        setElementLocal(sequenceSize, TRIG_ID, CC_ID, 1); // validate the sequence
        loadFromStorage();
        setSelectedSequence(sequenceSize);
    }
}

void ScripterAudioProcessor::removeSequence() {
    //int selectedSequence = getSelectedSequence();
    unsigned sequenceSize = getSequenceSize();
    if (sequenceSize > 0) {
        unsigned selectedSequence = getSelectedSequence();
        m_midiSequenceList->erase(m_midiSequenceList->begin() + selectedSequence);
        if (selectedSequence > 0) {
            setSelectedSequence(selectedSequence - 1);
        } // select the previous sequence
        saveToStorage();
    }
}

void ScripterAudioProcessor::loadFromStorage() {
    m_midiSequenceList->clear();
    unsigned selectedSequence = getSelectedSequence();

    for (int seq = 0; seq < MAX_SEQUENCES; seq++) {

        //if (getElement(seq, 0, 1) != 0) {
            MidiSequence sequence;
            for (int ev = 0; ev < MAX_EVENTS; ev++) {
                MidiEvent event(
                    getElement(seq, ev, 0),
                    getElement(seq, ev, 1),
                    getElement(seq, ev, 2));
                sequence.push_back(event);
            }
            if (!sequence.empty()) { // a valid sequence
                m_midiSequenceList->push_back(sequence);
            }
            else { // no more valid sequences
                break;
            }
        //}
    }

    if (selectedSequence >= m_midiSequenceList->size()) {
        selectedSequence = 0;
    }
}

void ScripterAudioProcessor::saveToStorage() {
    clearElements();

    unsigned seqIdx = 0, evIdx = 0;
    for (auto seq = m_midiSequenceList->begin(); seq != m_midiSequenceList->end(); ++seq) {
        evIdx = 0;
        for (auto ev = (*seq).begin(); ev != (*seq).end(); ++ev) {
            setElementLocal(seqIdx, evIdx, CH_ID, (*ev).channel);
            setElementLocal(seqIdx, evIdx, CC_ID, (*ev).cc);
            setElementLocal(seqIdx, evIdx, VAL_ID, (*ev).value);
            evIdx++;
        }
        seqIdx++;
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ScripterAudioProcessor();
}
