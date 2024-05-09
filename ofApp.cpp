#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 1.44);

	for (int deg = 0; deg < 360; deg += 5) {

		ofPushMatrix();
		ofRotate(deg);
		ofTranslate(glm::vec2(0, 250));

		auto rotate_deg = ofMap(ofNoise(deg * 0.05 + ofGetFrameNum() * 0.02), 0, 1, -360, 360);
		ofRotateX(rotate_deg);

		ofDrawLine(glm::vec2(0, -10), glm::vec2(0, -50));
		ofDrawLine(glm::vec2(0, 10), glm::vec2(0, 50));
		ofDrawSphere(glm::vec3(), 3);

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 0;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}