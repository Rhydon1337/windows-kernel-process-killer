#include "ProcessReference.h"

ProcessReference::ProcessReference(size_t process_id) :
	m_process(nullptr) {
	PsLookupProcessByProcessId(reinterpret_cast<HANDLE>(process_id), &m_process);
}

ProcessReference::~ProcessReference() {
	if (nullptr != m_process) {
		ObDereferenceObject(m_process);
	}
}

PEPROCESS ProcessReference::get() const {
	return m_process;
}
