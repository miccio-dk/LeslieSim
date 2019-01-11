/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginGUI  : public AudioProcessorEditor,
                   public Slider::Listener
{
public:
    //==============================================================================
    PluginGUI (LeslieSimAudioProcessor& p);
    ~PluginGUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    LeslieSimAudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> grp_general;
    std::unique_ptr<GroupComponent> grp_bass;
    std::unique_ptr<GroupComponent> grp_treble;
    std::unique_ptr<GroupComponent> grp_horn;
    std::unique_ptr<GroupComponent> grp_lpf;
    std::unique_ptr<Slider> sld_drive;
    std::unique_ptr<Label> lbl_drive;
    std::unique_ptr<Slider> sld_xver;
    std::unique_ptr<Label> lbl_xver;
    std::unique_ptr<Slider> sld_bass_speed;
    std::unique_ptr<Label> lbl_bass_speed;
    std::unique_ptr<Slider> sld_bass_am;
    std::unique_ptr<Label> lbl_bass_am;
    std::unique_ptr<Slider> sld_bass_mix;
    std::unique_ptr<Label> lbl_bass_mix;
    std::unique_ptr<Slider> sld_treble_speed;
    std::unique_ptr<Label> lbl_treble_speed;
    std::unique_ptr<Slider> sld_treble_am;
    std::unique_ptr<Label> lbl_treble_am;
    std::unique_ptr<Slider> sld_treble_mix;
    std::unique_ptr<Label> lbl_treble_mix;
    std::unique_ptr<Label> lbl_treble_lpf_freq;
    std::unique_ptr<Slider> sld_treble_lpf_depth;
    std::unique_ptr<Label> lbl_treble_lpf_depth;
    std::unique_ptr<Slider> sld_treble_mics;
    std::unique_ptr<Label> lbl_treble_mics;
    std::unique_ptr<Label> lbl_horn_radius;
    std::unique_ptr<Slider> sld_horn_freq;
    std::unique_ptr<Label> lbl_horn_freq;
    std::unique_ptr<Slider> sld_treble_lpf_freq;
    std::unique_ptr<Slider> sld_horn_radius;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
