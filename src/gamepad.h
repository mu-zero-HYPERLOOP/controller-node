#ifndef GAMEPAD_H
#define GAMEPAD_H

#ifdef __cplusplus
extern "C" {
#endif

// Use standard boolean types for C99 and later, ensure compatibility with older MSVC versions
#if defined(_MSC_VER) && (_MSC_VER <= 1600)
typedef int bool;
#define true 1
#define false 0
#else
#include <stdbool.h>
#endif

// Structure representing a gamepad device
typedef struct Gamepad_device {
    // Unique identifier for the device within the application session. It starts at 0 for the first attached device
    // and increments by 1 for each additional device. If a device is removed and then reattached, it receives a new ID.
    unsigned int deviceID;

    // A human-friendly name for the device
    const char *description;

    // USB vendor and product IDs, useful for identifying specific models
    int vendorID;
    int productID;

    // Count of axis and button elements on the device
    unsigned int numAxes;
    unsigned int numButtons;

    // Arrays storing the current state of each axis (range -1 to 1) and button (pressed or not)
    float *axisStates;
    bool *buttonStates;

    // Platform-specific storage for device data. Direct manipulation is not recommended.
    void *privateData;
} Gamepad_device;

// Initializes the gamepad library and detects initial devices. This must be the first Gamepad_* function called,
// except for callback registration functions. To receive attach callbacks for initial devices, register before initializing.
void Gamepad_init();

// Cleans up resources allocated by the gamepad library. Calling this function is optional at application termination,
// but useful for earlier resource release.
void Gamepad_shutdown();

// Returns the count of currently attached gamepad devices.
unsigned int Gamepad_numDevices();

// Retrieves a pointer to a gamepad device struct by index, or NULL if the index is invalid.
Gamepad_device *Gamepad_deviceAtIndex(unsigned int deviceIndex);

// Detects newly attached devices since the last detection call, triggering attach callbacks for any found.
void Gamepad_detectDevices();

// Processes input from all attached devices, triggering registered input callbacks.
void Gamepad_processEvents();

// Sets a callback for device attachment events, occurring during initialization and device detection.
void Gamepad_deviceAttachFunc(void (*callback)(Gamepad_device *device, void *context), void *context);

// Sets a callback for device detachment events, which may be triggered at any time.
void Gamepad_deviceRemoveFunc(void (*callback)(Gamepad_device *device, void *context), void *context);

// Sets a callback for button press events on any device, called during event processing.
void Gamepad_buttonDownFunc(void (*callback)(Gamepad_device *device, unsigned int buttonID, double timestamp, void *context), void *context);

// Sets a callback for button release events on any device, called during event processing.
void Gamepad_buttonUpFunc(void (*callback)(Gamepad_device *device, unsigned int buttonID, double timestamp, void *context), void *context);

// Sets a callback for axis movement events on any device, called during event processing.
void Gamepad_axisMoveFunc(void (*callback)(Gamepad_device *device, unsigned int axisID, float value, float lastValue, double timestamp, void *context), void *context);

#ifdef __cplusplus
}
#endif
#endif // GAMEPAD_H
