//
//  VideoApp.h
//  omniFORM
//
//  Created by Jared Counts on 9/22/15.
//
//

#pragma once

#include "Application.h"

class VideoApp : public Application {
public:
    VideoApp(string filepath);
    ~VideoApp();
    
    void update(float dt);
    void drawGraphicsForShapeDisplay(int x, int y, int width, int height);
    string appInstructionsText();
    void keyPressed(int key);
    
    string getName() {return "Video";};
    
private:
    void drawDebugGui(int x, int y);
    
    float heightvideoPaused = 0;
    float imagevideoPaused = 0;

    ofVideoPlayer heightvideo;
    ofVideoPlayer imagevideo;

};