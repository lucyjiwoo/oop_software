# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.26.4)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(machinedemolib-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[/opt/homebrew/bin/git]==])
set(GIT_VERSION_STRING [==[2.42.1]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[/opt/homebrew/bin/git;2.42.1]==]
)


include(ExternalProject)
ExternalProject_Add(machinedemolib-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/charles-owen/MachineDemoLib.git"
                    SOURCE_DIR          "/Users/lucysmac/Desktop/MSU/2023 Fall/CSE335/Canadian_jiwoo_jeong/cmake-build-debug/_deps/machinedemolib-src"
                    BINARY_DIR          "/Users/lucysmac/Desktop/MSU/2023 Fall/CSE335/Canadian_jiwoo_jeong/cmake-build-debug/_deps/machinedemolib-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


