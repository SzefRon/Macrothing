cmake_minimum_required(VERSION 3.0.0)
project(MacroCreator VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(include)

add_executable(MacroCreator
src/main.cpp
src/App.cpp
src/Abort.cpp
src/Instruction.cpp
src/WaitableInstruction.cpp
src/SendInputInstruction.cpp

src/instructions/Loop.cpp
src/instructions/Wait.cpp
src/instructions/KeyboardPress.cpp
src/instructions/KeyboardRelease.cpp
src/instructions/MousePress.cpp
src/instructions/MouseRelease.cpp
src/instructions/MouseMove.cpp

src/helper/KeyCodes.cpp

src/interpreter/Interpreter.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
