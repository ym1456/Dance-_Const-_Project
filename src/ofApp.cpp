#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sound.load("sound.wav");
	sound.play();

	ofBackground(255);
	ofSetFrameRate(30);

	value = 0;
	cellsize = 3;
	index = 0;
	a = 255;
	zpos = -300;
	nextCall = 0;
	name = { "***sangHyeok***" };
	
	for (int i = 0; i < 10; i++)
	{
		image[i].loadImage("image" + ofToString(i) + ".jpg");
		cols = image[i].getWidth() / cellsize;
		rows = image[i].getHeight() / cellsize;
	}
	
	for (int i = 0; i < 17700; i++)
	{
		randomA[i] = 0;
		randomV[i] = ofRandom(-2,2);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	zpos += 0.1;
	a -= 1.1; // alpha

	if (a < 35 && index!=9) {
		for (int i = 0; i < 17700; i++)
		{
			randomA[i] -= randomV[i];
		}
	}

	timer();
}

//--------------------------------------------------------------
void ofApp::draw(){
	drawPicture();
	ofSetColor(0, 200, 120);
	ofDrawBitmapString(name, 10, 10);
	ofDrawBitmapString(ofToString((int)ofGetFrameRate()), 10, 25);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::drawPicture() {
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			value += 0.1;
			x = i * cellsize + cellsize / 2;
			y = j * cellsize + cellsize / 2;

			ofColor c = image[index].getColor(x, y);
			ofColor c1(255, 255, 255);
			zBright = c.getBrightness() * sin(0.2 +  ofGetElapsedTimef() * 0.038) * 4;
			float z = ofMap(c.getBrightness(), 0, 255, 0, mouseX);

			ofPushMatrix();
			ofTranslate(ofGetWidth() / 2 - image[index].getWidth() / 2, ofGetHeight() / 2 - image[index].getHeight() / 2);
			ofTranslate(x, y, zBright);
			ofSetColor(c,a);
			ofSetRectMode(OF_RECTMODE_CENTER);
			ofDrawRectangle(randomA[i*j + i], randomA[i*j + j], zpos, cellsize, cellsize);
			ofPopMatrix();
		}
	}
}

void ofApp::timer() {
	if (nextCall < ofGetElapsedTimef()) {
		nextCall = ofGetElapsedTimef() + 7.75;

		for (int i = 0; i < 17700; i++)
		{
			randomA[i] = 0;
		}

		zpos = -300;
		a = 255;

		index += 1;
		if (index > 9) {
			index = 9;
			a = 0;
		}
	}


}