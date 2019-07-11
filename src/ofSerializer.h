//
// Copyright (c) 2017 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#ifndef OF_SERIALIZER_H
#define OF_SERIALIZER_H


#include "json.hpp"
#include "ofVectorMath.h"

// -----------------------------------------------------------------------------

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat3x3.hpp"
#include "glm/mat4x4.hpp"


namespace glm
{


template<typename T, glm::precision P>
inline void to_json(nlohmann::json& j, const glm::tvec2<T, P>& v)
{
    j = { { "x", v.x }, { "y", v.y } };
}


template<typename T, glm::precision P>
inline void from_json(const nlohmann::json& j, glm::tvec2<T, P>& v)
{
    v.x = j.value("x", typename glm::tvec2<T, P>::value_type(0));
    v.y = j.value("y", typename glm::tvec2<T, P>::value_type(0));
}


template<typename T, glm::precision P>
inline void to_json(nlohmann::json& j, const glm::tvec3<T, P>& v)
{
    j = { { "x", v.x }, { "y", v.y }, { "z", v.z } };
}


template<typename T, glm::precision P>
inline void from_json(const nlohmann::json& j, glm::tvec3<T, P>& v)
{
    v.x = j.value("x", typename glm::tvec3<T, P>::value_type(0));
    v.y = j.value("y", typename glm::tvec3<T, P>::value_type(0));
    v.z = j.value("z", typename glm::tvec3<T, P>::value_type(0));
}


template<typename T, glm::precision P>
inline void to_json(nlohmann::json& j, const glm::tvec4<T, P>& v)
{
    j = { { "x", v.x }, { "y", v.y }, { "z", v.z }, { "w", v.w } };
}


template<typename T, glm::precision P>
inline void from_json(const nlohmann::json& j, glm::tvec4<T, P>& v)
{
    v.x = j.value("x", typename glm::tvec3<T, P>::value_type(0));
    v.y = j.value("y", typename glm::tvec3<T, P>::value_type(0));
    v.z = j.value("z", typename glm::tvec3<T, P>::value_type(0));
    v.w = j.value("w", typename glm::tvec3<T, P>::value_type(1));
}


template<typename T, glm::precision P>
inline void to_json(nlohmann::json& j, const glm::tmat3x3<T, P>& v)
{
    j = { v[0], v[1], v[2] };
}


template<typename T, glm::precision P>
inline void from_json(const nlohmann::json& j, glm::tmat3x3<T, P>& v)
{
    v[0] = j[0];
    v[1] = j[1];
    v[2] = j[2];
}


template<typename T, glm::precision P>
inline void to_json(nlohmann::json& j, const glm::tmat4x4<T, P>& v)
{
    j = { v[0], v[1], v[2], v[3] };
}


template<typename T, glm::precision P>
inline void from_json(const nlohmann::json& j, glm::tmat4x4<T, P>& v)
{
    v[0] = j[0];
    v[1] = j[1];
    v[2] = j[2];
    v[3] = j[3];
}


template<typename T, glm::precision P>
inline void to_json(nlohmann::json& j, const glm::tquat<T, P>& v)
{
    j = { { "x", v.x }, { "y", v.y }, { "z", v.z }, { "w", v.w } };
}


template<typename T, glm::precision P>
inline void from_json(const nlohmann::json& j, glm::tquat<T, P>& v)
{
    v.x = j.value("x", typename glm::tquat<T, P>::value_type(1));
    v.y = j.value("y", typename glm::tquat<T, P>::value_type(0));
    v.z = j.value("z", typename glm::tquat<T, P>::value_type(0));
    v.w = j.value("w", typename glm::tquat<T, P>::value_type(0));
}


}; // namespace glm


inline void to_json(nlohmann::json& j, const ofVec2f& v)
{
    to_json(j, toGlm(v));
}


inline void from_json(const nlohmann::json& j, ofVec2f& v)
{
    glm::vec2 g;
    from_json(j, g);
    v = toOf(g);
}


inline void to_json(nlohmann::json& j, const ofVec3f& v)
{
    to_json(j, toGlm(v));
}


inline void from_json(const nlohmann::json& j, ofVec3f& v)
{
    glm::vec3 g;
    from_json(j, g);
    v = toOf(g);
}


inline void to_json(nlohmann::json& j, const ofVec4f& v)
{
    to_json(j, toGlm(v));
}


inline void from_json(const nlohmann::json& j, ofVec4f& v)
{
    glm::vec4 g;
    from_json(j, g);
    v = toOf(g);
}


inline void to_json(nlohmann::json& j, const ofMatrix3x3& v)
{
    to_json(j, toGlm(v));
}


inline void from_json(const nlohmann::json& j, ofMatrix3x3& v)
{
    glm::mat3 g;
    from_json(j, g);
    v = toOf(g);
}


inline void to_json(nlohmann::json& j, const ofMatrix4x4& v)
{
    to_json(j, toGlm(v));
}


inline void from_json(const nlohmann::json& j, ofMatrix4x4& v)
{
    glm::mat4 g;
    from_json(j, g);
    v = toOf(g);
}


inline void to_json(nlohmann::json& j, const ofQuaternion& v)
{
    to_json(j, toGlm(v));
}


inline void from_json(const nlohmann::json& j, ofQuaternion& v)
{
    glm::quat g;
    from_json(j, g);
    v = ofQuaternion(g);
}

// -----------------------------------------------------------------------------


#include "ofRectangle.h"


#define ENUM_TO_STRING(x) #x
#define ENUM_TO_STRING_CASE(x) { case x: return #x; }

#define STRING_TO_ENUM_RETURN(s, x) if { s x: return #x; }


//if (s == to_string(OF_ASPECT_RATIO_IGNORE))
//{
//    v = OF_ASPECT_RATIO_IGNORE;
//    return;
//}



//enum ofAspectRatioMode {
//    /// \brief Set the rectangle's width and height to match the target.
//    OF_ASPECT_RATIO_IGNORE            = 0,
//    /// \brief Resizes the rectangle to completely fit within the target.
//    OF_ASPECT_RATIO_KEEP              = 1,
//    /// \brief Resizes the rectangle to completely enclose the target.
//    OF_ASPECT_RATIO_KEEP_BY_EXPANDING = 2,
//};





//inline std::string to_string(const ofAspectRatioMode& v)
//{
//    switch (v)
//    {
//        MAKE_STRING_CASE(OF_ASPECT_RATIO_IGNORE)
//        MAKE_STRING_CASE(OF_ASPECT_RATIO_KEEP)
//        MAKE_STRING_CASE(OF_ASPECT_RATIO_KEEP_BY_EXPANDING)
////        case OF_ASPECT_RATIO_IGNORE: return "OF_ASPECT_RATIO_IGNORE";
////        case OF_ASPECT_RATIO_KEEP: return "OF_ASPECT_RATIO_KEEP";
////        case OF_ASPECT_RATIO_KEEP_BY_EXPANDING: return "OF_ASPECT_RATIO_KEEP_BY_EXPANDING";
//    }
//
//    return "OF_ASPECT_RATIO_IGNORE";
//}
//
//
//
//inline void to_json(nlohmann::json& j, const ofAspectRatioMode& v)
//{
//    j = to_string(v);
//}
//
//inline void from_json(const nlohmann::json& j, ofAspectRatioMode& v)
//{
//    std::string s = j.get<std::string>();
//    if (!s.empty())
//    {
//        if (s == to_string(OF_ASPECT_RATIO_IGNORE)) v = OF_ASPECT_RATIO_IGNORE; return; }
//        else if (s == to_string(OF_ASPECT_RATIO_KEEP)) { v = OF_ASPECT_RATIO_KEEP; return; }
//        else if (s == to_string(OF_ASPECT_RATIO_KEEP_BY_EXPANDING)) { v = OF_ASPECT_RATIO_KEEP_BY_EXPANDING; return; }
//    }
//
//    ofLogWarning("from_json") << "Unknown value: " << s;
//    v = OF_ASPECT_RATIO_IGNORE;
//    return;
//}
//





//
///// \brief Used to represent the available vertical rectangle alignment modes.
/////
///// \sa ofRectangle
//enum ofAlignVert {
//    /// \brief Do not perform any vertical alignment.
//    OF_ALIGN_VERT_IGNORE   = 0x0000,
//    /// \brief Use the upper edge of the rectangle to vertically anchor the alignment.
//    OF_ALIGN_VERT_TOP      = 0x0010,
//    /// \brief Use the bottom edge of the rectangle to vertically anchor the alignment.
//    OF_ALIGN_VERT_BOTTOM   = 0x0020,
//    /// \brief Use the center of the rectangle to vertically anchor the alignment.
//    OF_ALIGN_VERT_CENTER   = 0x0040,
//};
//
//
///// \brief Used to represent the available horizontal rectangle alignment modes.
/////
///// \sa ofRectangle
//enum ofAlignHorz {
//    /// \brief Do not perform any horizontal alignment.
//    OF_ALIGN_HORZ_IGNORE   = 0x0000,
//    /// \brief Use the left edge of the rectangle to horizontally anchor the alignment.
//    OF_ALIGN_HORZ_LEFT     = 0x0001,
//    /// \brief Use the right edge of the rectangle to horizontally anchor the alignment.
//    OF_ALIGN_HORZ_RIGHT    = 0x0002,
//    /// \brief Use the center of the rectangle to horizontally anchor the alignment.
//    OF_ALIGN_HORZ_CENTER   = 0x0004,
//};
//
//
//
//
//
//
//inline std::string to_string(const ofAspectRatioMode& v)
//{
//    switch (v)
//    {
//        case OF_LOG_VERBOSE:        return "OF_LOG_VERBOSE";
//        case OF_LOG_NOTICE:         return "OF_LOG_NOTICE";
//        case OF_LOG_WARNING:        return "OF_LOG_WARNING";
//        case OF_LOG_ERROR:          return "OF_LOG_ERROR";
//        case OF_LOG_FATAL_ERROR:    return "OF_LOG_FATAL_ERROR";
//        case OF_LOG_SILENT:         return "OF_LOG_SILENT";
//    }
//
//    return "OF_LOG_VERBOSE";
//}










inline void to_json(nlohmann::json& j, const ofRectangle& v)
{
    j = { { "x", v.x }, { "y", v.y }, { "width", v.width }, { "height", v.height } };
}


inline void from_json(const nlohmann::json& j, ofRectangle& v)
{
    /*
    auto positionIter = j.find("position");
    auto sizeIter = j.find("size");

    // Accept an alternate form alternate.
    if (positionIter != j.end() && sizeIter != j.end())
    {
        v.x = positionIter->value("x", float(0.0f));
        v.y = positionIter->value("y", float(0.0f));
        v.width = sizeIter->value("width", float (0.0f));
        v.height= sizeIter->value("height", float (0.0f));
        return;
    }
    */

    v.x = j.value("x", float(0.0f));
    v.y = j.value("y", float(0.0f));
    v.width = j.value("width", float(0.0f));
    v.height = j.value("height", float(0.0f));
}

// -----------------------------------------------------------------------------


#include "ofColor.h"


template<typename PixelType>
inline void to_json(nlohmann::json& j, const ofColor_<PixelType>& p)
{
    j = { { "r", p.r }, { "g", p.g }, { "b", p.b }, { "a", p.a } };
}


template<typename PixelType>
inline void from_json(const nlohmann::json& j, ofColor_<PixelType>& p)
{
    p.r = j.value("r", ofColor_<PixelType>::limit());
    p.g = j.value("g", ofColor_<PixelType>::limit());
    p.b = j.value("b", ofColor_<PixelType>::limit());
    p.a = j.value("a", ofColor_<PixelType>::limit());
}


// -----------------------------------------------------------------------------


#include "ofMesh.h"



inline std::string to_string(const ofPrimitiveMode& v)
{
    switch (v)
    {
        case OF_PRIMITIVE_TRIANGLES: return "OF_PRIMITIVE_TRIANGLES";
        case OF_PRIMITIVE_TRIANGLE_STRIP: return "OF_PRIMITIVE_TRIANGLE_STRIP";
        case OF_PRIMITIVE_TRIANGLE_FAN: return "OF_PRIMITIVE_TRIANGLE_FAN";
        case OF_PRIMITIVE_LINES: return "OF_PRIMITIVE_LINES";
        case OF_PRIMITIVE_LINE_STRIP: return "OF_PRIMITIVE_LINE_STRIP";
        case OF_PRIMITIVE_LINE_LOOP: return "OF_PRIMITIVE_LINE_LOOP";
        case OF_PRIMITIVE_POINTS: return "OF_PRIMITIVE_POINTS";
#ifndef TARGET_OPENGLES
        case OF_PRIMITIVE_LINES_ADJACENCY: return "OF_PRIMITIVE_LINES_ADJACENCY";
        case OF_PRIMITIVE_LINE_STRIP_ADJACENCY: return "OF_PRIMITIVE_LINE_STRIP_ADJACENCY";
        case OF_PRIMITIVE_TRIANGLES_ADJACENCY: return "OF_PRIMITIVE_TRIANGLES_ADJACENCY";
        case OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY: return "OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY";
        case OF_PRIMITIVE_PATCHES: return "OF_PRIMITIVE_PATCHES";
#endif
    }

    return "OF_PRIMITIVE_TRIANGLES";
}



inline void to_json(nlohmann::json& j, const ofPrimitiveMode& v)
{
    j = to_string(v);
}


inline void from_json(const nlohmann::json& j, ofPrimitiveMode& v)
{
    std::string s = j.get<std::string>();
    if (!s.empty())
    {
        if (s == to_string(OF_PRIMITIVE_TRIANGLES))
        {
            v = OF_PRIMITIVE_TRIANGLES;
            return;
        }
        else if (s == to_string(OF_PRIMITIVE_TRIANGLE_STRIP))
        {
            v = OF_PRIMITIVE_TRIANGLE_STRIP;
            return;
        }
        else if (s == to_string(OF_PRIMITIVE_TRIANGLE_FAN))
        {
            v = OF_PRIMITIVE_TRIANGLE_FAN;
            return;
        }
        else if (s == to_string(OF_PRIMITIVE_LINES))
        {
            v = OF_PRIMITIVE_LINES;
            return;
        }
        else if (s == to_string(OF_PRIMITIVE_LINE_STRIP))
        {
            v = OF_PRIMITIVE_LINE_STRIP;
            return;
        }
        else if (s == to_string(OF_PRIMITIVE_LINE_LOOP))
        {
            v = OF_PRIMITIVE_LINE_LOOP;
            return;
        }
        else if (s == to_string(OF_PRIMITIVE_POINTS))
        {
            v = OF_PRIMITIVE_POINTS;
            return;
        }
#ifndef TARGET_OPENGLES
        else if (s == to_string(OF_PRIMITIVE_LINES_ADJACENCY))
        {
            v = OF_PRIMITIVE_LINES_ADJACENCY;
            return;
        }
        else if (s == to_string(OF_PRIMITIVE_LINE_STRIP_ADJACENCY))
        {
            v = OF_PRIMITIVE_LINE_STRIP_ADJACENCY;
            return;
        }
        else if (s == to_string(OF_PRIMITIVE_TRIANGLES_ADJACENCY))
        {
            v = OF_PRIMITIVE_TRIANGLES_ADJACENCY;
            return;
        }
        else if (s == to_string(OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY))
        {
            v = OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY;
            return;
        }
        else if (s == to_string(OF_PRIMITIVE_PATCHES))
        {
            v = OF_PRIMITIVE_PATCHES;
            return;
        }
#endif
    }

    ofLogWarning("from_json") << "Unknown value: " << s;
    v = OF_PRIMITIVE_TRIANGLES;
    return;
}


//std::vector<V> vertices;
//std::vector<C> colors;
//std::vector<N> normals;
//std::vector<T> texCoords;
//std::vector<ofIndexType> indices;
//
//// this variables are only caches and returned always as const
//// mutable allows to change them from const methods
//mutable std::vector<ofMeshFace_<V,N,C,T>> faces;
//mutable bool bFacesDirty;
//
//bool bVertsChanged, bColorsChanged, bNormalsChanged, bTexCoordsChanged,
//bIndicesChanged;
//ofPrimitiveMode mode;
//
//bool useColors;
//bool useTextures;
//bool useNormals;
//bool useIndices;



template<class V, class N, class C, class T>
inline void to_json(nlohmann::json& j, const ofMesh_<V, N, C, T>& v)
{
    j["vertices"] = v.getVertices();
    j["normals"] = v.getNormals();
    j["colors"] = v.getColors();
    j["tex_coords"] = v.getTexCoords();

    j["indices"] = v.getIndices();

    j["using_normals"] = v.usingNormals();
    j["using_colors"] = v.usingColors();
    j["using_textures"] = v.usingTextures();

    j["using_indices"] = v.usingIndices();

    j["primitive_mode"] = v.getMode();
}


template<class V, class N, class C, class T>
inline void from_json(const nlohmann::json& j, ofMesh_<V, N, C, T>& v)
{
    v = ofMesh_<V, N, C, T>();
    v.addVertices(j.value("vertices", std::vector<V>()));
    v.addNormals(j.value("normals", std::vector<N>()));
    v.addColors(j.value("colors", std::vector<C>()));
    v.addTexCoords(j.value("tex_coords", std::vector<T>()));

    v.addIndices(j.value("indices", std::vector<ofIndexType>()));

    v.setMode(j.value("primitive_mode", OF_PRIMITIVE_TRIANGLES));

    bool usingColors = j.value("using_colors", true);
    bool usingTextures = j.value("using_textures", true);
    bool usingNormals = j.value("using_normals", true);
    bool usingIndices = j.value("using_indices", true);

    if (j.value("using_colors", true)) v.enableColors();
    else v.disableColors();

    if (j.value("using_textures", true)) v.enableTextures();
    else v.disableTextures();

    if (j.value("using_normals", true)) v.enableTextures();
    else v.disableTextures();

    if (j.value("using_indices", true)) v.enableIndices();
    else v.disableIndices();

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
        j["size"] = { { "width", v.getWidth() }, { "height", v.getHeight() } };;

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
            v.setSize(value.value("width", 100),
                      value.value("height", 100));
        else if (key == "title") v.title = value;
        else if (key == "window_mode") v.windowMode = value;
        ++iter;
    }
}


#endif // OF_SERIALIZER_H
