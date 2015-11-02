#include <vector>

typedef enum {
    INITIAL,
    IDLE,
    ATTRACT,
    PLAYING,
    DYING,
} GameState;

struct Pixel {
    unsigned char r,g,b;
    Pixel() : r(0), g(0), b(0) {}
};

class GameObject {
    public:
        std::vector<Pixel> bitmap;
        time_t nextaction;
        int xPos, yPos;
        // invoked by the game engine when we collide with another GameObject
        void (*onCollision)(const GameObject& other);
};

class GamePiece : public GameObject {
};

template <int ROWS, int COLS>
class GameBoard : public GameObject {
    public:
        GameBoard() {
            bitmap.resize(ROWS * COLS);
        }
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
        GamePiece _gamePiece;
        GameState _currentState;
};
