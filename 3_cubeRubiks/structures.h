#ifndef PRG_LABA8_CUBERUBIKS_STRUCTURES_H
#define PRG_LABA8_CUBERUBIKS_STRUCTURES_H

struct small_part_color {
    float color[3];
};

struct ColorsAll {
    float red_color[3] = {1.0f, 0.0f, 0.0f};
    float yellow_color[3] = {1.0f, 1.0f, 0.0f};
    float green_color[3] = {0.0f, 1.0f, 0.0f};
    float white_color[3] = {1.0f, 1.0f, 1.0f};
    float blue_color[3] = {0.0f, 0.0f, 1.0f};
    float orange_color[3] = {1.0f, 0.5f, 0.0f};
};

#endif
