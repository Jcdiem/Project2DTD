# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/clion/124/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/124/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild

# Utility rule file for json-populate.

# Include the progress variables for this target.
include CMakeFiles/json-populate.dir/progress.make

CMakeFiles/json-populate: CMakeFiles/json-populate-complete


CMakeFiles/json-populate-complete: json-populate-prefix/src/json-populate-stamp/json-populate-install
CMakeFiles/json-populate-complete: json-populate-prefix/src/json-populate-stamp/json-populate-mkdir
CMakeFiles/json-populate-complete: json-populate-prefix/src/json-populate-stamp/json-populate-download
CMakeFiles/json-populate-complete: json-populate-prefix/src/json-populate-stamp/json-populate-update
CMakeFiles/json-populate-complete: json-populate-prefix/src/json-populate-stamp/json-populate-patch
CMakeFiles/json-populate-complete: json-populate-prefix/src/json-populate-stamp/json-populate-configure
CMakeFiles/json-populate-complete: json-populate-prefix/src/json-populate-stamp/json-populate-build
CMakeFiles/json-populate-complete: json-populate-prefix/src/json-populate-stamp/json-populate-install
CMakeFiles/json-populate-complete: json-populate-prefix/src/json-populate-stamp/json-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'json-populate'"
	/snap/clion/124/bin/cmake/linux/bin/cmake -E make_directory /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles
	/snap/clion/124/bin/cmake/linux/bin/cmake -E touch /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles/json-populate-complete
	/snap/clion/124/bin/cmake/linux/bin/cmake -E touch /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-done

json-populate-prefix/src/json-populate-stamp/json-populate-install: json-populate-prefix/src/json-populate-stamp/json-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'json-populate'"
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-build && /snap/clion/124/bin/cmake/linux/bin/cmake -E echo_append
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-build && /snap/clion/124/bin/cmake/linux/bin/cmake -E touch /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-install

json-populate-prefix/src/json-populate-stamp/json-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'json-populate'"
	/snap/clion/124/bin/cmake/linux/bin/cmake -E make_directory /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-src
	/snap/clion/124/bin/cmake/linux/bin/cmake -E make_directory /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-build
	/snap/clion/124/bin/cmake/linux/bin/cmake -E make_directory /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix
	/snap/clion/124/bin/cmake/linux/bin/cmake -E make_directory /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/tmp
	/snap/clion/124/bin/cmake/linux/bin/cmake -E make_directory /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp
	/snap/clion/124/bin/cmake/linux/bin/cmake -E make_directory /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src
	/snap/clion/124/bin/cmake/linux/bin/cmake -E make_directory /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp
	/snap/clion/124/bin/cmake/linux/bin/cmake -E touch /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-mkdir

json-populate-prefix/src/json-populate-stamp/json-populate-download: json-populate-prefix/src/json-populate-stamp/json-populate-gitinfo.txt
json-populate-prefix/src/json-populate-stamp/json-populate-download: json-populate-prefix/src/json-populate-stamp/json-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'json-populate'"
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps && /snap/clion/124/bin/cmake/linux/bin/cmake -P /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/tmp/json-populate-gitclone.cmake
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps && /snap/clion/124/bin/cmake/linux/bin/cmake -E touch /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-download

json-populate-prefix/src/json-populate-stamp/json-populate-update: json-populate-prefix/src/json-populate-stamp/json-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing update step for 'json-populate'"
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-src && /snap/clion/124/bin/cmake/linux/bin/cmake -P /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/tmp/json-populate-gitupdate.cmake

json-populate-prefix/src/json-populate-stamp/json-populate-patch: json-populate-prefix/src/json-populate-stamp/json-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'json-populate'"
	/snap/clion/124/bin/cmake/linux/bin/cmake -E echo_append
	/snap/clion/124/bin/cmake/linux/bin/cmake -E touch /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-patch

json-populate-prefix/src/json-populate-stamp/json-populate-configure: json-populate-prefix/tmp/json-populate-cfgcmd.txt
json-populate-prefix/src/json-populate-stamp/json-populate-configure: json-populate-prefix/src/json-populate-stamp/json-populate-update
json-populate-prefix/src/json-populate-stamp/json-populate-configure: json-populate-prefix/src/json-populate-stamp/json-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'json-populate'"
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-build && /snap/clion/124/bin/cmake/linux/bin/cmake -E echo_append
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-build && /snap/clion/124/bin/cmake/linux/bin/cmake -E touch /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-configure

json-populate-prefix/src/json-populate-stamp/json-populate-build: json-populate-prefix/src/json-populate-stamp/json-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'json-populate'"
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-build && /snap/clion/124/bin/cmake/linux/bin/cmake -E echo_append
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-build && /snap/clion/124/bin/cmake/linux/bin/cmake -E touch /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-build

json-populate-prefix/src/json-populate-stamp/json-populate-test: json-populate-prefix/src/json-populate-stamp/json-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'json-populate'"
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-build && /snap/clion/124/bin/cmake/linux/bin/cmake -E echo_append
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-build && /snap/clion/124/bin/cmake/linux/bin/cmake -E touch /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-test

json-populate: CMakeFiles/json-populate
json-populate: CMakeFiles/json-populate-complete
json-populate: json-populate-prefix/src/json-populate-stamp/json-populate-install
json-populate: json-populate-prefix/src/json-populate-stamp/json-populate-mkdir
json-populate: json-populate-prefix/src/json-populate-stamp/json-populate-download
json-populate: json-populate-prefix/src/json-populate-stamp/json-populate-update
json-populate: json-populate-prefix/src/json-populate-stamp/json-populate-patch
json-populate: json-populate-prefix/src/json-populate-stamp/json-populate-configure
json-populate: json-populate-prefix/src/json-populate-stamp/json-populate-build
json-populate: json-populate-prefix/src/json-populate-stamp/json-populate-test
json-populate: CMakeFiles/json-populate.dir/build.make

.PHONY : json-populate

# Rule to build all files generated by this target.
CMakeFiles/json-populate.dir/build: json-populate

.PHONY : CMakeFiles/json-populate.dir/build

CMakeFiles/json-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/json-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/json-populate.dir/clean

CMakeFiles/json-populate.dir/depend:
	cd /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild /home/kodi86/Documents/Projects/Project2DTD/cmake-build-debug/_deps/json-subbuild/CMakeFiles/json-populate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/json-populate.dir/depend

