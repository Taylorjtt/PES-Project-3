*John Taylor*
# PES-Project-3 Memory Test Utility
## Introduction
This repository includes a suite of memory test utilities, a pseudo random pattern generator, a cross-platform logger, an LED controller and unit tests that test the functionality of the pattern generator as well as the memory test utilities. The code has been tested Using MCUXPresso on the **FRDM-KL25Z** dev board as well as **Ubuntu 18.04.3 LTS**
## Observations

### Memory Alignment
I really struggled for a while with the memory alignment portion of this project. I got to a point with the write_memory function where I understood the pointer math I needed to do to write an 8 bit value to a 32 bit pointer address, but the KL25Z wouldn't let me write to an unaligned address (it would just hardfault). I finally devised a way to force the write to be aligned by shifting bits around based on the result of the desired address modulo 4 and writing that data to the aligned address.

## Build Notes
1. Pull the repo from github
2. Import it into MCUXpresso IDE
3. Open the build target view
4. Go into the Debug Folder in the build targets view
5. Double click clean to clean the project
### Building and running the Unit Tests
1. Double click the unit_test build target to build this target
2. Create a build configuration that uses the C/C++ application "Debug/unit_tests.axf" as the target to run.
3. Connect to a the KLZ serial using a serial emulator of your choice (I use tio). The command is **sudo tio /dev/ttyACM0 -b 115200** for me.
4. Start the debug session. (Note: You will know if your debug session is correct if the code begins execution in the tests.c file. **IT SHOULD NOT START IN THE Project_3.c file!**)
5. Observe the output via serial.
### Building and running the Freedom board version
1. Double click Clean to clean the project and then double click the fb build target to build this target
2. Create a build configuration that uses the C/C++ application "Debug/Project_3.axf" as the target to run.
3. Connect to a the KLZ serial using a serial emulator of your choice I use tio (([https://tio.github.io/](https://tio.github.io/)). The command is **sudo tio /dev/ttyACM0 -b 115200** for me.
4. Start the debug session. (Note: You will know if your debug session is correct if the code begins execution in the Project_3.c file. **IT SHOULD NOT START IN THE tests.c file!**)
5. Observe the output via serial.
### Building and running the PC version
1. Double click clean to clean the project and then double click the pc build target to build this target
2. open a local terminal and navigate the project's debug folder
3. run the following command **./P3.o**
4. observe the output
