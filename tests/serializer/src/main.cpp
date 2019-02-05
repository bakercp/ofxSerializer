//
// Copyright (c) 2019 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:    MIT
//


#include "ofMain.h"
#include "ofAppNoWindow.h"
#include "ofxUnitTests.h"
#include "ofSerializer.h"


#define test_enum_json(e) ofxTest(e == ofJson(e), "e");

class ofApp: public ofxUnitTestsApp
{
    void run() override
    {
        {
            ofRectangle r0(1, 2, 3, 4);
            ofRectangle r1 = ofJson(r0);
            ofxTestEq(r0, r1, "ofRectangle");
        }
        
        {
            glm::vec2 r0(1, 2);
            ofxTestEq(r0, ofJson(r0), "glm::vec2");
        }
        
        {
            glm::vec3 r0(1, 2, 3);
            ofxTestEq(r0, ofJson(r0), "glm::vec3");
        }
        
        {
            glm::vec4 r0(1, 2, 3, 4);
            ofxTestEq(r0, ofJson(r0), "glm::vec4");
        }
        
        {
            glm::mat3 r0 = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
            ofxTestEq(r0, ofJson(r0), "glm::mat3");
        }
        
        {
            glm::mat4 r0 = {{ 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 }};
            ofxTestEq(r0, ofJson(r0), "glm::mat4");
        }
        
        {
            ofColor r0 = ofColor::fromHsb(ofRandom(255), ofRandom(255), ofRandom(255));
            ofColor r1 = ofJson(r0).get<ofColor>();
            ofxTestEq(r0, r1, "ofColor");
        }
        
        {
            ofPolyline r0;
            for (std::size_t i = 0; i < 100; ++i)
                r0.addVertex(glm::vec3(ofRandom(1.0),
                                       ofRandom(1.0),
                                       ofRandom(1.0)));
            ofPolyline r1 = ofJson(r0).get<ofPolyline>();
            
            for (std::size_t i = 0; i < r0.size(); ++i)
                assert(r0[i] == r1[i]);
            
            ofxTestEq(r0.isClosed(), r1.isClosed(), "ofPolyline");
        }
        
        {
            test_enum_json(OF_LOG_VERBOSE);
            test_enum_json(OF_LOG_NOTICE);
            test_enum_json(OF_LOG_WARNING);
            test_enum_json(OF_LOG_ERROR);
            test_enum_json(OF_LOG_FATAL_ERROR);
            test_enum_json(OF_LOG_SILENT);
        }

        {
            test_enum_json(OF_WINDOW);
            test_enum_json(OF_FULLSCREEN);
            test_enum_json(OF_GAME_MODE);
        }
        {
            ofWindowSettings r0;
            r0.setSize(40, 20);
            r0.setPosition({ 30.3, 60.6 });
            r0.windowMode = OF_FULLSCREEN;
            ofWindowSettings r1 = ofJson(r0);
            ofxTestEq(r0.getWidth(), r1.getWidth(), "ofWindowMode::getWidth()");
            ofxTestEq(r0.getHeight(), r1.getHeight(), "ofWindowMode::getHeight()");
            ofxTestEq(r0.getPosition(), r1.getPosition(), "ofWindowMode::getPosition()");
            ofxTestEq(r0.title, r1.title, "ofWindowMode::title");
            ofxTestEq(r0.windowMode, r1.windowMode, "ofWindowMode::windowMode");
        }
    }
};


int main()
{
	ofInit();
	auto window = make_shared<ofAppNoWindow>();
	auto app = make_shared<ofApp>();
	ofRunApp(window, app);
	return ofRunMainLoop();
}
