/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Dsp.h"

//==============================================================================
/**
*/
class LeslieSimAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    LeslieSimAudioProcessor();
    ~LeslieSimAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
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

    void setAmpDrive(float x);
    void setXverFreq(float x);
    void setBassSpeed(float x);
    void setBassAmDepth(float x);
    void setBassMix(float x);
    void setTrebleSpeed(float x);
    void setTrebleAmDepth(float x);
    void setTrebleMix(float x);
    void setTrebleMics(float x);
    void setTrebleLpfFreq(float x);
    void setTrebleLpfDepth(float x);
    void setHornRadius(float x);
    void setHornFreq(float x);

  private:
    Dsp dspFaust;
    MapUI dspControl;

    int blockSize, nChans;
    double currentSampleRate;
    float **audioBuffer;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LeslieSimAudioProcessor)
};
