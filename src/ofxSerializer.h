//
// Copyright (c) 2017 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofx/Serializer.h"

#include "ofJson.h"
#include "ofVectorMath.h"


namespace glm
{

    
inline void to_json(ofJson& j, const glm::vec2& p)
{
    j = { { "x", p.x }, { "y", p.y } };
}

inline void from_json(const ofJson& j, glm::vec2& p)
{
    p.x = j.value("x", glm::vec3::value_type(0.0f));
    p.y = j.value("y", glm::vec3::value_type(0.0f));
}

inline void to_json(ofJson& j, const glm::vec3& p)
{
    j = { { "x", p.x }, { "y", p.y }, { "z", p.z } };
}

inline void from_json(const ofJson& j, glm::vec3& p)
{
    p.x = j.value("x", glm::vec3::value_type(0.0f));
    p.y = j.value("y", glm::vec3::value_type(0.0f));
    p.z = j.value("z", glm::vec3::value_type(0.0f));
}

    
inline void to_json(ofJson& j, const glm::vec4& p)
{
    j = { { "x", p.x }, { "y", p.y }, { "z", p.z }, { "w", p.w } };
}

inline void from_json(const ofJson& j, glm::vec4& p)
{
    p.x = j.value("x", glm::vec4::value_type(0.0f));
    p.y = j.value("y", glm::vec4::value_type(0.0f));
    p.z = j.value("z", glm::vec4::value_type(0.0f));
    p.w = j.value("w", glm::vec4::value_type(1.0f));
}

inline void to_json(ofJson& j, const glm::mat3& p)
{
    j = { p[0], p[1], p[2] };
}

inline void from_json(const ofJson& j, glm::mat3& p)
{
    p[0] = j[0];
    p[1] = j[1];
    p[2] = j[2];
}

inline void to_json(ofJson& j, const glm::mat4& p)
{
    j = { p[0], p[1], p[2], p[3] };
}

inline void from_json(const ofJson& j, glm::mat4& p)
{
    p[0] = j[0];
    p[1] = j[1];
    p[2] = j[2];
    p[3] = j[3];
}


}; // namespace glm


#include "ofRectangle.h"


inline void to_json(ofJson& j, const ofRectangle& p)
{
    j = { { "x", p.x }, { "y", p.y }, { "width", p.width }, { "height", p.height } };
}

inline void from_json(const ofJson& j, ofRectangle& p)
{
    p.x = j.value("x", float(0.0f));
    p.y = j.value("y", float(0.0f));
    p.width = j.value("width", float(0.0f));
    p.height = j.value("height", float(0.0f));
}


inline void to_json(ofJson& j, const ofColor& p)
{
    j = { { "r", p.r }, { "g", p.g }, { "b", p.b }, { "a", p.a } };
}

inline void from_json(const ofJson& j, ofColor& p)
{
    p.r = j.value("r", 255);
    p.g = j.value("g", 255);
    p.b = j.value("b", 255);
    p.a = j.value("a", 255);
}


#include "ofPolyline.h"


inline void to_json(ofJson& j, const ofPolyline& p)
{
    j["is_closed"] = p.isClosed();
    ofJson vertices = ofJson::array();
    for (auto& v: p)
        vertices.push_back(v);
    j["vertices"] = vertices;
}


inline void from_json(const ofJson& j, ofPolyline& p)
{
    for (auto& v: j["vertices"])
        p.addVertex(v.get<glm::vec3>());
    p.setClosed(j.value("is_closed", false));
}


