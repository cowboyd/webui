/*
    WebUI Library 2.0.7
    
    http://webui.me
    https://github.com/alifcommunity/webui

    Licensed under GNU Lesser General Public License v2.1.
    Copyright (C)2023 Hassan DRAGA <https://github.com/hassandraga> - Canada.
*/

#ifndef _WEBUI_H
#define _WEBUI_H

#if defined(_MSC_VER) || defined(__TINYC__)
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT extern
#endif

#define WEBUI_VERSION           "2.0.7"     // Version
#define WEBUI_HEADER_SIGNATURE  0xFF        // All packets should start with this 8bit
#define WEBUI_HEADER_JS         0xFE        // Javascript result in frontend
#define WEBUI_HEADER_CLICK      0xFD        // Click event
#define WEBUI_HEADER_SWITCH     0xFC        // Frontend refresh
#define WEBUI_HEADER_CLOSE      0xFB        // Close window
#define WEBUI_HEADER_CALL_FUNC  0xFA        // Call a backend function
#define WEBUI_MAX_ARRAY         (1024)      // Max threads, servers, windows, pointers..
#define WEBUI_MIN_PORT          (10000)     // Minimum socket port
#define WEBUI_MAX_PORT          (65500)     // Should be less than 65535
#define WEBUI_MAX_BUF           (1024000)   // 1024 Kb max dynamic memory allocation
#define WEBUI_DEFAULT_PATH      "."         // Default root path
#define WEBUI_DEF_TIMEOUT       (8)         // Default startup timeout in seconds

// -- C STD ---------------------------
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <time.h>
#include <errno.h>
#include <math.h>
#if defined(__GNUC__) || defined(__TINYC__)
    #include <dirent.h>
#endif

// -- Windows -------------------------
#ifdef _WIN32
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    // #include <SDKDDKVer.h> // Fix _WIN32_WINNT warning
    #include <windows.h>
    #include <winsock2.h>
    #include <ws2tcpip.h>
    // #include <iphlpapi.h>
    #include <direct.h>
    #include <io.h>
    #include <tchar.h>
    #define WEBUI_GET_CURRENT_DIR _getcwd
    #define WEBUI_FILE_EXIST _access
    #define WEBUI_POPEN _popen
    #define WEBUI_PCLOSE _pclose
    #define WEBUI_MAX_PATH MAX_PATH
#endif
// -- Linux ---------------------------
#ifdef __linux__
    #include <pthread.h> // POSIX threading
    #include <unistd.h>
    #include <limits.h>
    #include <dirent.h>
    #include <sys/socket.h>
    #include <fcntl.h>
    #include <poll.h>
    #define WEBUI_GET_CURRENT_DIR getcwd
    #define WEBUI_FILE_EXIST access
    #define WEBUI_POPEN popen
    #define WEBUI_PCLOSE pclose
    #define WEBUI_MAX_PATH PATH_MAX
#endif

// -- Structs -------------------------
struct webui_event_t;
typedef struct webui_timer_t {
    struct timespec start;
    struct timespec now;
} webui_timer_t;
typedef struct webui_window_core_t {
    unsigned int window_number;
    bool server_running;
    bool connected;
    bool server_handled;
    bool multi_access;
    bool server_root;
    unsigned int server_port;
    bool is_bind_all;
    char* url;
    void (*cb_all[1])(struct webui_event_t* e);
    const char* html;
    const char* html_cpy;
    const char* icon;
    const char* icon_type;
    unsigned int CurrentBrowser;
    char* browser_path;
    char* profile_path;
    unsigned int connections;
    unsigned int runtime;
    bool detect_process_close;
    #ifdef _WIN32
        HANDLE server_thread;
    #else
        pthread_t server_thread;
    #endif
} webui_window_core_t;
typedef struct webui_window_t {
    webui_window_core_t core;
    char* path;
} webui_window_t;
typedef struct webui_event_t {
    unsigned int window_id;
    unsigned int element_id;
    char* element_name;
    webui_window_t* window;
    void* data;
    void* response;
} webui_event_t;
typedef struct webui_javascript_result_t {
    bool error;
    unsigned int length;
    const char* data;
} webui_javascript_result_t;
typedef struct webui_script_t {
    const char* script;
    unsigned int timeout;
    webui_javascript_result_t result;
} webui_script_t;
typedef struct webui_cb_t {
    webui_window_t* win;
    char* webui_internal_id;
    char* element_name;
    void* data;
} webui_cb_t;
typedef struct webui_cmd_async_t {
    webui_window_t* win;
    char* cmd;
} webui_cmd_async_t;
typedef struct webui_custom_browser_t {
    char* app;
    char* arg;
    bool auto_link;
} webui_custom_browser_t;
typedef struct webui_browser_t {
    unsigned int any;       // 0
    unsigned int chrome;    // 1
    unsigned int firefox;   // 2
    unsigned int edge;      // 3
    unsigned int safari;    // 4
    unsigned int chromium;  // 5
    unsigned int custom;    // 99
} webui_browser_t;
typedef struct webui_runtime_t {
    unsigned int none;      // 0
    unsigned int deno;      // 1
    unsigned int nodejs;    // 2
} webui_runtime_t;
typedef struct webui_t {
    unsigned int servers;
    unsigned int connections;
    unsigned int process;
    webui_custom_browser_t *custom_browser;
    bool wait_for_socket_window;
    char* html_elements[WEBUI_MAX_ARRAY];
    unsigned int used_ports[WEBUI_MAX_ARRAY];
    unsigned int last_window;
    unsigned int startup_timeout;
    bool use_timeout;
    bool timeout_extra;
    bool exit_now;
    const char* run_responses[WEBUI_MAX_ARRAY];
    bool run_done[WEBUI_MAX_ARRAY];
    bool run_error[WEBUI_MAX_ARRAY];
    unsigned int run_last_id;
    struct mg_mgr* mg_mgrs[WEBUI_MAX_ARRAY];
    struct mg_connection* mg_connections[WEBUI_MAX_ARRAY];
    webui_browser_t browser;
    webui_runtime_t runtime;
    bool initialized;
    void (*cb[WEBUI_MAX_ARRAY])(webui_event_t* e);
    void (*cb_interface[WEBUI_MAX_ARRAY])(unsigned int, unsigned int, char*, webui_window_t*, char*, char**);
    void (*cb_interface_all[1])(unsigned int, unsigned int, char*, webui_window_t*, char*, char**);
    char* executable_path;
    void *ptr_list[WEBUI_MAX_ARRAY];
    unsigned int ptr_position;
    size_t ptr_size[WEBUI_MAX_ARRAY];
} webui_t;

// -- Definitions ---------------------
EXPORT webui_t webui;
EXPORT void webui_wait();
EXPORT void webui_exit();
EXPORT bool webui_is_any_window_running();
EXPORT bool webui_is_app_running();
EXPORT void webui_set_timeout(unsigned int second);
EXPORT webui_window_t* webui_new_window();
EXPORT bool webui_show(webui_window_t* win, const char* html, unsigned int browser);
EXPORT bool webui_show_cpy(webui_window_t* win, const char* html, unsigned int browser);
EXPORT bool webui_refresh(webui_window_t* win, const char* html);
EXPORT bool webui_refresh_cpy(webui_window_t* win, const char* html);
EXPORT void webui_set_icon(webui_window_t* win, const char* icon_s, const char* type_s);
EXPORT void webui_multi_access(webui_window_t* win, bool status);
EXPORT const char* webui_new_server(webui_window_t* win, const char* path);
EXPORT void webui_close(webui_window_t* win);
EXPORT bool webui_is_shown(webui_window_t* win);
EXPORT void webui_script(webui_window_t* win, webui_script_t* script);
EXPORT unsigned int webui_bind(webui_window_t* win, const char* element, void (*func)(webui_event_t* e));
EXPORT void webui_bind_all(webui_window_t* win, void (*func)(webui_event_t* e));
EXPORT bool webui_open(webui_window_t* win, const char* url, unsigned int browser);
EXPORT void webui_script_cleanup(webui_script_t* script);
EXPORT void webui_script_runtime(webui_window_t* win, unsigned int runtime);
EXPORT int webui_get_int(webui_event_t* e);
EXPORT const char* webui_get_string(webui_event_t* e);
EXPORT bool webui_get_bool(webui_event_t* e);
EXPORT void webui_return_int(webui_event_t* e, int n);
EXPORT void webui_return_string(webui_event_t* e, char* s);
EXPORT void webui_return_bool(webui_event_t* e, bool b);
EXPORT void webui_clean_mem(void* p);

// -- Interface -----------------------
// Used by other languages to create WebUI wrappers
typedef struct webui_script_interface_t {
    char* script;
    unsigned int timeout;
    bool error;
    unsigned int length;
    const char* data;
} webui_script_interface_t;
EXPORT unsigned int webui_bind_interface(webui_window_t* win, const char* element, void (*func)(unsigned int, unsigned int, char*, webui_window_t*, char*, char**));
EXPORT void webui_script_interface(webui_window_t* win, const char* script, unsigned int timeout, bool* error, unsigned int* length, char** data);
EXPORT void webui_script_interface_struct(webui_window_t* win, webui_script_interface_t* js_int);

// Core
EXPORT void _webui_init();
EXPORT unsigned int _webui_get_cb_index(char* webui_internal_id);
EXPORT unsigned int _webui_set_cb_index(char* webui_internal_id);
EXPORT unsigned int _webui_get_free_port();
EXPORT unsigned int _webui_get_new_window_number();
EXPORT void _webui_wait_for_startup();
EXPORT void _webui_free_port(unsigned int port);
EXPORT void _webui_set_custom_browser(webui_custom_browser_t* p);
EXPORT char* _webui_get_current_path();
EXPORT void _webui_window_receive(webui_window_t* win, const char* packet, size_t len);
EXPORT void _webui_window_send(webui_window_t* win, char* packet, size_t packets_size);
EXPORT void _webui_window_event(webui_window_t* win, char* element_id, char* element, void* data, unsigned int data_len);
EXPORT unsigned int _webui_window_get_number(webui_window_t* win);
EXPORT void _webui_window_open(webui_window_t* win, char* link, unsigned int browser);
EXPORT int _webui_cmd_sync(char* cmd, bool show);
EXPORT int _webui_cmd_async(char* cmd, bool show);
EXPORT int _webui_run_browser(webui_window_t* win, char* cmd);
EXPORT void _webui_clean();
EXPORT bool _webui_browser_exist(webui_window_t* win, unsigned int browser);
EXPORT const char* _webui_browser_get_temp_path(unsigned int browser);
EXPORT bool _webui_folder_exist(char* folder);
EXPORT bool _webui_browser_create_profile_folder(webui_window_t* win, unsigned int browser);
EXPORT bool _webui_browser_start_edge(webui_window_t* win, const char* address);
EXPORT bool _webui_browser_start_firefox(webui_window_t* win, const char* address);
EXPORT bool _webui_browser_start_custom(webui_window_t* win, const char* address);
EXPORT bool _webui_browser_start_chrome(webui_window_t* win, const char* address);
EXPORT bool _webui_browser_start(webui_window_t* win, const char* address, unsigned int browser);
EXPORT long _webui_timer_diff(struct timespec *start, struct timespec *end);
EXPORT void _webui_timer_start(webui_timer_t* t);
EXPORT bool _webui_timer_is_end(webui_timer_t* t, unsigned int ms);
EXPORT void _webui_timer_clock_gettime(struct timespec *spec);
EXPORT bool _webui_set_root_folder(webui_window_t* win, const char* path);
EXPORT void _webui_wait_process(webui_window_t* win, bool status);
EXPORT const char* _webui_generate_js_bridge(webui_window_t* win);
EXPORT void _webui_print_hex(const char* data, size_t len);
EXPORT void _webui_free_mem(void **p);
EXPORT bool _webui_file_exist_mg(void *ev_data);
EXPORT bool _webui_file_exist(char* file);
EXPORT void _webui_free_all_mem();
#ifdef _WIN32
    EXPORT DWORD WINAPI _webui_cb(LPVOID _arg);
    EXPORT DWORD WINAPI _webui_run_browser_task(LPVOID _arg);
    EXPORT int _webui_system_win32(char* cmd, bool show);
#else
    EXPORT void* _webui_cb(void* _arg);
    EXPORT void* _webui_run_browser_task(void* _arg);
#endif

#endif /* _WEBUI_H */
