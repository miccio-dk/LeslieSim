/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginGUI.h"

//==============================================================================
LeslieSimAudioProcessor::LeslieSimAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
                         .withInput("Input", AudioChannelSet::stereo(), true)
#endif
                         .withOutput("Output", AudioChannelSet::stereo(), true)
#endif
      )
#endif
{
    // add something to ctor?
    nChans = 2;
    audioBuffer = new float *[nChans];
}

LeslieSimAudioProcessor::~LeslieSimAudioProcessor()
{
    // add something to destructor?
    delete[] audioBuffer;
}

//==============================================================================
const String LeslieSimAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool LeslieSimAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool LeslieSimAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool LeslieSimAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double LeslieSimAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int LeslieSimAudioProcessor::getNumPrograms()
{
    return 1; // NB: some hosts don't cope very well if you tell them there are 0 programs,
              // so this should be at least 1, even if you're not really implementing programs.
}

int LeslieSimAudioProcessor::getCurrentProgram()
{
    return 0;
}

void LeslieSimAudioProcessor::setCurrentProgram(int index)
{
}

const String LeslieSimAudioProcessor::getProgramName(int index)
{
    return {};
}

void LeslieSimAudioProcessor::changeProgramName(int index, const String &newName)
{
}

//==============================================================================
void LeslieSimAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    blockSize = samplesPerBlock;
    dspFaust.init(sampleRate);
    dspFaust.buildUserInterface(&dspControl);

    for (int i = 0; i < dspControl.getParamsCount(); i++)
    {
        std::cout << dspControl.getParamAddress(i) << "\n";
    }
}

void LeslieSimAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool LeslieSimAudioProcessor::isBusesLayoutSupported(const BusesLayout &layouts) const
{
#if JucePlugin_IsMidiEffect
    ignoreUnused(layouts);
    return true;
#else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono() && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

        // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
#endif

    return true;
#endif
}
#endif

void LeslieSimAudioProcessor::processBlock(AudioBuffer<float> &buffer, MidiBuffer &midiMessages)
{
    AudioSourceChannelInfo bufferToFill;
    bufferToFill.buffer = &buffer;
    bufferToFill.startSample = 0;
    bufferToFill.numSamples = buffer.getNumSamples();


    for (int i = 0; i < nChans; i++)
    {
        audioBuffer[i] = bufferToFill.buffer->getWritePointer(i, bufferToFill.startSample);
    }
    // any processing before going to "reverb" could be done here in a dedicated buffer loop

    dspFaust.compute(blockSize, audioBuffer, audioBuffer); // computing one block with Faust
}

//==============================================================================
bool LeslieSimAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor *LeslieSimAudioProcessor::createEditor()
{
    return new PluginGUI(*this);
}

//==============================================================================
void LeslieSimAudioProcessor::getStateInformation(MemoryBlock &destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void LeslieSimAudioProcessor::setStateInformation(const void *data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
void LeslieSimAudioProcessor::setAmpDrive(float x) { dspControl.setParamValue("/leslie/Amp_drive", x); }
void LeslieSimAudioProcessor::setXverFreq(float x) { dspControl.setParamValue("/leslie/Crossover_freq_(Hz)", x); }
void LeslieSimAudioProcessor::setBassSpeed(float x) { dspControl.setParamValue("/leslie/Signal_channels/Bass_channel/Bass_speed_(RPM)", x); }
void LeslieSimAudioProcessor::setBassAmDepth(float x) { dspControl.setParamValue("/leslie/Signal_channels/Bass_channel/Bass_AM_depth", x); }
void LeslieSimAudioProcessor::setBassMix(float x) { dspControl.setParamValue("/leslie/Signal_channels/Bass_channel/Bass_mix_(%)", x); }
void LeslieSimAudioProcessor::setTrebleSpeed(float x) { dspControl.setParamValue("/leslie/Signal_channels/Treble_channels/Treble_speed_(RPM)", x); }
void LeslieSimAudioProcessor::setTrebleAmDepth(float x) { dspControl.setParamValue("/leslie/Signal_channels/Treble_channels/Treble_AM_depth", x); }
void LeslieSimAudioProcessor::setTrebleMix(float x) { dspControl.setParamValue("/leslie/Signal_channels/Treble_channels/Treble_mix_(%)", x); }
void LeslieSimAudioProcessor::setTrebleMics(float x) { dspControl.setParamValue("/leslie/Signal_channels/Treble_channels/Mics_distance_(deg)", x); }
void LeslieSimAudioProcessor::setTrebleLpfFreq(float x) { dspControl.setParamValue("/leslie/Signal_channels/Treble_channels/Treble_LPF_center_freq_(Hz)", x); }
void LeslieSimAudioProcessor::setTrebleLpfDepth(float x) { dspControl.setParamValue("/leslie/Signal_channels/Treble_channels/Treble_LPF_depth_(oct.)", x); }
void LeslieSimAudioProcessor::setHornRadius(float x) { dspControl.setParamValue("/leslie/Signal_channels/Treble_channels/Treble_radius_(cm)", x); }
void LeslieSimAudioProcessor::setHornFreq(float x) { dspControl.setParamValue("/leslie/Signal_channels/Treble_channels/Horn_resonance_freq_(Hz)", x); }

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor *JUCE_CALLTYPE createPluginFilter()
{
    return new LeslieSimAudioProcessor();
}
