*John Taylor*
# PES-Project-3 Memory Test Utility
## Introduction
This repository includes a suite of memory test utilities, a pseudo random pattern generator, a cross-platform logger, an LED controller and unit tests that test the functionality of the pattern generator as well as the memory test utilities. The code has been tested Using MCUXPresso on the **FRDM-KL25Z** dev board as well as **Ubuntu 18.04.3 LTS**
## Observations
### Project Quality
A big issue for me so far in this class has been the quality of the projects. Each of the first two *real* projects have had big changes made to them almost a full week after the project's release. As someone who starts the project on the day they are released, this is frustrating because I may end up spending a lot of time working on something that is removed from the project completely next class. Choosing to wait until the next class period to start the project effectively reduces the total amount of time that I have to work on the project, so it is a lose-lose.
Besides the late changes to the project I personally have found 3 instances of incorrect function signatures or incorrect sample output data in  projects 1-3. I get the feeling that there isn't someone trying to actually do these projects before they are assigned. These type of errors muddy the water of what the project is trying to teach, and I expect better from a class that I am paying over $3000 to participate in.

### Memory Alignment
I really struggled for a while with the memory alignment portion of this project. I got to a point with the write_memory function where I understood the pointer math I needed to do to write an 8 bit value to a 32 bit pointer address, but the KL25Z wouldn't let me write to an unaligned address (it would just hardfault). I finally devised a way to force the write to be aligned by shifting bits around based on the result of the desired address modulo 4 and writing that data to the aligned address, but my issue is that we never even came close to touching on this in class. The responses I got in Slack when I asked about this are another thing that makes me feel like these projects aren't being test-driven by anyone before they are assigned.

## Build Notes
1. Pull the repo from github
2. Import it into MCUXpresso IDE
3. 
