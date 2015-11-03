typedef enum {
    KEYBOARD_EVENT,
    MOUSE_EVENT
} InputEventType;

struct InputEvent {
    virtual InputEventType eventType() const = 0;
};

struct KeyboardEvent : InputEvent {
    InputEventType eventType() const { return KEYBOARD_EVENT; }
    int keyValue;
}

struct MouseEvent : InputEvent {
    InputEventType eventType() const { return MOUSE_EVENT; }
    int xPos, yPos;
    int buttonMap;
}
