### Deno Server

This example shows how to show a simple WebUI window using a Deno-Web-Server.

 1. Download and [Install Deno](https://github.com/denoland/deno/releases) (*Or just copy deno binary file into this folder*)
 2. Download WebUI pre-built Library (*[webui.me](https://webui.me/)*)
 3. Run `deno run --allow-all --unstable deno_server.ts`

Folder structure example (*Windows*)

    [My Folder]
	    * deno.exe (if not installed)
	    * deno_server.ts --> Import webui.ts -> Load `webui-2-x64` library
	    * file1.js
	    * file2.ts
	    * ...
