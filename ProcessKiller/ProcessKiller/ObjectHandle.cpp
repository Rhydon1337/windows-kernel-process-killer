#include "ObjectHandle.h"

ObjectHandle::ObjectHandle(PVOID object, ACCESS_MASK desired_access)
	: m_handle(nullptr){
	auto nt_status = ObOpenObjectByPointer(object, OBJ_KERNEL_HANDLE,
		nullptr, desired_access, *PsProcessType, KernelMode, &m_handle);
	if (STATUS_SUCCESS != nt_status) {
		m_handle = nullptr;
	}
}

ObjectHandle::~ObjectHandle() {
	if (nullptr != m_handle) {
		ZwClose(m_handle);
	}
}

HANDLE ObjectHandle::get() const {
	return m_handle;
}
