# WebUI

[![Website](https://img.shields.io/circleci/project/github/badges/shields/master?style=for-the-badge)](https://github.com/alifcommunity/webui) [![Website](https://img.shields.io/github/issues/alifcommunity/webui.svg?branch=master&style=for-the-badge&url=https://google.com)](https://github.com/alifcommunity/webui/issues) [![Website](https://img.shields.io/website?label=webui.me&style=for-the-badge&url=https://google.com)](https://webui.me/)

> Use any web browser as GUI, with your preferred language in the backend, and HTML/JS/TS/CSS in the frontend.

![ScreenShot](screenshot.png)

> :warning: **Notice**:
> 
> * WebUI it's not a web-server solution or a framework, but it's an easy-embeddable tool to use any installed web browser as a user interface.
> 
> * We are currently writing documentation.
> 
> * WebUI is not ready yet for production release.

## Features

- Written in Pure C
- Fully Independent (*No need for any third-party library*)
- Lightweight (*~160 Kb using TCC*) & Small memory footprint
- Fast WS binary communication (*App--WebUI--Browser*)
- One header file
- Multi-platform & Multi-Browser
- Using private profile for safety

## CppCon 2019 Presentation

[Borislav Stanimirov](https://ibob.bg/) discusses using HTML5 in the web browser as GUI at the [C++ conference 2019](https://cppcon.org/).

<div align="center">
  <a href="https://www.youtube.com/watch?v=bbbcZd4cuxg"><img src="https://img.youtube.com/vi/bbbcZd4cuxg/0.jpg" alt="Embrace Modern Technology: Using HTML 5 for GUI in C++ - Borislav Stanimirov - CppCon 2019"></a>
</div>

## UI & The Web Technologies

Web application UI design is not just about how a product looks but how it works. Using web technologies in your UI makes your product modern and professional, And a well-designed web application will help you make a solid first impression on potential customers. Great web application design also assists you in nurturing leads and increasing conversions. In addition, it makes navigating and using your web app easier for your users.

## Why Use Web Browser?

Today's web browsers have everything a modern UI needs. Web browsers are very sophisticated and optimized. Therefore, using it as a GUI will be an excellent choice. While old legacy GUI lib is complex and outdated, a WebView-based app is still an option. However, a WebView needs a huge SDK to build and many dependencies to run, and it can only provide some features like a real web browser. That is why WebUI uses real web browsers to give you full features of comprehensive web technologies while keeping your software lightweight and portable.

## How does it work?

![ScreenShot](webui_diagram.png)

Think of WebUI like a WebView controller, but instead of embedding the WebView controller in your program, which makes the final program big in size and non-portable as it needs the WebView runtimes. Instead, using WebUI, you use a tiny static/dynamic library to run any installed web browser and use it as GUI by communicating with it using a WebSocket, which makes your program small, fast, and portable. **All it needs is a web browser**.

## Runtime Dependencies

|  | WebView | Qt | WebUI |
| ------ | ------ | ------ | ------ |
| Runtime Dependencies on Windows | *WebView2* | *QtCore, QtGui, QtWidgets* | *Any Web Browser* |
| Runtime Dependencies on Linux | *GTK3, WebKitGTK* | *QtCore, QtGui, QtWidgets* | *Any Web Browser* |
| Runtime Dependencies on macOS | *Cocoa, WebKit* | *QtCore, QtGui, QtWidgets* | *Any Web Browser* |

## Documentation

 - [Online Documentation](https://webui.me/docs/)

## Build

 - [Windows](https://github.com/alifcommunity/webui/tree/main/build/Windows)
 - [Linux](https://github.com/alifcommunity/webui/tree/main/build/Linux)

## Examples

 - [C](https://github.com/alifcommunity/webui/tree/main/examples/C)
 - [C++](https://github.com/alifcommunity/webui/tree/main/examples/C++)
 - [Python](https://github.com/alifcommunity/webui/tree/main/examples/Python)
 - [TypeScript / JavaScript](https://github.com/alifcommunity/webui/tree/main/examples/TypeScript)
 - [Go](https://github.com/alifcommunity/webui/tree/main/examples/Go/hello_world)
 - [Rust](https://github.com/alifcommunity/webui/tree/main/examples/Rust/hello_world)
 - [V - malisipi/vwebui](https://github.com/malisipi/vwebui/tree/main/examples)
 - [Nim - neroist/webui](https://github.com/neroist/webui/tree/main/examples)
 - [Zig](https://github.com/alifcommunity/webui/tree/main/examples/Zig)

## Supported Browser

| OS | Browser | Status |
| ------ | ------ | ------ |
| Windows | Firefox | ✔️ |
| Windows | Chrome | ✔️ |
| Windows | Edge | ✔️ |
| Linux | Firefox | ✔️ |
| Linux | Chrome | ✔️ |
| macOS | Firefox | *coming soon* |
| macOS | Chrome | *coming soon* |
| macOS | Safari | *coming soon* |

## Supported Language

| Language | Status | Link |
| ------ | ------ | ------ |
| C | ✔️ | [examples/C](https://github.com/alifcommunity/webui/tree/main/examples/C) |
| C++ | ✔️ | [examples/C++](https://github.com/alifcommunity/webui/tree/main/examples/C%2B%2B) |
| Python | ✔️ | [examples/Python](https://github.com/alifcommunity/webui/tree/main/examples/Python) |
| JavaScript | ✔️ | [examples/TypeScript/Nodejs](https://github.com/alifcommunity/webui/tree/main/examples/TypeScript/Nodejs) |
| TypeScript | ✔️ | [examples/TypeScript/Deno](https://github.com/alifcommunity/webui/tree/main/examples/TypeScript/Deno) |
| Go | ✔️ | [examples/Go](https://github.com/alifcommunity/webui/tree/main/examples/Go) |
| Rust | ✔️ | [examples/Rust](https://github.com/alifcommunity/webui/tree/main/examples/Rust) |
| V | ✔️ | [malisipi/vwebui](https://github.com/malisipi/vwebui) |
| Nim | ✔️ | [neroist/webui](https://github.com/neroist/webui) |
| Zig | ✔️ | [examples/Zig](https://github.com/alifcommunity/webui/tree/main/examples/Zig) |

### License

> GNU General Public License v3.0

### Contributions

Contributions are welcome! Please follow the guidelines below:

 - Please create PRs on the beta branches
 - Make sure that PRs deal with one issue only

### Stargazers

[![Stargazers repo roster for @alifcommunity/webui](https://reporoster.com/stars/alifcommunity/webui)](https://github.com/alifcommunity/webui/stargazers)
