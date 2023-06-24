#include "ofApp.h"

std::string onnxModelStatus;
std::string inferenceResult;
bool onnxModelIsLoaded;

void onnx(std::string info, std::string inference) {
	if (info == "status") {  
		onnxModelStatus = "Onnx model loaded. Click into the rectangle.";
		onnxModelIsLoaded = true;
	} else if (info == "inference") {
		inferenceResult = inference;
	}
}

//--------------------------------------------------------------
EMSCRIPTEN_BINDINGS(Module){
	emscripten::function("onnx", &onnx);
}

//--------------------------------------------------------------
void ofApp::setup(){
	onnxModelIsLoaded = false;
	ofSetBackgroundColor(100, 100, 100);
	onnxModelStatus = "Onnx model loading.";
	EM_ASM(
		startOnnxSession();
	);
}
 
//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawBitmapString(onnxModelStatus, 20, 20);
	ofDrawBitmapString(inferenceResult, 20, 40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (onnxModelIsLoaded) {
		EM_ASM(onnxInference());
	}
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
