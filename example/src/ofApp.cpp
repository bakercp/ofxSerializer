//
// Copyright (c) 2017 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


void ofApp::setup()
{
    {
        ofRectangle r0(1, 2, 3, 4);
        ofRectangle r1 = ofJson(r0).get<ofRectangle>();
        assert(r0 == r1);
    }
    
    {
        glm::vec2 r0(1, 2);
        glm::vec2 r1 = ofJson(r0).get<glm::vec2>();
        assert(r0 == r1);
    }

    {
        glm::vec3 r0(1, 2, 3);
        glm::vec3 r1 = ofJson(r0).get<glm::vec3>();
        assert(r0 == r1);
    }

    {
        glm::vec4 r0(1, 2, 3, 4);
        glm::vec4 r1 = ofJson(r0).get<glm::vec4>();
        assert(r0 == r1);
    }

    {
        glm::mat3 r0 = {{ 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
        glm::mat3 r1 = ofJson(r0).get<glm::mat3>();
        assert(r0 == r1);
    }

    {
        glm::mat4 r0 = {{ 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 }};
        glm::mat4 r1 = ofJson(r0).get<glm::mat4>();
        assert(r0 == r1);
    }
    
    {
        ofColor r0 = ofColor::fromHsb(ofRandom(255), ofRandom(255), ofRandom(255));
        ofColor r1 = ofJson(r0).get<ofColor>();
        assert(r0 == r1);
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
        assert(r0.isClosed() == r1.isClosed());
    }


}
