/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <Gamma/Filter.h>
#include <Gamma/Oscillator.h>

using namespace gam;
#define NUM_BANDS 4

//==============================================================================
/**
*/
class PhaserWahAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    PhaserWahAudioProcessor();
    ~PhaserWahAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    int getNumParameters() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
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

    typedef enum {
        BAND_FREQ1 = 0,
        BAND_WIDTH1,
        BAND_FREQ2,
        BAND_WIDTH2,
        BAND_FREQ3,
        BAND_WIDTH3,
        BAND_FREQ4,
        BAND_WIDTH4,

        MOD_DEPTH,
        MOD_FREQ,

        MIX,
        NUM_PARAMS
    } PARAMS;
private:

    float sr;
    float mix;
    float freq[NUM_BANDS];
    float bandwidth[NUM_BANDS];

    float modfreq, moddepth;
    Reson<> n[NUM_BANDS];
    SineR<> modulator;

    inline float calcMaxBandwidth(const float f){
        return 2 * f / log(f + 0.001);
    };
    
    void updateFilter(const int filterID);
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PhaserWahAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
