#include "Input.h"

SDL_Event Input::event;
const Uint8* Input::keyboard_state; 
Uint8* Input::prev_keyboard_state;

Uint32 Input::mouse_state; 
Uint32 Input::prev_mouse_state;

int Input::MAX_KEYS;
MousePosition Input::mouse_pos;

void Input::BCE_Input_Init()
{
	SDL_PollEvent(&event);
    keyboard_state = SDL_GetKeyboardState(&MAX_KEYS);
    prev_keyboard_state = new Uint8[MAX_KEYS];
}

void Input::Update()
{
    memcpy(prev_keyboard_state, keyboard_state, MAX_KEYS);
    prev_mouse_state = mouse_state;
    SDL_PollEvent(&event);
    mouse_state = SDL_GetMouseState(&(mouse_pos.x), &(mouse_pos.y));
}

bool Input::is_key_pressed(int keycode)
{
    return keyboard_state[keycode];
}

bool Input::is_key_down(int keycode)
{
    return !prev_keyboard_state[keycode] && keyboard_state[keycode];
}

Uint32 Input::event_type()
{
    return event.type;
}

bool Input::is_button_pressed(int button)
{
    return mouse_state & SDL_BUTTON(button);
}

bool Input::is_button_down(int button)
{
    return !(prev_mouse_state & SDL_BUTTON(button)) && (mouse_state & SDL_BUTTON(button));
}

bool Input::is_button_up(int button)
{
    return !(prev_mouse_state & SDL_BUTTON(button)) && (mouse_state & SDL_BUTTON(button));
}