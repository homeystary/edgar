#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sampleNumber = 0;
    gui.setup();
    gui.setSize(ofGetScreenWidth()/1.5, ofGetScreenHeight());
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            gui.add(influenceSlider[i][j].setup(std::to_string(i + 1) + " to " + std::to_string(j + 1) + " influence" , 0.0000001f, 0.0000001f, 1.0f));
        }
    }
    for(int i = 0; i < 8; i++) {
        gui.add(volumeSlider[i].setup("volume " + std::to_string(i + 1), 1.0f, 0.0f, 1.0f));
    }
    
    gui.add(speedSlider.setup("sample length", 1.0f, 0.1f, 1.0f));
    gui.add(startToggle.setup("on/off", false));
    for(int i = 4; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            influenceSlider[i][j].setPosition(250, ((i-4) * 152) + 19 * j + 30) ;
        }
    }
    for(int i = 0; i < 8; i++) {
        volumeSlider[i].setPosition(500, 19 * i + 68);
    }
    
    speedSlider.setPosition(500, 30);
    startToggle.setPosition(500, 258);
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    if(startToggle) {
        if(!isPlaying) {
            sampleNumber = holder;
            for(int i = 0; i < 8; i++) {
                if(sampleNumber == i) {
                    samplePlayer.setVolume(volumeSlider[i]);
                }
            }
            samplePlayer.load(std::to_string(sampleNumber) + ".wav");
            samplePlayer.setPosition(0.0f);
            samplePlayer.play();
            safeguardCount = 0;
        }
        if(samplePlayer.getPosition() > 0.92f * speedSlider) {
            isPlaying = false;
            
            for(int i = 0; i < 8; i++) {
                w = 0;
                sum[i] = 0;
                for(int j = 0; j < 8; j++) {
                    sum[i] = sum[i] + influenceSlider[i][j];
                }
                x = ofRandom(sum[i]);
                if(sampleNumber == i) {
                    /*for(int j = 0; j < 8; j++) {
                        if(x >= w && x < w + influenceSlider[i][j]) {
                            holder = j;
                            w = w + influenceSlider[i][j];
                        }
                     //THIS FOR LOOP DOESN'T WORK IN THE DESIRED WAY (ALL LOW NUMBERS LOOPS ACTIVE SAMPLE)
                    }*/
                    
                    //LONG WAY:
                    if(x < influenceSlider[i][0]) {
                        holder = 0;
                    }
                    if(x >= influenceSlider[i][0] && x < (influenceSlider[i][0] + influenceSlider[i][1])) {
                        holder = 1;
                    }
                    if(x >= (influenceSlider[i][0] + influenceSlider[i][1]) && x < (influenceSlider[i][0] + influenceSlider[i][1] + influenceSlider[i][2])) {
                        holder = 2;
                    }
                    if(x >= (influenceSlider[i][0] + influenceSlider[i][1] + influenceSlider[i][2]) && x < (influenceSlider[i][0] + influenceSlider[i][1] + influenceSlider[i][2] + influenceSlider[i][3])) {
                        holder = 3;
                    }
                    if(x >= (influenceSlider[i][0] + influenceSlider[i][1] + influenceSlider[i][2] + influenceSlider[i][3]) && x < (influenceSlider[i][0] + influenceSlider[i][1] + influenceSlider[i][2] + influenceSlider[i][3] + influenceSlider[i][4])) {
                        holder = 4;
                    }
                    if(x >= (influenceSlider[i][0] + influenceSlider[i][1] + influenceSlider[i][2] + influenceSlider[i][3] + influenceSlider[i][4]) && x < (influenceSlider[i][0] + influenceSlider[i][1] + influenceSlider[i][2] + influenceSlider[i][3] + influenceSlider[i][4] + influenceSlider[i][5])) {
                        holder = 5;
                    }
                    if(x >= (influenceSlider[i][0] + influenceSlider[i][1] + influenceSlider[i][2] + influenceSlider[i][3] + influenceSlider[i][4] + influenceSlider[i][5]) && x < (influenceSlider[i][0] + influenceSlider[i][1] + influenceSlider[i][2] + influenceSlider[i][3] + influenceSlider[i][4] + influenceSlider[i][5] + influenceSlider[i][6])) {
                        holder = 6;
                    }
                    if(x >= (influenceSlider[i][0] + influenceSlider[i][1] + influenceSlider[i][2] + influenceSlider[i][3] + influenceSlider[i][4] + influenceSlider[i][5] + influenceSlider[i][6])) {
                        holder = 7;
                    }
                }
            }
        }
        
        if(samplePlayer.getPosition() <= 0.92f * speedSlider) {
            isPlaying = true;
            safeguardCount++;
        }
        if(safeguardCount > 200) {
            isPlaying = false;
        }
    }
    if(!startToggle) {
        isPlaying = false;
    }
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
