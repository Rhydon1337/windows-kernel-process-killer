# windows-kernel-process-killer
Force kill a process using windows kernel driver.

Use a kernel driver to open a kernel handle to the process.

## Usage

sc create ProcessKiller binPath={ProcessKillerDriverFullPath.sys} type=kernel

sc start ProcessKiller

ProcessKillerCommander.exe {pid}

DONE!!!