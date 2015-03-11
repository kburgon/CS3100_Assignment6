# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kevin/Documents/CS3100/CS3100_Assignment6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kevin/Documents/CS3100/CS3100_Assignment6

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kevin/Documents/CS3100/CS3100_Assignment6/CMakeFiles /home/kevin/Documents/CS3100/CS3100_Assignment6/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kevin/Documents/CS3100/CS3100_Assignment6/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named SchedulerSimulator

# Build rule for target.
SchedulerSimulator: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SchedulerSimulator
.PHONY : SchedulerSimulator

# fast build rule for target.
SchedulerSimulator/fast:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/build
.PHONY : SchedulerSimulator/fast

Burst.o: Burst.cpp.o
.PHONY : Burst.o

# target to build an object file
Burst.cpp.o:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Burst.cpp.o
.PHONY : Burst.cpp.o

Burst.i: Burst.cpp.i
.PHONY : Burst.i

# target to preprocess a source file
Burst.cpp.i:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Burst.cpp.i
.PHONY : Burst.cpp.i

Burst.s: Burst.cpp.s
.PHONY : Burst.s

# target to generate assembly for a file
Burst.cpp.s:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Burst.cpp.s
.PHONY : Burst.cpp.s

Event.o: Event.cpp.o
.PHONY : Event.o

# target to build an object file
Event.cpp.o:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Event.cpp.o
.PHONY : Event.cpp.o

Event.i: Event.cpp.i
.PHONY : Event.i

# target to preprocess a source file
Event.cpp.i:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Event.cpp.i
.PHONY : Event.cpp.i

Event.s: Event.cpp.s
.PHONY : Event.s

# target to generate assembly for a file
Event.cpp.s:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Event.cpp.s
.PHONY : Event.cpp.s

EventQueue.o: EventQueue.cpp.o
.PHONY : EventQueue.o

# target to build an object file
EventQueue.cpp.o:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/EventQueue.cpp.o
.PHONY : EventQueue.cpp.o

EventQueue.i: EventQueue.cpp.i
.PHONY : EventQueue.i

# target to preprocess a source file
EventQueue.cpp.i:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/EventQueue.cpp.i
.PHONY : EventQueue.cpp.i

EventQueue.s: EventQueue.cpp.s
.PHONY : EventQueue.s

# target to generate assembly for a file
EventQueue.cpp.s:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/EventQueue.cpp.s
.PHONY : EventQueue.cpp.s

Processor.o: Processor.cpp.o
.PHONY : Processor.o

# target to build an object file
Processor.cpp.o:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Processor.cpp.o
.PHONY : Processor.cpp.o

Processor.i: Processor.cpp.i
.PHONY : Processor.i

# target to preprocess a source file
Processor.cpp.i:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Processor.cpp.i
.PHONY : Processor.cpp.i

Processor.s: Processor.cpp.s
.PHONY : Processor.s

# target to generate assembly for a file
Processor.cpp.s:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Processor.cpp.s
.PHONY : Processor.cpp.s

ReadyQueue.o: ReadyQueue.cpp.o
.PHONY : ReadyQueue.o

# target to build an object file
ReadyQueue.cpp.o:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/ReadyQueue.cpp.o
.PHONY : ReadyQueue.cpp.o

ReadyQueue.i: ReadyQueue.cpp.i
.PHONY : ReadyQueue.i

# target to preprocess a source file
ReadyQueue.cpp.i:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/ReadyQueue.cpp.i
.PHONY : ReadyQueue.cpp.i

ReadyQueue.s: ReadyQueue.cpp.s
.PHONY : ReadyQueue.s

# target to generate assembly for a file
ReadyQueue.cpp.s:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/ReadyQueue.cpp.s
.PHONY : ReadyQueue.cpp.s

Scheduler.o: Scheduler.cpp.o
.PHONY : Scheduler.o

# target to build an object file
Scheduler.cpp.o:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Scheduler.cpp.o
.PHONY : Scheduler.cpp.o

Scheduler.i: Scheduler.cpp.i
.PHONY : Scheduler.i

# target to preprocess a source file
Scheduler.cpp.i:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Scheduler.cpp.i
.PHONY : Scheduler.cpp.i

Scheduler.s: Scheduler.cpp.s
.PHONY : Scheduler.s

# target to generate assembly for a file
Scheduler.cpp.s:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Scheduler.cpp.s
.PHONY : Scheduler.cpp.s

Task.o: Task.cpp.o
.PHONY : Task.o

# target to build an object file
Task.cpp.o:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Task.cpp.o
.PHONY : Task.cpp.o

Task.i: Task.cpp.i
.PHONY : Task.i

# target to preprocess a source file
Task.cpp.i:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Task.cpp.i
.PHONY : Task.cpp.i

Task.s: Task.cpp.s
.PHONY : Task.s

# target to generate assembly for a file
Task.cpp.s:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/Task.cpp.s
.PHONY : Task.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/SchedulerSimulator.dir/build.make CMakeFiles/SchedulerSimulator.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... SchedulerSimulator"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Burst.o"
	@echo "... Burst.i"
	@echo "... Burst.s"
	@echo "... Event.o"
	@echo "... Event.i"
	@echo "... Event.s"
	@echo "... EventQueue.o"
	@echo "... EventQueue.i"
	@echo "... EventQueue.s"
	@echo "... Processor.o"
	@echo "... Processor.i"
	@echo "... Processor.s"
	@echo "... ReadyQueue.o"
	@echo "... ReadyQueue.i"
	@echo "... ReadyQueue.s"
	@echo "... Scheduler.o"
	@echo "... Scheduler.i"
	@echo "... Scheduler.s"
	@echo "... Task.o"
	@echo "... Task.i"
	@echo "... Task.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

