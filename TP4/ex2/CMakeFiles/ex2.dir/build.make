# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/florian/Bureau/git/IM7/TP4/ex2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/florian/Bureau/git/IM7/TP4/ex2

# Include any dependencies generated for this target.
include CMakeFiles/ex2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex2.dir/flags.make

CMakeFiles/ex2.dir/ex2.cpp.o: CMakeFiles/ex2.dir/flags.make
CMakeFiles/ex2.dir/ex2.cpp.o: ex2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/florian/Bureau/git/IM7/TP4/ex2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex2.dir/ex2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2.dir/ex2.cpp.o -c /home/florian/Bureau/git/IM7/TP4/ex2/ex2.cpp

CMakeFiles/ex2.dir/ex2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.dir/ex2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/florian/Bureau/git/IM7/TP4/ex2/ex2.cpp > CMakeFiles/ex2.dir/ex2.cpp.i

CMakeFiles/ex2.dir/ex2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.dir/ex2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/florian/Bureau/git/IM7/TP4/ex2/ex2.cpp -o CMakeFiles/ex2.dir/ex2.cpp.s

CMakeFiles/ex2.dir/ex2.cpp.o.requires:

.PHONY : CMakeFiles/ex2.dir/ex2.cpp.o.requires

CMakeFiles/ex2.dir/ex2.cpp.o.provides: CMakeFiles/ex2.dir/ex2.cpp.o.requires
	$(MAKE) -f CMakeFiles/ex2.dir/build.make CMakeFiles/ex2.dir/ex2.cpp.o.provides.build
.PHONY : CMakeFiles/ex2.dir/ex2.cpp.o.provides

CMakeFiles/ex2.dir/ex2.cpp.o.provides.build: CMakeFiles/ex2.dir/ex2.cpp.o


# Object files for target ex2
ex2_OBJECTS = \
"CMakeFiles/ex2.dir/ex2.cpp.o"

# External object files for target ex2
ex2_EXTERNAL_OBJECTS =

ex2: CMakeFiles/ex2.dir/ex2.cpp.o
ex2: CMakeFiles/ex2.dir/build.make
ex2: /usr/local/lib/libopencv_dnn.so.3.4.0
ex2: /usr/local/lib/libopencv_ml.so.3.4.0
ex2: /usr/local/lib/libopencv_objdetect.so.3.4.0
ex2: /usr/local/lib/libopencv_shape.so.3.4.0
ex2: /usr/local/lib/libopencv_stitching.so.3.4.0
ex2: /usr/local/lib/libopencv_superres.so.3.4.0
ex2: /usr/local/lib/libopencv_videostab.so.3.4.0
ex2: /usr/local/lib/libopencv_viz.so.3.4.0
ex2: /usr/local/lib/libopencv_calib3d.so.3.4.0
ex2: /usr/local/lib/libopencv_features2d.so.3.4.0
ex2: /usr/local/lib/libopencv_flann.so.3.4.0
ex2: /usr/local/lib/libopencv_highgui.so.3.4.0
ex2: /usr/local/lib/libopencv_photo.so.3.4.0
ex2: /usr/local/lib/libopencv_video.so.3.4.0
ex2: /usr/local/lib/libopencv_videoio.so.3.4.0
ex2: /usr/local/lib/libopencv_imgcodecs.so.3.4.0
ex2: /usr/local/lib/libopencv_imgproc.so.3.4.0
ex2: /usr/local/lib/libopencv_core.so.3.4.0
ex2: CMakeFiles/ex2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/florian/Bureau/git/IM7/TP4/ex2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex2.dir/build: ex2

.PHONY : CMakeFiles/ex2.dir/build

CMakeFiles/ex2.dir/requires: CMakeFiles/ex2.dir/ex2.cpp.o.requires

.PHONY : CMakeFiles/ex2.dir/requires

CMakeFiles/ex2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex2.dir/clean

CMakeFiles/ex2.dir/depend:
	cd /home/florian/Bureau/git/IM7/TP4/ex2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/florian/Bureau/git/IM7/TP4/ex2 /home/florian/Bureau/git/IM7/TP4/ex2 /home/florian/Bureau/git/IM7/TP4/ex2 /home/florian/Bureau/git/IM7/TP4/ex2 /home/florian/Bureau/git/IM7/TP4/ex2/CMakeFiles/ex2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex2.dir/depend

