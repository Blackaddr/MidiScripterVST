# MidiScripterVST
A VST Plugin for using an incoming MIDI CC event to trigger a sequence of output CC events. 

## Why did I write this?
As you read this, you may start thinking, "Why don't you just use presets?" Well, I have presets for about 40 songs in my live set. Each song has up to 3 or 4 different "configuations" for the intro, verse, bridge, etc. I don't want to manage presets! I want one preset per song, then use stomp switches to "trigger" the configuration for different parts of the song, and do it with a single stomp (no tap dancing, please!)

## Okay, let's make a plugin!
I needed a basic pluggin to make it a little easier to reconfigure a large number of VSTs running in my VST host when playing live. Sure, it's easy to configure multiple effects to turn on or off with only one press of a stomp switch on my MIDI Foot Controller.  But what happens if I want to also set some "knob" type parameters to different values that aren't on/off? I needed to write a SEQUENCE of MIDI CC messages that get TRIGGERED by a single incoming MIDI CC event.

![Default screen](https://github.com/blackaddr/MidiScripterVST/blob/master/MidiScripter.png)

The plugin works by letting define up to 10 unique SEQUENCES, each with up to 10 output MIDI events per sequence. Here's an example sequence to illustrate:

1) TRIGGER: Hit a stomp switch on my MIDI Foot Controller which sends CC#20 with value 127.

2) SEQUENCE: Create a sequence in MidiScripterVST that looks for CC#20, value 127. When it sees this EVENT, execute the following settings for a lead solo for example:

Sequence #1:
i) send CC#30, 127 (turn on distortion, a.k.a no bypass)
ii) send CC#31, 0 (turn off reverb)
iii) send CC#40, 35 (set Amp treble to 35)
iV) send CC#41, 115 (set distortion pedal gain to 115)
v) send CC$32, 127 (turn on compressor)

The idea is to use a sequnce for each part of a song. The sequence contains all the MIDI CC messages needed to configure the rest of the VST effects. The VST Host manages each song as a preset, so I have a nice hierarchy of control.

NOTE: This plugin is written with JUCE. JUCE is great for making audio plugins with GUIs when you're not a UI developer. However, I find it's APIs change a lot over time. Any JUCE project I make seems to require modifications to get it compiling again everytime there is a major JUCE update. This plugin is provided as "reference". I don't intend to maintain or update it beyond my own personal needs.
