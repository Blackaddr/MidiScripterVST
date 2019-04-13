/*
  ==============================================================================

    Misc.cpp
    Created: 27 Mar 2019 6:08:12pm
    Author:  Edmund Blackaddr

  ==============================================================================
*/

#include "Misc.h"

int getElement(int *arr, int seq, int ev, int word)
{
    int index = (seq*MAX_EVENTS*3) + (ev*3) + word;
    return arr[index];
}

//int getElement(int (&arr)[MAX_SEQUENCES][MAX_EVENTS][3], int seq, int ev, int word)
//{
//    int index = arr[seq][ev][word];
//    return arr[index];
//}

void setElement(int *arr, int seq, int ev, int word, int value)
{
    int index = (seq*MAX_EVENTS*3) + (ev*3) + word;
    arr[index] = value;
}

//void setElement(int (&arr)[MAX_EVENTS][MAX_EVENTS][3], int seq, int ev, int word, int value)
//{
//    int index = arr[seq][ev][word];
//    arr[index] = value;
//}
