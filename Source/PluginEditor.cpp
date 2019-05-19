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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ScripterProcessorEditor::ScripterProcessorEditor (AudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (triggerCh = new Label ("new label",
                                              TRANS("0\n")));
    triggerCh->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    triggerCh->setJustificationType (Justification::centred);
    triggerCh->setEditable (true, true, false);
    triggerCh->setColour (TextEditor::textColourId, Colours::black);
    triggerCh->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    triggerCh->addListener (this);

    addAndMakeVisible (triggerCC = new Label ("new label",
                                              TRANS("0\n")));
    triggerCC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    triggerCC->setJustificationType (Justification::centred);
    triggerCC->setEditable (true, true, false);
    triggerCC->setColour (TextEditor::textColourId, Colours::black);
    triggerCC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    triggerCC->addListener (this);

    addAndMakeVisible (triggerVal = new Label ("new label",
                                               TRANS("0\n")));
    triggerVal->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    triggerVal->setJustificationType (Justification::centred);
    triggerVal->setEditable (true, true, false);
    triggerVal->setColour (TextEditor::textColourId, Colours::black);
    triggerVal->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    triggerVal->addListener (this);

    addAndMakeVisible (sequenceSelectorBox = new ComboBox ("new combo box"));
    sequenceSelectorBox->setEditableText (false);
    sequenceSelectorBox->setJustificationType (Justification::centredLeft);
    sequenceSelectorBox->setTextWhenNothingSelected (String());
    sequenceSelectorBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    sequenceSelectorBox->addListener (this);

    addAndMakeVisible (outputEvent0Ch = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent0Ch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent0Ch->setJustificationType (Justification::centred);
    outputEvent0Ch->setEditable (true, true, false);
    outputEvent0Ch->setColour (TextEditor::textColourId, Colours::black);
    outputEvent0Ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent0Ch->addListener (this);

    addAndMakeVisible (outputEvent0CC = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent0CC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent0CC->setJustificationType (Justification::centred);
    outputEvent0CC->setEditable (true, true, false);
    outputEvent0CC->setColour (TextEditor::textColourId, Colours::black);
    outputEvent0CC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent0CC->addListener (this);

    addAndMakeVisible (outputEvent0Val = new Label ("new label",
                                                    TRANS("0\n")));
    outputEvent0Val->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent0Val->setJustificationType (Justification::centred);
    outputEvent0Val->setEditable (true, true, false);
    outputEvent0Val->setColour (TextEditor::textColourId, Colours::black);
    outputEvent0Val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent0Val->addListener (this);

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("#1")));
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputEvent1Ch = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent1Ch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent1Ch->setJustificationType (Justification::centred);
    outputEvent1Ch->setEditable (true, true, false);
    outputEvent1Ch->setColour (TextEditor::textColourId, Colours::black);
    outputEvent1Ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent1Ch->addListener (this);

    addAndMakeVisible (outputEvent1CC = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent1CC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent1CC->setJustificationType (Justification::centred);
    outputEvent1CC->setEditable (true, true, false);
    outputEvent1CC->setColour (TextEditor::textColourId, Colours::black);
    outputEvent1CC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent1CC->addListener (this);

    addAndMakeVisible (outputEvent1Val = new Label ("new label",
                                                    TRANS("0\n")));
    outputEvent1Val->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent1Val->setJustificationType (Justification::centred);
    outputEvent1Val->setEditable (true, true, false);
    outputEvent1Val->setColour (TextEditor::textColourId, Colours::black);
    outputEvent1Val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent1Val->addListener (this);

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("#2")));
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
    textEditor->setMultiLine (true);
    textEditor->setReturnKeyStartsNewLine (true);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (String());

    addAndMakeVisible (addSequence = new TextButton ("add sequence"));
    addSequence->setButtonText (TRANS("NEW"));
    addSequence->addListener (this);
    addSequence->setColour (TextButton::buttonColourId, Colours::aqua);
    addSequence->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (outputEvent2Ch = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent2Ch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent2Ch->setJustificationType (Justification::centred);
    outputEvent2Ch->setEditable (true, true, false);
    outputEvent2Ch->setColour (TextEditor::textColourId, Colours::black);
    outputEvent2Ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent2Ch->addListener (this);

    addAndMakeVisible (outputEvent2CC = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent2CC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent2CC->setJustificationType (Justification::centred);
    outputEvent2CC->setEditable (true, true, false);
    outputEvent2CC->setColour (TextEditor::textColourId, Colours::black);
    outputEvent2CC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent2CC->addListener (this);

    addAndMakeVisible (outputEvent2Val = new Label ("new label",
                                                    TRANS("0\n")));
    outputEvent2Val->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent2Val->setJustificationType (Justification::centred);
    outputEvent2Val->setEditable (true, true, false);
    outputEvent2Val->setColour (TextEditor::textColourId, Colours::black);
    outputEvent2Val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent2Val->addListener (this);

    addAndMakeVisible (label8 = new Label ("new label",
                                           TRANS("#3")));
    label8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputEvent3Ch = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent3Ch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent3Ch->setJustificationType (Justification::centred);
    outputEvent3Ch->setEditable (true, true, false);
    outputEvent3Ch->setColour (TextEditor::textColourId, Colours::black);
    outputEvent3Ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent3Ch->addListener (this);

    addAndMakeVisible (outputEvent3CC = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent3CC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent3CC->setJustificationType (Justification::centred);
    outputEvent3CC->setEditable (true, true, false);
    outputEvent3CC->setColour (TextEditor::textColourId, Colours::black);
    outputEvent3CC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent3CC->addListener (this);

    addAndMakeVisible (outputEvent3Val = new Label ("new label",
                                                    TRANS("0\n")));
    outputEvent3Val->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent3Val->setJustificationType (Justification::centred);
    outputEvent3Val->setEditable (true, true, false);
    outputEvent3Val->setColour (TextEditor::textColourId, Colours::black);
    outputEvent3Val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent3Val->addListener (this);

    addAndMakeVisible (label11 = new Label ("new label",
                                            TRANS("#4")));
    label11->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputEvent4Ch = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent4Ch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent4Ch->setJustificationType (Justification::centred);
    outputEvent4Ch->setEditable (true, true, false);
    outputEvent4Ch->setColour (TextEditor::textColourId, Colours::black);
    outputEvent4Ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent4Ch->addListener (this);

    addAndMakeVisible (outputEvent4CC = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent4CC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent4CC->setJustificationType (Justification::centred);
    outputEvent4CC->setEditable (true, true, false);
    outputEvent4CC->setColour (TextEditor::textColourId, Colours::black);
    outputEvent4CC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent4CC->addListener (this);

    addAndMakeVisible (outputEvent4Val = new Label ("new label",
                                                    TRANS("0\n")));
    outputEvent4Val->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent4Val->setJustificationType (Justification::centred);
    outputEvent4Val->setEditable (true, true, false);
    outputEvent4Val->setColour (TextEditor::textColourId, Colours::black);
    outputEvent4Val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent4Val->addListener (this);

    addAndMakeVisible (label12 = new Label ("new label",
                                            TRANS("#5")));
    label12->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputEvent5Ch = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent5Ch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent5Ch->setJustificationType (Justification::centred);
    outputEvent5Ch->setEditable (true, true, false);
    outputEvent5Ch->setColour (TextEditor::textColourId, Colours::black);
    outputEvent5Ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent5Ch->addListener (this);

    addAndMakeVisible (outputEvent5CC = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent5CC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent5CC->setJustificationType (Justification::centred);
    outputEvent5CC->setEditable (true, true, false);
    outputEvent5CC->setColour (TextEditor::textColourId, Colours::black);
    outputEvent5CC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent5CC->addListener (this);

    addAndMakeVisible (outputEvent5Val = new Label ("new label",
                                                    TRANS("0\n")));
    outputEvent5Val->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent5Val->setJustificationType (Justification::centred);
    outputEvent5Val->setEditable (true, true, false);
    outputEvent5Val->setColour (TextEditor::textColourId, Colours::black);
    outputEvent5Val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent5Val->addListener (this);

    addAndMakeVisible (label13 = new Label ("new label",
                                            TRANS("#6")));
    label13->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label13->setJustificationType (Justification::centredLeft);
    label13->setEditable (false, false, false);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputEvent6Ch = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent6Ch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent6Ch->setJustificationType (Justification::centred);
    outputEvent6Ch->setEditable (true, true, false);
    outputEvent6Ch->setColour (TextEditor::textColourId, Colours::black);
    outputEvent6Ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent6Ch->addListener (this);

    addAndMakeVisible (outputEvent6CC = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent6CC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent6CC->setJustificationType (Justification::centred);
    outputEvent6CC->setEditable (true, true, false);
    outputEvent6CC->setColour (TextEditor::textColourId, Colours::black);
    outputEvent6CC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent6CC->addListener (this);

    addAndMakeVisible (outputEvent6Val = new Label ("new label",
                                                    TRANS("0\n")));
    outputEvent6Val->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent6Val->setJustificationType (Justification::centred);
    outputEvent6Val->setEditable (true, true, false);
    outputEvent6Val->setColour (TextEditor::textColourId, Colours::black);
    outputEvent6Val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent6Val->addListener (this);

    addAndMakeVisible (label14 = new Label ("new label",
                                            TRANS("#7")));
    label14->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputEvent7Ch = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent7Ch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent7Ch->setJustificationType (Justification::centred);
    outputEvent7Ch->setEditable (true, true, false);
    outputEvent7Ch->setColour (TextEditor::textColourId, Colours::black);
    outputEvent7Ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent7Ch->addListener (this);

    addAndMakeVisible (outputEvent7CC = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent7CC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent7CC->setJustificationType (Justification::centred);
    outputEvent7CC->setEditable (true, true, false);
    outputEvent7CC->setColour (TextEditor::textColourId, Colours::black);
    outputEvent7CC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent7CC->addListener (this);

    addAndMakeVisible (outputEvent7Val = new Label ("new label",
                                                    TRANS("0\n")));
    outputEvent7Val->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent7Val->setJustificationType (Justification::centred);
    outputEvent7Val->setEditable (true, true, false);
    outputEvent7Val->setColour (TextEditor::textColourId, Colours::black);
    outputEvent7Val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent7Val->addListener (this);

    addAndMakeVisible (label15 = new Label ("new label",
                                            TRANS("#8")));
    label15->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label15->setJustificationType (Justification::centredLeft);
    label15->setEditable (false, false, false);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputEvent8Ch = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent8Ch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent8Ch->setJustificationType (Justification::centred);
    outputEvent8Ch->setEditable (true, true, false);
    outputEvent8Ch->setColour (TextEditor::textColourId, Colours::black);
    outputEvent8Ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent8Ch->addListener (this);

    addAndMakeVisible (outputEvent8CC = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent8CC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent8CC->setJustificationType (Justification::centred);
    outputEvent8CC->setEditable (true, true, false);
    outputEvent8CC->setColour (TextEditor::textColourId, Colours::black);
    outputEvent8CC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent8CC->addListener (this);

    addAndMakeVisible (outputEvent8Val = new Label ("new label",
                                                    TRANS("0\n")));
    outputEvent8Val->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent8Val->setJustificationType (Justification::centred);
    outputEvent8Val->setEditable (true, true, false);
    outputEvent8Val->setColour (TextEditor::textColourId, Colours::black);
    outputEvent8Val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent8Val->addListener (this);

    addAndMakeVisible (label16 = new Label ("new label",
                                            TRANS("#9")));
    label16->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label16->setJustificationType (Justification::centredLeft);
    label16->setEditable (false, false, false);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (outputEvent9Ch = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent9Ch->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent9Ch->setJustificationType (Justification::centred);
    outputEvent9Ch->setEditable (true, true, false);
    outputEvent9Ch->setColour (TextEditor::textColourId, Colours::black);
    outputEvent9Ch->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent9Ch->addListener (this);

    addAndMakeVisible (outputEvent9CC = new Label ("new label",
                                                   TRANS("0\n")));
    outputEvent9CC->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent9CC->setJustificationType (Justification::centred);
    outputEvent9CC->setEditable (true, true, false);
    outputEvent9CC->setColour (TextEditor::textColourId, Colours::black);
    outputEvent9CC->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent9CC->addListener (this);

    addAndMakeVisible (outputEvent9Val = new Label ("new label",
                                                    TRANS("0\n")));
    outputEvent9Val->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    outputEvent9Val->setJustificationType (Justification::centred);
    outputEvent9Val->setEditable (true, true, false);
    outputEvent9Val->setColour (TextEditor::textColourId, Colours::black);
    outputEvent9Val->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    outputEvent9Val->addListener (this);

    addAndMakeVisible (label17 = new Label ("new label",
                                            TRANS("#10")));
    label17->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label17->setJustificationType (Justification::centredLeft);
    label17->setEditable (false, false, false);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (deleteSequence = new TextButton ("delete sequence"));
    deleteSequence->setButtonText (TRANS("DELETE"));
    deleteSequence->addListener (this);
    deleteSequence->setColour (TextButton::buttonColourId, Colours::red);
    deleteSequence->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (printAllEventsButton = new ToggleButton ("printAllEventsEnable"));
    printAllEventsButton->setButtonText (TRANS("Print All CC Events"));
    printAllEventsButton->addListener (this);

    addAndMakeVisible (printTriggeredEventsButton = new ToggleButton ("printTriggeredEventsEnable"));
    printTriggeredEventsButton->setButtonText (TRANS("Print Triggered Events"));
    printTriggeredEventsButton->addListener (this);

    addAndMakeVisible (copySequence = new TextButton ("copy sequence"));
    copySequence->setButtonText (TRANS("COPY"));
    copySequence->addListener (this);
    copySequence->setColour (TextButton::buttonColourId, Colours::aqua);
    copySequence->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (clearText = new TextButton ("clear text"));
    clearText->setButtonText (TRANS("CLEAR"));
    clearText->addListener (this);
    clearText->setColour (TextButton::buttonColourId, Colours::white);
    clearText->setColour (TextButton::textColourOffId, Colours::black);

    addAndMakeVisible (versionLabel = new Label ("version",
                                                 TRANS("X.X.X")));
    versionLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    versionLabel->setJustificationType (Justification::centredLeft);
    versionLabel->setEditable (true, true, false);
    versionLabel->setColour (Label::textColourId, Colours::aqua);
    versionLabel->setColour (TextEditor::textColourId, Colours::black);
    versionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    versionLabel->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 420);


    //[Constructor] You can add your own custom stuff here..
    versionLabel->setText(VERSION_STRING, NotificationType::dontSendNotification);
    setWindowText(String(String("MidiScripter version ") + VERSION_STRING));
    m_ourProcessor = getProcessor(); // keep a handy pointer to the associated processor
    updateSelector();
    updateGui();

    if (m_ourProcessor) {
        m_ourProcessor->setValidEditor(true); // notify the prcoessor the editor is now valid
    }
    //[/Constructor]
}

ScripterProcessorEditor::~ScripterProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    triggerCh = nullptr;
    triggerCC = nullptr;
    triggerVal = nullptr;
    sequenceSelectorBox = nullptr;
    outputEvent0Ch = nullptr;
    outputEvent0CC = nullptr;
    outputEvent0Val = nullptr;
    label6 = nullptr;
    outputEvent1Ch = nullptr;
    outputEvent1CC = nullptr;
    outputEvent1Val = nullptr;
    label7 = nullptr;
    textEditor = nullptr;
    addSequence = nullptr;
    outputEvent2Ch = nullptr;
    outputEvent2CC = nullptr;
    outputEvent2Val = nullptr;
    label8 = nullptr;
    outputEvent3Ch = nullptr;
    outputEvent3CC = nullptr;
    outputEvent3Val = nullptr;
    label11 = nullptr;
    outputEvent4Ch = nullptr;
    outputEvent4CC = nullptr;
    outputEvent4Val = nullptr;
    label12 = nullptr;
    outputEvent5Ch = nullptr;
    outputEvent5CC = nullptr;
    outputEvent5Val = nullptr;
    label13 = nullptr;
    outputEvent6Ch = nullptr;
    outputEvent6CC = nullptr;
    outputEvent6Val = nullptr;
    label14 = nullptr;
    outputEvent7Ch = nullptr;
    outputEvent7CC = nullptr;
    outputEvent7Val = nullptr;
    label15 = nullptr;
    outputEvent8Ch = nullptr;
    outputEvent8CC = nullptr;
    outputEvent8Val = nullptr;
    label16 = nullptr;
    outputEvent9Ch = nullptr;
    outputEvent9CC = nullptr;
    outputEvent9Val = nullptr;
    label17 = nullptr;
    deleteSequence = nullptr;
    printAllEventsButton = nullptr;
    printTriggeredEventsButton = nullptr;
    copySequence = nullptr;
    clearText = nullptr;
    versionLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    if (m_ourProcessor) {
        m_ourProcessor->setValidEditor(false);
    }
    //[/Destructor]
}

//==============================================================================
void ScripterProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 28, y = 20, width = 180, height = 30;
        String text (TRANS("Blackaddr Audio MidiScripter"));
        Colour fillColour = Colours::aqua;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 244, y = 108, width = 28, height = 30;
        String text (TRANS("Ch."));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 244, y = 140, width = 28, height = 30;
        String text (TRANS("CC"));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 244, y = 172, width = 28, height = 30;
        String text (TRANS("Val"));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 92, y = 84, width = 28, height = 30;
        String text (TRANS("Ch."));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 132, y = 84, width = 28, height = 30;
        String text (TRANS("CC"));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 172, y = 84, width = 28, height = 30;
        String text (TRANS("Val"));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 268, y = 60, width = 100, height = 30;
        String text (TRANS("Output Events"));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 100, y = 60, width = 100, height = 30;
        String text (TRANS("Trigger Event"));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 36, y = 84, width = 44, height = 30;
        String text (TRANS("Seq."));
        Colour fillColour = Colours::azure;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ScripterProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    triggerCh->setBounds (92, 112, 32, 24);
    triggerCC->setBounds (135, 112, 32, 24);
    triggerVal->setBounds (177, 112, 32, 24);
    sequenceSelectorBox->setBounds (20, 112, 68, 48);
    outputEvent0Ch->setBounds (265, 111, 32, 24);
    outputEvent0CC->setBounds (265, 141, 32, 24);
    outputEvent0Val->setBounds (265, 175, 32, 24);
    label6->setBounds (265, 88, 32, 24);
    outputEvent1Ch->setBounds (299, 111, 32, 24);
    outputEvent1CC->setBounds (299, 143, 32, 24);
    outputEvent1Val->setBounds (299, 175, 32, 24);
    label7->setBounds (299, 87, 32, 24);
    textEditor->setBounds (18, 251, 424, 152);
    addSequence->setBounds (24, 184, 48, 24);
    outputEvent2Ch->setBounds (332, 111, 32, 24);
    outputEvent2CC->setBounds (332, 144, 32, 24);
    outputEvent2Val->setBounds (332, 175, 32, 24);
    label8->setBounds (332, 87, 32, 24);
    outputEvent3Ch->setBounds (365, 111, 32, 24);
    outputEvent3CC->setBounds (365, 144, 32, 24);
    outputEvent3Val->setBounds (365, 175, 32, 24);
    label11->setBounds (365, 86, 32, 24);
    outputEvent4Ch->setBounds (398, 110, 32, 24);
    outputEvent4CC->setBounds (398, 144, 32, 24);
    outputEvent4Val->setBounds (398, 175, 32, 24);
    label12->setBounds (398, 86, 32, 24);
    outputEvent5Ch->setBounds (428, 111, 32, 24);
    outputEvent5CC->setBounds (428, 144, 32, 24);
    outputEvent5Val->setBounds (428, 175, 32, 24);
    label13->setBounds (428, 85, 32, 24);
    outputEvent6Ch->setBounds (461, 111, 32, 24);
    outputEvent6CC->setBounds (461, 144, 32, 24);
    outputEvent6Val->setBounds (461, 175, 32, 24);
    label14->setBounds (461, 85, 32, 24);
    outputEvent7Ch->setBounds (496, 111, 32, 24);
    outputEvent7CC->setBounds (496, 144, 32, 24);
    outputEvent7Val->setBounds (496, 175, 32, 24);
    label15->setBounds (496, 84, 32, 24);
    outputEvent8Ch->setBounds (528, 111, 32, 24);
    outputEvent8CC->setBounds (528, 144, 32, 24);
    outputEvent8Val->setBounds (528, 175, 32, 24);
    label16->setBounds (528, 84, 32, 24);
    outputEvent9Ch->setBounds (559, 111, 32, 24);
    outputEvent9CC->setBounds (559, 143, 32, 24);
    outputEvent9Val->setBounds (559, 175, 32, 24);
    label17->setBounds (559, 84, 32, 24);
    deleteSequence->setBounds (165, 184, 53, 24);
    printAllEventsButton->setBounds (24, 216, 152, 24);
    printTriggeredEventsButton->setBounds (192, 216, 176, 24);
    copySequence->setBounds (95, 184, 48, 24);
    clearText->setBounds (388, 214, 48, 24);
    versionLabel->setBounds (211, 23, 56, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ScripterProcessorEditor::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    if (m_ourProcessor->getSequenceSize() == 0) { return; }
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == triggerCh)
    {
        //[UserLabelCode_triggerCh] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_triggerCh]
    }
    else if (labelThatHasChanged == triggerCC)
    {
        //[UserLabelCode_triggerCC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_triggerCC]
    }
    else if (labelThatHasChanged == triggerVal)
    {
        //[UserLabelCode_triggerVal] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_triggerVal]
    }
    else if (labelThatHasChanged == outputEvent0Ch)
    {
        //[UserLabelCode_outputEvent0Ch] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID+1, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent0Ch]
    }
    else if (labelThatHasChanged == outputEvent0CC)
    {
        //[UserLabelCode_outputEvent0CC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 1, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent0CC]
    }
    else if (labelThatHasChanged == outputEvent0Val)
    {
        //[UserLabelCode_outputEvent0Val] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 1, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent0Val]
    }
    else if (labelThatHasChanged == outputEvent1Ch)
    {
        //[UserLabelCode_outputEvent1Ch] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 2, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent1Ch]
    }
    else if (labelThatHasChanged == outputEvent1CC)
    {
        //[UserLabelCode_outputEvent1CC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 2, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent1CC]
    }
    else if (labelThatHasChanged == outputEvent1Val)
    {
        //[UserLabelCode_outputEvent1Val] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 2, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent1Val]
    }
    else if (labelThatHasChanged == outputEvent2Ch)
    {
        //[UserLabelCode_outputEvent2Ch] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 3, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent2Ch]
    }
    else if (labelThatHasChanged == outputEvent2CC)
    {
        //[UserLabelCode_outputEvent2CC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 3, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent2CC]
    }
    else if (labelThatHasChanged == outputEvent2Val)
    {
        //[UserLabelCode_outputEvent2Val] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 3, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent2Val]
    }
    else if (labelThatHasChanged == outputEvent3Ch)
    {
        //[UserLabelCode_outputEvent3Ch] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 4, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent3Ch]
    }
    else if (labelThatHasChanged == outputEvent3CC)
    {
        //[UserLabelCode_outputEvent3CC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 4, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent3CC]
    }
    else if (labelThatHasChanged == outputEvent3Val)
    {
        //[UserLabelCode_outputEvent3Val] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 4, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent3Val]
    }
    else if (labelThatHasChanged == outputEvent4Ch)
    {
        //[UserLabelCode_outputEvent4Ch] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 5, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent4Ch]
    }
    else if (labelThatHasChanged == outputEvent4CC)
    {
        //[UserLabelCode_outputEvent4CC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 5, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent4CC]
    }
    else if (labelThatHasChanged == outputEvent4Val)
    {
        //[UserLabelCode_outputEvent4Val] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 5, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent4Val]
    }
    else if (labelThatHasChanged == outputEvent5Ch)
    {
        //[UserLabelCode_outputEvent5Ch] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 6, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent5Ch]
    }
    else if (labelThatHasChanged == outputEvent5CC)
    {
        //[UserLabelCode_outputEvent5CC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 6, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent5CC]
    }
    else if (labelThatHasChanged == outputEvent5Val)
    {
        //[UserLabelCode_outputEvent5Val] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 6, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent5Val]
    }
    else if (labelThatHasChanged == outputEvent6Ch)
    {
        //[UserLabelCode_outputEvent6Ch] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 7, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent6Ch]
    }
    else if (labelThatHasChanged == outputEvent6CC)
    {
        //[UserLabelCode_outputEvent6CC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 7, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent6CC]
    }
    else if (labelThatHasChanged == outputEvent6Val)
    {
        //[UserLabelCode_outputEvent6Val] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 7, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent6Val]
    }
    else if (labelThatHasChanged == outputEvent7Ch)
    {
        //[UserLabelCode_outputEvent7Ch] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 8, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent7Ch]
    }
    else if (labelThatHasChanged == outputEvent7CC)
    {
        //[UserLabelCode_outputEvent7CC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 8, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent7CC]
    }
    else if (labelThatHasChanged == outputEvent7Val)
    {
        //[UserLabelCode_outputEvent7Val] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 8, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent7Val]
    }
    else if (labelThatHasChanged == outputEvent8Ch)
    {
        //[UserLabelCode_outputEvent8Ch] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 9, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent8Ch]
    }
    else if (labelThatHasChanged == outputEvent8CC)
    {
        //[UserLabelCode_outputEvent8CC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 9, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent8CC]
    }
    else if (labelThatHasChanged == outputEvent8Val)
    {
        //[UserLabelCode_outputEvent8Val] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 9, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent8Val]
    }
    else if (labelThatHasChanged == outputEvent9Ch)
    {
        //[UserLabelCode_outputEvent9Ch] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 10, CH_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent9Ch]
    }
    else if (labelThatHasChanged == outputEvent9CC)
    {
        //[UserLabelCode_outputEvent9CC] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 10, CC_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent9CC]
    }
    else if (labelThatHasChanged == outputEvent9Val)
    {
        //[UserLabelCode_outputEvent9Val] -- add your label text handling code here..
        m_ourProcessor->setElement(m_ourProcessor->getSelectedSequence(), TRIG_ID + 10, VAL_ID, labelThatHasChanged->getText().getIntValue());
        //[/UserLabelCode_outputEvent9Val]
    }
    else if (labelThatHasChanged == versionLabel)
    {
        //[UserLabelCode_versionLabel] -- add your label text handling code here..
        //[/UserLabelCode_versionLabel]
    }

    //[UserlabelTextChanged_Post]
    updateGui();
    //[/UserlabelTextChanged_Post]
}

void ScripterProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    if (m_ourProcessor->getSequenceSize() == 0) { return; }
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == sequenceSelectorBox)
    {
        //[UserComboBoxCode_sequenceSelectorBox] -- add your combo box handling code here..
        int selectedSequence = comboBoxThatHasChanged->getSelectedItemIndex();
        m_ourProcessor->setSelectedSequence(selectedSequence);
        updateGui();
        //[/UserComboBoxCode_sequenceSelectorBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void ScripterProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == addSequence)
    {
        //[UserButtonCode_addSequence] -- add your button handler code here..
        m_ourProcessor->addSequence();
        int sequenceSize = m_ourProcessor->getSequenceSize();
        sequenceSelectorBox->addItem(String(sequenceSize), sequenceSize);
        sequenceSelectorBox->setSelectedItemIndex(m_ourProcessor->getSelectedSequence());
        updateGui();
        //[/UserButtonCode_addSequence]
    }
    else if (buttonThatWasClicked == deleteSequence)
    {
        //[UserButtonCode_deleteSequence] -- add your button handler code here..
        m_ourProcessor->removeSequence();
        int selectedSequence = m_ourProcessor->getSelectedSequence();
        sequenceSelectorBox->clear();
        for (unsigned seq = 0; seq < m_ourProcessor->getSequenceSize(); seq++) {
            sequenceSelectorBox->addItem(String(seq + 1), seq + 1);
        }
        sequenceSelectorBox->setSelectedItemIndex(selectedSequence);
        updateGui();
        //[/UserButtonCode_deleteSequence]
    }
    else if (buttonThatWasClicked == printAllEventsButton)
    {
        //[UserButtonCode_printAllEventsButton] -- add your button handler code here..
        m_ourProcessor->setPrintAllCCEvents(buttonThatWasClicked->getToggleState());
        //[/UserButtonCode_printAllEventsButton]
    }
    else if (buttonThatWasClicked == printTriggeredEventsButton)
    {
        //[UserButtonCode_printTriggeredEventsButton] -- add your button handler code here..
        m_ourProcessor->setPrintTriggeredEvents(buttonThatWasClicked->getToggleState());
        //[/UserButtonCode_printTriggeredEventsButton]
    }
    else if (buttonThatWasClicked == copySequence)
    {
        //[UserButtonCode_copySequence] -- add your button handler code here..
        m_ourProcessor->copySelectedSequence();
        int sequenceSize = m_ourProcessor->getSequenceSize();
        sequenceSelectorBox->addItem(String(sequenceSize), sequenceSize);
        sequenceSelectorBox->setSelectedItemIndex(m_ourProcessor->getSelectedSequence());
        updateGui();
        //[/UserButtonCode_copySequence]
    }
    else if (buttonThatWasClicked == clearText)
    {
        //[UserButtonCode_clearText] -- add your button handler code here..
        textEditor->setText("", true);
        //[/UserButtonCode_clearText]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void ScripterProcessorEditor::updateSelector()
{
    if (!m_ourProcessor) { return; }
    if (!sequenceSelectorBox) {
        return;
    }

    int selectedSequence = m_ourProcessor->getSelectedSequence();
    sequenceSelectorBox->clear();
    for (unsigned seq = 0; seq < m_ourProcessor->getSequenceSize(); seq++) {
        sequenceSelectorBox->addItem(String(seq + 1), seq + 1);
    }
    sequenceSelectorBox->setSelectedItemIndex(selectedSequence);
}

void ScripterProcessorEditor::updateGui()
{
    if (!m_ourProcessor) { return; }

    if (m_ourProcessor->getSequenceSize() == 0) {
        triggerCh->setText(String("0"), NotificationType::sendNotification);
        triggerCC->setText(String("0"), NotificationType::sendNotification);
        triggerVal->setText(String("0"), NotificationType::sendNotification);

        outputEvent0Ch->setText(String("0"), NotificationType::sendNotification);
        outputEvent0CC->setText(String("0"), NotificationType::sendNotification);
        outputEvent0Val->setText(String("0"), NotificationType::sendNotification);

        outputEvent1Ch->setText(String("0"), NotificationType::sendNotification);
        outputEvent1CC->setText(String("0"), NotificationType::sendNotification);
        outputEvent1Val->setText(String("0"), NotificationType::sendNotification);

        outputEvent2Ch->setText(String("0"), NotificationType::sendNotification);
        outputEvent2CC->setText(String("0"), NotificationType::sendNotification);
        outputEvent2Val->setText(String("0"), NotificationType::sendNotification);

        outputEvent3Ch->setText(String("0"), NotificationType::sendNotification);
        outputEvent3CC->setText(String("0"), NotificationType::sendNotification);
        outputEvent3Val->setText(String("0"), NotificationType::sendNotification);

        outputEvent4Ch->setText(String("0"), NotificationType::sendNotification);
        outputEvent4CC->setText(String("0"), NotificationType::sendNotification);
        outputEvent4Val->setText(String("0"), NotificationType::sendNotification);

        outputEvent5Ch->setText(String("0"), NotificationType::sendNotification);
        outputEvent5CC->setText(String("0"), NotificationType::sendNotification);
        outputEvent5Val->setText(String("0"), NotificationType::sendNotification);

        outputEvent6Ch->setText(String("0"), NotificationType::sendNotification);
        outputEvent6CC->setText(String("0"), NotificationType::sendNotification);
        outputEvent6Val->setText(String("0"), NotificationType::sendNotification);

        outputEvent7Ch->setText(String("0"), NotificationType::sendNotification);
        outputEvent7CC->setText(String("0"), NotificationType::sendNotification);
        outputEvent7Val->setText(String("0"), NotificationType::sendNotification);

        outputEvent8Ch->setText(String("0"), NotificationType::sendNotification);
        outputEvent8CC->setText(String("0"), NotificationType::sendNotification);
        outputEvent8Val->setText(String("0"), NotificationType::sendNotification);

        outputEvent9Ch->setText(String("0"), NotificationType::sendNotification);
        outputEvent9CC->setText(String("0"), NotificationType::sendNotification);
        outputEvent9Val->setText(String("0"), NotificationType::sendNotification);
        return;
    }

    unsigned idx = TRIG_ID;
    int selectedSequence = m_ourProcessor->getSelectedSequence();
    MidiEvent event;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    triggerCh->setText(String(event.channel), NotificationType::sendNotification);
    triggerCC->setText(String(event.cc), NotificationType::sendNotification);
    triggerVal->setText(String(event.value), NotificationType::sendNotification);
    idx++;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    outputEvent0Ch->setText(String(event.channel), NotificationType::sendNotification);
    outputEvent0CC->setText(String(event.cc), NotificationType::sendNotification);
    outputEvent0Val->setText(String(event.value), NotificationType::sendNotification);
    idx++;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    outputEvent1Ch->setText(String(event.channel), NotificationType::sendNotification);
    outputEvent1CC->setText(String(event.cc), NotificationType::sendNotification);
    outputEvent1Val->setText(String(event.value), NotificationType::sendNotification);
    idx++;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    outputEvent2Ch->setText(String(event.channel), NotificationType::sendNotification);
    outputEvent2CC->setText(String(event.cc), NotificationType::sendNotification);
    outputEvent2Val->setText(String(event.value), NotificationType::sendNotification);
    idx++;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    outputEvent3Ch->setText(String(event.channel), NotificationType::sendNotification);
    outputEvent3CC->setText(String(event.cc), NotificationType::sendNotification);
    outputEvent3Val->setText(String(event.value), NotificationType::sendNotification);
    idx++;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    outputEvent4Ch->setText(String(event.channel), NotificationType::sendNotification);
    outputEvent4CC->setText(String(event.cc), NotificationType::sendNotification);
    outputEvent4Val->setText(String(event.value), NotificationType::sendNotification);
    idx++;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    outputEvent5Ch->setText(String(event.channel), NotificationType::sendNotification);
    outputEvent5CC->setText(String(event.cc), NotificationType::sendNotification);
    outputEvent5Val->setText(String(event.value), NotificationType::sendNotification);
    idx++;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    outputEvent6Ch->setText(String(event.channel), NotificationType::sendNotification);
    outputEvent6CC->setText(String(event.cc), NotificationType::sendNotification);
    outputEvent6Val->setText(String(event.value), NotificationType::sendNotification);
    idx++;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    outputEvent7Ch->setText(String(event.channel), NotificationType::sendNotification);
    outputEvent7CC->setText(String(event.cc), NotificationType::sendNotification);
    outputEvent7Val->setText(String(event.value), NotificationType::sendNotification);
    idx++;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    outputEvent8Ch->setText(String(event.channel), NotificationType::sendNotification);
    outputEvent8CC->setText(String(event.cc), NotificationType::sendNotification);
    outputEvent8Val->setText(String(event.value), NotificationType::sendNotification);
    idx++;

    event = m_ourProcessor->getEvent(selectedSequence, idx);
    outputEvent9Ch->setText(String(event.channel), NotificationType::sendNotification);
    outputEvent9CC->setText(String(event.cc), NotificationType::sendNotification);
    outputEvent9Val->setText(String(event.value), NotificationType::sendNotification);
    idx++;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ScripterProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="AudioProcessor&amp; ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="28 20 180 30" fill="solid: ff00ffff" hasStroke="0" text="Blackaddr Audio MidiScripter"
          fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
          justification="33"/>
    <TEXT pos="244 108 28 30" fill="solid: fff0ffff" hasStroke="0" text="Ch."
          fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="244 140 28 30" fill="solid: fff0ffff" hasStroke="0" text="CC"
          fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="244 172 28 30" fill="solid: fff0ffff" hasStroke="0" text="Val"
          fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="92 84 28 30" fill="solid: fff0ffff" hasStroke="0" text="Ch."
          fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="132 84 28 30" fill="solid: fff0ffff" hasStroke="0" text="CC"
          fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="172 84 28 30" fill="solid: fff0ffff" hasStroke="0" text="Val"
          fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="268 60 100 30" fill="solid: fff0ffff" hasStroke="0" text="Output Events"
          fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="100 60 100 30" fill="solid: fff0ffff" hasStroke="0" text="Trigger Event"
          fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="36 84 44 30" fill="solid: fff0ffff" hasStroke="0" text="Seq."
          fontname="Default font" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
  </BACKGROUND>
  <LABEL name="new label" id="f7bc40719b84f5a2" memberName="triggerCh"
         virtualName="" explicitFocusOrder="0" pos="92 112 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="f0c29bf453c26c8c" memberName="triggerCC"
         virtualName="" explicitFocusOrder="0" pos="135 112 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="46c0140facb00a74" memberName="triggerVal"
         virtualName="" explicitFocusOrder="0" pos="177 112 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="new combo box" id="bcb98b7a732915d5" memberName="sequenceSelectorBox"
            virtualName="" explicitFocusOrder="0" pos="20 112 68 48" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="f4ee2dff826fa9dd" memberName="outputEvent0Ch"
         virtualName="" explicitFocusOrder="0" pos="265 111 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="afe8e73c60f41ed2" memberName="outputEvent0CC"
         virtualName="" explicitFocusOrder="0" pos="265 141 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="1887c7aa0d310c43" memberName="outputEvent0Val"
         virtualName="" explicitFocusOrder="0" pos="265 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="86bee063dc7ba045" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="265 88 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="#1" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a8b303d6c437ce46" memberName="outputEvent1Ch"
         virtualName="" explicitFocusOrder="0" pos="299 111 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="b2125a1a71fc8bb9" memberName="outputEvent1CC"
         virtualName="" explicitFocusOrder="0" pos="299 143 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="a06f1059dbda195" memberName="outputEvent1Val"
         virtualName="" explicitFocusOrder="0" pos="299 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="6f2bc4f006cb756e" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="299 87 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="#2" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="a017ed130a1419c" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="18 251 424 152" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="add sequence" id="598515700d23c2c6" memberName="addSequence"
              virtualName="" explicitFocusOrder="0" pos="24 184 48 24" bgColOff="ff00ffff"
              textCol="ff000000" buttonText="NEW" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="467482ac978518d4" memberName="outputEvent2Ch"
         virtualName="" explicitFocusOrder="0" pos="332 111 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="524136be7f027a08" memberName="outputEvent2CC"
         virtualName="" explicitFocusOrder="0" pos="332 144 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="2f44ce69f8a32d58" memberName="outputEvent2Val"
         virtualName="" explicitFocusOrder="0" pos="332 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="955143ae4bec40cb" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="332 87 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="#3" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="fe8822c60859586" memberName="outputEvent3Ch"
         virtualName="" explicitFocusOrder="0" pos="365 111 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="412596abd90fd34f" memberName="outputEvent3CC"
         virtualName="" explicitFocusOrder="0" pos="365 144 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="efa358cdc8436c15" memberName="outputEvent3Val"
         virtualName="" explicitFocusOrder="0" pos="365 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="18c121a1d18e14e0" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="365 86 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="#4" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="43c74ef3adce0783" memberName="outputEvent4Ch"
         virtualName="" explicitFocusOrder="0" pos="398 110 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="524f6684e77b4aa" memberName="outputEvent4CC"
         virtualName="" explicitFocusOrder="0" pos="398 144 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8f2ca80762002e85" memberName="outputEvent4Val"
         virtualName="" explicitFocusOrder="0" pos="398 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="2d670420cab23730" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="398 86 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="#5" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="38d82a6073a13959" memberName="outputEvent5Ch"
         virtualName="" explicitFocusOrder="0" pos="428 111 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="fa92600782075f3c" memberName="outputEvent5CC"
         virtualName="" explicitFocusOrder="0" pos="428 144 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="fd658a09e66ab620" memberName="outputEvent5Val"
         virtualName="" explicitFocusOrder="0" pos="428 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="7c194088d234ea99" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="428 85 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="#6" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="4286fe20b999c4ad" memberName="outputEvent6Ch"
         virtualName="" explicitFocusOrder="0" pos="461 111 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="fa1044dea4948614" memberName="outputEvent6CC"
         virtualName="" explicitFocusOrder="0" pos="461 144 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="768c43736467b8ee" memberName="outputEvent6Val"
         virtualName="" explicitFocusOrder="0" pos="461 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="d24e4453e8005fe2" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="461 85 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="#7" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="19f329256a8c84d7" memberName="outputEvent7Ch"
         virtualName="" explicitFocusOrder="0" pos="496 111 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="a0008e9fcc843569" memberName="outputEvent7CC"
         virtualName="" explicitFocusOrder="0" pos="496 144 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="eaf688f401989272" memberName="outputEvent7Val"
         virtualName="" explicitFocusOrder="0" pos="496 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="b9815b186206e09f" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="496 84 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="#8" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="71ef1f3a2a1b5d7f" memberName="outputEvent8Ch"
         virtualName="" explicitFocusOrder="0" pos="528 111 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="b1d48e425d4c8b89" memberName="outputEvent8CC"
         virtualName="" explicitFocusOrder="0" pos="528 144 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="59cbc6fa93356027" memberName="outputEvent8Val"
         virtualName="" explicitFocusOrder="0" pos="528 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="41633ab8522195cd" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="528 84 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="#9" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="ca6bec013f6ef80d" memberName="outputEvent9Ch"
         virtualName="" explicitFocusOrder="0" pos="559 111 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="4d5fc7f723f5d77b" memberName="outputEvent9CC"
         virtualName="" explicitFocusOrder="0" pos="559 143 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="e66def2fa70110ea" memberName="outputEvent9Val"
         virtualName="" explicitFocusOrder="0" pos="559 175 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="0&#10;" editableSingleClick="1" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="dab91f4a3270b6bc" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="559 84 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="#10" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="delete sequence" id="d143991517e3ec9b" memberName="deleteSequence"
              virtualName="" explicitFocusOrder="0" pos="165 184 53 24" bgColOff="ffff0000"
              textCol="ff000000" buttonText="DELETE" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="printAllEventsEnable" id="254b18c237e10c7e" memberName="printAllEventsButton"
                virtualName="" explicitFocusOrder="0" pos="24 216 152 24" buttonText="Print All CC Events"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="printTriggeredEventsEnable" id="58342d6ae6624931" memberName="printTriggeredEventsButton"
                virtualName="" explicitFocusOrder="0" pos="192 216 176 24" buttonText="Print Triggered Events"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="copy sequence" id="841295fd7c7ab195" memberName="copySequence"
              virtualName="" explicitFocusOrder="0" pos="95 184 48 24" bgColOff="ff00ffff"
              textCol="ff000000" buttonText="COPY" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="clear text" id="4996d12d5698415a" memberName="clearText"
              virtualName="" explicitFocusOrder="0" pos="388 214 48 24" bgColOff="ffffffff"
              textCol="ff000000" buttonText="CLEAR" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="version" id="ad6b8f428a552b7e" memberName="versionLabel"
         virtualName="" explicitFocusOrder="0" pos="211 23 56 24" textCol="ff00ffff"
         edTextCol="ff000000" edBkgCol="0" labelText="X.X.X" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
