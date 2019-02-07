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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginGUI::PluginGUI (LeslieSimAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    grp_general.reset (new GroupComponent ("general group",
                                           TRANS("General")));
    addAndMakeVisible (grp_general.get());
    grp_general->setTextLabelPosition (Justification::centredLeft);

    grp_bass.reset (new GroupComponent ("bass group",
                                        TRANS("Bass")));
    addAndMakeVisible (grp_bass.get());
    grp_bass->setTextLabelPosition (Justification::centredLeft);

    grp_treble.reset (new GroupComponent ("treble channel",
                                          TRANS("Treble")));
    addAndMakeVisible (grp_treble.get());
    grp_treble->setTextLabelPosition (Justification::centredLeft);

    grp_horn.reset (new GroupComponent ("horn group",
                                        TRANS("Horn")));
    addAndMakeVisible (grp_horn.get());
    grp_horn->setTextLabelPosition (Justification::centredLeft);

    grp_lpf.reset (new GroupComponent ("lpf group",
                                       TRANS("LP filter")));
    addAndMakeVisible (grp_lpf.get());
    grp_lpf->setTextLabelPosition (Justification::centredLeft);

    sld_drive.reset (new Slider ("amp drive"));
    addAndMakeVisible (sld_drive.get());
    sld_drive->setRange (0, 100, 0);
    sld_drive->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_drive->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_drive->addListener (this);

    lbl_drive.reset (new Label ("amp drive lbl",
                                TRANS("Amp drive")));
    addAndMakeVisible (lbl_drive.get());
    lbl_drive->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_drive->setJustificationType (Justification::centred);
    lbl_drive->setEditable (false, false, false);
    lbl_drive->setColour (TextEditor::textColourId, Colours::black);
    lbl_drive->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_xver.reset (new Slider ("xver freq"));
    addAndMakeVisible (sld_xver.get());
    sld_xver->setRange (200, 8000, 0);
    sld_xver->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_xver->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_xver->addListener (this);

    lbl_xver.reset (new Label ("xver freq lbl",
                               TRANS("Crossover freq")));
    addAndMakeVisible (lbl_xver.get());
    lbl_xver->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_xver->setJustificationType (Justification::centred);
    lbl_xver->setEditable (false, false, false);
    lbl_xver->setColour (TextEditor::textColourId, Colours::black);
    lbl_xver->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_bass_speed.reset (new Slider ("bass speed"));
    addAndMakeVisible (sld_bass_speed.get());
    sld_bass_speed->setRange (5, 300, 0);
    sld_bass_speed->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_bass_speed->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_bass_speed->addListener (this);

    lbl_bass_speed.reset (new Label ("bass speed lbl",
                                     TRANS("Speed")));
    addAndMakeVisible (lbl_bass_speed.get());
    lbl_bass_speed->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_bass_speed->setJustificationType (Justification::centred);
    lbl_bass_speed->setEditable (false, false, false);
    lbl_bass_speed->setColour (TextEditor::textColourId, Colours::black);
    lbl_bass_speed->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_bass_am.reset (new Slider ("bass am"));
    addAndMakeVisible (sld_bass_am.get());
    sld_bass_am->setRange (0, 10, 0);
    sld_bass_am->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_bass_am->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_bass_am->addListener (this);

    lbl_bass_am.reset (new Label ("bass am lbl",
                                  TRANS("AM depth")));
    addAndMakeVisible (lbl_bass_am.get());
    lbl_bass_am->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_bass_am->setJustificationType (Justification::centred);
    lbl_bass_am->setEditable (false, false, false);
    lbl_bass_am->setColour (TextEditor::textColourId, Colours::black);
    lbl_bass_am->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_bass_mix.reset (new Slider ("bass mix"));
    addAndMakeVisible (sld_bass_mix.get());
    sld_bass_mix->setRange (0, 100, 0);
    sld_bass_mix->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_bass_mix->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_bass_mix->addListener (this);

    lbl_bass_mix.reset (new Label ("bass mix lbl",
                                   TRANS("Mix")));
    addAndMakeVisible (lbl_bass_mix.get());
    lbl_bass_mix->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_bass_mix->setJustificationType (Justification::centred);
    lbl_bass_mix->setEditable (false, false, false);
    lbl_bass_mix->setColour (TextEditor::textColourId, Colours::black);
    lbl_bass_mix->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_treble_speed.reset (new Slider ("treble speed"));
    addAndMakeVisible (sld_treble_speed.get());
    sld_treble_speed->setRange (5, 500, 0);
    sld_treble_speed->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_treble_speed->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_treble_speed->addListener (this);

    lbl_treble_speed.reset (new Label ("treble speed lbl",
                                       TRANS("Speed")));
    addAndMakeVisible (lbl_treble_speed.get());
    lbl_treble_speed->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_treble_speed->setJustificationType (Justification::centred);
    lbl_treble_speed->setEditable (false, false, false);
    lbl_treble_speed->setColour (TextEditor::textColourId, Colours::black);
    lbl_treble_speed->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_treble_am.reset (new Slider ("treble am"));
    addAndMakeVisible (sld_treble_am.get());
    sld_treble_am->setRange (0, 10, 0);
    sld_treble_am->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_treble_am->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_treble_am->addListener (this);

    lbl_treble_am.reset (new Label ("treble am lbl",
                                    TRANS("AM depth")));
    addAndMakeVisible (lbl_treble_am.get());
    lbl_treble_am->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_treble_am->setJustificationType (Justification::centred);
    lbl_treble_am->setEditable (false, false, false);
    lbl_treble_am->setColour (TextEditor::textColourId, Colours::black);
    lbl_treble_am->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_treble_mix.reset (new Slider ("treble mix"));
    addAndMakeVisible (sld_treble_mix.get());
    sld_treble_mix->setRange (0, 100, 0);
    sld_treble_mix->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_treble_mix->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_treble_mix->addListener (this);

    lbl_treble_mix.reset (new Label ("treble mix lbl",
                                     TRANS("Mix")));
    addAndMakeVisible (lbl_treble_mix.get());
    lbl_treble_mix->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_treble_mix->setJustificationType (Justification::centred);
    lbl_treble_mix->setEditable (false, false, false);
    lbl_treble_mix->setColour (TextEditor::textColourId, Colours::black);
    lbl_treble_mix->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    lbl_treble_lpf_freq.reset (new Label ("treble lpf freq lbl",
                                          TRANS("LPF freq")));
    addAndMakeVisible (lbl_treble_lpf_freq.get());
    lbl_treble_lpf_freq->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_treble_lpf_freq->setJustificationType (Justification::centred);
    lbl_treble_lpf_freq->setEditable (false, false, false);
    lbl_treble_lpf_freq->setColour (TextEditor::textColourId, Colours::black);
    lbl_treble_lpf_freq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_treble_lpf_depth.reset (new Slider ("treble lpf depth"));
    addAndMakeVisible (sld_treble_lpf_depth.get());
    sld_treble_lpf_depth->setRange (0, 4, 0);
    sld_treble_lpf_depth->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_treble_lpf_depth->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_treble_lpf_depth->addListener (this);

    lbl_treble_lpf_depth.reset (new Label ("treble lpf depth lbl",
                                           TRANS("LPF depth")));
    addAndMakeVisible (lbl_treble_lpf_depth.get());
    lbl_treble_lpf_depth->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_treble_lpf_depth->setJustificationType (Justification::centred);
    lbl_treble_lpf_depth->setEditable (false, false, false);
    lbl_treble_lpf_depth->setColour (TextEditor::textColourId, Colours::black);
    lbl_treble_lpf_depth->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_treble_mics.reset (new Slider ("treble mics"));
    addAndMakeVisible (sld_treble_mics.get());
    sld_treble_mics->setRange (0, 180, 0);
    sld_treble_mics->setSliderStyle (Slider::LinearHorizontal);
    sld_treble_mics->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_treble_mics->addListener (this);

    lbl_treble_mics.reset (new Label ("treble mics lbl",
                                      TRANS("Mics distance")));
    addAndMakeVisible (lbl_treble_mics.get());
    lbl_treble_mics->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_treble_mics->setJustificationType (Justification::centred);
    lbl_treble_mics->setEditable (false, false, false);
    lbl_treble_mics->setColour (TextEditor::textColourId, Colours::black);
    lbl_treble_mics->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    lbl_horn_radius.reset (new Label ("horn radius lbl",
                                      TRANS("Radius")));
    addAndMakeVisible (lbl_horn_radius.get());
    lbl_horn_radius->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_horn_radius->setJustificationType (Justification::centred);
    lbl_horn_radius->setEditable (false, false, false);
    lbl_horn_radius->setColour (TextEditor::textColourId, Colours::black);
    lbl_horn_radius->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_horn_freq.reset (new Slider ("horn freq"));
    addAndMakeVisible (sld_horn_freq.get());
    sld_horn_freq->setRange (1000, 3000, 0);
    sld_horn_freq->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_horn_freq->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_horn_freq->addListener (this);

    lbl_horn_freq.reset (new Label ("horn freq lbl",
                                    TRANS("Resonant freq")));
    addAndMakeVisible (lbl_horn_freq.get());
    lbl_horn_freq->setFont (Font (14.0f, Font::plain).withTypefaceStyle ("Regular"));
    lbl_horn_freq->setJustificationType (Justification::centred);
    lbl_horn_freq->setEditable (false, false, false);
    lbl_horn_freq->setColour (TextEditor::textColourId, Colours::black);
    lbl_horn_freq->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    sld_treble_lpf_freq.reset (new Slider ("treble lpf freq"));
    addAndMakeVisible (sld_treble_lpf_freq.get());
    sld_treble_lpf_freq->setRange (500, 3000, 0);
    sld_treble_lpf_freq->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_treble_lpf_freq->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_treble_lpf_freq->addListener (this);

    sld_treble_lpf_freq->setBounds ((((8 + 128) + 112) + 112) + 16, ((getHeight() - 8 - 120) + 0 - 120) + 16, 64, 80);

    sld_horn_radius.reset (new Slider ("horn radius"));
    addAndMakeVisible (sld_horn_radius.get());
    sld_horn_radius->setRange (5, 70, 0);
    sld_horn_radius->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    sld_horn_radius->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    sld_horn_radius->addListener (this);

    sld_horn_radius->setBounds ((((8 + 128) + 112) + 112) + 16, (getHeight() - 8 - 120) + 16, 64, 80);


    //[UserPreSize]
    // add suffixes
    sld_drive->setTextValueSuffix(" %");
    sld_xver->setTextValueSuffix(" Hz");
    sld_bass_speed->setTextValueSuffix(" RPM");
    sld_bass_am->setTextValueSuffix("");
    sld_bass_mix->setTextValueSuffix(" %");
    sld_treble_speed->setTextValueSuffix(" RPM");
    sld_treble_am->setTextValueSuffix("");
    sld_treble_mix->setTextValueSuffix(" %");
    sld_treble_mics->setTextValueSuffix(" deg");
    sld_treble_lpf_freq->setTextValueSuffix(" Hz");
    sld_treble_lpf_depth->setTextValueSuffix(" oct");
    sld_horn_radius->setTextValueSuffix(" cm");
    sld_horn_freq->setTextValueSuffix(" Hz");
    // skew factors
    sld_xver->setSkewFactorFromMidPoint(1500);
    sld_horn_radius->setSkewFactor(0.5);
    sld_bass_speed->setSkewFactor(0.6);
    sld_treble_speed->setSkewFactor(0.6);
    sld_treble_lpf_freq->setSkewFactorFromMidPoint(2500);
    // trim decimal places
    sld_drive->setNumDecimalPlacesToDisplay(0);
    sld_xver->setNumDecimalPlacesToDisplay(1);
    sld_bass_speed->setNumDecimalPlacesToDisplay(1);
    sld_bass_am->setNumDecimalPlacesToDisplay(1);
    sld_bass_mix->setNumDecimalPlacesToDisplay(1);
    sld_treble_speed->setNumDecimalPlacesToDisplay(1);
    sld_treble_am->setNumDecimalPlacesToDisplay(1);
    sld_treble_mix->setNumDecimalPlacesToDisplay(1);
    sld_treble_mics->setNumDecimalPlacesToDisplay(1);
    sld_treble_lpf_freq->setNumDecimalPlacesToDisplay(0);
    sld_treble_lpf_depth->setNumDecimalPlacesToDisplay(2);
    sld_horn_radius->setNumDecimalPlacesToDisplay(1);
    sld_horn_freq->setNumDecimalPlacesToDisplay(0);
    // set to default value
    sld_drive->setValue(25);
    sld_xver->setValue(800);
    sld_bass_speed->setValue(40);
    sld_bass_am->setValue(5);
    sld_bass_mix->setValue(75);
    sld_treble_speed->setValue(50);
    sld_treble_am->setValue(2);
    sld_treble_mix->setValue(75);
    sld_treble_mics->setValue(90);
    sld_treble_lpf_freq->setValue(1500);
    sld_treble_lpf_depth->setValue(1);
    sld_horn_radius->setValue(17);
    sld_horn_freq->setValue(2000);
    //[/UserPreSize]

    setSize (560, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginGUI::~PluginGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    grp_general = nullptr;
    grp_bass = nullptr;
    grp_treble = nullptr;
    grp_horn = nullptr;
    grp_lpf = nullptr;
    sld_drive = nullptr;
    lbl_drive = nullptr;
    sld_xver = nullptr;
    lbl_xver = nullptr;
    sld_bass_speed = nullptr;
    lbl_bass_speed = nullptr;
    sld_bass_am = nullptr;
    lbl_bass_am = nullptr;
    sld_bass_mix = nullptr;
    lbl_bass_mix = nullptr;
    sld_treble_speed = nullptr;
    lbl_treble_speed = nullptr;
    sld_treble_am = nullptr;
    lbl_treble_am = nullptr;
    sld_treble_mix = nullptr;
    lbl_treble_mix = nullptr;
    lbl_treble_lpf_freq = nullptr;
    sld_treble_lpf_depth = nullptr;
    lbl_treble_lpf_depth = nullptr;
    sld_treble_mics = nullptr;
    lbl_treble_mics = nullptr;
    lbl_horn_radius = nullptr;
    sld_horn_freq = nullptr;
    lbl_horn_freq = nullptr;
    sld_treble_lpf_freq = nullptr;
    sld_horn_radius = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 4, y = 8, width = 416, height = 56;
        String text (TRANS("Leslie Speaker Sim"));
        Colour fillColour = Colours::blanchedalmond;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSerifFontName(), 56.0f, Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (-0.1f));
        g.drawText (text, x, y, width, height,
                    Justification::topLeft, true);
    }

    {
        int x = getWidth() - 4 - 144, y = 30, width = 144, height = 12;
        String text (TRANS("Riccardo Miccini, 2018"));
        Colour fillColour = Colours::blanchedalmond;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSerifFontName(), 12.0f, Font::plain).withExtraKerningFactor (-0.1f));
        g.drawText (text, x, y, width, height,
                    Justification::centredRight, true);
    }

    {
        int x = getWidth() - 4 - 144, y = 42, width = 144, height = 12;
        String text (TRANS("Made with FAUST+JUCE"));
        Colour fillColour = Colour (0xff42a2c8);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (Font::getDefaultSerifFontName(), 12.0f, Font::plain).withExtraKerningFactor (-0.1f));
        g.drawText (text, x, y, width, height,
                    Justification::centredRight, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    grp_general->setBounds (8, getHeight() - 8 - (getHeight() - 80), 128, getHeight() - 80);
    grp_bass->setBounds (8 + 128, getHeight() - 8 - (getHeight() - 80), 112, getHeight() - 80);
    grp_treble->setBounds ((8 + 128) + 112, getHeight() - 8 - (getHeight() - 80), 112, getHeight() - 80);
    grp_horn->setBounds (((8 + 128) + 112) + 112, getHeight() - 8 - 120, 192, 120);
    grp_lpf->setBounds (((8 + 128) + 112) + 112, (getHeight() - 8 - 120) + 0 - 120, 192, 120);
    sld_drive->setBounds (8 + 128 / 2 - (96 / 2), (getHeight() - 8 - (getHeight() - 80)) + 16, 96, 112);
    lbl_drive->setBounds (8 + 128 / 2 - (112 / 2), ((getHeight() - 8 - (getHeight() - 80)) + 16) + 112, 112, 16);
    sld_xver->setBounds (8 + 128 / 2 - (96 / 2), (((getHeight() - 8 - (getHeight() - 80)) + 16) + 112) + 48, 96, 112);
    lbl_xver->setBounds (8 + 128 / 2 - (112 / 2), ((((getHeight() - 8 - (getHeight() - 80)) + 16) + 112) + 48) + 112, 112, 16);
    sld_bass_speed->setBounds ((8 + 128) + 112 / 2 - (64 / 2), (getHeight() - 8 - (getHeight() - 80)) + 8, 64, 80);
    lbl_bass_speed->setBounds ((8 + 128) + 112 / 2 - (112 / 2), ((getHeight() - 8 - (getHeight() - 80)) + 8) + 80, 112, 16);
    sld_bass_am->setBounds ((8 + 128) + 112 / 2 - (64 / 2), (((getHeight() - 8 - (getHeight() - 80)) + 8) + 80) + 16, 64, 80);
    lbl_bass_am->setBounds ((8 + 128) + 112 / 2 - (112 / 2), ((((getHeight() - 8 - (getHeight() - 80)) + 8) + 80) + 16) + 80, 112, 16);
    sld_bass_mix->setBounds ((8 + 128) + 112 / 2 - (64 / 2), (((((getHeight() - 8 - (getHeight() - 80)) + 8) + 80) + 16) + 80) + 32, 64, 80);
    lbl_bass_mix->setBounds ((8 + 128) + 112 / 2 - (112 / 2), ((((((getHeight() - 8 - (getHeight() - 80)) + 8) + 80) + 16) + 80) + 32) + 80, 112, 16);
    sld_treble_speed->setBounds (((8 + 128) + 112) + 112 / 2 - (64 / 2), (getHeight() - 8 - (getHeight() - 80)) + 8, 64, 80);
    lbl_treble_speed->setBounds (((8 + 128) + 112) + 112 / 2 - (112 / 2), ((getHeight() - 8 - (getHeight() - 80)) + 8) + 80, 112, 16);
    sld_treble_am->setBounds (((8 + 128) + 112) + 112 / 2 - (64 / 2), (((getHeight() - 8 - (getHeight() - 80)) + 8) + 80) + 16, 64, 80);
    lbl_treble_am->setBounds (((8 + 128) + 112) + 112 / 2 - (112 / 2), ((((getHeight() - 8 - (getHeight() - 80)) + 8) + 80) + 16) + 80, 112, 16);
    sld_treble_mix->setBounds (((8 + 128) + 112) + 112 / 2 - (64 / 2), (((((getHeight() - 8 - (getHeight() - 80)) + 8) + 80) + 16) + 80) + 32, 64, 80);
    lbl_treble_mix->setBounds (((8 + 128) + 112) + 112 / 2 - (112 / 2), ((((((getHeight() - 8 - (getHeight() - 80)) + 8) + 80) + 16) + 80) + 32) + 80, 112, 16);
    lbl_treble_lpf_freq->setBounds (((((8 + 128) + 112) + 112) + 16) + 64 / 2 - (112 / 2), (((getHeight() - 8 - 120) + 0 - 120) + 16) + 80, 112, 16);
    sld_treble_lpf_depth->setBounds ((((8 + 128) + 112) + 112) + 192 - 16 - 64, ((getHeight() - 8 - 120) + 0 - 120) + 16, 64, 80);
    lbl_treble_lpf_depth->setBounds (((((8 + 128) + 112) + 112) + 192 - 16 - 64) + 64 / 2 - (112 / 2), (((getHeight() - 8 - 120) + 0 - 120) + 16) + 80, 112, 16);
    sld_treble_mics->setBounds (((8 + 128) + 112) + 112, (((getHeight() - 8 - 120) + 0 - 120) + 0 - 16) + 0 - 56, 192, 56);
    lbl_treble_mics->setBounds (((8 + 128) + 112) + 112, ((getHeight() - 8 - 120) + 0 - 120) + 0 - 16, 192, 16);
    lbl_horn_radius->setBounds (((((8 + 128) + 112) + 112) + 16) + 64 / 2 - (112 / 2), ((getHeight() - 8 - 120) + 16) + 80, 112, 16);
    sld_horn_freq->setBounds ((((8 + 128) + 112) + 112) + 192 - 16 - 64, (getHeight() - 8 - 120) + 16, 64, 80);
    lbl_horn_freq->setBounds (((((8 + 128) + 112) + 112) + 192 - 16 - 64) + 64 / 2 - (112 / 2), ((getHeight() - 8 - 120) + 16) + 80, 112, 16);
    //[UserResized] Add your own custom resize handling here..
    sld_treble_lpf_freq->setBounds(((((8 + 128) + 112) + 112) + 16) + 64 / 2 - (64 / 2), ((getHeight() - 8 - 120) + 0 - 120) + 16, 64, 80);
    sld_horn_radius->setBounds(((((8 + 128) + 112) + 112) + 16) + 64 / 2 - (64 / 2), (getHeight() - 8 - 120) + 16, 64, 80);
    //[/UserResized]
}

void PluginGUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    float x = sliderThatWasMoved->getValue();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sld_drive.get())
    {
        //[UserSliderCode_sld_drive] -- add your slider handling code here..
        processor.setAmpDrive(x);
        //[/UserSliderCode_sld_drive]
    }
    else if (sliderThatWasMoved == sld_xver.get())
    {
        //[UserSliderCode_sld_xver] -- add your slider handling code here..
        processor.setXverFreq(x);
        //[/UserSliderCode_sld_xver]
    }
    else if (sliderThatWasMoved == sld_bass_speed.get())
    {
        //[UserSliderCode_sld_bass_speed] -- add your slider handling code here..
        processor.setBassSpeed(x);
        //[/UserSliderCode_sld_bass_speed]
    }
    else if (sliderThatWasMoved == sld_bass_am.get())
    {
        //[UserSliderCode_sld_bass_am] -- add your slider handling code here..
        processor.setBassAmDepth(x);
        //[/UserSliderCode_sld_bass_am]
    }
    else if (sliderThatWasMoved == sld_bass_mix.get())
    {
        //[UserSliderCode_sld_bass_mix] -- add your slider handling code here..
        processor.setBassMix(x);
        //[/UserSliderCode_sld_bass_mix]
    }
    else if (sliderThatWasMoved == sld_treble_speed.get())
    {
        //[UserSliderCode_sld_treble_speed] -- add your slider handling code here..
        processor.setTrebleSpeed(x);
        //[/UserSliderCode_sld_treble_speed]
    }
    else if (sliderThatWasMoved == sld_treble_am.get())
    {
        //[UserSliderCode_sld_treble_am] -- add your slider handling code here..
        processor.setTrebleAmDepth(x);
        //[/UserSliderCode_sld_treble_am]
    }
    else if (sliderThatWasMoved == sld_treble_mix.get())
    {
        //[UserSliderCode_sld_treble_mix] -- add your slider handling code here..
        processor.setTrebleMix(x);
        //[/UserSliderCode_sld_treble_mix]
    }
    else if (sliderThatWasMoved == sld_treble_lpf_depth.get())
    {
        //[UserSliderCode_sld_treble_lpf_depth] -- add your slider handling code here..
        processor.setTrebleLpfDepth(x);
        //[/UserSliderCode_sld_treble_lpf_depth]
    }
    else if (sliderThatWasMoved == sld_treble_mics.get())
    {
        //[UserSliderCode_sld_treble_mics] -- add your slider handling code here..
        processor.setTrebleMics(x);
        //[/UserSliderCode_sld_treble_mics]
    }
    else if (sliderThatWasMoved == sld_horn_freq.get())
    {
        //[UserSliderCode_sld_horn_freq] -- add your slider handling code here..
        processor.setHornFreq(x);
        //[/UserSliderCode_sld_horn_freq]
    }
    else if (sliderThatWasMoved == sld_treble_lpf_freq.get())
    {
        //[UserSliderCode_sld_treble_lpf_freq] -- add your slider handling code here..
        processor.setTrebleLpfFreq(x);
        //[/UserSliderCode_sld_treble_lpf_freq]
    }
    else if (sliderThatWasMoved == sld_horn_radius.get())
    {
        //[UserSliderCode_sld_horn_radius] -- add your slider handling code here..
        processor.setHornRadius(x);
        //[/UserSliderCode_sld_horn_radius]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginGUI" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="LeslieSimAudioProcessor&amp; p"
                 variableInitialisers="AudioProcessorEditor(&amp;p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="1" initialWidth="560" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <TEXT pos="4 8 416 56" fill="solid: ffffebcd" hasStroke="0" text="Leslie Speaker Sim"
          fontname="Default serif font" fontsize="56.0" kerning="-0.10000000000000000555"
          bold="1" italic="0" justification="9" typefaceStyle="Bold"/>
    <TEXT pos="4Rr 30 144 12" fill="solid: ffffebcd" hasStroke="0" text="Riccardo Miccini, 2018"
          fontname="Default serif font" fontsize="12.0" kerning="-0.10000000000000000555"
          bold="0" italic="0" justification="34"/>
    <TEXT pos="4Rr 42 144 12" fill="solid: ff42a2c8" hasStroke="0" text="Made with FAUST+JUCE"
          fontname="Default serif font" fontsize="12.0" kerning="-0.10000000000000000555"
          bold="0" italic="0" justification="34"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="general group" id="a37772edebdc7800" memberName="grp_general"
                  virtualName="" explicitFocusOrder="0" pos="8 8Rr 128 80M" title="General"
                  textpos="33"/>
  <GROUPCOMPONENT name="bass group" id="1342a6fca74e9e73" memberName="grp_bass"
                  virtualName="" explicitFocusOrder="0" pos="0R 8Rr 112 80M" posRelativeX="a37772edebdc7800"
                  title="Bass" textpos="33"/>
  <GROUPCOMPONENT name="treble channel" id="d4fcd00a0a255092" memberName="grp_treble"
                  virtualName="" explicitFocusOrder="0" pos="0R 8Rr 112 80M" posRelativeX="1342a6fca74e9e73"
                  title="Treble" textpos="33"/>
  <GROUPCOMPONENT name="horn group" id="eb13afa19b5093b3" memberName="grp_horn"
                  virtualName="" explicitFocusOrder="0" pos="0R 8Rr 192 120" posRelativeX="d4fcd00a0a255092"
                  title="Horn" textpos="33"/>
  <GROUPCOMPONENT name="lpf group" id="a3c9e1695633e23f" memberName="grp_lpf" virtualName=""
                  explicitFocusOrder="0" pos="0R 0r 192 120" posRelativeX="d4fcd00a0a255092"
                  posRelativeY="eb13afa19b5093b3" title="LP filter" textpos="33"/>
  <SLIDER name="amp drive" id="5fe6dfb1d5e4d0cb" memberName="sld_drive"
          virtualName="" explicitFocusOrder="0" pos="0Cc 16 96 112" posRelativeX="a37772edebdc7800"
          posRelativeY="a37772edebdc7800" min="0.0" max="100.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="amp drive lbl" id="236d4949729d2c22" memberName="lbl_drive"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="a37772edebdc7800"
         posRelativeY="5fe6dfb1d5e4d0cb" edTextCol="ff000000" edBkgCol="0"
         labelText="Amp drive" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="xver freq" id="257cddd2ba64691e" memberName="sld_xver"
          virtualName="" explicitFocusOrder="0" pos="0Cc 48 96 112" posRelativeX="a37772edebdc7800"
          posRelativeY="236d4949729d2c22" min="200.0" max="8000.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="xver freq lbl" id="e48b0bdd454acdb2" memberName="lbl_xver"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="a37772edebdc7800"
         posRelativeY="257cddd2ba64691e" edTextCol="ff000000" edBkgCol="0"
         labelText="Crossover freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="bass speed" id="4ea6b4e8810d40e8" memberName="sld_bass_speed"
          virtualName="" explicitFocusOrder="0" pos="0Cc 8 64 80" posRelativeX="1342a6fca74e9e73"
          posRelativeY="1342a6fca74e9e73" min="5.0" max="300.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="bass speed lbl" id="991e5f808f0a09e8" memberName="lbl_bass_speed"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="1342a6fca74e9e73"
         posRelativeY="4ea6b4e8810d40e8" edTextCol="ff000000" edBkgCol="0"
         labelText="Speed" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="bass am" id="310856ced3b820cb" memberName="sld_bass_am"
          virtualName="" explicitFocusOrder="0" pos="0Cc 0R 64 80" posRelativeX="1342a6fca74e9e73"
          posRelativeY="991e5f808f0a09e8" min="0.0" max="10.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="bass am lbl" id="8301bfc6db52ce7d" memberName="lbl_bass_am"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="1342a6fca74e9e73"
         posRelativeY="310856ced3b820cb" edTextCol="ff000000" edBkgCol="0"
         labelText="AM depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="bass mix" id="c67e228ca9b9786e" memberName="sld_bass_mix"
          virtualName="" explicitFocusOrder="0" pos="0Cc 32 64 80" posRelativeX="1342a6fca74e9e73"
          posRelativeY="8301bfc6db52ce7d" min="0.0" max="100.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="bass mix lbl" id="e1ee6545b11be2f" memberName="lbl_bass_mix"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="1342a6fca74e9e73"
         posRelativeY="c67e228ca9b9786e" edTextCol="ff000000" edBkgCol="0"
         labelText="Mix" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="treble speed" id="57880ec898859564" memberName="sld_treble_speed"
          virtualName="" explicitFocusOrder="0" pos="0Cc 8 64 80" posRelativeX="d4fcd00a0a255092"
          posRelativeY="d4fcd00a0a255092" min="5.0" max="500.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="treble speed lbl" id="e11e50f8ec703bd9" memberName="lbl_treble_speed"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="d4fcd00a0a255092"
         posRelativeY="57880ec898859564" edTextCol="ff000000" edBkgCol="0"
         labelText="Speed" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="treble am" id="7ada846e3bc8308" memberName="sld_treble_am"
          virtualName="" explicitFocusOrder="0" pos="0Cc 0R 64 80" posRelativeX="d4fcd00a0a255092"
          posRelativeY="e11e50f8ec703bd9" min="0.0" max="10.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="treble am lbl" id="92809cb3be2de6fa" memberName="lbl_treble_am"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="d4fcd00a0a255092"
         posRelativeY="7ada846e3bc8308" edTextCol="ff000000" edBkgCol="0"
         labelText="AM depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="treble mix" id="20a21d7a3073ff17" memberName="sld_treble_mix"
          virtualName="" explicitFocusOrder="0" pos="0Cc 32 64 80" posRelativeX="d4fcd00a0a255092"
          posRelativeY="92809cb3be2de6fa" min="0.0" max="100.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="treble mix lbl" id="bfab5895105cf60c" memberName="lbl_treble_mix"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="d4fcd00a0a255092"
         posRelativeY="20a21d7a3073ff17" edTextCol="ff000000" edBkgCol="0"
         labelText="Mix" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="treble lpf freq lbl" id="652befdf52274550" memberName="lbl_treble_lpf_freq"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="17a5d6da6912290f"
         posRelativeY="17a5d6da6912290f" edTextCol="ff000000" edBkgCol="0"
         labelText="LPF freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="treble lpf depth" id="385cc1d8047e3adb" memberName="sld_treble_lpf_depth"
          virtualName="" explicitFocusOrder="0" pos="16Rr 16 64 80" posRelativeX="a3c9e1695633e23f"
          posRelativeY="a3c9e1695633e23f" min="0.0" max="4.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="treble lpf depth lbl" id="f7dfde8ee79d4f3e" memberName="lbl_treble_lpf_depth"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="385cc1d8047e3adb"
         posRelativeY="385cc1d8047e3adb" edTextCol="ff000000" edBkgCol="0"
         labelText="LPF depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="treble mics" id="fe24bc4f392ec662" memberName="sld_treble_mics"
          virtualName="" explicitFocusOrder="0" pos="0R 0r 192 56" posRelativeX="d4fcd00a0a255092"
          posRelativeY="b016722fd0834cd6" min="0.0" max="180.0" int="0.0"
          style="LinearHorizontal" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="treble mics lbl" id="b016722fd0834cd6" memberName="lbl_treble_mics"
         virtualName="" explicitFocusOrder="0" pos="0R 0r 192 16" posRelativeX="d4fcd00a0a255092"
         posRelativeY="a3c9e1695633e23f" edTextCol="ff000000" edBkgCol="0"
         labelText="Mics distance" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="horn radius lbl" id="d319361562ea3fce" memberName="lbl_horn_radius"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="358882dcb76e224f"
         posRelativeY="358882dcb76e224f" edTextCol="ff000000" edBkgCol="0"
         labelText="Radius" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="horn freq" id="800bc67f71a9381" memberName="sld_horn_freq"
          virtualName="" explicitFocusOrder="0" pos="16Rr 16 64 80" posRelativeX="eb13afa19b5093b3"
          posRelativeY="eb13afa19b5093b3" min="1000.0" max="3000.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="horn freq lbl" id="870b376e91910480" memberName="lbl_horn_freq"
         virtualName="" explicitFocusOrder="0" pos="0Cc 0R 112 16" posRelativeX="800bc67f71a9381"
         posRelativeY="800bc67f71a9381" edTextCol="ff000000" edBkgCol="0"
         labelText="Resonant freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="14.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="treble lpf freq" id="17a5d6da6912290f" memberName="sld_treble_lpf_freq"
          virtualName="" explicitFocusOrder="0" pos="16 16 64 80" posRelativeX="a3c9e1695633e23f"
          posRelativeY="a3c9e1695633e23f" min="500.0" max="3000.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="horn radius" id="358882dcb76e224f" memberName="sld_horn_radius"
          virtualName="" explicitFocusOrder="0" pos="16 16 64 80" posRelativeX="eb13afa19b5093b3"
          posRelativeY="eb13afa19b5093b3" min="5.0" max="70.0" int="0.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
