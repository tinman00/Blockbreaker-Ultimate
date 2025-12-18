#pragma once
#include "GameObject.h"

class UI :
    public GameObject
{
public:
    int layer; // Greater layer means ui upper.
    int top, bottom;
    int left, right;
    int width, height;
    virtual void OnClick();
    bool Enclose(int x, int y);
};

