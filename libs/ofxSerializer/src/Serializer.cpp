//
// Copyright (c) 2017 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofxSerializer.h"
#include "ofLog.h"
#include "ofRectangle.h"
#include "ofWindowSettings.h"


namespace ofx {


template<>
ofRectangle deserialize(const ofJson& json)
{
    return ofRectangle(json["x"], json["y"], json["width"], json["height"]);
}


template<>
ofJson serialize(const ofRectangle& value)
{
    return ofJson {
        { "x", value.x },
        { "y", value.y },
        { "width", value.width },
        { "height", value.height }
    };
}


template<>
ofVec2f deserialize(const ofJson& json)
{
    return ofVec2f(json["x"], json["y"]);
}


template<>
ofJson serialize(const ofVec2f& value)
{
    return ofJson {{ "x", value.x }, { "y", value.y }};
}


template<>
ofVec3f deserialize(const ofJson& json)
{
    return ofVec3f(json["x"], json["y"], json["z"]);
}


template<>
ofJson serialize(const ofVec3f& value)
{
    return ofJson {{ "x", value.x }, { "y", value.y }, { "z", value.z }};
}


std::string toString(ofLogLevel level)
{
    switch (level)
    {
        case OF_LOG_VERBOSE: return "OF_LOG_VERBOSE";
        case OF_LOG_NOTICE: return "OF_LOG_NOTICE";
        case OF_LOG_WARNING: return "OF_LOG_WARNING";
        case OF_LOG_ERROR: return "OF_LOG_ERROR";
        case OF_LOG_FATAL_ERROR: "OF_LOG_FATAL_ERROR";
        case OF_LOG_SILENT: return "OF_LOG_SILENT";
    }
}


template<>
ofLogLevel deserialize(const ofJson& json)
{
    if (json == toString(OF_LOG_VERBOSE)) return OF_LOG_VERBOSE;
    else if (json == toString(OF_LOG_NOTICE)) return OF_LOG_NOTICE;
    else if (json == toString(OF_LOG_WARNING)) return OF_LOG_WARNING;
    else if (json == toString(OF_LOG_ERROR)) return OF_LOG_ERROR;
    else if (json == toString(OF_LOG_FATAL_ERROR)) return OF_LOG_FATAL_ERROR;
    else if (json == toString(OF_LOG_SILENT)) return OF_LOG_SILENT;
    else throw std::invalid_argument("Unknown " + json.dump());
}


template<>
ofJson serialize(const ofLogLevel& value)
{
    return toString(value);
}

std::string toString(ofWindowMode level)
{
    switch (level)
    {
        case OF_WINDOW: return "OF_WINDOW";
        case OF_FULLSCREEN: return "OF_FULLSCREEN";
        case OF_GAME_MODE: return "OF_GAME_MODE";
    }
}

    
template<>
ofWindowMode deserialize(const ofJson& json)
{
    if (json == toString(OF_WINDOW)) return OF_WINDOW;
    else if (json == toString(OF_FULLSCREEN)) return OF_FULLSCREEN;
    else if (json == toString(OF_GAME_MODE)) return OF_GAME_MODE;
    else throw std::invalid_argument("Unknown " + json.dump());
}


template<>
ofJson serialize(const ofWindowMode& value)
{
    return toString(value);
}


template<>
ofWindowSettings deserialize(const ofJson& json)
{
    ofWindowSettings settings;

    if (json.count("position"))
    {
        settings.setPosition(deserialize<ofVec2f>(json["position"]));
    }

    ofJson size = json["size"];

    settings.width = size.value("width", settings.width);
    settings.height = size.value("height", settings.height);

    settings.title = json.value("title", settings.title);
    settings.windowMode = deserialize(json["window_mode"], settings.windowMode);

    return settings;
}


template<>
ofJson serialize(const ofWindowSettings& value)
{
    ofJson json;

    if (value.isPositionSet())
    {
        json["position"] = serialize(value.getPosition());
    }

    json["size"]["width"] = value.width;
    json["size"]["height"] = value.height;
    json["title"] = value.title;
    json["window_mode"] = serialize(value.windowMode);

    return json;
}


} // namespace ofx
