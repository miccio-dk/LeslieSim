# Leslie speaker simulator
> Mini-project for *Sound Processing* (AAU SMC 2018)


## Abstract
This archive presents a virtual simulation of the Leslie Speaker commonly found in Hammond electric organs.   
The digital effect has been developed using the FAUST programming language, and then ported into a VST-compatible format using the JUCE C++ framework.

A paper detailing the models and implementation can be found in the `report` directory.
Slides for this project can be found at https://slides.com/riccardomiccini/deck/live.


## Instructions
### Test DSP
- open [FAUST online editor](https://faust.grame.fr/tools/editor/index.html)
- copy content of `faust/leslie.dsp`
- possible actions: 
  - run in browser
  - show interactive block diagram
  - export (e.g. VST, standalone, android app...)
- *note: the user interface and performances differ from the JUCE version*
- *note: the graph bars on the UI show the angles of the rotating motors and the position of the read and write buffer pointers*
### Build project
- run Projucer
- open `juce/LeslieSim/LeslieSim.jucer`
- generate exporters for desired platform
- compile using selected plaftorm
- *note: the compilation should return a VST as well as a stand-alone version*
- *note: only tested on Ubuntu Linux 16.04 LTS and 18.04 LTS*


#### Riccardo Miccini, 2018