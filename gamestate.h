#include <vector>

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
        void (*onCollision)(const GameObject& other, Direction direction);
};

class GamePiece : public GameObject {
};

template <int ROWS, int COLS>
class GameBoard : public GameObject {
    public:
        GameBoard() {
            bitmap.resize(ROWS * COLS);
        }
        // returns all objects that are adjacent in the given direction
        // may return a zero-length vector
        const std::vector<GameObject> adjacentObjectsInDirection(Direction direction);
};

class Game {
    public:
        // The main game engine.
        void advanceState();
        Game() : currentState(INITIAL) {
        }
        const GameState gameState() const { return _currentState; }
    private:
        GameBoard _gameBoard;
        GameState _currentState;
};
