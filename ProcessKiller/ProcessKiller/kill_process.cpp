#include "kill_process.h"

#include "ProcessReference.h"
#include "ObjectHandle.h"

NTSTATUS kill_process(const KillProcessArgs& args) {
	if (args.pid <= 0) {
		return STATUS_INVALID_PARAMETER;
	}
	ProcessReference eprocess(args.pid);
	if (nullptr == eprocess.get()) {
		return STATUS_INVALID_PARAMETER;
	}

	
	ObjectHandle handle(eprocess.get(), GENERIC_ALL);
	if (nullptr == handle.get()) {
		return STATUS_INVALID_PARAMETER;
	}

	return ZwTerminateProcess(handle.get(), 0);;
}
