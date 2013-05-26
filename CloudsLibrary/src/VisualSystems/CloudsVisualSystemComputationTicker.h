#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "CloudsVisualSystemRezanator.h"

/** 
 * COMPUTATION visual system
 * shows ticker tape strands running in fields
 * that can be zoomed in and diverted
 */

class CloudsVisualSystemComputationTicker : public CloudsVisualSystemRezanator {
  public:

	string getSystemName();
    
    void selfSetup();
    void selfSetupGuis();
    
    void selfAutoMode();
    void selfUpdate();
    void selfDrawBackground();
    void selfDrawDebug();
    void selfSceneTransformation();
    void selfDraw();
    void selfExit();
    void selfBegin();
	void selfEnd();
    
    void selfKeyPressed(ofKeyEventArgs & args);
    void selfKeyReleased(ofKeyEventArgs & args);
    
    void selfMouseDragged(ofMouseEventArgs& data);
    void selfMouseMoved(ofMouseEventArgs& data);
    void selfMousePressed(ofMouseEventArgs& data);
    void selfMouseReleased(ofMouseEventArgs& data);
    
    void selfSetupGui();
    void selfGuiEvent(ofxUIEventArgs &e);
    
    void selfSetupSystemGui();
    void guiSystemEvent(ofxUIEventArgs &e);
    
    void selfSetupRenderGui();
    void guiRenderEvent(ofxUIEventArgs &e);
	
  protected:

	int width, height;
	ofVboMesh mesh;
	vector<int> startIndeces;

	void regenerateParticles();
		
	ofImage speedTexture;
	ofImage shiftTexture;
	
	void reloadShaders();
	ofShader updateShader;
	ofShader drawShader;
	
	ofVboMesh offsetMesh;
	ofFbo sourceOffset,targetOffset;
	
	ofFbo fbo;
	
	float pathDeviation;
	
	float speed;
	float scale;
	float pointSize;
	float deviation;
	float colorflip;
	
	bool debug;
	bool regenerate;
};