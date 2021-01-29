#pragma once
#include <wdm.h>

struct KillProcessArgs {
	UINT32 pid;
};

NTSTATUS kill_process(const KillProcessArgs& process_to_kill);