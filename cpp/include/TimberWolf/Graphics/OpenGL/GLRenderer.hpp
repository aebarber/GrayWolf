#ifndef TW_CLASS_GLRENDERER
#define TW_CLASS_GLRENDERER

/**
 * @file
 *
 * Header file for the tw::GLRenderer class.
 */

#include <memory>
#include <stdexcept>

#include <GL/glew.h>

#include "../Material.hpp"
#include "../MaterialHandle.hpp"
#include "../Mesh.hpp"
#include "../MeshHandle.hpp"
#include "../Model.hpp"
#include "../../Log/Log.hpp"
#include "../Renderer.hpp"
#include "../../Window/Window.hpp"

#include "GLMaterialHandle.hpp"
#include "GLMeshHandle.hpp"

namespace tw {
class GLRenderer : public Renderer {

    GLRenderer () = default;
    virtual ~GLRenderer () = default;

    GLRenderer (GLRenderer&&) = default;
    GLRenderer& operator = (GLRenderer&&) = default;

    GLRenderer (const GLRenderer&) = default;
    GLRenderer& operator = (const GLRenderer&) = default;

    virtual MaterialHandle* put (Material&) override;
    virtual MeshHandle* put (Mesh&) override;

    virtual void render (const Scene*) override;

    virtual void clear () override;
    virtual void clearColor () override;
    virtual void clearDepth () override;

    virtual void onWindowOpen () override;
    virtual void onWindowClose () override;

    virtual void setClearColor (const Color&) override;

protected:

    void drawModel (Model*);

    static void glLiveDebug (GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar*, const void*);

};
}

#endif