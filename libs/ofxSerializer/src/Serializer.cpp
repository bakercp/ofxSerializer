//
// Copyright (c) 2017 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#include "ofxSerializer.h"
#include "ofLog.h"
#include "ofPolyline.h"
#include "ofRectangle.h"
#include "ofWindowSettings.h"


namespace ofx {


bool icompare_pred(unsigned char a, unsigned char b)
{
    return std::tolower(a) == std::tolower(b);
}


bool icompare(const std::string& a, const std::string& b)
{
    if (a.length() == b.length())
    {
        return std::equal(b.begin(), b.end(),
                          a.begin(), icompare_pred);
    }
    else
    {
        return false;
    }
}


template<>
ofRectangle deserialize(const ofJson& json)
{
    ofRectangle out;

    try
    {
        auto iter = json.cbegin();
        while (iter != json.cend())
        {
            const auto& key = iter.key();
            const auto& value = iter.value();

            if (key == "x") out.setX(value);
            else if (key == "y") out.setY(value);
            else if (key == "width") out.setWidth(value);
            else if (key == "height") out.setHeight(value);

            ++iter;
        }
    }
    catch (const std::exception& exc)
    {
        ofLogError("deserialize") << exc.what() << ": " << json.dump();
    }

    return out;
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
    ofVec2f out;

    try
    {
        auto iter = json.cbegin();
        while (iter != json.cend())
        {
            const auto& key = iter.key();
            const auto& value = iter.value();

            if (key == "x") out.x = value;
            else if (key == "y") out.y = value;

            ++iter;
        }

    }
    catch (const std::exception& exc)
    {
        ofLogError("deserialize") << exc.what() << ": " << json.dump();
    }

    return out;
}


template<>
glm::vec2 deserialize(const ofJson& json)
{
    glm::vec2 out;

    try
    {
        auto iter = json.cbegin();
        while (iter != json.cend())
        {
            const auto& key = iter.key();
            const auto& value = iter.value();

            if (key == "x") out.x = value;
            else if (key == "y") out.y = value;

            ++iter;
        }
    }
    catch (const std::exception& exc)
    {
        ofLogError("deserialize") << exc.what() << ": " << json.dump();
    }

    return out;
}


template<>
ofJson serialize(const glm::vec2& value)
{
    return ofJson {{ "x", value.x }, { "y", value.y }};
}


template<>
ofJson serialize(const ofVec2f& value)
{
    return ofJson {{ "x", value.x }, { "y", value.y }};
}


template<>
ofVec3f deserialize(const ofJson& json)
{
    ofVec3f out;

    try
    {
        auto iter = json.cbegin();
        while (iter != json.cend())
        {
            const auto& key = iter.key();
            const auto& value = iter.value();

            if (key == "x") out.x = value;
            else if (key == "y") out.y = value;
            else if (key == "z") out.z = value;

            ++iter;
        }
        
    }
    catch (const std::exception& exc)
    {
        ofLogError("deserialize") << exc.what() << ": " << json.dump();
    }

    return out;
}


template<>
glm::vec3 deserialize(const ofJson& json)
{
    glm::vec3 out;

    try
    {
        auto iter = json.cbegin();
        while (iter != json.cend())
        {
            const auto& key = iter.key();
            const auto& value = iter.value();

            if (key == "x") out.x = value;
            else if (key == "y") out.y = value;
            else if (key == "z") out.z = value;
            
            ++iter;
        }
    }
    catch (const std::exception& exc)
    {
        ofLogError("deserialize") << exc.what() << ": " << json.dump();
    }

    return out;
}


template<>
ofJson serialize(const ofVec3f& value)
{
    return ofJson {{ "x", value.x }, { "y", value.y }, { "z", value.z }};
}


template<>
ofJson serialize(const glm::vec3& value)
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
    try
    {
        if (icompare(json, toString(OF_LOG_VERBOSE)) || icompare(json, "verbose"))
            return OF_LOG_VERBOSE;
        else if (icompare(json, toString(OF_LOG_NOTICE)) || icompare(json, "notice"))
            return OF_LOG_NOTICE;
        else if (icompare(json, toString(OF_LOG_WARNING)) || icompare(json, "warning"))
            return OF_LOG_WARNING;
        else if (icompare(json, toString(OF_LOG_ERROR)) || icompare(json, "error"))
            return OF_LOG_ERROR;
        else if (icompare(json, toString(OF_LOG_FATAL_ERROR)) || icompare(json, "fatal"))
            return OF_LOG_FATAL_ERROR;
        else if (icompare(json, toString(OF_LOG_SILENT)) || icompare(json, "silent"))
            return OF_LOG_SILENT;
        else
        {
            ofLogWarning("deserialize") << "Unknown " << json.dump();
            return OF_LOG_NOTICE;
        }
    }
    catch (const std::exception& exc)
    {
        ofLogError("deserialize") << exc.what() << ": " << json.dump();
        return OF_LOG_NOTICE;
    }
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
    try
    {
        if (json == toString(OF_WINDOW)) return OF_WINDOW;
        else if (json == toString(OF_FULLSCREEN)) return OF_FULLSCREEN;
        else if (json == toString(OF_GAME_MODE)) return OF_GAME_MODE;
        else
        {
            ofLogWarning("deserialize") << "Unknown " << json.dump();
            return OF_WINDOW;
        }
    }
    catch (const std::exception& exc)
    {
        ofLogError("deserialize") << exc.what() << ": " << json.dump();
        return OF_WINDOW;
    }
}


template<>
ofJson serialize(const ofWindowMode& value)
{
    return toString(value);
}


template<>
ofWindowSettings deserialize(const ofJson& json)
{
    ofWindowSettings out;

    try
    {
        auto iter = json.cbegin();
        while (iter != json.cend())
        {
            const auto& key = iter.key();
            const auto& value = iter.value();

            if (key == "position") out.setPosition(deserialize<ofVec2f>(value));
            else if (key == "size")
            {
                if (value.count("width")) out.width = value["width"];
                if (value.count("height")) out.height = value["height"];
            }
            else if (key == "title") out.title = value;
            else if (key == "window_mode") out.windowMode = deserialize<ofWindowMode>(value);

            ++iter;
        }

    }
    catch (const std::exception& exc)
    {
        ofLogError("deserialize") << exc.what() << ": " << json.dump();
    }

    return out;
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

    if (!value.title.empty())
    {
        json["title"] = value.title;
    }

    json["window_mode"] = serialize(value.windowMode);

    return json;
}


template<>
ofJson serialize(const ofPolyline& value)
{
    ofJson json;
    for (const auto& vertex: value) json.push_back(serialize(vertex));
    return json;
}


template<>
ofPolyline deserialize(const ofJson& json)
{
    ofPolyline out;

    try
    {
        for (const auto& element: json)
        {
            out.addVertex(deserialize<glm::vec3>(element));
        }
    }
    catch (const std::exception& exc)
    {
        ofLogError("deserialize") << exc.what() << ": " << json.dump();
    }

    return out;
}



} // namespace ofx
