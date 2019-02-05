//
// Copyright (c) 2017 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#ifndef OF_SERIALIZER_H
#define OF_SERIALIZER_H


#include "json.hpp"

// -----------------------------------------------------------------------------

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat3x3.hpp"
#include "glm/mat4x4.hpp"


namespace glm
{


template<typename T, precision P>
inline void to_json(nlohmann::json& j, const glm::tvec2<T, P>& v)
{
    j = { { "x", v.x }, { "y", v.y } };
}
    

template<typename T, precision P>
inline void from_json(const nlohmann::json& j, glm::tvec2<T, P>& v)
{
    v.x = j.value("x", typename glm::tvec2<T, P>::value_type(0));
    v.y = j.value("y", typename glm::tvec2<T, P>::value_type(0));
}


template<typename T, precision P>
inline void to_json(nlohmann::json& j, const glm::tvec3<T, P>& v)
{
    j = { { "x", v.x }, { "y", v.y }, { "z", v.z } };
}

    
template<typename T, precision P>
inline void from_json(const nlohmann::json& j, glm::tvec3<T, P>& v)
{
    v.x = j.value("x", typename glm::tvec3<T, P>::value_type(0));
    v.y = j.value("y", typename glm::tvec3<T, P>::value_type(0));
    v.z = j.value("z", typename glm::tvec3<T, P>::value_type(0));
}

    
template<typename T, precision P>
inline void to_json(nlohmann::json& j, const glm::tvec4<T, P>& v)
{
    j = { { "x", v.x }, { "y", v.y }, { "z", v.z }, { "w", v.w } };
}

    
template<typename T, precision P>
inline void from_json(const nlohmann::json& j, glm::tvec4<T, P>& v)
{
    v.x = j.value("x", typename glm::tvec3<T, P>::value_type(0));
    v.y = j.value("y", typename glm::tvec3<T, P>::value_type(0));
    v.z = j.value("z", typename glm::tvec3<T, P>::value_type(0));
    v.w = j.value("w", typename glm::tvec3<T, P>::value_type(1));
}

    
template<typename T, precision P>
inline void to_json(nlohmann::json& j, const glm::tmat3x3<T, P>& v)
{
    j = { v[0], v[1], v[2] };
}


template<typename T, precision P>
inline void from_json(const nlohmann::json& j, glm::tmat3x3<T, P>& v)
{
    v[0] = j[0];
    v[1] = j[1];
    v[2] = j[2];
}


template<typename T, precision P>
inline void to_json(nlohmann::json& j, const glm::tmat4x4<T, P>& v)
{
    j = { v[0], v[1], v[2], v[3] };
}

    
template<typename T, precision P>
inline void from_json(const nlohmann::json& j, glm::tmat4x4<T, P>& v)
{
    v[0] = j[0];
    v[1] = j[1];
    v[2] = j[2];
    v[3] = j[3];
}


}; // namespace glm


// -----------------------------------------------------------------------------


#include "ofRectangle.h"


inline void to_json(nlohmann::json& j, const ofRectangle& v)
{
    j = { { "x", v.x }, { "y", v.y }, { "width", v.width }, { "height", v.height } };
}


inline void from_json(const nlohmann::json& j, ofRectangle& v)
{
    v.x = j.value("x", float(0.0f));
    v.y = j.value("y", float(0.0f));
    v.width = j.value("width", float(0.0f));
    v.height = j.value("height", float(0.0f));
}

// -----------------------------------------------------------------------------


#include "ofColor.h"


inline void to_json(nlohmann::json& j, const ofColor& p)
{
    j = { { "r", p.r }, { "g", p.g }, { "b", p.b }, { "a", p.a } };
}


inline void from_json(const nlohmann::json& j, ofColor& p)
{
    p.r = j.value("r", 255);
    p.g = j.value("g", 255);
    p.b = j.value("b", 255);
    p.a = j.value("a", 255);
}


// -----------------------------------------------------------------------------


#include "ofPolyline.h"


template<typename VertexType>
inline void to_json(nlohmann::json& j, const ofPolyline_<VertexType>& v)
{
    j["is_closed"] = v.isClosed();
    nlohmann::json vertices = nlohmann::json::array();
    for (auto& vertex: v)
        vertices.push_back(vertex);
    j["vertices"] = vertices;
}


template<typename VertexType>
inline void from_json(const nlohmann::json& j, ofPolyline_<VertexType>& v)
{
    const auto& vertices = j["vertices"];
    for (auto& vertex: vertices)
        v.addVertex(vertex.get<VertexType>());
    v.setClosed(j.value("is_closed", false));
}



// -----------------------------------------------------------------------------


#include "ofLog.h"


inline std::string to_string(const ofLogLevel& v)
{
    switch (v)
    {
        case OF_LOG_VERBOSE:        return "OF_LOG_VERBOSE";
        case OF_LOG_NOTICE:         return "OF_LOG_NOTICE";
        case OF_LOG_WARNING:        return "OF_LOG_WARNING";
        case OF_LOG_ERROR:          return "OF_LOG_ERROR";
        case OF_LOG_FATAL_ERROR:    return "OF_LOG_FATAL_ERROR";
        case OF_LOG_SILENT:         return "OF_LOG_SILENT";
    }
    
    return "OF_LOG_VERBOSE";
}



inline void to_json(nlohmann::json& j, const ofLogLevel& v)
{
    j = to_string(v);
}


inline void from_json(const nlohmann::json& j, ofLogLevel& v)
{
    std::string s = j.get<std::string>();
    if (!s.empty())
    {
        if (s == to_string(OF_LOG_VERBOSE))
        {
            v = OF_LOG_VERBOSE;
            return;
        }
        else if (s == to_string(OF_LOG_NOTICE))
        {
            v = OF_LOG_NOTICE;
            return;
        }
        else if (s == to_string(OF_LOG_WARNING))
        {
            v = OF_LOG_WARNING;
            return;
        }
        else if (s == to_string(OF_LOG_ERROR))
        {
            v = OF_LOG_ERROR;
            return;
        }
        else if (s == to_string(OF_LOG_FATAL_ERROR))
        {
            v = OF_LOG_FATAL_ERROR;
            return;
        }
        else if (s == to_string(OF_LOG_SILENT))
        {
            v = OF_LOG_SILENT;
            return;
        }
    }

    ofLogWarning("from_json") << "Unknown value: " << s;
    v = OF_LOG_VERBOSE;
    return;
}


// -----------------------------------------------------------------------------


#include "ofWindowSettings.h"


inline std::string to_string(const ofWindowMode& v)
{
    switch (v)
    {
        case OF_WINDOW:     return "OF_WINDOW";
        case OF_FULLSCREEN: return "OF_FULLSCREEN";
        case OF_GAME_MODE:  return "OF_GAME_MODE";
    }

    return "OF_WINDOW";
}


inline void to_json(nlohmann::json& j, const ofWindowMode& v)
{
    j = to_string(v);
}


inline void from_json(const nlohmann::json& j, ofWindowMode& v)
{
    std::string s = j.get<std::string>();
    if (!s.empty())
    {
        if (s == to_string(OF_WINDOW))
        {
            v = OF_WINDOW;
            return;
        }
        else if (s == to_string(OF_FULLSCREEN))
        {
            v = OF_FULLSCREEN;
            return;
        }
        else if (s == to_string(OF_GAME_MODE))
        {
            v = OF_GAME_MODE;
            return;
        }
    }

    ofLogWarning("from_json") << "Unknown value: " << s;
    v = OF_WINDOW;
    return;
}

inline void to_json(nlohmann::json& j, const ofWindowSettings& v)
{
    if (v.isPositionSet())
        j["position"] = v.getPosition();
    if (v.isSizeSet())
        j["size"] = glm::ivec2(v.getWidth(), v.getHeight());
    if (!v.title.empty())
        j["title"] = v.title;
    
    j["window_mode"] = v.windowMode;
}


inline void from_json(const nlohmann::json& j, ofWindowSettings& v)
{
    auto iter = j.cbegin();
    while (iter != j.cend())
    {
        const auto& key = iter.key();
        const auto& value = iter.value();

        if (key == "position") v.setPosition(value);
        else if (key == "size")
        {
            auto s = value.get<glm::ivec2>();
            v.setSize(s.x, s.y);
        }
        else if (key == "title") v.title = value;
        else if (key == "window_mode") v.windowMode = value;
        ++iter;
    }
}


#endif // OF_SERIALIZER_H
