#pragma once

#include <ntifs.h>

struct KillProcessArgs {
	UINT32 pid;
};

NTSTATUS kill_process(const KillProcessArgs& process_to_kill);