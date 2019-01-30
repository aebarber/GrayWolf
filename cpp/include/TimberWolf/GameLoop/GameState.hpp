#ifndef TW_CLASS_GameState
#define TW_CLASS_GameState

/**
 * @file
 *
 * Header file for the tw::GameState class.
 */

#include "Controller.hpp"
#include "../Window/Window.hpp"
#include "../Core/Color.hpp"
namespace tw { class GameStateManager; }

namespace tw {
class GameState {

public:

    // GameState stacking transparency flags
    static const bool transparentRender = false;
    static const bool transparentUpdate = false;
    static const bool transparentInput = false;

    // constructor and destructor
    GameState () = default;
    virtual ~GameState () = default;

    // move operations
    GameState (GameState&&) = default;
    GameState& operator = (GameState&&) = default;

    // copy operations
    GameState (const GameState&) = default;
    GameState& operator = (const GameState&) = default;

    // state management event callbacks
    virtual void onActivate () = 0;
    virtual void onDeactivate () = 0;
    virtual void onPush () = 0;
    virtual void onPop () = 0;
    virtual void onAscend () = 0;
    virtual void onDescend () = 0;

    // game loop callbacks
    virtual void render (double) = 0;
    virtual void update (double) = 0;

    // input handling
    Controller& getController ();
    void setController (Controller&&);
    void setController (Controller&);
    void clearController ();

protected:

    Controller m_controller;

};
}

#endif