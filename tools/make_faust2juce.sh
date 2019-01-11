# generate dsp-faust.zip
faust2api -juce faust/leslie.dsp
unzip dsp-faust.zip
mv dsp-faust/DspFaust.* juce/LeslieSim/Source/
rm dsp-faust.zip
rm -r dsp-faust