#!/bin/bash

g++ Color.cpp ANSIEscapeSequences.cpp BaseWidget.cpp Button.cpp Text.cpp InputBox.cpp Spacer.cpp Border.cpp HContainer.cpp VContainer.cpp InputParser.cpp GTUI.cpp $1.cpp -o $2