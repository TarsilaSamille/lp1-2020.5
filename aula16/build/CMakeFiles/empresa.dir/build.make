# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/build"

# Include any dependencies generated for this target.
include CMakeFiles/empresa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/empresa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/empresa.dir/flags.make

CMakeFiles/empresa.dir/src/main.cpp.o: CMakeFiles/empresa.dir/flags.make
CMakeFiles/empresa.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/empresa.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/empresa.dir/src/main.cpp.o -c "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/src/main.cpp"

CMakeFiles/empresa.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/empresa.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/src/main.cpp" > CMakeFiles/empresa.dir/src/main.cpp.i

CMakeFiles/empresa.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/empresa.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/src/main.cpp" -o CMakeFiles/empresa.dir/src/main.cpp.s

CMakeFiles/empresa.dir/src/Empresa.cpp.o: CMakeFiles/empresa.dir/flags.make
CMakeFiles/empresa.dir/src/Empresa.cpp.o: ../src/Empresa.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/empresa.dir/src/Empresa.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/empresa.dir/src/Empresa.cpp.o -c "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/src/Empresa.cpp"

CMakeFiles/empresa.dir/src/Empresa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/empresa.dir/src/Empresa.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/src/Empresa.cpp" > CMakeFiles/empresa.dir/src/Empresa.cpp.i

CMakeFiles/empresa.dir/src/Empresa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/empresa.dir/src/Empresa.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/src/Empresa.cpp" -o CMakeFiles/empresa.dir/src/Empresa.cpp.s

CMakeFiles/empresa.dir/src/Funcionario.cpp.o: CMakeFiles/empresa.dir/flags.make
CMakeFiles/empresa.dir/src/Funcionario.cpp.o: ../src/Funcionario.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/empresa.dir/src/Funcionario.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/empresa.dir/src/Funcionario.cpp.o -c "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/src/Funcionario.cpp"

CMakeFiles/empresa.dir/src/Funcionario.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/empresa.dir/src/Funcionario.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/src/Funcionario.cpp" > CMakeFiles/empresa.dir/src/Funcionario.cpp.i

CMakeFiles/empresa.dir/src/Funcionario.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/empresa.dir/src/Funcionario.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/src/Funcionario.cpp" -o CMakeFiles/empresa.dir/src/Funcionario.cpp.s

# Object files for target empresa
empresa_OBJECTS = \
"CMakeFiles/empresa.dir/src/main.cpp.o" \
"CMakeFiles/empresa.dir/src/Empresa.cpp.o" \
"CMakeFiles/empresa.dir/src/Funcionario.cpp.o"

# External object files for target empresa
empresa_EXTERNAL_OBJECTS =

empresa: CMakeFiles/empresa.dir/src/main.cpp.o
empresa: CMakeFiles/empresa.dir/src/Empresa.cpp.o
empresa: CMakeFiles/empresa.dir/src/Funcionario.cpp.o
empresa: CMakeFiles/empresa.dir/build.make
empresa: CMakeFiles/empresa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable empresa"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/empresa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/empresa.dir/build: empresa

.PHONY : CMakeFiles/empresa.dir/build

CMakeFiles/empresa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/empresa.dir/cmake_clean.cmake
.PHONY : CMakeFiles/empresa.dir/clean

CMakeFiles/empresa.dir/depend:
	cd "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16" "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16" "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/build" "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/build" "/home/tarsila/Área de Trabalho/LP/lp1-2020.5/aula16/build/CMakeFiles/empresa.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/empresa.dir/depend

