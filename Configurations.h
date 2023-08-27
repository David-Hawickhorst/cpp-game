/******************************************************************************
 * @brief
 *****************************************************************************/
#pragma once

struct WindowConfig {
    int width;
    int height;
    int frameLimit;
    WindowConfig() : width(1280), height(720), frameLimit(60) {}
};

struct ShapeFillColor {
    int red;
    int green;
    int blue;
};


struct PlayerConfig {
    int shapeRadius;
    int collisionRadius;
    int verticies;
};
