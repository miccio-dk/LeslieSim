/* ------------------------------------------------------------
name: "leslie"
Code generated with Faust 2.13.14 (https://faust.grame.fr)
Compilation options: cpp, -scal -ftz 0
------------------------------------------------------------ */

#ifndef  __Dsp_H__
#define  __Dsp_H__

// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Romain Michon (rmichonATccrmaDOTstanfordDOTedu)
// Description: Simple Faust architecture file to easily integrate a Faust DSP module
// in a JUCE project

// needed by any Faust arch file
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <cstdlib>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key] = value; }
};

static int lsr(int x, int n) { return int(((unsigned int)x) >> n); }

static int int2pow2(int x) { int r = 0; while ((1<<r) < x) r++; return r; }

static long lopt(char* argv[], const char* name, long def)
{
	int	i;
    for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return std::atoi(argv[i+1]);
	return def;
}

static bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

static const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


// allows to control a Faust DSP module in a simple manner by using parameter's path
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#include <vector>
#include <map>
#include <string>

/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __UI_H__
#define __UI_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust DSP User Interface
 * User Interface as expected by the buildUserInterface() method of a DSP.
 * This abstract class contains only the method that the Faust compiler can
 * generate to describe a DSP user interface.
 ******************************************************************************/

struct Soundfile;

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
    
        // -- soundfiles
    
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

#endif
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            std::replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
        void pushLabel(const std::string& label) { fControlsLevel.push_back(label); }
        void popLabel() { fControlsLevel.pop_back(); }
    
};

#endif  // FAUST_PATHBUILDER_H

/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
    
        // -- soundfiles
        virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, FAUSTFLOAT value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        FAUSTFLOAT getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return FAUSTFLOAT(0);
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return int(fPathZoneMap.size()); }
        
        std::string getParamAddress(int index)
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
    
        std::string getParamAddress(FAUSTFLOAT* zone)
        {
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            do {
                if ((*it).second == zone) return (*it).first;
            }
            while (it++ != fPathZoneMap.end());
            return "";
        }
};

#endif // FAUST_MAPUI_H

// needed by any Faust arch file
/************************************************************************
 FAUST Architecture File
 Copyright (C) 2003-2017 GRAME, Centre National de Creation Musicale
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 ************************************************************************/

#ifndef __dsp__
#define __dsp__

#include <string>
#include <vector>

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
 * DSP memory manager.
 */

struct dsp_memory_manager {
    
    virtual ~dsp_memory_manager() {}
    
    virtual void* allocate(size_t size) = 0;
    virtual void destroy(void* ptr) = 0;
    
};

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the ui_interface parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /**
         * Global init, calls the following methods:
         * - static class 'classInit': static tables initialization
         * - 'instanceInit': constants and instance state initialization
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void init(int samplingRate) = 0;

        /**
         * Init instance state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceInit(int samplingRate) = 0;

        /**
         * Init instance constant state
         *
         * @param samplingRate - the sampling rate in Hertz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
 
        /**
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value) metadata.
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with successive in/out audio buffers.
         *
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation: alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the number of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, double or quad)
         *
         */
        virtual void compute(double /*date_usec*/, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { fDSP->metadata(m); }
        // Beware: subclasses usually have to overload the two 'compute' methods
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
    
};

/**
 * DSP factory class.
 */

class dsp_factory {
    
    protected:
    
        // So that to force sub-classes to use deleteDSPFactory(dsp_factory* factory);
        virtual ~dsp_factory() {}
    
    public:
    
        virtual std::string getName() = 0;
        virtual std::string getSHAKey() = 0;
        virtual std::string getDSPCode() = 0;
        virtual std::string getCompileOptions() = 0;
        virtual std::vector<std::string> getLibraryList() = 0;
        virtual std::vector<std::string> getIncludePathnames() = 0;
    
        virtual dsp* createDSPInstance() = 0;
    
        virtual void setMemoryManager(dsp_memory_manager* manager) = 0;
        virtual dsp_memory_manager* getMemoryManager() = 0;
    
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif

// tags used by the Faust compiler to paste the generated c++ code
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <math.h>

static float Dsp_faustpower2_f(float value) {
	return (value * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS Dsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class Dsp : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fRec3[2];
	FAUSTFLOAT fHslider2;
	float fRec7[2];
	float fVec0[2];
	float fRec6[2];
	float fRec5[3];
	float fRec4[3];
	int IOTA;
	float fVec1[16384];
	float fConst2;
	FAUSTFLOAT fHslider3;
	float fRec8[2];
	float fConst3;
	FAUSTFLOAT fHslider4;
	float fRec10[2];
	float fRec9[2];
	FAUSTFLOAT fHbargraph0;
	FAUSTFLOAT fHslider5;
	float fRec11[2];
	FAUSTFLOAT fHslider6;
	float fRec12[2];
	FAUSTFLOAT fHslider7;
	float fRec13[2];
	FAUSTFLOAT fHslider8;
	float fRec14[2];
	float fRec2[3];
	FAUSTFLOAT fHslider9;
	float fRec15[2];
	float fConst4;
	float fConst5;
	float fRec1[3];
	float fConst6;
	FAUSTFLOAT fHslider10;
	float fRec16[2];
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fRec19[3];
	float fConst12;
	float fConst13;
	float fRec18[3];
	float fConst14;
	float fRec17[3];
	FAUSTFLOAT fHslider11;
	float fRec20[2];
	FAUSTFLOAT fHslider12;
	float fRec22[2];
	float fRec21[2];
	FAUSTFLOAT fHbargraph1;
	float fRec23[3];
	float fRec25[3];
	float fRec24[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "0.0");
		m->declare("filename", "leslie");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("misceffects.lib/name", "Faust Math Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "leslie");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
	}

	virtual int getNumInputs() {
		return 1;
		
	}
	virtual int getNumOutputs() {
		return 2;
		
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (2.91545184e-05f * fConst0);
		fConst3 = (0.0166666675f / fConst0);
		fConst4 = (12566.3711f / fConst0);
		fConst5 = (6.28318548f / fConst0);
		fConst6 = (39738.3516f / fConst0);
		fConst7 = std::tan((628.318542f / fConst0));
		fConst8 = (1.0f / fConst7);
		fConst9 = (1.0f / (((fConst8 + 1.41421354f) / fConst7) + 1.0f));
		fConst10 = Dsp_faustpower2_f(fConst7);
		fConst11 = (1.0f / fConst10);
		fConst12 = (((fConst8 + -1.41421354f) / fConst7) + 1.0f);
		fConst13 = (2.0f * (1.0f - fConst11));
		fConst14 = (0.0f - (2.0f / fConst10));
		
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(100.0f);
		fHslider1 = FAUSTFLOAT(800.0f);
		fHslider2 = FAUSTFLOAT(25.0f);
		fHslider3 = FAUSTFLOAT(20.0f);
		fHslider4 = FAUSTFLOAT(50.0f);
		fHslider5 = FAUSTFLOAT(90.0f);
		fHslider6 = FAUSTFLOAT(1.0f);
		fHslider7 = FAUSTFLOAT(1500.0f);
		fHslider8 = FAUSTFLOAT(1.0f);
		fHslider9 = FAUSTFLOAT(2000.0f);
		fHslider10 = FAUSTFLOAT(100.0f);
		fHslider11 = FAUSTFLOAT(1.0f);
		fHslider12 = FAUSTFLOAT(30.0f);
		
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec3[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec7[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fVec0[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fRec6[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fRec5[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec4[l6] = 0.0f;
			
		}
		IOTA = 0;
		for (int l7 = 0; (l7 < 16384); l7 = (l7 + 1)) {
			fVec1[l7] = 0.0f;
			
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec8[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			fRec10[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fRec9[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec11[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec12[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			fRec13[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec14[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fRec2[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec15[l16] = 0.0f;
			
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec1[l17] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fRec16[l18] = 0.0f;
			
		}
		for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
			fRec19[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 3); l20 = (l20 + 1)) {
			fRec18[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec17[l21] = 0.0f;
			
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fRec20[l22] = 0.0f;
			
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec22[l23] = 0.0f;
			
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec21[l24] = 0.0f;
			
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec23[l25] = 0.0f;
			
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec25[l26] = 0.0f;
			
		}
		for (int l27 = 0; (l27 < 3); l27 = (l27 + 1)) {
			fRec24[l27] = 0.0f;
			
		}
		
	}
	
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual Dsp* clone() {
		return new Dsp();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("leslie");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->addHorizontalSlider("Amp drive", &fHslider2, 25.0f, 0.0f, 100.0f, 0.00999999978f);
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->addHorizontalSlider("Crossover freq (Hz)", &fHslider1, 800.0f, 200.0f, 8000.0f, 0.00999999978f);
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Signal channels");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("Bass channel");
		ui_interface->declare(&fHslider12, "00", "");
		ui_interface->addHorizontalSlider("Bass speed (RPM)", &fHslider12, 30.0f, 5.0f, 300.0f, 0.00999999978f);
		ui_interface->declare(&fHbargraph1, "01", "");
		ui_interface->addHorizontalBargraph("Bass rotation angle", &fHbargraph1, -3.14159274f, 3.14159274f);
		ui_interface->declare(&fHslider11, "1", "");
		ui_interface->addHorizontalSlider("Bass AM depth", &fHslider11, 1.0f, 0.0f, 10.0f, 0.00999999978f);
		ui_interface->declare(&fHslider10, "999", "");
		ui_interface->addHorizontalSlider("Bass mix (%)", &fHslider10, 100.0f, 0.0f, 100.0f, 0.00999999978f);
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("Treble channels");
		ui_interface->declare(&fHslider4, "00", "");
		ui_interface->addHorizontalSlider("Treble speed (RPM)", &fHslider4, 50.0f, 5.0f, 500.0f, 0.00999999978f);
		ui_interface->declare(&fHbargraph0, "01", "");
		ui_interface->addHorizontalBargraph("Treble rotation angle", &fHbargraph0, -3.14159274f, 3.14159274f);
		ui_interface->declare(&fHslider3, "1", "");
		ui_interface->addHorizontalSlider("Treble radius (cm)", &fHslider3, 20.0f, 5.0f, 70.0f, 0.00999999978f);
		ui_interface->declare(&fHslider5, "2", "");
		ui_interface->addHorizontalSlider("Mics distance (deg)", &fHslider5, 90.0f, 0.0f, 180.0f, 0.00999999978f);
		ui_interface->declare(&fHslider6, "3", "");
		ui_interface->addHorizontalSlider("Treble AM depth", &fHslider6, 1.0f, 0.0f, 10.0f, 0.00999999978f);
		ui_interface->declare(&fHslider7, "4", "");
		ui_interface->addHorizontalSlider("Treble LPF center freq (Hz)", &fHslider7, 1500.0f, 500.0f, 3000.0f, 0.00999999978f);
		ui_interface->declare(&fHslider8, "5", "");
		ui_interface->addHorizontalSlider("Treble LPF depth (oct.)", &fHslider8, 1.0f, 0.0f, 4.0f, 0.00999999978f);
		ui_interface->declare(&fHslider9, "6", "");
		ui_interface->addHorizontalSlider("Horn resonance freq (Hz)", &fHslider9, 2000.0f, 1000.0f, 3000.0f, 0.00999999978f);
		ui_interface->declare(&fHslider0, "999", "");
		ui_interface->addHorizontalSlider("Treble mix (%)", &fHslider0, 100.0f, 0.0f, 100.0f, 0.00999999978f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (0.00100000005f * float(fHslider0));
		float fSlow1 = (0.00100000005f * float(fHslider1));
		float fSlow2 = (0.00100000005f * float(fHslider2));
		float fSlow3 = (0.00100000005f * float(fHslider3));
		float fSlow4 = (0.00100000005f * float(fHslider4));
		float fSlow5 = (0.00100000005f * float(fHslider5));
		float fSlow6 = (0.00100000005f * float(fHslider6));
		float fSlow7 = (0.00100000005f * float(fHslider7));
		float fSlow8 = (0.00100000005f * float(fHslider8));
		float fSlow9 = (0.00100000005f * float(fHslider9));
		float fSlow10 = (0.00100000005f * float(fHslider10));
		float fSlow11 = (0.00100000005f * float(fHslider11));
		float fSlow12 = (0.00100000005f * float(fHslider12));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow0 + (0.999000013f * fRec0[1]));
			fRec3[0] = (fSlow1 + (0.999000013f * fRec3[1]));
			float fTemp0 = std::tan((fConst1 * fRec3[0]));
			float fTemp1 = Dsp_faustpower2_f(fTemp0);
			float fTemp2 = (0.0f - (2.0f / fTemp1));
			fRec7[0] = (fSlow2 + (0.999000013f * fRec7[1]));
			float fTemp3 = std::max<float>(-1.0f, std::min<float>(1.0f, ((std::pow(10.0f, (0.0199999996f * fRec7[0])) * float(input0[i])) + 0.100000001f)));
			float fTemp4 = (fTemp3 * (1.0f - (0.333333343f * Dsp_faustpower2_f(fTemp3))));
			fVec0[0] = fTemp4;
			fRec6[0] = (((0.995000005f * fRec6[1]) + fTemp4) - fVec0[1]);
			float fTemp5 = (1.0f / fTemp0);
			float fTemp6 = (((fTemp5 + -1.41421354f) / fTemp0) + 1.0f);
			float fTemp7 = (1.0f - (1.0f / fTemp1));
			float fTemp8 = (((fTemp5 + 1.41421354f) / fTemp0) + 1.0f);
			fRec5[0] = (fRec6[0] - (((fRec5[2] * fTemp6) + (2.0f * (fRec5[1] * fTemp7))) / fTemp8));
			fRec4[0] = (((((fRec5[1] * fTemp2) + (fRec5[0] / fTemp1)) + (fRec5[2] / fTemp1)) - ((fTemp6 * fRec4[2]) + (2.0f * (fTemp7 * fRec4[1])))) / fTemp8);
			float fTemp9 = ((((fTemp2 * fRec4[1]) + (fRec4[0] / fTemp1)) + (fRec4[2] / fTemp1)) / fTemp8);
			fVec1[(IOTA & 16383)] = fTemp9;
			fRec8[0] = (fSlow3 + (0.999000013f * fRec8[1]));
			float fTemp10 = Dsp_faustpower2_f(fRec8[0]);
			fRec10[0] = (fSlow4 + (0.999000013f * fRec10[1]));
			float fTemp11 = (fRec9[1] + (fConst3 * fRec10[1]));
			fRec9[0] = (fTemp11 - std::floor(fTemp11));
			fHbargraph0 = FAUSTFLOAT((3.14159274f * ((2.0f * fRec9[0]) + -1.0f)));
			fRec11[0] = (fSlow5 + (0.999000013f * fRec11[1]));
			float fTemp12 = (0.00872664619f * fRec11[0]);
			float fTemp13 = (fHbargraph0 - fTemp12);
			float fTemp14 = std::sqrt((fTemp10 * (Dsp_faustpower2_f((std::cos(fTemp13) + 1.0f)) + Dsp_faustpower2_f((std::sin(fTemp13) + 1.0f)))));
			float fTemp15 = (fConst2 * fTemp14);
			int iTemp16 = int(fTemp15);
			float fTemp17 = std::floor(fTemp15);
			fRec12[0] = (fSlow6 + (0.999000013f * fRec12[1]));
			float fTemp18 = (1.41421354f - (fTemp14 / fRec8[0]));
			fRec13[0] = (fSlow7 + (0.999000013f * fRec13[1]));
			fRec14[0] = (fSlow8 + (0.999000013f * fRec14[1]));
			float fTemp19 = std::tan((fConst1 * (fRec13[0] * std::pow(2.0f, (fRec14[0] * fTemp18)))));
			float fTemp20 = (1.0f / fTemp19);
			float fTemp21 = (((fTemp20 + 1.41421354f) / fTemp19) + 1.0f);
			fRec2[0] = ((((fVec1[((IOTA - std::min<int>(10001, std::max<int>(0, iTemp16))) & 16383)] * (fTemp17 + (1.0f - fTemp15))) + ((fTemp15 - fTemp17) * fVec1[((IOTA - std::min<int>(10001, std::max<int>(0, (iTemp16 + 1)))) & 16383)])) * std::pow(10.0f, (0.0500000007f * (fRec12[0] * fTemp18)))) - (((fRec2[2] * (((fTemp20 + -1.41421354f) / fTemp19) + 1.0f)) + (2.0f * (fRec2[1] * (1.0f - (1.0f / Dsp_faustpower2_f(fTemp19)))))) / fTemp21));
			fRec15[0] = (fSlow9 + (0.999000013f * fRec15[1]));
			float fTemp22 = std::tan((fConst1 * fRec15[0]));
			float fTemp23 = (1.0f / fTemp22);
			float fTemp24 = std::sin((fConst5 * fRec15[0]));
			float fTemp25 = (fConst4 / fTemp24);
			float fTemp26 = (((fTemp23 - fTemp25) / fTemp22) + 1.0f);
			float fTemp27 = (1.0f - (1.0f / Dsp_faustpower2_f(fTemp22)));
			float fTemp28 = (2.0f * (fRec1[1] * fTemp27));
			float fTemp29 = (((fTemp23 + fTemp25) / fTemp22) + 1.0f);
			fRec1[0] = (((fRec2[2] + (fRec2[0] + (2.0f * fRec2[1]))) / fTemp21) - (((fRec1[2] * fTemp26) + fTemp28) / fTemp29));
			float fTemp30 = (fConst6 / fTemp24);
			float fTemp31 = (((fTemp23 + fTemp30) / fTemp22) + 1.0f);
			float fTemp32 = (((fTemp23 - fTemp30) / fTemp22) + 1.0f);
			fRec16[0] = (fSlow10 + (0.999000013f * fRec16[1]));
			fRec19[0] = (((fRec5[2] + (fRec5[0] + (2.0f * fRec5[1]))) - ((fTemp6 * fRec19[2]) + (2.0f * (fTemp7 * fRec19[1])))) / fTemp8);
			fRec18[0] = (((fRec19[2] + (fRec19[0] + (2.0f * fRec19[1]))) / fTemp8) - (fConst9 * ((fConst12 * fRec18[2]) + (fConst13 * fRec18[1]))));
			fRec17[0] = (fConst9 * ((((fConst11 * fRec18[0]) + (fConst14 * fRec18[1])) + (fConst11 * fRec18[2])) - ((fConst12 * fRec17[2]) + (fConst13 * fRec17[1]))));
			fRec20[0] = (fSlow11 + (0.999000013f * fRec20[1]));
			fRec22[0] = (fSlow12 + (0.999000013f * fRec22[1]));
			float fTemp33 = (fRec21[1] + (fConst3 * fRec22[1]));
			fRec21[0] = (fTemp33 - std::floor(fTemp33));
			fHbargraph1 = FAUSTFLOAT((3.14159274f * ((2.0f * fRec21[0]) + -1.0f)));
			fRec23[0] = (fConst9 * ((fRec18[2] + (fRec18[0] + (2.0f * fRec18[1]))) - ((fConst12 * fRec23[2]) + (fConst13 * fRec23[1]))));
			float fTemp34 = (fRec16[0] * (((0.0f - (fConst9 * (((fConst11 * fRec17[0]) + (fConst14 * fRec17[1])) + (fConst11 * fRec17[2])))) * std::pow(10.0f, (0.0500000007f * (fRec20[0] * (1.41421354f - std::sqrt((Dsp_faustpower2_f((std::cos(fHbargraph1) + 1.0f)) + Dsp_faustpower2_f((std::sin(fHbargraph1) + 1.0f))))))))) + (fConst9 * (fRec23[2] + (fRec23[0] + (2.0f * fRec23[1]))))));
			output0[i] = FAUSTFLOAT((0.00999999978f * (((fRec0[0] * ((fTemp28 + (fRec1[0] * fTemp31)) + (fRec1[2] * fTemp32))) / fTemp29) + fTemp34)));
			float fTemp35 = (fHbargraph0 + fTemp12);
			float fTemp36 = std::sqrt((fTemp10 * (Dsp_faustpower2_f((std::cos(fTemp35) + 1.0f)) + Dsp_faustpower2_f((std::sin(fTemp35) + 1.0f)))));
			float fTemp37 = (fConst2 * fTemp36);
			int iTemp38 = int(fTemp37);
			float fTemp39 = std::floor(fTemp37);
			float fTemp40 = (1.41421354f - (fTemp36 / fRec8[0]));
			float fTemp41 = std::tan((fConst1 * (fRec13[0] * std::pow(2.0f, (fRec14[0] * fTemp40)))));
			float fTemp42 = (1.0f / fTemp41);
			float fTemp43 = (((fTemp42 + 1.41421354f) / fTemp41) + 1.0f);
			fRec25[0] = ((((fVec1[((IOTA - std::min<int>(10001, std::max<int>(0, iTemp38))) & 16383)] * (fTemp39 + (1.0f - fTemp37))) + ((fTemp37 - fTemp39) * fVec1[((IOTA - std::min<int>(10001, std::max<int>(0, (iTemp38 + 1)))) & 16383)])) * std::pow(10.0f, (0.0500000007f * (fRec12[0] * fTemp40)))) - (((fRec25[2] * (((fTemp42 + -1.41421354f) / fTemp41) + 1.0f)) + (2.0f * (fRec25[1] * (1.0f - (1.0f / Dsp_faustpower2_f(fTemp41)))))) / fTemp43));
			float fTemp44 = (2.0f * (fTemp27 * fRec24[1]));
			fRec24[0] = (((fRec25[2] + (fRec25[0] + (2.0f * fRec25[1]))) / fTemp43) - (((fTemp26 * fRec24[2]) + fTemp44) / fTemp29));
			output1[i] = FAUSTFLOAT((0.00999999978f * (fTemp34 + ((fRec0[0] * ((fTemp44 + (fRec24[0] * fTemp31)) + (fTemp32 * fRec24[2]))) / fTemp29))));
			fRec0[1] = fRec0[0];
			fRec3[1] = fRec3[0];
			fRec7[1] = fRec7[0];
			fVec0[1] = fVec0[0];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1];
			fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1];
			fRec4[1] = fRec4[0];
			IOTA = (IOTA + 1);
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec14[1] = fRec14[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec15[1] = fRec15[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fRec16[1] = fRec16[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fRec17[2] = fRec17[1];
			fRec17[1] = fRec17[0];
			fRec20[1] = fRec20[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec23[2] = fRec23[1];
			fRec23[1] = fRec23[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			
		}
		
	}

	
};

#endif
