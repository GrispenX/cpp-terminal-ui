#ifndef ALIGNMENT_H
#define ALIGNMENT_H

enum Organizing
{
    VERTICAL,
    HORIZONTAL
};

enum Position
{
    TOP_LEFT,
    TOP_MIDDLE,
    TOP_RIGHT,
    MIDDLE_LEFT,
    MIDDLE_MIDDLE,
    MIDDLE_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_MIDDLE,
    BOTTOM_RIGHT
};

class Alignment
{
public:
    Organizing organizing; // Direction of elements situated in frame
    Position position;

    unsigned int paddle_top;
    unsigned int paddle_bottom;
    unsigned int paddle_left;
    unsigned int paddle_right;

    float gap; // Distance between elements in % (from 0 to 1)
    unsigned int max_gap; // Biggest possible distance between elements. 0 for disable
};

Alignment::Alignment()
{
    organizing = HORIZONTAL;
    position = TOP_LEFT;

    paddle_top = 0;
    paddle_bottom = 0;
    paddle_left = 0;
    paddle_right = 0;

    gap = 1;
    max_gap = 0;
}

#endif