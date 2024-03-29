# controller-node

The Gamepad interface offers a foundational mechanism for capturing input from USB gaming controllers. It maps each control element on a connected game controller to one or more buttons and one or more axes. Buttons act as on/off switches, whereas axes provide continuous values that range from -1.0f to 1.0f. The specific elements available and their sequence are determined by the operating system and the driver in use.

For typical implementation: Initiate by setting up a callback with Gamepad_deviceAttachFunc() to receive alerts when a new device connects, followed by executing Gamepad_init() and Gamepad_detectDevices(). This setup ensures your callback is activated for each game controller connection. Furthermore, to track button presses, releases, and axis movements, establish callbacks using Gamepad_buttonDownFunc(), Gamepad_buttonUpFunc(), and Gamepad_axisMoveFunc(). To maintain up-to-date with events and newly connected devices post the initial Gamepad_init() execution, run Gamepad_processEvents() in every frame and Gamepad_detectDevices() periodically. For monitoring device disconnections, incorporate Gamepad_deviceRemoveFunc() into your callback notifications.

## Prerequisites

OpenGL: sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev