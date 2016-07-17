#include "ofApp.h"


void ofApp::setup()
{
    ofRectangle rect(1, 2, 3, 4);
    ofJson rectJson = ofx::serialize(rect);
    ofRectangle r = ofx::deserialize<ofRectangle>(rectJson);
//    std::cout << r << std::endl;

    ofWindowSettings windowSettings;
    windowSettings.setPosition(ofVec2f(25, 25));
    std::cout << ofx::serialize(windowSettings).dump(4) << std::endl;


}
