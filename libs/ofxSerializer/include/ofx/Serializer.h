//
// Copyright (c) 2017 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "ofConstants.h"
#include "ofRectangle.h"
#include "ofJson.h"


namespace ofx {


template<typename ToType, typename FromType = ofJson>
ToType deserialize(const FromType& from);

template<typename ToType, typename FromType = ofJson>
ToType deserialize(const FromType& from, const ToType& defaultValue)
{
    try
    {
        return deserialize<ToType, FromType>(from);
    }
    catch (const std::exception& exc)
    {
        ofLogWarning("deserialize") << exc.what();
        return defaultValue;
    }
}

template<typename FromType, typename ToType = ofJson>
ToType serialize(const FromType& from);


} // namespace ofx


