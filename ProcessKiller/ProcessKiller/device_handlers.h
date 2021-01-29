#pragma once
#include <wdm.h>

#define KILL_PROCESS_IOCTL CTL_CODE(FILE_DEVICE_UNKNOWN, 0x1337, METHOD_BUFFERED, FILE_WRITE_DATA)

NTSTATUS device_create_close(PDEVICE_OBJECT device_object, PIRP irp);

NTSTATUS device_ioctl(PDEVICE_OBJECT device_object, PIRP irp);