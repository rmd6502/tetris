#include <vector>

#include "inputEvent.h"

typedef enum {
    INITIAL,
    IDLE,
    ATTRACT,
    PLAYING,
    DYING,
} GameState;

typedef enum {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
} Direction;

struct Pixel {
    unsigned char r,g,b;
    Pixel() : r(0), g(0), b(0) {}
    Pixel(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}
};

class GameObject {
    public:
        std::vector<Pixel> bitmap;
        time_t nextaction;
        int xPos, yPos;
        // invoked by the game engine when we collide with another GameObject
        virtual void onCollision(Game& game, const GameObject& other) = 0;
        // invoked by the game engine to advance state
        virtual void advanceState(Game &game) = 0;
        // right now events are just keypresses, but it would be good to
        // handle all sorts of events
        virtual void onInputEvent(Game& game, const InputEvent& event) = 0;
        // when one GameObject is drawn adjacent to another
        virtual void onAdjacent(Game& game, const GameObject& other, Direction direction) = 0;
        // actions when game state changes
        virtual void onGameStateChange(Game& game, GameState newState);
};

template <int ROWS, int COLS>
class GameBoard : public GameObject {
    public:
        GameBoard() {
            bitmap.resize(ROWS * COLS);
        }
};

// The game engine.  You shouldn't have to modify this
class Game {
    public:
        // The main game engine.
        void advanceState();
        Game() : currentState(INITIAL) {
        }
        const GameState gameState() const { return _currentState; }
        bool setGameState(GameState newState);
        bool addGameObject(GameObject& object);
        bool removeGameObject(GameObject& object);
    private:
        GameState _currentState;
        std::vector<GameObject> _gameObjects;
};
