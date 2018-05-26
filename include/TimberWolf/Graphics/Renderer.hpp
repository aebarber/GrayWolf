#ifndef H_TW_RENDERER
#define H_TW_RENDERER

/**
 * @file
 *
 * Header for the tw::Renderer class.
 */

#include <GL/glew.h>
#include "Model.hpp"
#include "../Log/Log.hpp"

namespace tw {
class Renderer {

public:

    Renderer () = delete; // static only
    ~Renderer () = delete;

    Renderer (Renderer&&) = delete;
    Renderer& operator = (Renderer&&) = delete;

    Renderer (const Renderer&) = delete;
    Renderer& operator = (const Renderer&) = delete;

    static void render (const Model&);

};
}

#endif