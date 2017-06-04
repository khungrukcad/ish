#include "emu/cpu.h"
#include "emu/interrupt.h"
#include "misc.h"

int handle_interrupt(struct cpu_state *cpu, int interrupt);

dword_t user_get(addr_t addr);
byte_t user_get8(addr_t addr);
void user_put(addr_t addr, dword_t value);
void user_put8(addr_t addr, byte_t value);
int user_get_string(addr_t addr, char *buf, size_t max);
void user_put_string(addr_t addr, const char *buf);
int user_get_count(addr_t addr, void *buf, size_t count);
void user_put_count(addr_t addr, const void *buf, size_t count);

int sys_execve(const char *file, char *const argv[], char *const envp[]);
dword_t _sys_execve(addr_t file, addr_t argv, addr_t envp);

dword_t sys_exit(dword_t status);

#define MAX_PATH 4096
int sys_open(const char *pathname, int flags);
int sys_close(int fd);
dword_t sys_readlink(addr_t pathname, addr_t buf, dword_t bufsize);

ssize_t sys_write(int fd, const char *buf, size_t count);
dword_t _sys_write(dword_t fd, addr_t data, dword_t count);

addr_t sys_brk(addr_t new_brk);
int handle_pagefault(addr_t addr);

#define UNAME_LENGTH 65
struct uname {
    char system[UNAME_LENGTH];   // Linux
    char hostname[UNAME_LENGTH]; // my-compotar
    char release[UNAME_LENGTH];  // 1.2.3-ish
    char version[UNAME_LENGTH];  // SUPER AWESOME
    char arch[UNAME_LENGTH];     // i686
    char domain[UNAME_LENGTH];   // lol
};
int sys_uname(struct uname *uts);
dword_t _sys_uname(addr_t uts_addr);

int sys_set_thread_area(addr_t u_info);

typedef int (*syscall_t)(dword_t,dword_t,dword_t,dword_t,dword_t,dword_t);