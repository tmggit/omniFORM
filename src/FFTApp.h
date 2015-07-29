//
//  FFTApp.h
//  TMG Shape Displays
//
//  Created by Luke Vink on 7/28/15.
//  Copyright 2015 MIT Media Lab. All rights reserved.
//

#pragma once

#include "Application.h"
#include "fft.h"

#define BUFFER_SIZE 64
#define NUM_WINDOWS 128

class FFTApp : public Application {

public:
    
    FFTApp(KinectManager *manager);

    void update(float dt);
    void drawGraphicsForShapeDisplay();
    void keyPressed(int key);

    string getName() {return "FFT BOS Visualizer";};
    string appInstructionsText();

    void drawDebugGui(int x, int y);
    void setBaseApp(ofBaseApp *_baseApp);
    void exit();

    void audioReceived 	(float *input, int bufferSize, int nChannels);
   
    ofSoundStream soundStream;

   
private:
    
    ofBaseApp *baseApp;
    
    void drawFFT();
    void updateWaveParametersWithKinect();
    void generateWave();
    void convertTouchToWave();
    void updateScaleParametersWithKinect();

    float normalizedPhase = 0;
    float frequency;
    float numCrests;
    bool bosEnabled = true;
    float scaler = 100.0;

    ofColor color;
    
    //FFT Parameters
    float  *left;
    float  *right;
    int     bufferCounter;
    fft		myfft;
    
    float magnitude[BUFFER_SIZE];
    float phase[BUFFER_SIZE];
    float power[BUFFER_SIZE];
    
    float freq[NUM_WINDOWS][BUFFER_SIZE/2];
    float freq_phase[NUM_WINDOWS][BUFFER_SIZE/2];
    
    //Shape Display FFT Shift Parameters
    int spectrogramMemory[SHAPE_DISPLAY_SIZE_X][SHAPE_DISPLAY_SIZE_Y] = {0};
    int currentRow = 0;
    
};