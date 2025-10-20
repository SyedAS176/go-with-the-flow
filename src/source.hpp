#pragma once

// Class to represent a source or sink in a section
class Source {
public:
    // Constructor: sets the index and the source/sink amount
    Source(int i, float s);

    int index;          // Section index
    float sourceAmount; // Amount of source/sink
};