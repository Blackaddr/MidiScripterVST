/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <array>
#include "../JuceLibraryCode/JuceHeader.h"
#include "Misc.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ScripterProcessorEditor  : public AudioProcessorEditor,
                                 public Label::Listener,
                                 public ComboBox::Listener,
                                 public Button::Listener
{
public:
    //==============================================================================
    ScripterProcessorEditor (AudioProcessor& ownerFilter);
    ~ScripterProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    ScripterAudioProcessor* getProcessor() const
    {
        return static_cast <ScripterAudioProcessor*>(getAudioProcessor());
    }

    void setWindowText(String text) {
        if (textEditor) {
            textEditor->insertTextAtCaret(text);
        }
    }
    void updateSelector();
    void updateGui();
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void labelTextChanged (Label* labelThatHasChanged) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ScripterAudioProcessor *m_ourProcessor = nullptr;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> triggerCh;
    ScopedPointer<Label> triggerCC;
    ScopedPointer<Label> triggerVal;
    ScopedPointer<ComboBox> sequenceSelectorBox;
    ScopedPointer<Label> outputEvent0Ch;
    ScopedPointer<Label> outputEvent0CC;
    ScopedPointer<Label> outputEvent0Val;
    ScopedPointer<Label> label6;
    ScopedPointer<Label> outputEvent1Ch;
    ScopedPointer<Label> outputEvent1CC;
    ScopedPointer<Label> outputEvent1Val;
    ScopedPointer<Label> label7;
    ScopedPointer<TextEditor> textEditor;
    ScopedPointer<TextButton> addSequence;
    ScopedPointer<Label> outputEvent2Ch;
    ScopedPointer<Label> outputEvent2CC;
    ScopedPointer<Label> outputEvent2Val;
    ScopedPointer<Label> label8;
    ScopedPointer<Label> outputEvent3Ch;
    ScopedPointer<Label> outputEvent3CC;
    ScopedPointer<Label> outputEvent3Val;
    ScopedPointer<Label> label11;
    ScopedPointer<Label> outputEvent4Ch;
    ScopedPointer<Label> outputEvent4CC;
    ScopedPointer<Label> outputEvent4Val;
    ScopedPointer<Label> label12;
    ScopedPointer<Label> outputEvent5Ch;
    ScopedPointer<Label> outputEvent5CC;
    ScopedPointer<Label> outputEvent5Val;
    ScopedPointer<Label> label13;
    ScopedPointer<Label> outputEvent6Ch;
    ScopedPointer<Label> outputEvent6CC;
    ScopedPointer<Label> outputEvent6Val;
    ScopedPointer<Label> label14;
    ScopedPointer<Label> outputEvent7Ch;
    ScopedPointer<Label> outputEvent7CC;
    ScopedPointer<Label> outputEvent7Val;
    ScopedPointer<Label> label15;
    ScopedPointer<Label> outputEvent8Ch;
    ScopedPointer<Label> outputEvent8CC;
    ScopedPointer<Label> outputEvent8Val;
    ScopedPointer<Label> label16;
    ScopedPointer<Label> outputEvent9Ch;
    ScopedPointer<Label> outputEvent9CC;
    ScopedPointer<Label> outputEvent9Val;
    ScopedPointer<Label> label17;
    ScopedPointer<TextButton> deleteSequence;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScripterProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
