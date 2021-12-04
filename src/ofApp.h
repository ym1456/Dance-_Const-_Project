#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void drawPicture();
		void timer();
		ofSoundPlayer sound;
		ofImage image[10];

		string name;
		int cellsize;
		int cols, rows;
		int x, y, zpos;
		float a;
		int index;
		int zBright;
		int value;
		float nextCall;

		bool bRecording = false;

		float randomV[17700];
		float randomA[17700];

};
