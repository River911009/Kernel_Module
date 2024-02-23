
# Kernel_Module
A learning note about creating Embedded Linux Kernel Module.

---

## Hardware Environment
- Broadcom BCM2711, Quad core Cortex-A72 (ARM v8) 64-bit SoC
- CPU Architecture: aarch64

---

## Software Environment
- OS: Debian GNU/Linux 12 (bookworm)
- Kernel: 6.1.0-rpi8-rpi-v8
- GNU GCC: Debian 12.2.0-14
- GNU Make: 4.3

---

## Development Environment Setup
I use SSH tool to connect to my Raspberry pi through a WIFI router.
So I can plug in only one power cable to the PI.

To setup this environment, below are those steps:
1. Write Raspbian IMG into the micro SD card with official Raspberry PI Imager.
2. Insert the micro SD card, then connect an HDMI screen, a keyboard and the power adapter.
3. When the first boot up, follow the setup step to config the language, keyboard type and WIFI password.
4. After reboot, open Terminal to enable some interfaces using "raspi-config" tool.
```bash
$sudo raspi-config
3 Interface Options -> I1 SSH -> <Yes>
3 Interface Options -> I2 VNC -> <Yes> (optional)
3 Interface Options -> I3 SPI -> <Yes> (optional, would be use later)
3 Interface Options -> I4 I2C -> <Yes> (optional, would be use later)
```
5. Reboot again, and now it doesn't need the screen and keyboard anymore.

---

## Compile and Load Module

1. Compile module
```bash
$make
```
if compile was successful, there are some files created in the project folder.
```bash
$ls
Makefile
modules.order
Module.symvers
$(MODULE_NAME).c
$(MODULE_NAME).ko
$(MODULE_NAME).mod
$(MODULE_NAME).mod.c
$(MODULE_NAME).mod.o
$(MODULE_NAME).o
```
and we will load the .ko module to the kernel space by root user.

2. List out modules loaded at kernel space.
```bash
$sudo lsmod
```

3. The message log
```bash
$sudo dmesg
```
it log the printk in kernel space.

4. Insert and Remove Module
Insert the module
```bash
$sudo insmod $(MODULE_NAME).ko
```
Remove the module
```bash
$sudo rmmod $(MODULE_NAME)
```

---
Written by [River](https://github.com/River911009) at 23 Feb 2024.
