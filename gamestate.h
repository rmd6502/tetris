#include <vector>

typedef enum {
    INITIAL,
    IDLE,
    ATTRACT,
    PLAYING,
    DYING,
} GameState;

class GameObject {
    public:
        init();
        std::vector<int> bitmap;
        time_t nextaction;
};

class Game {
    public:
        void advanceState();
    private:
        std::vector<GameObject> _gameObjects;
        GameState currentState;
};
