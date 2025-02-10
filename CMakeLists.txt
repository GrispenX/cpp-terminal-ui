add_library(gtui STATIC)
target_sources(gtui
    PRIVATE
    Color.cpp 
    ANSIEscapeSequences.cpp
    BaseWidget.cpp
    Button.cpp
    Text.cpp
    InputBox.cpp
    Spacer.cpp
    Border.cpp
    BaseContainer.cpp
    HContainer.cpp
    VContainer.cpp
    InputParser.cpp
    GTUI.cpp)
target_include_directories(gtui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})