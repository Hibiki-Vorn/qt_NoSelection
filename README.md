# Qt NoSelection

A fun little Qt/QML + C++ program that displays the question **“Are you idiot?”** with two interactive buttons: **YES** and **NO**.
The **NO** button runs away from the mouse cursor, while clicking **YES** shows a message box.

## Features

* Display text: “Are you idiot?”
* **YES** button: shows a message box when clicked.
* **NO** button: moves randomly when the mouse hovers over it.
* Built with **Qt Quick Controls 2** and **Material theme**.
* Cross-platform (Windows / Linux / macOS).

## Demo

```
[Place a screenshot or GIF here showing the NO button moving away from the cursor]
```

## Project Structure

```
qt_NoSelection/
├── main.cpp           # Program entry, loads QML
├── main.h             # WindowAction class, handles button logic
├── main.qml           # QML UI
├── resources.qrc      # Resource file, includes images
├── msgboxicon_no.jpg  # Icon used in message box
└── CMakeLists.txt     # CMake build configuration
```

## Build & Run

### 1. Install dependencies

* Qt 6.x
* CMake 3.16+
* Qt Quick Controls 2

On Ubuntu/Linux:

```bash
sudo apt install qt6-base-dev qt6-qml-dev cmake build-essential
```

### 2. Build the project

```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
```

### 3. Run the program

```bash
./qt_NoSelection
```

## Customization

* Modify `main.qml` to change button positions, colors, or fonts.
* Extend the `WindowAction` class to add new interactions or effects.

## Author

Hieronymus
