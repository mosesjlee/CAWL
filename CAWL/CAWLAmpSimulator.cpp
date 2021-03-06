//
//  CAWLAmpSimulator.cpp
//  cawlTester
//
//  Created by Moses Lee on 9/24/17.
//  Copyright © 2017 Moses Lee. All rights reserved.
//

#include "CAWLAmpSimulator.hpp"

#define N 3

/*
 This struct below is from CAPS written Tim Goetze and David Yeh. This struct
 is a container for Thiele and Small parameters for the different cabinet
 designs. This is not my work.
 */
typedef struct {
    double R1, R2, R3, R4;
    double C1, C2, C3;
} TSParameters;

/*
 This class below is from CAPS written Tim Goetze and David Yeh.
 This is not my work. I only modified the process function to fit my design
 */
class TDFII
{
public:
    double a[N+1];
    double b[N+1];
    double h[N+1];
    
    void reset()
    {
        for (int i = 0; i <= N; ++i)
            h[i] = 0;   // zero state
    }
    
    void init (double fs)
    {
        reset();
        clear();
    }
    
    void clear()
    {
        for (int i=0; i<= N; i++)
            a[i] = b[i] = 0;
        b[0] = 1;
    }
    
    /* per-band recursion:
     *     y = 2 * (a * (x - x[-2]) + c * y[-1] - b * y[-2])
     */
    void process (float * buf, const unsigned int numSamples)
    {
        for(unsigned j = 0; j < numSamples; j++)
        {
            float s = buf[j];
            double y = h[0] + b[0]*s;
            for (int i=1; i<N; ++i)
                h[i-1] = h[i] + b[i]*s - a[i]*y;

            h[N-1] = b[N]*s - a[N]*y;
            
            buf[j] = (float) y;
        }
    }
};

/*
 This class below is from CAPS written Tim Goetze and David Yeh.
 This is not my work. I modified the process function, and the init functions
 to fit my design
 */

#define k *1e3
#define M *1e6
#define nF *1e-9
#define pF *1e-12
TSParameters fender = {250 k, 1 M, 25 k, 56 k, 250 pF, 20 nF, 20 nF}  /* 59 Bassman 5F6-A */;
TSParameters voxAC30 = {1 M, 1 M, 20 k, 100 k, 50 pF, 22 nF, 22 nF};
TSParameters princeton = {250 k, 250 k, 4.8 k, 100 k, 250 pF, 100 nF, 47 nF};
class ToneStack
{
private:
    double c;   // BT coef
    
    double b1t, b1m, b1l, b1d,
    b2t, b2m2, b2m, b2l, b2lm, b2d,
    b3lm, b3m2, b3m, b3t, b3tm, b3tl,
    a0, a1d, a1m, a1l, a2m, a2lm, a2m2, a2l, a2d,
    a3lm, a3m2, a3m, a3l, a3d;      // intermediate calculations
    
    double fs;
    TDFII filter;
    
public:
    /* in ../ToneStack.cc */
    static const char * presetdict;
	static TSParameters presets[];
    
    ToneStack()
    {
        setmodel(0);
    }
    
    ToneStack(TSParameters & p)
    {
        setparams(p);
    }
    
    void init (double _fs)
    {
        c = 2 * _fs;
    }
    
    void reset() { filter.reset(); }
    void setmodel (int model)
    {
        //setparams (presets[model]);
		//setparams (fender);
        filter.reset();
        filter.clear();
    }
    
    void setparams (TSParameters & p)
    {
        double R1 = p.R1, R2 = p.R2, R3 = p.R3, R4 = p.R4;
        double C1 = p.C1, C2 = p.C2, C3 = p.C3;
        
        b1t  = C1*R1;
        b1m  = C3*R3;
        b1l  = C1*R2 + C2*R2;
        b1d  = C1*R3 + C2*R3;
        b2t  = C1*C2*R1*R4 + C1*C3*R1*R4;
        b2m2 = -(C1*C3*R3*R3 + C2*C3*R3*R3);
        b2m  = C1*C3*R1*R3 + C1*C3*R3*R3 + C2*C3*R3*R3;
        b2l  = C1*C2*R1*R2 + C1*C2*R2*R4 + C1*C3*R2*R4;
        b2lm = C1*C3*R2*R3 + C2*C3*R2*R3;
        b2d  = C1*C2*R1*R3 + C1*C2*R3*R4 + C1*C3*R3*R4;
        b3lm = C1*C2*C3*R1*R2*R3 + C1*C2*C3*R2*R3*R4;
        b3m2 = -(C1*C2*C3*R1*R3*R3 + C1*C2*C3*R3*R3*R4);
        b3m  = C1*C2*C3*R1*R3*R3 + C1*C2*C3*R3*R3*R4;
        b3t  = C1*C2*C3*R1*R3*R4;
        b3tm = -b3t;
        b3tl = C1*C2*C3*R1*R2*R4;
        a0   = 1;
        a1d  = C1*R1 + C1*R3 + C2*R3 + C2*R4 + C3*R4;
        a1m  = C3*R3;
        a1l  = C1*R2 + C2*R2;
        a2m  = C1*C3*R1*R3 - C2*C3*R3*R4 + C1*C3*R3*R3 + C2*C3*R3*R3;
        a2lm = C1*C3*R2*R3 + C2*C3*R2*R3;
        a2m2 = -(C1*C3*R3*R3 + C2*C3*R3*R3);
        a2l  = C1*C2*R2*R4 + C1*C2*R1*R2 + C1*C3*R2*R4 + C2*C3*R2*R4;
        a2d  = C1*C2*R1*R4 + C1*C3*R1*R4 + C1*C2*R3*R4
        + C1*C2*R1*R3 + C1*C3*R3*R4 + C2*C3*R3*R4;
        a3lm = C1*C2*C3*R1*R2*R3 + C1*C2*C3*R2*R3*R4;
        a3m2 = -(C1*C2*C3*R1*R3*R3 + C1*C2*C3*R3*R3*R4);
        a3m  = C1*C2*C3*R3*R3*R4 + C1*C2*C3*R1*R3*R3 - C1*C2*C3*R1*R3*R4;
        a3l  = C1*C2*C3*R1*R2*R4;
        a3d  = C1*C2*C3*R1*R3*R4;
        
        filter.reset();
    }
    
    /* extensively reworked TG 5/2011 */
    inline void updatecoefs (double b, double m, double t)
    {
        struct {
            double a1, a2, a3;
            double b1, b2, b3;
        } acoef; // analog coefficients
        
        // digital coefficients
        double dcoef_a[N + 1];
        double dcoef_b[N + 1];
        
        m = (m - 1) * 3.5;
        m = pow (10, m);
        
        acoef.a1 = a1d + m*a1m + b*a1l;
        acoef.a2 = m*a2m + b*m*a2lm + m*m*a2m2 + b*a2l + a2d;
        acoef.a3 = b*m*a3lm + m*m*a3m2 + m*a3m + b*a3l + a3d;
        
        double c2 = c*c, c3 = c2*c;
        
        acoef.a1 *= c, acoef.a2 *= c2, acoef.a3 *= c3;
        
        dcoef_a[0] = -1 - acoef.a1 - acoef.a2 - acoef.a3; // sets scale
        dcoef_a[1] = -3 - acoef.a1 + acoef.a2 + 3*acoef.a3;
        dcoef_a[2] = -3 + acoef.a1 + acoef.a2 - 3*acoef.a3;
        dcoef_a[3] = -1 + acoef.a1 - acoef.a2 + acoef.a3;
        
        acoef.b1 = t*b1t + m*b1m + b*b1l + b1d;
        acoef.b2 = t*b2t + m*m*b2m2 + m*b2m + b*b2l + b*m*b2lm + b2d;
        acoef.b3 = b*m*b3lm + m*m*b3m2 + m*b3m + t*b3t + t*m*b3tm + t*b*b3tl;
        
        acoef.b1 *= c, acoef.b2 *= c2, acoef.b3 *= c3;
        
        dcoef_b[0] = - acoef.b1 - acoef.b2 - acoef.b3;
        dcoef_b[1] = - acoef.b1 + acoef.b2 + 3*acoef.b3;
        dcoef_b[2] = acoef.b1 + acoef.b2 - 3*acoef.b3;
        dcoef_b[3] = acoef.b1 - acoef.b2 + acoef.b3;
        
        double a0i = 1. / dcoef_a[0];
        for (int i=1; i<=3; ++i)
            filter.a[i] = dcoef_a[i] * a0i;
        
        for (int i=0; i<=3; ++i)
            filter.b[i] = dcoef_b[i] * a0i;
    }
    
    void process (float * buf, unsigned const int numSamples)
    {
        filter.process(buf, numSamples);
    }
};

ToneStack stack;
/*
 Below is my CAWLAmpSimulator class that uses the Valve Tube
 simulator to the preamp processing and the buffer is then sent
 to the ToneStack modeling process.
 */

/*
 Default constructor
 */
CAWLAmpSimulator::CAWLAmpSimulator()
{
    CAWLAmpSimulator(0);
}

/*
 Constructor that allows user to choose amp model
 @param model -> 0 for Fender, 1 for Vox, and 2 for princeton
 */
CAWLAmpSimulator::CAWLAmpSimulator(int model)
{
    if(model == 0) {
        stack = ToneStack(fender);
        std::cout << "fender" << std::endl;
    } else if (model == 1){
        stack = ToneStack(voxAC30);
        std::cout << "vox" << std::endl;
    } else {
        stack = ToneStack(princeton);
        std::cout << "princeton" << std::endl;
    }
	cAmpBass = 0.5;
	cAmpMid = 0.5;
	cAmpTreble = 0.5;
    stack.init(cSampleRate);
    lsf.setCenterFreq(720);
    hp1.setCenterFreq(120);
}

/*
 Default destructor
 */
CAWLAmpSimulator::~CAWLAmpSimulator()
{
}

/*
 Main processing block.
 @param audioStreambuf the buffer of audio stream in 32 bit float
 @param numSamples the number of samples in the buffer block
 */
void CAWLAmpSimulator::processBuffer(float *AudioStreamBuf, const unsigned int numOfSamples)
{
	//1st send it to be processed by the valve simulator
	//valveTube.processBuffer(AudioStreamBuf, numOfSamples);
    //hp1.processBuffer(AudioStreamBuf, numOfSamples);
//    lsf.processBuffer(buf, numOfSamples);

	//3rd send it to be processed by the tone stack
    stack.updatecoefs(cAmpBass, cAmpMid, cAmpTreble);
	stack.process(AudioStreamBuf, numOfSamples);
}

void CAWLAmpSimulator::setAmpModel(int model)
{
	if(model == 1)
	{
		stack.setparams(fender);
	}
	else if (model == 2)
	{
		stack.setparams(voxAC30);
	}
	else if (model == 3)
	{
		stack.setparams(princeton);
	}
}

/*
 Sets the gain for the tube simulator
 @param gain -> the gain of the valve tube
 */
void CAWLAmpSimulator::setGain(float gain)
{
    valveTube.setGain(gain);
}

/*
 */
void CAWLAmpSimulator::setAmpBass(double newBass)
{
	if(newBass > 1.0)
		cAmpBass = 1.0;
	else if (newBass < 0.0)
		cAmpBass = 0.0;
	else
		cAmpBass = newBass;
}

/*
 */
void CAWLAmpSimulator::setAmpMid(double newMid)
{
	if(newMid > 1.0)
		cAmpMid = 1.0;
	else if (newMid < 0.0)
		cAmpMid = 0.0;
	else
		cAmpMid = newMid;
}

/*
 */
void CAWLAmpSimulator::setAmpTreble(double newTreble)
{
	if(newTreble > 1.0)
		cAmpTreble = 1.0;
	else if (newTreble < 0.0)
		cAmpTreble = 0.0;
	else
		cAmpTreble = newTreble;
}

















