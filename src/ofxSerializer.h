//
// Copyright (c) 2017 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "json.hpp"

// -----------------------------------------------------------------------------

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat3x3.hpp"
#include "glm/mat4x4.hpp"


namespace glm
{

    
inline void to_json(nlohmann::json& j, const glm::vec2& p)
{
    j = { { "x", p.x }, { "y", p.y } };
}

inline void from_json(const nlohmann::json& j, glm::vec2& p)
{
    p.x = j.value("x", glm::vec3::value_type(0.0f));
    p.y = j.value("y", glm::vec3::value_type(0.0f));
}

inline void to_json(nlohmann::json& j, const glm::vec3& p)
{
    j = { { "x", p.x }, { "y", p.y }, { "z", p.z } };
}

inline void from_json(const nlohmann::json& j, glm::vec3& p)
{
    p.x = j.value("x", glm::vec3::value_type(0.0f));
    p.y = j.value("y", glm::vec3::value_type(0.0f));
    p.z = j.value("z", glm::vec3::value_type(0.0f));
}

    
inline void to_json(nlohmann::json& j, const glm::vec4& p)
{
    j = { { "x", p.x }, { "y", p.y }, { "z", p.z }, { "w", p.w } };
}

inline void from_json(const nlohmann::json& j, glm::vec4& p)
{
    p.x = j.value("x", glm::vec4::value_type(0.0f));
    p.y = j.value("y", glm::vec4::value_type(0.0f));
    p.z = j.value("z", glm::vec4::value_type(0.0f));
    p.w = j.value("w", glm::vec4::value_type(1.0f));
}

inline void to_json(nlohmann::json& j, const glm::mat3& p)
{
    j = { p[0], p[1], p[2] };
}

inline void from_json(const nlohmann::json& j, glm::mat3& p)
{
    p[0] = j[0];
    p[1] = j[1];
    p[2] = j[2];
}

inline void to_json(nlohmann::json& j, const glm::mat4& p)
{
    j = { p[0], p[1], p[2], p[3] };
}

inline void from_json(const nlohmann::json& j, glm::mat4& p)
{
    p[0] = j[0];
    p[1] = j[1];
    p[2] = j[2];
    p[3] = j[3];
}


}; // namespace glm


// -----------------------------------------------------------------------------


#include "ofRectangle.h"


inline void to_json(nlohmann::json& j, const ofRectangle& p)
{
    j = { { "x", p.x }, { "y", p.y }, { "width", p.width }, { "height", p.height } };
}

inline void from_json(const nlohmann::json& j, ofRectangle& p)
{
    p.x = j.value("x", float(0.0f));
    p.y = j.value("y", float(0.0f));
    p.width = j.value("width", float(0.0f));
    p.height = j.value("height", float(0.0f));
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


inline void to_json(nlohmann::json& j, const ofPolyline& p)
{
    j["is_closed"] = p.isClosed();
    nlohmann::json vertices = nlohmann::json::array();
    for (auto& v: p)
        vertices.push_back(v);
    j["vertices"] = vertices;
}


inline void from_json(const nlohmann::json& j, ofPolyline& p)
{
    for (auto& v: j["vertices"])
        p.addVertex(v.get<glm::vec3>());
    p.setClosed(j.value("is_closed", false));
}



// -----------------------------------------------------------------------------


#include "ofLog.h"


inline void to_json(nlohmann::json& j, const ofLogLevel& v)
{
        switch (level)
        {
            case OF_LOG_VERBOSE:     v = "OF_LOG_VERBOSE"; break;
            case OF_LOG_NOTICE:      v = "OF_LOG_NOTICE";  break;
            case OF_LOG_WARNING:     v = "OF_LOG_WARNING"; break;
            case OF_LOG_ERROR:       v = "OF_LOG_ERROR";   break;
            case OF_LOG_FATAL_ERROR: v = "OF_LOG_FATAL_ERROR"; break;
            case OF_LOG_SILENT:      v = "OF_LOG_SILENT";  break;
            default:                 v = "OF_LOG_VERBOSE"; break;
        }
}


inline void from_json(const nlohmann::json& j, ofLogLevel& v)
{
    std::string s = j.get<std::string>();
    if (!s.empty())
    {
        if      (s == "OF_LOG_VERBOSE")     return OF_LOG_VERBOSE;
        else if (s == "OF_LOG_NOTICE")      return OF_LOG_NOTICE;
        else if (s == "OF_LOG_WARNING")     return OF_LOG_WARNING;
        else if (s == "OF_LOG_ERROR")       return OF_LOG_ERROR;
        else if (s == "OF_LOG_FATAL_ERROR") return OF_LOG_FATAL_ERROR;
        else if (s == "OF_LOG_SILENT")      return OF_LOG_SILENT;
    }

    ofLogWarning("from_json") << "Unknown value: " << s;
    return OF_LOG_VERBOSE;

}
