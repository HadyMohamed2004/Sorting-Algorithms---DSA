# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Sorting_Algorithms.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Sorting_Algorithms.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Sorting_Algorithms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sorting_Algorithms.dir/flags.make

CMakeFiles/Sorting_Algorithms.dir/main.cpp.obj: CMakeFiles/Sorting_Algorithms.dir/flags.make
CMakeFiles/Sorting_Algorithms.dir/main.cpp.obj: D:/[02]\ FCAI\ -\ CU/[04]\ Year\ 2\ -\ 2nd\ Term/[02]\ CS214\ -\ Data\ Structures/[02]\ Assignments/Assignment\ 1/Sorting-Algorithms-DSA/main.cpp
CMakeFiles/Sorting_Algorithms.dir/main.cpp.obj: CMakeFiles/Sorting_Algorithms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sorting_Algorithms.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sorting_Algorithms.dir/main.cpp.obj -MF CMakeFiles\Sorting_Algorithms.dir\main.cpp.obj.d -o CMakeFiles\Sorting_Algorithms.dir\main.cpp.obj -c "D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA\main.cpp"

CMakeFiles/Sorting_Algorithms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Sorting_Algorithms.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA\main.cpp" > CMakeFiles\Sorting_Algorithms.dir\main.cpp.i

CMakeFiles/Sorting_Algorithms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Sorting_Algorithms.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA\main.cpp" -o CMakeFiles\Sorting_Algorithms.dir\main.cpp.s

# Object files for target Sorting_Algorithms
Sorting_Algorithms_OBJECTS = \
"CMakeFiles/Sorting_Algorithms.dir/main.cpp.obj"

# External object files for target Sorting_Algorithms
Sorting_Algorithms_EXTERNAL_OBJECTS =

Sorting_Algorithms.exe: CMakeFiles/Sorting_Algorithms.dir/main.cpp.obj
Sorting_Algorithms.exe: CMakeFiles/Sorting_Algorithms.dir/build.make
Sorting_Algorithms.exe: CMakeFiles/Sorting_Algorithms.dir/linkLibs.rsp
Sorting_Algorithms.exe: CMakeFiles/Sorting_Algorithms.dir/objects1.rsp
Sorting_Algorithms.exe: CMakeFiles/Sorting_Algorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sorting_Algorithms.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sorting_Algorithms.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sorting_Algorithms.dir/build: Sorting_Algorithms.exe
.PHONY : CMakeFiles/Sorting_Algorithms.dir/build

CMakeFiles/Sorting_Algorithms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sorting_Algorithms.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sorting_Algorithms.dir/clean

CMakeFiles/Sorting_Algorithms.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA" "D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA" "D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA\cmake-build-debug" "D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA\cmake-build-debug" "D:\[02] FCAI - CU\[04] Year 2 - 2nd Term\[02] CS214 - Data Structures\[02] Assignments\Assignment 1\Sorting-Algorithms-DSA\cmake-build-debug\CMakeFiles\Sorting_Algorithms.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Sorting_Algorithms.dir/depend

