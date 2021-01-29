#pragma once

#include <ntifs.h>

class ProcessReference {
public:
	ProcessReference(size_t process_id);
	~ProcessReference();
	PEPROCESS get() const;
	
private:
	PEPROCESS m_process;
};

