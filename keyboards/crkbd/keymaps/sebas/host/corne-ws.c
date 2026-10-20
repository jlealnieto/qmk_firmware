// Copyright 2026 Sebastian Leal (@jlealnieto)
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Envía el workspace activo de AeroSpace al Corne por Raw HID, para mostrarlo en la OLED.
// Lo llama AeroSpace desde `exec-on-workspace-change` en ~/.aerospace.toml.
//
// Compilar:
//   clang -O2 -o ~/.local/bin/corne-ws corne-ws.c \
//     -I/opt/homebrew/include/hidapi -L/opt/homebrew/lib -lhidapi
// Uso:
//   corne-ws 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hidapi.h>

#define CORNE_VID 0x4653
#define CORNE_PID 0x0001
// Interfaz Raw HID de QMK
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define REPORT_SIZE 32
#define WS_NAME_LEN 5

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "uso: corne-ws <workspace>\n");
        return 2;
    }
    if (hid_init() != 0) {
        return 1;
    }

    // El teclado expone varias interfaces HID; solo la de Raw HID acepta estos reportes
    char *path = NULL;
    struct hid_device_info *devs = hid_enumerate(CORNE_VID, CORNE_PID);
    for (struct hid_device_info *d = devs; d; d = d->next) {
        if (d->usage_page == RAW_USAGE_PAGE && d->usage == RAW_USAGE_ID) {
            path = strdup(d->path);
            break;
        }
    }
    hid_free_enumeration(devs);

    // Sin teclado conectado no es un error: AeroSpace llama a esto en cada cambio
    if (!path) {
        hid_exit();
        return 0;
    }

    hid_device *dev = hid_open_path(path);
    free(path);
    if (!dev) {
        hid_exit();
        return 1;
    }

    // Primer byte = report ID (0 en QMK), después 'W' + nombre del workspace
    unsigned char buf[REPORT_SIZE + 1] = {0};
    buf[1] = 'W';
    strncpy((char *)&buf[2], argv[1], WS_NAME_LEN);
    int res = hid_write(dev, buf, sizeof(buf));

    hid_close(dev);
    hid_exit();
    return res < 0 ? 1 : 0;
}
