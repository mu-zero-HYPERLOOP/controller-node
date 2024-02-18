#ifndef INTERNAL_EVENTS_H
#define INTERNAL_EVENTS_H

#include "gamepad.h" // Ensure Gamepad_device is known

// Enumerates types of gamepad events for clear event management
typedef enum {
	GAMEPAD_EVENT_DEVICE_ATTACHED,
	GAMEPAD_EVENT_DEVICE_REMOVED,
	GAMEPAD_EVENT_BUTTON_DOWN,
	GAMEPAD_EVENT_BUTTON_UP,
	GAMEPAD_EVENT_AXIS_MOVED
} Gamepad_eventType;

// Structure to represent button events with detailed information
typedef struct {
	struct Gamepad_device *device; // The device that generated the event
	double timestamp;              // Event time in seconds since the program started
	unsigned int buttonID;         // ID of the button involved in the event
	bool down;                     // State of the button: true if pressed
} Gamepad_buttonEvent;

// Structure to represent axis movement events with precise values
typedef struct {
	struct Gamepad_device *device; // The device that generated the event
	double timestamp;              // Event time in seconds since the program started
	unsigned int axisID;           // ID of the axis involved in the event
	float value;                   // Current axis position in the range [-1..1]
	float lastValue;               // Previous axis position in the range [-1..1]
} Gamepad_axisEvent;

// Declarations for callback function pointers with context support
extern void (*Gamepad_deviceAttachCallback)(struct Gamepad_device *device, void *context);
extern void (*Gamepad_deviceRemoveCallback)(struct Gamepad_device *device, void *context);
extern void (*Gamepad_buttonDownCallback)(struct Gamepad_device *device, unsigned int buttonID, double timestamp, void *context);
extern void (*Gamepad_buttonUpCallback)(struct Gamepad_device *device, unsigned int buttonID, double timestamp, void *context);
extern void (*Gamepad_axisMoveCallback)(struct Gamepad_device *device, unsigned int axisID, float value, float lastValue, double timestamp, void *context);

// Context pointers for each type of event callback
extern void *Gamepad_deviceAttachContext;
extern void *Gamepad_deviceRemoveContext;
extern void *Gamepad_buttonDownContext;
extern void *Gamepad_buttonUpContext;
extern void *Gamepad_axisMoveContext;

#endif // INTERNAL_EVENTS_H
