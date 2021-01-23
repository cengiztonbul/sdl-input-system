  #pragma once
#include <iostream>
#include <algorithm>

#include <SDL/SDL_events.h>
#include <SDL/SDL_keyboard.h>
#include <SDL/SDL_keycode.h>
#include <SDL/SDL_mouse.h>
#include "keycodes.h"

struct MousePosition
{
	int x, y;
};

class Input
{
private:
    static SDL_Event event;
    
    static int MAX_KEYS;
    static const Uint8 *keyboard_state;
    static Uint8 *prev_keyboard_state;

    static int MAX_BUTTONS;
    static Uint32 mouse_state;
    static Uint32 prev_mouse_state;

public:
    static MousePosition mouse_pos;
	
public:
    static void BCE_Input_Init();
    static void Update();

public:
    static bool is_key_pressed(int keycode);
    static bool is_key_down(int keycode);

    static bool is_button_pressed(int button);
    static bool is_button_down(int button);
    static bool is_button_up(int button);
    
    static Uint32 event_type();
};