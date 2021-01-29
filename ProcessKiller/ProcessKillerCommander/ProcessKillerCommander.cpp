#include <iostream>
#include <string>

#include "Windows.h"

struct KillProcessArgs {
	UINT32 pid;
};

int main(int argc, char** argv) {

	std::cout << "start process killer commander" << std::endl;
	if (argc != 2) {
		std::cout << "invalid number of arguments" << std::endl;
		return 1;
	}
	
	auto handle = CreateFileA("\\\\.\\ProcessKiller", GENERIC_ALL, 
		0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (INVALID_HANDLE_VALUE == handle) {
        std::cout << "open ProcessKiller handle failed" << std::endl;
        return 1;
    }
	KillProcessArgs args = {static_cast<UINT32>(std::stoi(argv[1]))};
	DWORD returned_bytes = 0;
    if (!DeviceIoControl(handle, 0x1337, &args, sizeof args,
		nullptr, 0, &returned_bytes, nullptr)) {
		std::cout << "device ioctl failed" << std::endl;
		CloseHandle(handle);
		return 1;
    }

	std::cout << "device ioctl succeeded" << std::endl;

	CloseHandle(handle);
	return 0;
}

