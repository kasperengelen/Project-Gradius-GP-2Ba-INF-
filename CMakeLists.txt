# AUTHOR: KASPER ENGELEN
# NOTE: IF MANUAL FILE DISCORVERY IS SELECTED, EACH SUBDIR IN THE SOURCE FOLDER NEEDS A CMAKELISTS.TXT THAT ADDS THE WANTED SOURCEFILES TO THE VARIABLE 'SOURCE_FILES'
# NOTE: THE COMPILER WILL LOOK FOR HEADERS IN THE HEADER DIRECTORY. THE DIR STRUCTURE OF THE HEADER DIR MIRRORS THAT OF THE SOURCE DIR. IF YOU INCLUDE A HEADER IN A PATH, IT WILL TRY TO LOCATE THAT PATH RELATIVE TO THE HEADER DIR.
# NOTE: YOU CAN ALSO PLACE HEADER FILES INSIDE THE SOURCE DIRECTORY

cmake_minimum_required (VERSION 3.5)

# -- PROJECT SETTINGS --
set(PROJECT_NAME "GP Project")
set(BIN_NAME GP_PROJECT_EXEC)

# -- COMPILER FLAGS --
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_STATIC_LINKER_FLAGS "-lsfml-system -lsfml-window -lsfml-graphics")

# -- SOURCE FILE DISCOVERY SETTINGS --
# Set to 'AUTO' for recursive search, or 'MAN' for manually specified CMakeLists.txt
set(FILE_DISCOVERY_MODE "AUTO")

# -- SPECIFY SUBDIR LOCATIONS --
# NOTE ALL RELATIVE TO BUILD DIRECTORY!
set(BIN_DIR "../bin")   # output dir for binaries
set(SOURCE_DIR "./src") # dir where to find source files

# -- GUARD TO PREVENT IN SOURCE BUILDS --
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message(WARNING "You're trying to run an in-source build. This will pollute the project with CMake build files. CMake will now restart with arguments:
                        cmake -H. -B${BUILD_DIR}")
    # SOURCE: https://stackoverflow.com/questions/11143062/getting-cmake-to-build-out-of-source-without-wrapping-scripts
    execute_process(
            COMMAND ${CMAKE_COMMAND} -H. -B./build
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
    message(FATAL_ERROR "CMake finished out-of-source build. Ignore this error.")
endif()

# -- SET PROJECT NAME AND OUTPUT DIR --
project(${PROJECT_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}) # set output dir for executables to "./bin/"

# -- FIND SOURCE FILES --
if(FILE_DISCOVERY_MODE STREQUAL "AUTO")
    file(GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.cpp")
    message("USING AUTOMATIC SOURCE FILE DISCOVERY.")
elseif(FILE_DISCOVERY_MODE STREQUAL "MAN")
    add_subdirectory(${SOURCE_DIR}) # set sourcefiles as subdirectory
    message("USING MANUAL SOURCE FILE DISCOVERY.")
else()
    message(FATAL_ERROR "FATAL ERROR: FILE DISCOVERY MODE CANNOT BE '${FILE_DISCOVERY_MODE}'.")
    return()
endif()

# -- EXPAND MODULE PATH TO ACCOMODATE FOR SFML --
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# -- FIND SFML LIBRARY --
find_package(SFML 2 COMPONENTS system window graphics)

# -- INCLUDE SFML --
include_directories(${SFML_INCLUDE_DIR})

add_executable(${BIN_NAME} ${SOURCE_FILES})

# -- LINK SFML --
target_link_libraries(${BIN_NAME} ${SFML_LIBRARIES})








