#pragma once

#include <ntifs.h>

class ObjectHandle {
public:
	ObjectHandle(PVOID object, ACCESS_MASK desired_access);
	~ObjectHandle();

	HANDLE get() const;

private:
	HANDLE m_handle;
};

