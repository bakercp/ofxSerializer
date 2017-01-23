//
// Copyright (c) 2017 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofApp.h"


void ofApp::setup()
{
    ofRectangle rect(1, 2, 3, 4);
    ofJson rectJson = ofx::serialize(rect);
    ofRectangle r = ofx::deserialize<ofRectangle>(rectJson);
    std::cout << r << std::endl;

    ofWindowSettings windowSettings;
    windowSettings.setPosition(ofVec2f(25, 25));
    std::cout << ofx::serialize(windowSettings).dump(4) << std::endl;

    {
        ofVec2f vec(1, 2);
        std::cout << ofx::serialize(vec).dump(4) << std::endl;
    }

    {
        glm::vec2 vec(3, 4);
        std::cout << ofx::serialize(vec).dump(4) << std::endl;
    }


    ofPolyline polyline;
    polyline.addVertex(0, 1, 2);
    polyline.addVertex(1, 2, 3);
    polyline.addVertex(2, 3, 4);
    polyline.addVertex(4, 5, 6);

    ofJson polylineJson = ofx::serialize(polyline);

    std::cout << polylineJson.dump(4) << std::endl;

    ofPolyline p = ofx::deserialize<ofPolyline>(polylineJson);

    for (const auto& vertex: p)
    {
        std::cout << vertex << std::endl;
    }

}
